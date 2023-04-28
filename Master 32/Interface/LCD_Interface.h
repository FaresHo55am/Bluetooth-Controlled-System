/*
 * LCD_Interface.h
 *
 *  Created on: Sep 3, 2022
 *      Author: Dell
 */
#include "DIO_Interface.h"
#include "../STD_types.h"

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define lcd_Clear					 0x01
#define lcd_Home					 0x02
#define lcd_EntryMode    		     0x06
#define lcd_DisplayOFF				 0x08
#define lcd_DisplayOn 	  			 0x0c
#define lcd_FunctionReset 			 0x30
#define lcd_FunctionSet8bit_5x7Dots  0x38
#define lcd_SetCursor      			 0x80

/*new*/
#define lcd_ShiftDsiplay     	     0x1c
#define lcd_RightShift       		 0x1C
#define lcd_LeftShift       		 0x18
#define lcd_FunctionSet8bit_5x10Dots 0x3C
#define lcd_ShiftDsiplay     	     0x1c


#define lcd_DataPORT PORTC
#define lcd_ControlPORT PORTD
#define lcd_RSPIN PIN4
#define lcd_RWPIN PIN3
#define lcd_EPIN  PIN2

void LCD_Init();
void LCD_Write_Command(u8);
void LCD_Write_Char(u8);
void LCD_Set_Col_Row(u8,u8);
void LCD_Write_String(u8*);
void LCD_Write_Extra_Char(u8,u8,u8);
/*new*/


#endif /* LCD_INTERFACE_H_ */
