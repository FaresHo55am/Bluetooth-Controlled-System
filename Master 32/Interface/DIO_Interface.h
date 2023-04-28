#include "../STD_types.h"
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

#define INPUT 		0
#define OUTPUT_PIN 	1
#define OUTPUT_PORT 0xff

#define HIGH_PORT 0xff
#define HIGH_PIN 1
#define LOW  0
#define TOGGLE  2

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7


void DIO_SetPortDir(u8, u8);
void DIO_SetPortValue(u8, u8);
u8 DIO_ReadPort(u8);
void DIO_SetPinDir(u8, u8, u8);
void DIO_SetPinValue(u8, u8, u8);
u8 DIO_ReadPin(u8, u8);

#endif /* DIO_INTERFACE_H_ */
