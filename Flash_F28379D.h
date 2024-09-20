/*
 * Flash_F28379D.h
 *
 *  Created on: 18 de set de 2024
 *      Author: wodwa
 */

#ifndef FLASH_F28379D_H_
#define FLASH_F28379D_H_
#include "Peripheral_Setup.h"
#include "F021_F2837xD_C28x.h"

#define NO_ERROR                    0x1000
#define BLANK_ERROR                 0x2000
#define VERIFY_ERROR                0x3000
#define PROGRAM_ERROR               0x4000
#define COMMAND_ERROR               0x5000
#define UNLOCK_ERROR                0x6000

#define INCORRECT_DATA_BUFFER_LENGTH         0x7000
#define INCORRECT_ECC_BUFFER_LENGTH          0x8000
#define DATA_ECC_BUFFER_LENGTH_MISMATCH      0x9000
#define FEATURE_NOT_AVAILABLE                0xB000
#define FAILURE                              0xE000
#define NOT_RECOGNIZED                       0xF000

#define N_SECTOR    14
#define N_WORDS     8    // 8*16 = 128 bits

#define Bzero_SectorN_start         0xBE000
#define Bzero_SectorN_End           0xBFFFF
#define Bzero_SectorM_start         0xBC000
#define Bzero_SectorM_End           0xBDFFF
#define Bzero_SectorL_start         0xBA000
#define Bzero_SectorL_End           0xBBFFF
#define Bzero_SectorK_start         0xB8000
#define Bzero_SectorK_End           0xB9FFF
#define Bzero_SectorJ_start         0xB0000
#define Bzero_SectorJ_End           0xB7FFF
#define Bzero_SectorI_start         0xA8000
#define Bzero_SectorI_End           0xAFFFF
#define Bzero_SectorH_start         0xA0000
#define Bzero_SectorH_End           0xA7FFF
#define Bzero_SectorG_start         0x98000
#define Bzero_SectorG_End           0x9FFFF
#define Bzero_SectorF_start         0x90000
#define Bzero_SectorF_End           0x97FFF
#define Bzero_SectorE_start         0x88000
#define Bzero_SectorE_End           0x8FFFF
#define Bzero_SectorD_start         0x86000
#define Bzero_SectorD_End           0x87FFF
#define Bzero_SectorC_start         0x84000
#define Bzero_SectorC_End           0x85FFF
#define Bzero_SectorB_start         0x82000
#define Bzero_SectorB_End           0x83FFF
#define Bzero_SectorA_start         0x80000
#define Bzero_SectorA_End           0x81FFF

#define Bzero_16KSector_u32length   0x1000
#define Bzero_64KSector_u32length   0x4000

#define FW_COD_SIZE   0x00
#define FW_COD_DST_H   0x01
#define FW_COD_DST_L   0x02
#define FW_COD_DATA   0x03
#define FW_COD_END   0xFF

typedef struct{
   Uint16 Status;
   Uint32 Address;
   Uint16 flashAPIError;
   Uint32 flashAPIFsmStatus;
}st_statuscode;

typedef struct{
    Uint16 BlockSize;
    Uint32 DestAddr;
}st_BlockHeader;

#ifdef _FLASH
#pragma CODE_SECTION(FW_Update,".TI.ramfunc");
#pragma CODE_SECTION(FW_Copy_Data,".TI.ramfunc");
#pragma CODE_SECTION(Flash_Find_Sector,".TI.ramfunc");
#pragma CODE_SECTION(Flash_Set_APIError,".TI.ramfunc");
#pragma CODE_SECTION(Flash_Get_SCI_Data,".TI.ramfunc");

extern Uint16 Upflash_LoadStart;
extern Uint16 Upflash_LoadSize;
extern Uint16 Upflash_LoadEnd;
extern Uint16 Upflash_RunStart;
extern Uint16 Upflash_RunSize;
extern Uint16 Upflash_RunEnd;
#endif

void FW_Update(void);
uint8_t FW_Copy_Data(void);
Uint32 Flash_Find_Sector(Uint32 address, Uint16 *size);
void Flash_Set_APIError(Fapi_StatusType status, st_statuscode *v);
void Flash_Get_SCI_Data(Uint16 *data, uint8_t *cod);

#endif /* FLASH_F28379D_H_ */
