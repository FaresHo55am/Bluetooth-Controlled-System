#include "../STD_types.h"
#include "../BIT_MATH.h"
#include "../Register/Global_Interrupt_Register.h"

void Global_Interrupt_vid_Enable()  {SET_BIT(SREG_reg,7);}
void Global_Interrupt_vid_Disable() {CLR_BIT(SREG_reg,7);}
