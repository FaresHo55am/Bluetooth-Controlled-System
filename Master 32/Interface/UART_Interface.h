/*
 * UART_Interface.h
 *
 *  Created on: Oct 14, 2022
 *      Author: Dell
 */

#ifndef INTERFACE_UART_INTERFACE_H_
#define INTERFACE_UART_INTERFACE_H_

#include "../Register/UART_Register.h"
#include "../STD_types.h"

/*
 * Notes for building driver
 * NVM that -> for tx udr_reg = 0x05
 * UDR
 * UCSRA
 * UCSRB
 * UCSRC
 * msb of address 0x40 1 -> UCSRC 0 -> UBRRH so we use register value as a whole not bit math
 * UBRRH, UBRRL baud rate regitser
 *
 * init : 1 stop / no parity / 8 data / Asynch. / 9600 bps / no interrupts
 * send char(u8 char) , u8 receive char()
 */
void UART_Init();
void UART_SendChar(u8 Character);
u8 UART_ReceiveChar();
void UART_SendString(u8 *String);
u16 UART_ReceiveString(u8 Size);
#endif /* INTERFACE_UART_INTERFACE_H_ */
