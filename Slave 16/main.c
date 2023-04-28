#include "Slave_Interface.h"

int main()
{
	SPI_Init_Slave(); // initializing Atmega16 as a slave

	LED_Init();
	Fan_Init();
	_7Seg_Init();

	TIMER0_OVF_Init();
	TIMER0_OVF_SetCallback(OVF_Handler);

	u8 CodeRecieved;
	clkRequestFlag = 0;

	while(1)
	{
		CodeRecieved = SPI_Transceiver(SPI_temp);
		switch (CodeRecieved)
		{
			case CodeLedTog: LED_Toggle(); break;
			case CodeLedDAC: LED_DAC()	 ; break;
			case CodeFan:    Fan_Toggle(); break;
			case CodeClk:    CLK_Setclk(); break;
		}
	}
	return 0;
}
