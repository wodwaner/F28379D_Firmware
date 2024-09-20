/*
 * Peripheral_Setup.h
 *
 *  Created on: 23 de jul de 2020
 *      Author: waner
 */

#ifndef PERIPHERAL_SETUP_H_
#define PERIPHERAL_SETUP_H_
#include "F28x_Project.h"
//Configures which trigger will start a burst conversion sequence.
#define TRIG_SEL_SOFT   0x00
#define TRIG_SEL_TIM0   0x01
#define TRIG_SEL_TIM1   0x02
#define TRIG_SEL_TIM2   0x03
#define TRIG_SEL_GPIO   0x04
#define TRIG_SEL_ePWM1_SOCA 0x05
#define TRIG_SEL_ePWM1_SOCB 0x06
#define TRIG_SEL_ePWM2_SOCA 0x07
#define TRIG_SEL_ePWM2_SOCB 0x08
#define TRIG_SEL_ePWM3_SOCA 0x09
#define TRIG_SEL_ePWM3_SOCB 0x0A
#define TRIG_SEL_ePWM4_SOCA 0x0B
#define TRIG_SEL_ePWM4_SOCB 0x0C
#define TRIG_SEL_ePWM5_SOCA 0x0D
#define TRIG_SEL_ePWM5_SOCB 0x0E
#define TRIG_SEL_ePWM6_SOCA 0x0F
#define TRIG_SEL_ePWM6_SOCB 0x10
#define TRIG_SEL_ePWM7_SOCA 0x11
#define TRIG_SEL_ePWM7_SOCB 0x12
#define TRIG_SEL_ePWM8_SOCA 0x13
#define TRIG_SEL_ePWM8_SOCB 0x14
#define TRIG_SEL_ePWM9_SOCA 0x15
#define TRIG_SEL_ePWM9_SOCB 0x16
#define TRIG_SEL_ePWM10_SOCA    0x17
#define TRIG_SEL_ePWM10_SOCB    0x18
#define TRIG_SEL_ePWM11_SOCA    0x19
#define TRIG_SEL_ePWM11_SOCB    0x1A
#define TRIG_SEL_ePWM12_SOCA    0x1B
#define TRIG_SEL_ePWM12_SOCB    0x1C

void Setup_GPIO(void);
void Setup_SCI_A(void);

#define CPU_FREQ        200E6
#define LSPCLK_FREQ     CPU_FREQ/4
#define SCI_FREQ        115200
#define SCI_PRD         (LSPCLK_FREQ/(SCI_FREQ*8))-1
#define UART_BUFF_SIZE    16

#ifndef _UINT8_T_DECLARED
typedef unsigned char uint8_t;
#define _UINT8_T_DECLARED
#endif

#define PWM_PERIOD LSPCLK_FREQ/10000

#endif /* PERIPHERAL_SETUP_H_ */
