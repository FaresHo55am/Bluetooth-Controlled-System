
#ifndef INTERFACE_TIMER_INTERFACE_H_
#define INTERFACE_TIMER_INTERFACE_H_

#include "../BIT_MATH.h"
#include "DIO_Interface.h"
#include "../Register/Timer_Register.h"
#include "../STD_types.h"

//callback is a function pointer with size void "Soon the size would be size of the function"
void TIMER0_OVF_SetCallback  (void *CallBack_ptr());
void TIMER0_CTC_SetCallback  (void *CallBack_ptr());
void TIMER1_OVF_SetCallback  (void *CallBack_ptr());
void TIMER1A_CTC_SetCallback (void *CallBack_ptr());
void TIMER1B_CTC_SetCallback (void *CallBack_ptr());
void TIMER1_ICU_SetCallback  (void *CallBack_ptr());

// Timer 0
void TIMER0_SetTimerVal(u8 u8_CopyTimerValue);
u8 TIMER0_GetTimerVal(void);

// Timer 0 Normal/OVF Mode
void TIMER0_OVF_Init();
void TIMER1_OVF_Init();
void TIMER0_PWM_Init(u8 u8_DutyCycle_percent);


// Timer 0 CTC Mode
void TIMER0_CTC_SetCompareVal(u8 Copy_u8Value);

void TIMER1_SetTimerVal(u16);

//Interrupt vectors that call the callback pointer to function



/*
AMIN

void TIM1_voidEnableCTCAINT(void);
void TIM1_voidDisableCTCAINT(void);
void TIM1_voidEnableCTCBINT(void);
void TIM1_voidDisableCTCBINT(void);
void TIM1_voidEnableICUINT(void);
void TIM1_voidDisableICUINT(void);

void TIM0_voidSetCTCCallback( void (*callback_Copy_ptr) (void) );
void TIM1_voidInitialize(void);
void TIM1_voidSetTimerReg(u16 Copy_u16Value);
void TIM1_voidSetCompareVal(u16 Copy_u16Value);
void TIM1_voidEnableOVINT(void);
void TIM1_voidDisableOVINT(void);
void TIM1_voidEnableCTCINT(void);
void TIM1_voidDisableCTCINT(void);
u16 TIM1_u16GETCounter(void);
u16 TIM1_u16GETICUValue(void);
void TIM1_voidSetICUEdge(u16 Copy_u8edge);
void TIM1_voidSetOVCallback( void (*callback_Copy_ptr) (void) );
void TIM1_voidSetCTCACallback( void (*callback_Copy_ptr) (void) );
void TIM1_voidSetCTCBCallback( void (*callback_Copy_ptr) (void) );
void TIM1_voidSetICUCallback( void (*callback_Copy_ptr) (void) );
 */

#endif /* INTERFACE_TIMER_INTERFACE_H_ */
