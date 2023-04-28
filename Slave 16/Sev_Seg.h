#ifndef SEV_SEG_H_
#define SEV_SEG_H_

#include "STD_types.h"

//Normal
//#define num0 0b00111111
//#define num1 0b00000110
//#define num2 0b01011011
//#define num3 0b01001111
//#define num4 0b01100110
//#define num5 0b01101101
//#define num6 0b01111101
//#define num7 0b00000111
//#define num8 0b01111111
//#define num9 0b01101111

//Flipped
#define num0 0b01111110
#define num1 0b00110000
#define num2 0b01101101
#define num3 0b01111001
#define num4 0b00110011
#define num5 0b01011011
#define num6 0b01011111
#define num7 0b01110000
#define num8 0b01111111
#define num9 0b01111011

u8 N[10]={num0,num1,num2,num3,num4,num5,num6,num7,num8,num9};

#endif /* SEV_SEG_H_ */
