/*
 * SCIx.c
 *
 *  Created on: 18 de set de 2024
 *      Author: wodwa
 */
#include "SCIx.h"

void SCI_Config(st_SCI *v){
    v->send = &SCI_Send;
    v->tx[0] = 'H'; v->tx[1] = 'e'; v->tx[2] = v->tx[3] = 'l'; v->tx[4] = 'o';
    v->tx[5] = ' ';
    v->tx[6] = 'W'; v->tx[7] = 'o'; v->tx[8] = 'r'; v->tx[9] = 'l'; v->tx[10] = 'd';

    v->tx[11] = '.';
    v->tx[12] = '.';
    v->tx[13] = '.';

    v->tx[14] = '\r';
    v->tx[15] = '\n';
}

void SCI_Send(st_SCI *v){
    uint8_t i = 0;
    for(i = 0; i  < UART_BUFF_SIZE; i++){
        //while (SciaRegs.SCIFFTX.bit.TXFFST != 0){}
        while(!SciaRegs.SCICTL2.bit.TXRDY){
        }
        SciaRegs.SCITXBUF.all = v->tx[i];
    }
    v->transmit_message = 0;
}





