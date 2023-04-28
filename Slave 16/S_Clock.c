#include "Slave_Interface.h"
#include "Sev_Seg.h"

u16 OVF_count = 0;
u16 Second_Passed = 346; //346~347 Overflows for a complete second to count
u8 clk_Pos;

void _7Seg_Init()
{
	DIO_SetPortDir(PORTD,OUTPUT_PORT); //7seg number
	DIO_SetPortValue(PORTD,LOW);
	for(u8 i=0; i<6; i++)
	{
		DIO_SetPinDir(PORTA,i,OUTPUT_PIN);
		DIO_SetPinValue(PORTA,i,LOW);
	}
}

void CLK_Setclk()
{
	clkRequestFlag = 1;
	//If the user wants to set the clock multiple times, the timer0 interrupt OVF enable bit is disabled temporarily
	Global_Interrupt_vid_Disable();
	//CLK is array that receives the clock time
	for(clk_Pos = 0; clk_Pos < 6; clk_Pos++) CLK[5-clk_Pos] = SPI_Transceiver(SPI_temp);
	CLK_Valid();
	_delay_ms(500);
	Global_Interrupt_vid_Enable();
	TIMER0_SetTimerVal(255);
}

void CLK_Valid()
{
	//if the clock value are double digits or more, the clock starts at 00:00:00
	//if the clock entered by user exceeds the time 23:59:59 the clock resets to 00:00:00
	if(CLK[5]>2 || CLK[4]>9 || CLK[3]>5 || CLK[2]>9 || CLK[1]>5 || CLK[0]>9) CLK_StartfromZero();
	if(CLK[5]>2 && CLK[4]>4) CLK_StartfromZero();
}

void OVF_Handler()
{
	//Overflow always happens, keeping the 7 segments always on
	OVF_count++;
	CLK_AlwaysOn();
	if(OVF_count >= Second_Passed)
	{
		OVF_count = 0;
		CLK_1second(); //the clock second value increments by 1 when the there are 346 overflows that occur
	}
	TIMER0_SetTimerVal(255);
}

void CLK_AlwaysOn()
{
	for(clk_Pos=0; clk_Pos<6; clk_Pos++)
	{
		//PA 0->5 GND
		//PD 0->6 but we can change PD7 as it's NC pin
		DIO_SetPortValue(PORTD,0);
		CLR_BIT(PORTA_reg,clk_Pos);
		DIO_SetPortValue(PORTD,N[CLK[clk_Pos]]);		//Loading the port with the correct number
		_delay_us(1);
		SET_BIT(PORTA_reg,clk_Pos);
	}
	DIO_SetPortValue(PORTD,N[CLK[clk_Pos-1]]);
}

void CLK_1second()
{
	//This function only changes the value displayed on the clock displays
	Second_Passed = (Second_Passed == 346) ? 347 : 346;
	CLK[0]++;
	if(CLK[0] == 10)
	{
		CLK[0] = 0; CLK[1]++;
		if(CLK[1] == 6)
		{
			CLK[1] = 0; CLK[2]++;
			if(CLK[2] == 10)
			{
				CLK[2] = 0; CLK[3]++;
				if(CLK[3] == 6)
				{
					CLK[3] = 0; CLK[4]++;
					if(CLK[5] == 2 && CLK[4] == 4) CLK_StartfromZero();
					else CLK[5]++;
}}}}}

void CLK_StartfromZero()
{
	for(clk_Pos=0;clk_Pos<6;clk_Pos++) CLK[clk_Pos] = 0;
}
