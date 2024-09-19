/*
 * Peripheral_Setup.c
 */
#include "Peripheral_Setup.h"

void Setup_GPIO(void){
    // pg 959 Table Mux, pg 965 Registers and  spruhm8i.pdf - Technical reference
    EALLOW;
    // LED 31 A, 2
    // LED 34 B, 1
    GpioCtrlRegs.GPBGMUX1.bit.GPIO34 = 0;
    GpioCtrlRegs.GPAGMUX2.bit.GPIO31 = 0;

    GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 0;
    GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 0;

    GpioCtrlRegs.GPBPUD.bit.GPIO34 = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO31 = 1;

    GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO31 = 1;

    GpioCtrlRegs.GPBCSEL1.bit.GPIO34 = GPIO_MUX_CPU1;
    GpioCtrlRegs.GPACSEL4.bit.GPIO31 = GPIO_MUX_CPU1;

    // SCIA USB
    GpioCtrlRegs.GPBGMUX1.bit.GPIO42 = 3;
    GpioCtrlRegs.GPBGMUX1.bit.GPIO43 = 3;

    GpioCtrlRegs.GPBMUX1.bit.GPIO42 = 3;
    GpioCtrlRegs.GPBMUX1.bit.GPIO43 = 3;
    GpioCtrlRegs.GPBCSEL2.bit.GPIO43 = 3;   // Asynch input

    EDIS;
}


void Setup_SCI_A(void){
    EALLOW;
    CpuSysRegs.PCLKCR7.bit.SCI_A = 1;
    EDIS;
    // pg 2279 spruhm8i.pdf - Technical reference
    SciaRegs.SCICCR.all = 0x0007;               // 1 stop bit,  No loopback, no parity, 8 char bits,
    //SciaRegs.SCICCR.bit.SCICHAR = 0x07;       // SCI character length from one to eight           bits

    // async mode, idle-line protocol
    SciaRegs.SCICTL1.all = 0x0003;          // enable TX, RX, internal SCICLK, Disable RX ERR, SLEEP, TXWAKE
    SciaRegs.SCICTL2.bit.TXINTENA = 0;
    SciaRegs.SCICTL2.bit.RXBKINTENA = 1;
    SciaRegs.SCIHBAUD.all = 0x0000;
    SciaRegs.SCILBAUD.all = SCI_PRD;

    SciaRegs.SCIFFTX.all = 0xC022;
    //ScibRegs.SCIFFRX.all = 0x001F;
    SciaRegs.SCIFFRX.bit.RXFFIENA = 1;
    SciaRegs.SCIFFRX.bit.RXFFIL = UART_BUFF_SIZE;

    SciaRegs.SCIFFCT.all = 0x00;
    SciaRegs.SCICTL1.all = 0x0023;     // Relinquish SCI from Reset
    SciaRegs.SCIFFTX.bit.TXFIFORESET = 1;
    SciaRegs.SCIFFRX.bit.RXFIFORESET = 1;
}





