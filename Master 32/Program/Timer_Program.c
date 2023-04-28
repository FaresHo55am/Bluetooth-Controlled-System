#include "../BIT_MATH.h"
#include "../Interface/DIO_Interface.h"
#include "../Interface/Global_Interrupt_Interface.h"
#include "../Interface/Timer_Interface.h"
#include "../Register/Timer_Register.h"
#include "../STD_types.h"

void (*TIMER0_OVF_callback) () = NULL;
void (*TIMER0_CTC_callback) () = NULL;
void (*TIMER1_OVF_callback) (void) = NULL;
//void (*TIMER1A_CTC_callback)(void) = NULL;
//void (*TIMER1B_CTC_callback)(void) = NULL;
//void (*TIMER1_ICU_callback) (void) = NULL;

void TIMER0_OVF_Init()
{
	TIMSK_reg = 0x00; //if it was in any other mode
	//from prescalar 010 -> clkIO/8
	//from prescalar 101 -> clkIO/1024
	SET_BIT(TCCR0_reg,0);
	CLR_BIT(TCCR0_reg,1);
	SET_BIT(TCCR0_reg,2);

	//OVF Mode "Normal Mode"
	CLR_BIT(TCCR0_reg,3);
	CLR_BIT(TCCR0_reg,6);

	//enable OVF Interrupt
	SET_BIT(TIMSK_reg,0);
}

void TIMER0_CTC_Init()
{
	TIMSK_reg = 0x00; //if it was in any other mode
	//from prescalar 010 -> clkIO/8
	CLR_BIT(TCCR0_reg,0);
	SET_BIT(TCCR0_reg,1);
	CLR_BIT(TCCR0_reg,2);

	//CTC Mode "Compare Mode"
	SET_BIT(TCCR0_reg,3);
	CLR_BIT(TCCR0_reg,6);

	//Toggle on compare match i.e., when the max is reached the ocr0 signal toggles
	CLR_BIT(TCCR0_reg,5);
	SET_BIT(TCCR0_reg,4);

	//enable CTC Interrupt
	SET_BIT(TIMSK_reg,1);
}

void TIMER0_PWM_Init(u8 u8_DutyCycle_percent)
{
	TIMSK_reg = 0x00; //if it was in any other mode

	//from prescalar 010 -> clkIO/8
	CLR_BIT(TCCR0_reg,0);
	SET_BIT(TCCR0_reg,1);
	CLR_BIT(TCCR0_reg,2);

	//PWM Mode
	SET_BIT(TCCR0_reg,3);
	SET_BIT(TCCR0_reg,6);

	//clear on compare match, High before compare (1111*OCR_Value*000000*OVF*1111...)
	SET_BIT(TCCR0_reg,5);
	CLR_BIT(TCCR0_reg,4);

	//Setting Duty Cycle
	OCR0_reg = (u8_DutyCycle_percent * 256) / 100;
}

void TIMER0_SetTimerVal(u8 u8_CopyTimerValue)
{
	TCNT0_reg = u8_CopyTimerValue;
}
void TIMER1_SetTimerVal(u16 u16_CopyTimerValue)
{
	TCNT1_reg = u16_CopyTimerValue;
}

//u8 TIMER0_GetTimerVal(void)
//{
//	return TCNT0_reg;
//}

//void TIMER0_CTC_SetCompareVal(u8 Copy_u8Value)
//{
//	OCR0_reg = Copy_u8Value;
//}

void TIMER1_OVF_Init()
{
	//from prescalar 010 -> clkIO/8
	CLR_BIT(TCCR1B_reg,0);
	SET_BIT(TCCR1B_reg,1);
	CLR_BIT(TCCR1B_reg,2);

	//OVF Mode "Normal Mode"
	CLR_BIT(TCCR1A_reg,1);
	CLR_BIT(TCCR1A_reg,0);
	CLR_BIT(TCCR1B_reg,3);
	CLR_BIT(TCCR1B_reg,4);

	//enable OVF Interrupt
	SET_BIT(TIMSK_reg,2);
}

void TIMER0_OVF_SetCallback  (void (*CallBack_ptr()))
{
	TIMER0_OVF_callback = CallBack_ptr;
}
void TIMER1_OVF_SetCallback  (void (*CallBack_ptr()))
{
	TIMER1_OVF_callback = CallBack_ptr;
}
//void TIMER0_CTC_SetCallback  (void *CallBack_ptr())
//{
//	TIMER0_CTC_callback = CallBack_ptr;
//}

//void __vector_6 (void) __attribute__ ((signal,used, externally_visible)) ;
//void __vector_6 (void)
//{
//	TIMER1_ICU_callback();
//}
//void __vector_7 (void) __attribute__ ((signal,used, externally_visible)) ;
//void __vector_7 (void)
//{
//	TIMER1A_CTC_callback();
//}
//void __vector_8 (void) __attribute__ ((signal,used, externally_visible)) ;
//void __vector_8 (void)
//{
//	TIMER1B_CTC_callback();
//}
void __vector_9 (void) __attribute__ ((signal,used, externally_visible)) ;
void __vector_9 (void)
{
	TIMER1_OVF_callback();
}

void __vector_10 (void) __attribute__ ((signal,used, externally_visible)) ;
void __vector_10 (void)
{
	TIMER0_CTC_callback();
}
void __vector_11 (void) __attribute__ ((signal,used, externally_visible)) ;
void __vector_11 (void)
{
	TIMER0_OVF_callback();
}
