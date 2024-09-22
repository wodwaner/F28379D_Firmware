/*
 * Flash_F28379.c
 *
 *  Created on: 18 de set de 2024
 *      Author: wodwa
 */
#include "Flash_F28379D.h"

void FW_Update(void){
    uint8_t i, t;
    uint8_t msn[] = {'U','P','F','W','1','0','0','0','0','0','0','0','0','0','\r','\n'};
    DINT;
    IFR = 0x0000;
    SciaRegs.SCIFFRX.bit.RXFFIENA = 0;  // Disable Interrupt RX
    SciaRegs.SCIFFTX.bit.TXFIFORESET = 1;
    SciaRegs.SCIFFRX.bit.RXFIFORESET = 1;

    for(i=0; i<UART_BUFF_SIZE; i++){
        t = SciaRegs.SCIRXBUF.all;
        while(!SciaRegs.SCICTL2.bit.TXRDY);
        SciaRegs.SCITXBUF.all = *(msn+i);
    }

    GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1;
    FW_Copy_Data();
    // Reset
    EALLOW;
    WdRegs.SCSR.all = 0;    //enable WDRST
    WdRegs.WDCR.all = 0x28; //enable WD
    EDIS;
    do{

    }while(1);

}

uint8_t FW_Copy_Data(void){
    st_BlockHeader BlockHeader, Sector;
    Uint16 Buffer[N_WORDS];
    Uint16 i, j;
    Uint16 wordData;
    Uint16 wordsWritten = 0;

    uint8_t cod = 0;
    Fapi_StatusType oReturnCheck;
    Fapi_FlashStatusWordType oFlashStatusWord;
    Fapi_FlashStatusType oFlashStatus;

    EALLOW;
    // This function is required to initialize the Flash API based on System frequency before any other Flash API operation can be performed
    oReturnCheck = Fapi_initializeAPI(F021_CPU0_BASE_ADDRESS, 200);
    if(oReturnCheck != Fapi_Status_Success) return 0x01;
    //oFlashStatus = Fapi_getFsmStatus();

    // Fapi_setActiveFlashBank function sets the Flash bank and FMC for further there is only one bank per FMC in
    // the TMS320F2837xD device, only Fapi_FlashBank0 should be used for this paramete, TMS320F2837xD Flash API pg 11 SPNU629A.pdf
    oReturnCheck = Fapi_setActiveFlashBank(Fapi_FlashBank0);
    if(oReturnCheck != Fapi_Status_Success) return 0x02;
    EDIS;

    while(1){
        FW_Get_SCI_Data(&wordData, &cod);
        if(cod == FW_COD_SIZE) BlockHeader.BlockSize = wordData;
        else if(cod == FW_COD_END) return 0;

        FW_Get_SCI_Data(&wordData, &cod);
        if(cod == FW_COD_DST_H) BlockHeader.DestAddr = wordData;
        else if(cod == FW_COD_END) return 0;

        BlockHeader.DestAddr <<= 16;

        FW_Get_SCI_Data(&wordData, &cod);
        if(cod == FW_COD_DST_L) BlockHeader.DestAddr |= wordData;
        else if(cod == FW_COD_END) return 0;

        wordsWritten = 0;
        EALLOW;
        for(i=0; i<BlockHeader.BlockSize; i+=0){
            //program 8 words at once, 128-bits
            for(j=0; j<N_WORDS; j++){
                if(i < BlockHeader.BlockSize){
                    i++;
                    FW_Get_SCI_Data(&wordData, &cod);
                    if(cod == FW_COD_DATA) Buffer[j] = wordData;
                }else{
                    Buffer[j] = 0xFFFF;
                }
            }
            //check if there are words left to be written
            if(wordsWritten < BlockHeader.BlockSize){
                //clean out flash banks if needed
                Sector.DestAddr = Flash_Find_Sector(BlockHeader.DestAddr, &Sector.BlockSize);
                if(Sector.DestAddr != 0xdeadbeef){
                    // Erase Sector
                    oReturnCheck = Fapi_issueAsyncCommandWithAddress(Fapi_EraseSector,(uint32 *)Sector.DestAddr);
                    while(Fapi_checkFsmForReady() == Fapi_Status_FsmBusy);  // Wait until FSM is done with erase sector operation
                    // Verify that Sector is erased. The Erase step itself does a verify as it goes.
                    oReturnCheck = Fapi_doBlankCheck((uint32 *)Sector.DestAddr,Sector.BlockSize,&oFlashStatusWord);
                    oFlashStatus = Fapi_getFsmStatus();
                    if((oReturnCheck != Fapi_Status_Success) || (oFlashStatus != 0)) return 0x03;
                }
                //program 8 words at once, 128-bits
                oReturnCheck = Fapi_issueProgrammingCommand((uint32 *)BlockHeader.DestAddr,\
                                                            Buffer,\
                                                            N_WORDS,\
                                                            0,\
                                                            0,\
                                                            Fapi_AutoEccGeneration);
                while(Fapi_checkFsmForReady() == Fapi_Status_FsmBusy);
                oFlashStatus = Fapi_getFsmStatus();
                if(oReturnCheck != Fapi_Status_Success || oFlashStatus != 0) return 0x04;

                oReturnCheck = Fapi_doVerify((uint32 *)(BlockHeader.DestAddr),\
                                             (N_WORDS/2),\
                                             (uint32 *)(&Buffer[0]),\
                                             &oFlashStatusWord);
                if(oReturnCheck != Fapi_Status_Success) return 0x05;

            }// end if wordsWritten < BlockHeader.BlockSize
            BlockHeader.DestAddr += N_WORDS;
            wordsWritten += N_WORDS;
        } // end for i < BlockHeader.BlockSize
        EDIS;
    }
}


// Find Sector - This routine finds what sector the mentioned address is a part of.
Uint32 Flash_Find_Sector(Uint32 address, Uint16 *size){
    static uint8_t SectorErased[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    if((address >= Bzero_SectorA_start) && (address <= Bzero_SectorA_End) && (SectorErased[0] == 0)){
        SectorErased[0] = 1;
        *size = Bzero_16KSector_u32length;
        return (Uint32)Bzero_SectorA_start;
    }
    if((address >= Bzero_SectorB_start) && (address <= Bzero_SectorB_End) && (SectorErased[1] == 0)){
        SectorErased[1] = 1;
        *size = Bzero_16KSector_u32length;
        return (Uint32)Bzero_SectorB_start;
    }
    if((address >= Bzero_SectorC_start) && (address <= Bzero_SectorC_End) && (SectorErased[2] == 0)){
        SectorErased[2] = 1;
        *size = Bzero_16KSector_u32length;
        return (Uint32)Bzero_SectorC_start;
    }
    if((address >= Bzero_SectorD_start) && (address <= Bzero_SectorD_End) && (SectorErased[3] == 0)){
        SectorErased[3] = 1;
        *size = Bzero_16KSector_u32length;
        return (Uint32)Bzero_SectorD_start;
    }
    if((address >= Bzero_SectorE_start) && (address <= Bzero_SectorE_End) && (SectorErased[4] == 0)){
        SectorErased[4] = 1;
        *size = Bzero_64KSector_u32length;
        return (Uint32)Bzero_SectorE_start;
    }
    if((address >= Bzero_SectorF_start) && (address <= Bzero_SectorF_End) && (SectorErased[5] == 0)){
        SectorErased[5] = 1;
        *size = Bzero_64KSector_u32length;
        return (Uint32)Bzero_SectorF_start;
    }
    if((address >= Bzero_SectorG_start) && (address <= Bzero_SectorG_End) && (SectorErased[6] == 0)){
        SectorErased[6] = 1;
        *size = Bzero_64KSector_u32length;
        return (Uint32)Bzero_SectorG_start;
    }
    if((address >= Bzero_SectorH_start) && (address <= Bzero_SectorH_End) && (SectorErased[7] == 0)){
        SectorErased[7] = 1;
        *size = Bzero_64KSector_u32length;
        return (Uint32)Bzero_SectorH_start;
    }
    if((address >= Bzero_SectorI_start) && (address <= Bzero_SectorI_End) && (SectorErased[8] == 0)){
        SectorErased[8] = 1;
        *size = Bzero_64KSector_u32length;
        return (Uint32)Bzero_SectorI_start;
    }
    if((address >= Bzero_SectorJ_start) && (address <= Bzero_SectorJ_End) && (SectorErased[9] == 0)){
        SectorErased[9] = 1;
        *size = Bzero_64KSector_u32length;
        return (Uint32)Bzero_SectorJ_start;
    }
    if((address >= Bzero_SectorK_start) && (address <= Bzero_SectorK_End) && (SectorErased[10] == 0)){
        SectorErased[10] = 1;
        *size = Bzero_16KSector_u32length;
        return (Uint32)Bzero_SectorK_start;
    }
    if((address >= Bzero_SectorL_start) && (address <= Bzero_SectorL_End) && (SectorErased[11] == 0)){
        SectorErased[11] = 1;
        *size = Bzero_16KSector_u32length;
        return (Uint32)Bzero_SectorL_start;
    }
    if((address >= Bzero_SectorM_start) && (address <= Bzero_SectorM_End) && (SectorErased[12] == 0)){
        SectorErased[12] = 1;
        *size = Bzero_16KSector_u32length;
        return (Uint32)Bzero_SectorM_start;
    }
    if((address >= Bzero_SectorN_start) && (address <= Bzero_SectorN_End) && (SectorErased[13] == 0)){
        SectorErased[13] = 1;
        *size = Bzero_16KSector_u32length;
        return (Uint32)Bzero_SectorN_start;
    }
    *size = 0;
    return 0xdeadbeef; // a proxy address to signify that it is not/ a flash sector.
}

/*void Flash_Set_APIError(Fapi_StatusType status, st_statuscode *v){
    if(status == Fapi_Error_AsyncIncorrectDataBufferLength) v->flashAPIError = INCORRECT_DATA_BUFFER_LENGTH;
    else if(status == Fapi_Error_AsyncIncorrectEccBufferLength)  v->flashAPIError = INCORRECT_ECC_BUFFER_LENGTH;
    else if(status == Fapi_Error_AsyncDataEccBufferLengthMismatch)  v->flashAPIError = DATA_ECC_BUFFER_LENGTH_MISMATCH;
    else if(status == Fapi_Error_FeatureNotAvailable)  v->flashAPIError = FEATURE_NOT_AVAILABLE;
    else if(status == Fapi_Error_Fail)  v->flashAPIError = FAILURE;
    else  v->Status = NOT_RECOGNIZED;
}*/

void FW_Get_SCI_Data(Uint16 *data, uint8_t *cod){
    uint8_t temp[3];
    while(SciaRegs.SCIFFRX.bit.RXFFST < 3);
    temp[0] = SciaRegs.SCIRXBUF.all;
    temp[1] = SciaRegs.SCIRXBUF.all;
    temp[2] = SciaRegs.SCIRXBUF.all;
    *data =  (temp[0]<<8) + (temp[1]);
    *cod = temp[2];
    while(!SciaRegs.SCICTL2.bit.TXRDY);
    SciaRegs.SCITXBUF.all = temp[0];
    while(!SciaRegs.SCICTL2.bit.TXRDY);
    SciaRegs.SCITXBUF.all = temp[2];
}
