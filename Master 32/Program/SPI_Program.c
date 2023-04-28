#include "../BIT_MATH.h"
#include "../STD_types.h"
#include "../Interface/SPI_Interface.h"
#include "../Interface/DIO_Interface.h"

void SPI_Init_Master()
{
	DIO_SetPinDir(PORTB,PIN4,OUTPUT_PIN); //ss
	DIO_SetPinValue(PORTB,PIN4,HIGH_PIN);
	DIO_SetPinDir(PORTB,PIN5,OUTPUT_PIN); //mosi
	DIO_SetPinDir(PORTB,PIN6,INPUT); //miso
	DIO_SetPinDir(PORTB,PIN7,OUTPUT_PIN); //sck

	//SPI_CLK = Fosc / 16
	SET_BIT(SPCR_reg,0);
	CLR_BIT(SPCR_reg,1);
	CLR_BIT(SPSR_reg,0);

	SET_BIT(SPCR_reg,4); //master
	SET_BIT(SPCR_reg,6); //SPI enable

//	SET_BIT(SPCR_reg,3); //CPOL idle -> HIGH
//	SET_BIT(SPCR_reg,2); //CPHA Setup -> leading (Falling)
}
void SPI_Init_Slave()
{
	DIO_SetPinDir(PORTB,PIN4,INPUT); //ss
	DIO_SetPinDir(PORTB,PIN5,INPUT); //mosi
	DIO_SetPinDir(PORTB,PIN6,OUTPUT_PIN); //miso
	DIO_SetPinDir(PORTB,PIN7,INPUT); //sck

	//SPI_CLK = Fosc / 16
	SET_BIT(SPCR_reg,0);
	CLR_BIT(SPCR_reg,1);
	CLR_BIT(SPSR_reg,0);

	CLR_BIT(SPCR_reg,4); //Slave

	SET_BIT(SPCR_reg,6); //SPI enable

//	SET_BIT(SPCR_reg,3); //CPOL idle -> HIGH
//	SET_BIT(SPCR_reg,2); //CPHA Setup -> leading (Falling)
}
void SPI_Transmit(u8 data)
{
	SPDR_reg = data;
	while(!GET_BIT(SPSR_reg,7));
}
u8 SPI_Recieve()
{
	while(!GET_BIT(SPSR_reg,7));
	return SPDR_reg;
}
u8 SPI_Transceiver(u8 data)
{
	SPDR_reg = data;
	while(!GET_BIT(SPSR_reg,7));
	//SPSR -> read busy flag -> aka if the flag is low then this means transferring is complete
	return SPDR_reg;
}
