
#ifndef MASTER_INTERFACE_H_
#define MASTER_INTERFACE_H_

/*
 * This file contains all the necessary drivers for the master controller (Atmega32)
 */

#include "All.h"

/*
 * The following BT (BlueTooth) codes label which operation the user is requesting
 */
#define BT_ledtoggle  1
#define BT_ledDAC	  2
#define BT_Fan		  3
#define BT_Clk		  4

/*
 * The following SPI codes label the operation that indicates the slave operation that is to be carried out
 */
#define CodeLedTog    5
#define CodeLedDAC    6
#define CodeFan       7
#define CodeClk       8

//5 seconds to adjust the brightness
#define Code5seconds  9

#define Fan_on        10
#define Fan_off       11

u16 Value;
u8 BT_Recieved;
u8 SPI_temp; //dummy variable which is returned after SPI send operation
u8 FanState;

//IR Functions
void IR_Init();
u8 IR_Read();

//Buzzer Functions
void Buzzer_Init();
void Buzzer_TOG();

//Door Functions
void Servo_Init();
void Door_Open();
void Door_Close();

//LCD Functions
void LCD_Welcome();
u8   LCD_Pass();
void LCD_True();
void LCD_False();
void LCD_Options();
void LCD_StartClock();
void LCD_ShowBar(u8);
void LCD_ShowFan();
void LCD_Wait5seconds();

//LED Functions
void LED_Toggle();
void LED_DAC();

//Fan Function
void Fan();

//Clock Functions
void Clock();

u8   Clk_Valid(u8);
u8   BT_Valid(u8);

void _5_Seconds();

#endif /* MASTER_INTERFACE_H_ */
