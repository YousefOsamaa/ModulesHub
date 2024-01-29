#ifndef TIMER1_INTERFACE
#define TIMER1_INTERFACE

#include "../../LIB/ErrorStates.h"
#include "../../LIB/STD.h"




extern ErrorState_t Timer1_enu_Initialization(void);

extern ErrorState_t Timer1_enu_GetICR1(u16* Copy_u16_ContentOfICR1);

extern ErrorState_t Timer1_enu_SetTCNT1(u16 Copy_u16_WrittenValue);

extern ErrorState_t Timer1_enu_GetTCNT1(u16* Copy_u16_ContentOfTCNT1);


#endif