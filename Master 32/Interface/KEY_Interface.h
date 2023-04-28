
#ifndef INTERFACE_KEY_INTERFACE_H_
#define INTERFACE_KEY_INTERFACE_H_

#include "../Interface/DIO_Interface.h"
#include "../STD_types.h"

#define Key_Port	   PORTA
#define Key_Port_Dir   0x0f

#define NOT_PRESSED    0xff
//						   0123					4567
#define Key_COL_Start  0 //C1 -> C4 output  ~~  R1 -> R4 input
#define Key_COL_End    4

#define Key_ROW_Start  4
#define Key_ROW_End    8

void KEY_Init();
u8 KEY_Read();

#endif /* INTERFACE_KEY_INTERFACE_H_ */
