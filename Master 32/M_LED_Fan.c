#include "Master_Interface.h"

u8 LED_tog[] = {"LED Toggled"};
u8 Dim0[]    = {"Brightness"};
u8 Dim1[]    = {"Min          Max"};
u8 Fan0[]    = {"Fan ON"};
u8 Fan1[]    = {"Fan OFF"};

u8 Flag_5seconds = 0;
u16 count = 0;
u8 FanState = Fan_off;

void LED_Toggle()
{
	LCD_Write_Command(lcd_Clear);
	LCD_Set_Col_Row(3,1); LCD_Write_String(LED_tog); //LED Toggled message appears
	SPI_temp = SPI_Transceiver(CodeLedTog);
	_delay_ms(1000);
}

void LED_DAC()
{
	LCD_Write_Command(lcd_Clear);
	LCD_Set_Col_Row(3,1); LCD_Write_String(Dim0); //LED Toggled message appears
	LCD_Set_Col_Row(1,2); LCD_Write_String(Dim1); //shows bar representing the brightness level of the LED

	SPI_temp = SPI_Transceiver(CodeLedDAC);

	//Timer0 starts counting 5 seconds
	Global_Interrupt_vid_Enable();
	Flag_5seconds = 0;
	TIMER0_SetTimerVal(5);

	while(!Flag_5seconds) //This flag is raised once 5 seconds are done counting
	{
		Value = SPI_Transceiver(SPI_temp);
		LCD_ShowBar(Value);
	}
	//This send code directs that the slave must exit this operation and wait for another
	SPI_temp = SPI_Transceiver(Code5seconds);
	Global_Interrupt_vid_Disable();
}

void Fan()
{
	SPI_temp = SPI_Transceiver(CodeFan);
	FanState = (FanState==Fan_on) ? Fan_off : Fan_on ;
	LCD_Write_Command(lcd_Clear); LCD_Set_Col_Row(5,1);

	if (FanState==Fan_on) LCD_Write_String(Fan0);
	else if (FanState==Fan_off) LCD_Write_String(Fan1);

	_delay_ms(1000);
}

void _5_Seconds()
{
	//timer 0 used for counting 5 seconds
	//250x(1/7812.5)x157 = 5.024 seconds

	if(++count == 157)
	{
		Flag_5seconds = 1;
		count = 0;
	}
	else TIMER0_SetTimerVal(5);
}
