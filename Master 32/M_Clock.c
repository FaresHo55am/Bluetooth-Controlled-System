#include "Master_Interface.h"

u8 CLK0[] = {"Clock Hr:Min:Sec"};

void Clock()
{
	SPI_temp = SPI_Transceiver(CodeClk); //to indicate a clock is to be set by user
	LCD_Write_Command(lcd_Clear);
	LCD_Set_Col_Row(1,1); LCD_Write_String(CLK0);

	u8 BT_Recieved;
	u8 Loop=0;
	u8 x=0;

	while(Loop<6)
	{
		//6 numbers are received (from hours value to seconds value)
		BT_Recieved = UART_ReceiveChar()-'0';
		while(!Clk_Valid(BT_Recieved)) BT_Recieved = UART_ReceiveChar()-'0';

		//Since the clock is operating from the slave, the values of clock number is sent through
		SPI_temp = SPI_Transceiver(BT_Recieved);
		LCD_Set_Col_Row(7+x+Loop,2); LCD_Write_Char(BT_Recieved + '0');
		if(Loop==1)
		{
			LCD_Set_Col_Row(9,2);
			LCD_Write_Char(':');
			x++;
		}
		else if (Loop==3)
		{
			LCD_Set_Col_Row(12,2);
			LCD_Write_Char(':');
			x++;
		}
		Loop++;
	}
	LCD_StartClock();
}

u8 Clk_Valid(u8 x) {return(x>=0 && x<=9);} //Check validity of clock numbers
