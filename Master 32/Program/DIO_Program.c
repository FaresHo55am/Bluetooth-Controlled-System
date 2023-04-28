#include "../BIT_MATH.h"
#include "../Interface/DIO_Interface.h"
#include "../Register/DIO_Register.h"
#include "../STD_types.h"

//first 6 functions don't involve pull up or down

/*_____PORT_____*/

//Determine if DDRA->D is input or output (Whole Register)
void DIO_SetPortDir(u8 u8_PortID_Copy, u8 u8_PortDir_Copy)
{
	switch(u8_PortID_Copy)
	{
		case PORTA: DDRA_reg = u8_PortDir_Copy; break;
		case PORTB: DDRB_reg = u8_PortDir_Copy; break;
		case PORTC: DDRC_reg = u8_PortDir_Copy; break;
		case PORTD: DDRD_reg = u8_PortDir_Copy; break;
		default: break;
	}
}

//Picking if LOW/HIGH (WHOLE Register)
void DIO_SetPortValue(u8 u8_PortID_Copy, u8 u8_Value_Copy)
{
	switch(u8_PortID_Copy)
	{
		case PORTA: PORTA_reg = u8_Value_Copy;  break;
		case PORTB: PORTB_reg = u8_Value_Copy; break;
		case PORTC: PORTC_reg = u8_Value_Copy; break;
		case PORTD: PORTD_reg = u8_Value_Copy; break;
		default: break;
	}
}

//Reading The PIN value (i.e., is it high or low? changes with changing switch position)
u8 DIO_ReadPort(u8 u8_PortID_Copy)
{
	switch(u8_PortID_Copy)
	{
		case PORTA: return PINA_reg;
		case PORTB: return PINB_reg;
		case PORTC: return PINC_reg;
		case PORTD: return PIND_reg;
		default: return 0xff; break;
	}
}


/*_____PIN_____*/

//Picking a specific Bit to be output or input (One bit of the register)
void DIO_SetPinDir(u8 u8_PortID_Copy, u8 u8_PinID_Copy, u8 u8_PortDir_Copy)
{
	if(u8_PortDir_Copy == OUTPUT_PIN)
	{
		switch(u8_PortID_Copy)
		{
			case PORTA: SET_BIT(DDRA_reg, u8_PinID_Copy); break;
			case PORTB: SET_BIT(DDRB_reg, u8_PinID_Copy); break;
			case PORTC: SET_BIT(DDRC_reg, u8_PinID_Copy); break;
			case PORTD: SET_BIT(DDRD_reg, u8_PinID_Copy); break;
			default: break;
		}
	}
	else if(u8_PortDir_Copy == INPUT)
	{
		switch(u8_PortID_Copy)
		{
			case PORTA: CLR_BIT(DDRA_reg, u8_PinID_Copy); break;
			case PORTB: CLR_BIT(DDRB_reg, u8_PinID_Copy); break;
			case PORTC: CLR_BIT(DDRC_reg, u8_PinID_Copy); break;
			case PORTD: CLR_BIT(DDRD_reg, u8_PinID_Copy); break;
			default: break;
		}
	}
}

//Picking if LOW/HIGH on a specific PIN
void DIO_SetPinValue(u8 u8_PortID_Copy, u8 u8_PinID_Copy, u8 u8_Value_Copy)
{
	if(u8_Value_Copy == HIGH_PIN)
	{
		switch(u8_PortID_Copy)
		{
			case PORTA: SET_BIT(PORTA_reg, u8_PinID_Copy); break;
			case PORTB: SET_BIT(PORTB_reg, u8_PinID_Copy); break;
			case PORTC: SET_BIT(PORTC_reg, u8_PinID_Copy); break;
			case PORTD: SET_BIT(PORTD_reg, u8_PinID_Copy); break;
			default: break;
		}
	}
	else if(u8_Value_Copy == LOW)
	{
		switch(u8_PortID_Copy)
		{
			case PORTA: CLR_BIT(PORTA_reg, u8_PinID_Copy); break;
			case PORTB: CLR_BIT(PORTB_reg, u8_PinID_Copy); break;
			case PORTC: CLR_BIT(PORTC_reg, u8_PinID_Copy); break;
			case PORTD: CLR_BIT(PORTD_reg, u8_PinID_Copy); break;
			default: break;
		}
	}
	else if(u8_Value_Copy == TOGGLE)
	{
		switch(u8_PortID_Copy)
		{
			case PORTA: TOG_BIT(PORTA_reg, u8_PinID_Copy); break;
			case PORTB: TOG_BIT(PORTB_reg, u8_PinID_Copy); break;
			case PORTC: TOG_BIT(PORTC_reg, u8_PinID_Copy); break;
			case PORTD: TOG_BIT(PORTD_reg, u8_PinID_Copy); break;
			default: break;
		}
	}
}

//Reading a specific PIN of a PORT (input)
u8 DIO_ReadPin(u8 u8_PortID_Copy, u8 u8_PinID_Copy)
{
	u8 u8_PinVal;
	switch (u8_PortID_Copy)
	{
		case PORTA: u8_PinVal = GET_BIT(PINA_reg,u8_PinID_Copy); break;
		case PORTB: u8_PinVal = GET_BIT(PINB_reg,u8_PinID_Copy); break;
		case PORTC: u8_PinVal = GET_BIT(PINC_reg,u8_PinID_Copy); break;
		case PORTD: u8_PinVal = GET_BIT(PIND_reg,u8_PinID_Copy); break;
		default: u8_PinVal = 0xff; break;
	}
	return u8_PinVal;
}
