#include "Master_Interface.h"

u8 Door0[] = {"Door Opened"};
u8 Door1[] = {"Door Closed"};

void IR_Init()
{
	DIO_SetPinDir(PORTB,PIN0,INPUT);
}

u8 IR_Read()
{
	return DIO_ReadPin(PORTB,PIN0); //IR sensor low when detection
}

void Servo_Init()
{
	CLR_BIT(TCCR1A_reg,6);SET_BIT(TCCR1A_reg,7);
	SET_BIT(TCCR1A_reg,1);CLR_BIT(TCCR1A_reg,0);
	//Non Inverted Fast PWM

	CLR_BIT(TCCR1B_reg,2);SET_BIT(TCCR1B_reg,4);
	SET_BIT(TCCR1B_reg,3);SET_BIT(TCCR1B_reg,1);
	SET_BIT(TCCR1B_reg,0);
	//Prescaler = 64, Mode 14 (Fast PWM)

	ICR1_reg = 3749; //Setting top counter in ICR1 register to 3749 (8,000,000 / (64*(1+3749)) ~= 33Hz)
	DIO_SetPinDir(PORTD,PIN5,OUTPUT_PIN);
}

void Door_Open()
{
	LCD_Write_Command(lcd_Clear);
	LCD_Set_Col_Row(1,1); LCD_Write_String(Door0);
	OCR1A_reg = 61; //90 degree rotation
	_delay_ms(1500);
}

void Door_Close()
{
	LCD_Write_Command(lcd_Clear);
	LCD_Set_Col_Row(1,1); LCD_Write_String(Door1);
	OCR1A_reg = 148;
	_delay_ms(1500);
	TCCR1A_reg = 0;
	TCCR1B_reg = 0;
}

void Buzzer_Init()
{
	DIO_SetPinDir(PORTB,PIN1,OUTPUT_PIN);
	DIO_SetPinValue(PORTB,PIN1,LOW);
}

void Buzzer_TOG()
{
	DIO_SetPinValue(PORTB,PIN1,TOGGLE);
}
