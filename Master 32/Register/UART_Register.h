
#ifndef REGISTER_UART_REGISTER_H_
#define REGISTER_UART_REGISTER_H_

#include "../STD_types.h"

#define UCSRA_reg  *((volatile u8*)(0x2B))
#define UCSRB_reg  *((volatile u8*)(0x2A))
#define UBRRL_reg  *((volatile u8*)(0x29))
#define UCSRC_reg  *((volatile u8*)(0x40))
#define UBRRH_reg  *((volatile u8*)(0x40)) //not used often as max = 207 < 255 so only Low byte
#define UDR_reg    *((volatile u8*)(0x2C))

#endif /* REGISTER_UART_REGISTER_H_ */
