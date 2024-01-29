#include "../../LIB/ErrorStates.h"
#include "../../LIB/STD.h"


#include "Timer1_Config.h"
#include "Timer1_Private.h"


extern ErrorState_t Timer1_enu_Initialization(void)
{
    u8 Local_u8_ErrorFlag = ES_NOK;
    

    //Waveform Generation Mode and Interrupt Mode Selection
    #if TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_NORMAL

        //Clearing WGM11:0
        TCCR1A &= 0xFC;
        //Clearing WGM13:2
        TCCR1B &= 0xE7;

        //Configuring Overflow interrupt
        #if TIMER1_INTERRUPT_MODE  == TIMER1_ACTIVATE_INT_MODE

            //Setting TOIE1 bit 
            TIFR |= ( 1 << TIFR_TOIE1);

        #elif TIMER1_INTERRUPT_MODE  == TIMER1_ACTIVATE_POLLING_MODE

            //Clearing TOIE1 bit 
            TIFR &= ~( 1 << TIFR_TOIE1);

        #else
            
            #error TIMER1_INTERRUPT_MODE is invalid
        
        #endif



    #else
        
        #error  TIMER1_WAVEFORM_GENERATION_MODE is invalid 

    #endif


    //Input Capture Mode Edge Selection
    #if TIMER1_INPUT_CAPTURE_MODE == TIMER1_ICU_FALLING_EDGE
        
        //Clearing  ICES1 bit
        TCCR1B &= ~(1 << TCCR1B_ICES1);

    #elif   TIMER1_INPUT_CAPTURE_MODE == TIMER1_ICU_RISING_EDGE
        
        //Setting  ICES1 bit
        TCCR1B |= (1 << TCCR1B_ICES1);

    #else
        
        #error TIMER1_INPUT_CAPTURE_MODE is invalid

    #endif


    //Input Capture Mode Interrupt 
    #if TIMER1_INPUT_CAPTURE_INTERRUPT_MODE == TIMER1_DEACTIVATE_ICU_INTERRUPT 

        //Settting TICIE1 bit    
        TIMSK &= ~(1 << TIMSK_TICIE1);

    #elif TIMER1_INPUT_CAPTURE_INTERRUPT_MODE ==  TIMER1_ACTIVATE_ICU_INTERRUPT 

        //Settting TICIE1 bit    
        TIMSK |= (1 << TIMSK_TICIE1);
    
    #else

        #error TIMER1_INPUT_CAPTURE_INTERRUPT_MODE is invalid

    #endif


    //Clock Selection
    TCCR1B &= 0xF8; //Clearing CS12:0 bits
    #if TIMER1_CLOCK_SELECTION == TIMER1_V_GND
        
        //Bits already cleared

    #elif TIMER1_CLOCK_SELECTION ==  TIMER1_PS_1

        //Bits contain 0 0 1
        TCCR1B |= (1 << TCCR1B_CS10);

    #elif TIMER1_CLOCK_SELECTION ==  TIMER1_PS_8

        //Bits contain 0 1 0
        TCCR1B |= (1 << TCCR1B_CS11);
    
    #elif TIMER1_CLOCK_SELECTION ==  TIMER1_PS_64

        //Bits contain 0 1 1
        TCCR1B |= (1 << TCCR1B_CS10);
        TCCR1B |= (1 << TCCR1B_CS11);
    
    #elif TIMER1_CLOCK_SELECTION ==  TIMER1_PS_256
    
        //Bits contain 1 0 0
        TCCR1B |= (1 << TCCR1B_CS12);

    #elif TIMER1_CLOCK_SELECTION ==  TIMER1_PS_1024
    
        //Bits contain 1 0 1
        TCCR1B |= (1 << TCCR1B_CS10);
        TCCR1B |= (1 << TCCR1B_CS12);

    #elif TIMER1_CLOCK_SELECTION ==  TIMER1_FALLING_EGDE

        //Bits contain 1 1 0
        TCCR1B |= (1 << TCCR1B_CS11);
        TCCR1B |= (1 << TCCR1B_CS12);
    
    #elif TIMER1_CLOCK_SELECTION ==  TIMER1_RISING_EGDE

        //Bits contain 1 1 1
        TCCR1B |= (7 << TCCR1B_CS10);

    #else
        
        #error TIMER1_CLOCK_SELECTION is in valid

    #endif

    return Local_u8_ErrorFlag;
}

extern ErrorState_t Timer1_enu_GetICR1(u16* Copy_u16_ContentOfICR1)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    if(Copy_u16_ContentOfICR1)
    {
        //Reading Low Byte
        *Copy_u16_ContentOfICR1= ICR1L;

        //Reading High Byte
        *Copy_u16_ContentOfICR1 |= (u16)ICR1H << ICR1H_B15;
    }
    else
    {
        Local_u8_ErrorFlag = ES_NULL_POINTER;
    }

    return Local_u8_ErrorFlag; 
}

extern ErrorState_t Timer1_enu_SetTCNT1(u16 Copy_u16_WrittenValue)
{
    u8 Local_u8_ErrorFlag = ES_NOK;
    
    //Wriiting High Byte
    TCNT1H = Copy_u16_WrittenValue >> 8;

    //Writing Low Byte
    TCNT1L = Copy_u16_WrittenValue;
    
    return Local_u8_ErrorFlag;
}

extern ErrorState_t Timer1_enu_GetTCNT1(u16* Copy_u16_ContentOfTCNT1)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    if(Copy_u16_ContentOfTCNT1)
    {
        //Reading Low Byte
        *Copy_u16_ContentOfTCNT1 = TCNT1L;

        //Reading High Byte
        *Copy_u16_ContentOfTCNT1 |= (u16)TCNT1H << TCNT1H_B15;
        
    }
    else
    {
        Local_u8_ErrorFlag = ES_NULL_POINTER;
    }

    return Local_u8_ErrorFlag;
}