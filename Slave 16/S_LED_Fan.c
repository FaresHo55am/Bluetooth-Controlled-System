#include "Slave_Interface.h"

u8 Pot_Val = 0;

void LED_Init()
{
	//PORTC is connected to R2R DAC circuit, also ADC channel7 will be used via potentiometer to control the brightness
	DIO_SetPortDir(PORTC,OUTPUT_PORT);
	DIO_SetPortValue(PORTC,LOW);
	ADC_Init();
	DIO_SetPinDir(PORTA,PIN7,INPUT);
}

void Fan_Init()
{
	DIO_SetPinDir(PORTB,PIN1,OUTPUT_PIN);
	DIO_SetPinValue(PORTB,PIN1,LOW);
}

void LED_Toggle()
{
	//if the brightness is relatively low compared to detectable brightness (140), the LED turns of (PORTC = 0xFF)
	//otherwise it switches to 0x00
	if(DIO_ReadPort(PORTC) < 140)
	{
		DIO_SetPortValue(PORTC,HIGH_PORT);
	}
	else DIO_SetPortValue(PORTC,LOW);
}

void LED_DAC()
{
	//since the ADC Channel7 is used while the ground pins for the 7 segments are used, some errors occur
	//so the clock is paused, Timer0 of master starts counting 5 seconds
	//the value of brightness is sent via SPI until the 5 second flag is raised from master
	//once 5 second flag is received, the clock resumes but added 5 seconds to it

	TIMER0_SetTimerVal(0);
	Global_Interrupt_vid_Disable();
	Pot_Val = 0;
	while(SPI_Transceiver(Pot_Val) != Code5seconds)
	{
		Pot_Val = ADC_MAP(ADC_Read(Channel_A7),1023,155);
		DIO_SetPortValue(PORTC,100+Pot_Val); //for smooth brightness change, the brightness starts at 100 which is around 2v
	}
	if(clkRequestFlag)
	{
		u8 seconds = 5;
		while(seconds--) CLK_1second();
		Global_Interrupt_vid_Enable();
		TIMER0_SetTimerVal(255);
	}
}

void Fan_Toggle()
{
	DIO_SetPinValue(PORTB,PIN1,TOGGLE);
}
