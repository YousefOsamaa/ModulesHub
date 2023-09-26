#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"

//lower

//my own
#include "EXTI_Config.h"
#include "EXTI_Private.h"

u8 EXTI_u8EXTIPinNum = EXTI_NUM_PINS;

EXTI_t EXTI_astrEXTIConfig [ EXTI_NUM_PINS ]=
    {
        {EXTI_INT0 , EXTI_ANY_CHANGE , EXTI_INTERRUPT_MODE},
        {EXTI_INT1 , EXTI_RISING ,  EXTI_INTERRUPT_MODE},
        {EXTI_INT2 , EXTI_RISING ,  EXTI_INTERRUPT_MODE},
    };
