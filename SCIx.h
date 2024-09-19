/*
 * SCIx.h
 *
 *  Created on: 18 de set de 2024
 *      Author: wodwa
 */

#ifndef SCIX_H_
#define SCIX_H_
#include "Peripheral_Setup.h"


typedef struct{
    uint8_t tx[UART_BUFF_SIZE];
    uint8_t rx[UART_BUFF_SIZE];
    uint8_t new_message;
    uint8_t transmit_message;
    void  (*send)();        // Pointer to calculation function
} st_SCI;
void SCI_Config(st_SCI *v);
void SCI_Send(st_SCI *v);

#endif /* SCIX_H_ */
