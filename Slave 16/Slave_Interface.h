#ifndef SLAVE_INTERFACE_H_
#define SLAVE_INTERFACE_H_

#include "All.h"

#define BT_ledtoggle  1
#define BT_ledDAC	  2
#define BT_Fan		  3
#define BT_Clk		  4

#define CodeLedTog    5
#define CodeLedDAC    6
#define CodeFan       7
#define CodeClk       8

#define Code5seconds  9

void LED_Init();
void Fan_Init();
void _7Seg_Init();

void LED_Toggle();
void LED_DAC();
void Fan_Toggle();

void CLK_Setclk();
void CLK_Valid();
void CLK_1second();
void CLK_AlwaysOn();
void CLK_StartfromZero();
void CLK_5seconds();
void OVF_Handler();

u8 clkRequestFlag;
u8 SPI_temp;
u8 CLK[6];

#endif /* SLAVE_INTERFACE_H_ */
