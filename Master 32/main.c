#include "Master_Interface.h"

int main()
{
	SPI_Init_Master(); // initializing Atmega32 as a master

	LCD_Init();
	IR_Init();		  //IR Sensor
	KEY_Init();		  //Keypad for password
	Buzzer_Init();	  //Buzzer for alerting if an intruder tries entering
	UART_Init();	  //This is to receive bluetooth signals via UART protocol

	TIMER0_OVF_Init();//Timer0 Normal mode is used for counting 5 seconds to give the user time to adjust the brightness
	TIMER0_OVF_SetCallback(_5_Seconds);

	u8 CorrectEntry = 0; //Variable to indicate the correct door password is correct (Pass: 1234)

	while(1)
	{
		//if the user has approached but failed to write the password correctly 3 times, the IR sensor resets
		while(!CorrectEntry)
		{
			LCD_Welcome();
			CorrectEntry = LCD_Pass();
		}

		LCD_Options(); //Display Task options
		BT_Recieved = UART_ReceiveChar() - '0'; //The received code is in character type so '0' is subtracted giving a number
		while(!BT_Valid(BT_Recieved)) BT_Recieved = UART_ReceiveChar() - '0';

		switch(BT_Recieved) //Switch case used for the option picked by the user
		{
		case BT_ledtoggle: LED_Toggle(); break;
		case BT_ledDAC:    LED_DAC();    break;
		case BT_Fan:       Fan();        break;
		case BT_Clk:       Clock();      break;
		}
	}
	return 0;
}
u8 BT_Valid(u8 Op) {return (Op>=1 && Op<=4);} //Validity check of the BT received code






