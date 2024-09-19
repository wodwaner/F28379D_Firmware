#include "Peripheral_Setup.h"
#include "SCIx.h"
#include "Flash_F28379D.h"

// ====== Local functions ==================

// ======= Interruptions ===================
#pragma CODE_SECTION(isr_cpu_timer0, ".TI.ramfunc");
#pragma CODE_SECTION(isr_scia_rx, ".TI.ramfunc");
__interrupt void isr_cpu_timer0(void);
__interrupt void isr_scia_rx(void);
// ======= Local variables =================
uint32_t counter = 0;
st_SCI SCI;

void main(void){
    uint8_t i;
#ifdef _FLASH
    memcpy(&Upflash_RunStart, &Upflash_LoadStart, (size_t)&Upflash_LoadSize);
#endif

    InitSysCtrl();                              // Initialize System Control:
    DisablePeripheralClocks();
    DINT;                                       // Disable CPU interrupts
    InitPieCtrl();                              // Initialize the PIE control registers to their default state
    IER = 0x0000;                               // Disable CPU interrupts
    IFR = 0x0000;                               // Clear all CPU interrupt flags:
    InitPieVectTable();                         // Initialize the PIE vector table

    EALLOW;
    CpuSysRegs.PCLKCR0.bit.CPUTIMER0 = 1;       // Enable timer clock
    PieVectTable.TIMER0_INT = &isr_cpu_timer0;  // Redirect Timer0 to interruption
    PieVectTable.SCIA_RX_INT = &isr_scia_rx;    // Redirect SCIA RX to interruption
    EDIS;

    // pg. 102 PIE Channel Mapping spruhm8i.pdf - Technical reference
    PieCtrlRegs.PIEIER1.bit.INTx7 = 1;          // Enable PieVector to Timer 0 interrupt
    PieCtrlRegs.PIEIER9.bit.INTx1 = 1;          // Enable PieVector to SCIA RX interrupt
    IER |= (M_INT1|M_INT9);                     // Enable lines of interrupt

    Setup_GPIO();                               // Configure GPIOs
    Setup_SCI_A();
    SCI_Config(&SCI);

    InitCpuTimers();                            // Initializae cpu timer
    ConfigCpuTimer(&CpuTimer0, 200, 1000000);   // Configure cpu timer0 with 200MHz and 1s
    CpuTimer0Regs.TCR.all = 0x4000;             // Enable timer 0
    //========================================

    EINT;                                       // Enable Global interrupt INTM
    ERTM;                                       // Enable Global realtime interrupt DBGM
    GpioDataRegs.GPADAT.bit.GPIO31 = 1;         // Turn off BLUE LED
    GpioDataRegs.GPBDAT.bit.GPIO34 = 1;         // Turn off RED LED

    while(1){
        counter++;
        if(counter == 0x000FFFFF){
            counter = 0;
        }

        if(SCI.transmit_message) SCI.send(&SCI);

        if(SCI.new_message){
            SCI.new_message = 0;
            if(SCI.rx[14] != '\r' || SCI.rx[15] != '\n') continue;
            for(i=0;i<UART_BUFF_SIZE-2;i++) SCI.tx[i] = ' ';
            if(SCI.rx[0] == 'F' && SCI.rx[1] == 'W' && SCI.rx[2] == 'V' && SCI.rx[3] == 'E' && SCI.rx[4] == 'R'){
                SCI.tx[0] = 'F'; SCI.tx[1] = 'W'; SCI.tx[2] = '.'; SCI.tx[3] = ' ';
                SCI.tx[4] = 'V'; SCI.tx[5] = '0'; SCI.tx[6] = '0'; SCI.tx[7] = '3';
                SCI.transmit_message = 1;
            }else if(SCI.rx[0] == 'H' && SCI.rx[1] == 'E' && SCI.rx[2] == 'L' && SCI.rx[3] == 'L' && SCI.rx[4] == 'O'){
                SCI.tx[0] = 'H'; SCI.tx[1] = 'e'; SCI.tx[2] = SCI.tx[3] = 'l'; SCI.tx[4] = 'o';
                SCI.tx[5] = ' ';
                SCI.tx[6] = 'W'; SCI.tx[7] = 'o'; SCI.tx[8] = 'r'; SCI.tx[9] = 'l'; SCI.tx[10] = 'd';
                SCI.transmit_message = 1;
            }else if(SCI.rx[0] == 'U' && SCI.rx[1] == 'P' && SCI.rx[2] == 'F' && SCI.rx[3] == 'W' && SCI.rx[4] == '0'){
                FW_Update();
            }
        }
    }
    return;
}


// ======= Interruptions ===================
__interrupt void isr_cpu_timer0(void){
    GpioDataRegs.GPATOGGLE.bit.GPIO31 = 1;
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}

__interrupt void isr_scia_rx(void){
    // Read 16 bytes
    uint8_t i = 0;
    while(i != UART_BUFF_SIZE) SCI.rx[i++] = SciaRegs.SCIRXBUF.all;  // Read data
    SCI.new_message = 1;
    SciaRegs.SCIFFRX.bit.RXFFOVRCLR = 1;    // Clear Overflow flag
    SciaRegs.SCIFFRX.bit.RXFFINTCLR = 1;    // Clear Interrupt flag
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP9; // Issue PIE ack
}
