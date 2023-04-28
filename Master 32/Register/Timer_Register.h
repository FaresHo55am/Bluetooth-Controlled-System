
#ifndef REGISTER_TIMER_REGISTER_H_
#define REGISTER_TIMER_REGISTER_H_

#include "../Interface/DIO_Interface.h"
#include "../Interface/Timer_Interface.h"
#include "../BIT_MATH.h"
#include "../STD_types.h"

#define TCNT0_reg 	*((volatile u8*)(0x52))
#define OCR0_reg 	*((volatile u8*)(0x5C))
#define TCCR0_reg 	*((volatile u8*)(0x53))
#define TIFR_reg 	*((volatile u8*)(0x58))
#define TIMSK_reg 	*((volatile u8*)(0x59))


#define TCCR1A_reg 	*((volatile u8*)(0x4F))
#define TCCR1B_reg 	*((volatile u8*)(0x4E))
#define TCNT1_reg 	*((volatile u16*)(0x4C))
#define OCR1A_reg 	*((volatile u16*)(0x4A))
#define OCR1B_reg 	*((volatile u16*)(0x48))
#define ICR1_reg 	*((volatile u16*)(0x46))

#endif /* REGISTER_TIMER_REGISTER_H_ */
