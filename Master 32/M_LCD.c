#include "Master_Interface.h"

u8 Body0[] = {"No Visitor"}; //3
u8 Body1[] = {"Visitor Detected"}; //0
u8 Welcome[] = {"Welcome!"}; //4
u8 Pass0[] = {"Enter Password"};
u8 Pass1[] = {"Correct Password"};
u8 Pass2[] = {"Wrong Password"};
u8 Pass3[] = {"Access Granted"};
u8 Pass4[] = {"Intruder Alert"};

u8 Options_word1[] = {"TogLED~1 Dim~2"};
u8 Options_word2[] = {"Fan~3 SetClk~4"};


u8 CorrectPassword;

void LCD_Welcome()
{
	LCD_Write_Command(lcd_Clear);
	// Text on the LCD to indicate no body approached the door
	LCD_Set_Col_Row(3,1); LCD_Write_String(Body0);
	while(IR_Read());

	//Body is detected
	LCD_Write_Command(lcd_Clear);
	LCD_Set_Col_Row(1,1); LCD_Write_String(Body1); _delay_ms(1000);

	//Welcome text
	LCD_Write_Command(lcd_Clear);
	LCD_Set_Col_Row(4,1); LCD_Write_String(Welcome);_delay_ms(2500);
	LCD_Write_Command(lcd_Clear);
}

u8 LCD_Pass()
{
	LCD_Write_Command(lcd_Clear);
	LCD_Set_Col_Row(1,1); LCD_Write_String(Pass0);
	u32 Key_Pressed = -1;
	u8 Col=2;
	u8 incorrect=0;
	u32 i=1000;
	u32 Entered_Pass = 0;
	u8 digits = 15;

	while(digits--)
	{
		while(KEY_Read()==0xff); //Not pressed == 0xFF, Enter == 0x0A
		Key_Pressed=KEY_Read();
		while(!(KEY_Read()==0xff));

		if(Key_Pressed==0x0A)
		{
			digits=15;
			if(Entered_Pass == 1234) //Correct pass
			{
				LCD_True();
				return 1;
			}
			else if(Entered_Pass != 1234) //Wrong password
			{
				if(incorrect == 2)
				{
					LCD_Wait5seconds();
					return 0;
				}
				else
				{
					incorrect++;		 //An incorrect password counter
					LCD_False();
					Entered_Pass = 0;
					Col=2;
					i=1000;
				}
			}
			LCD_Write_Command(lcd_Clear);
			LCD_Set_Col_Row(1,1); LCD_Write_String(Pass0);
		}
		else
		{
			LCD_Set_Col_Row(Col,2); LCD_Write_Char('*'); Col++; //When a number is entered, * appears
			Entered_Pass += Key_Pressed * i;
			i/=10;
		}
	}
	return 0;
}

void LCD_True()
{
	LCD_Write_Command(lcd_Clear);
	LCD_Set_Col_Row(1,1); LCD_Write_String(Pass1);
	_delay_ms(500); //Correct pass message appears on LCD

	LCD_Write_Command(lcd_Clear);
	LCD_Set_Col_Row(1,1); LCD_Write_String(Pass3);
	_delay_ms(500); //Access Granted message appears on LCD

	Servo_Init(); //Servo motor is controlled by Timer1A fast PWM mode
	Door_Open();  //Servo controlling door to rotate by 90 degrees
	Door_Close(); //returning to its closed door angle
}

void LCD_False()
{
	_delay_ms(50);
	LCD_Write_Command(lcd_Clear);
	LCD_Set_Col_Row(1,1); LCD_Write_String(Pass2); //Wrong password message on the LCD
	_delay_ms(2000);
	LCD_Write_Command(lcd_Clear);
}

void LCD_Wait5seconds()
{
	// Wrong 3 times on LCD, user -if there is- waits 5 seconds while an alert buzzer goes off

	LCD_Write_Command(lcd_Clear);
	_delay_ms(500);
	LCD_Set_Col_Row(2,1); LCD_Write_String(Pass4);
	for(u8 i=0; i<50; i++)
	{
		Buzzer_TOG();
		_delay_ms(100);
	}
}

void LCD_Options()
{
	//Display Task options
	LCD_Write_Command(lcd_Clear);
	LCD_Set_Col_Row(1,1); LCD_Write_String(Options_word1);
	LCD_Set_Col_Row(1,2); LCD_Write_String(Options_word2);
}

void LCD_ShowBar(u8 Value)
{
	if(Value==155)	    LCD_Write_Extra_Char(8,5,2);
	else if(Value>135)  LCD_Write_Extra_Char(7,5,2);
	else if(Value>115)  LCD_Write_Extra_Char(6,5,2);
	else if(Value>95)   LCD_Write_Extra_Char(5,5,2);
	else if(Value>75)   LCD_Write_Extra_Char(4,5,2);
	else if(Value>55)   LCD_Write_Extra_Char(3,5,2);
	else if(Value>35)   LCD_Write_Extra_Char(2,5,2);
	else if(Value>15)   LCD_Write_Extra_Char(1,5,2);
	else {LCD_Set_Col_Row(5,2); LCD_Write_String(" ");}
}

void LCD_StartClock()
{
	_delay_ms(500);
	LCD_Write_Command(lcd_Clear);
	LCD_Set_Col_Row(4,1); LCD_Write_String("Clock Will");
	LCD_Set_Col_Row(1,2); LCD_Write_String("Start Now");
	_delay_ms(1500);
}
