#include "../Interface/UART_Interface.h"
#include "../BIT_MATH.h"
#include "../STD_types.h"
#include "../Interface/DIO_Interface.h"

void UART_Init()
{
	DIO_SetPinDir(PORTD,PIN0,INPUT);
	DIO_SetPinDir(PORTD,PIN1,OUTPUT_PIN);

	SET_BIT(UCSRB_reg,3);
	SET_BIT(UCSRB_reg,4); //enables TX & RX
	CLR_BIT(UCSRB_reg,2); //for 8 bits

	UCSRC_reg = 0b10000110; //parity = none / 8 Data Line (DL) / Asynch / 1 stop
	UBRRL_reg = 51; //9600 bps
}

void UART_SendChar(u8 Character)
{
//	DIO_SetPinValue(PORTD,PIN2,HIGH_PIN);
	while(!GET_BIT(UCSRA_reg,6));
	UDR_reg = Character;
//	DIO_SetPinValue(PORTD,PIN2,LOW);
}
u8 UART_ReceiveChar()
{
	while(!GET_BIT(UCSRA_reg,7));
	return UDR_reg;
}
//void UART_SendString(u8 *String)
//{
//	u8 size=0, index=0;
//	while(*(String+index++) != '\0') size++;
//	u8 iteration;
//	for(iteration = 0; iteration<size; iteration++)
//	{
//		UART_SendChar(String[iteration]);
//	}
//}
//u16 UART_ReceiveString(u8 Size)
//{
//	u8 i;
//	for(i=0;i<size;i++)
//	UART_ReceiveChar();
//}
