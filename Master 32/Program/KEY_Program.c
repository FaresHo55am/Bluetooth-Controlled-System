#include "../STD_types.h"
#include "../BIT_MATH.h"
#include "../Interface/DIO_Interface.h"
#include "../Register/DIO_Register.h"
#include "../Interface/KEY_Interface.h"

const u8 Key_Val[4][4] =
		{
		  { //column 1
			0x01, 	//ROW 1
			0x04,	//ROW 2
			0x07,	//ROW 3
			0xFD }, //ROW 4
		  { //column 2
			0x02, 	//ROW 1
			0x05, 	//ROW 2
			0x08, 	//ROW 3
			0x00 }, //ROW 4
		  { //column 3
			0x03,	//ROW 1
			0x06,	//ROW 2
			0x09,	//ROW 3
			0xFE }, //ROW 4
		  { //column 4
			0x0A,	//ROW 1
			0x0A,	//ROW 2
			0x0A,	//ROW 3
			0x0A }  //ROW 4
		};
void KEY_Init()
{
	DIO_SetPortDir(Key_Port,Key_Port_Dir); //C1 -> C4 output  ~~  R1 -> R4 input
	for(u8 i = Key_ROW_Start; i < Key_ROW_End ;i++)
		DIO_SetPinValue(Key_Port,i,HIGH_PIN); // Setting rows to be pull-up (Press => 0)
}
u8 KEY_Read()
{
	u8 u8_LOC_Col, u8_LOC_Row;
	u8 u8_LOC_Return = NOT_PRESSED;
	for(u8_LOC_Col = Key_COL_Start; u8_LOC_Col < Key_COL_End; u8_LOC_Col++)
	{ //setting each column to LOW and checking if any of its rows are also LOW rather than "HIGH_PIN"*
		DIO_SetPinValue(Key_Port,u8_LOC_Col,LOW);
		for(u8_LOC_Row = Key_ROW_Start; u8_LOC_Row < Key_ROW_End; u8_LOC_Row++)
		{
			if(!DIO_ReadPin(Key_Port,u8_LOC_Row))
			{ //here is the row checking i.e., if the row of the picked column is low
				u8_LOC_Return = Key_Val[u8_LOC_Col - Key_COL_Start][u8_LOC_Row - Key_ROW_Start];
			}
		}
		DIO_SetPinValue(Key_Port,u8_LOC_Col,HIGH_PIN); //if col 1 is low -> 1011, we need to return it to high -> 1111
	}
	return u8_LOC_Return;
}
