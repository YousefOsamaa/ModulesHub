// #include "../LIB/STD.h"
// #include "../LIB/ErrorStates.h"


// #include "TMU_Private.h"
// #include "TMU_Config.h"

// static u32 u32_SystemTicks;

// static u16 u16_TimerCounter;
// #if TMU_TIMER_CHANNEL == TMU_TIMER_0 || TMU_TIMER_CHANNEL == TMU_TIMER_2

//     static u16 u16_NumberOfOverFlows;
//     static u8 u8_PreLoad;

// #endif



// //APIs' implementations
// extern ErrorState_t TMU_enu_Initialization(void)
// {
//     u8 Local_u8_ErrorFlag = ES_NOK;
    
    
//     #if TMU_TIMER_CHANNEL == TMU_TIMER_0

//         //1] Initialzing Timer/Counter 0

//         //Choosing Timer/Counter 0 Waveform Generation Mode to be Normal
//         //Bits contain 00
//         TCCR0 &= 0x00;

//         //Choosing PS to be 64 
//         //Bits contain 11
//         TCCR0 |= (3 >> TCCR0_CS00);

//         //Choosing OC0 to be disconnected
//         //Bits aleardy contain 00


//         //Choosing INT Mode
//         //Bit contains 1
//         TIMSK |= (1 << TIMSK_TOIE0);

         
//         #if TMU_OS_TICK >= TMU_OS_TICK_MIN && TMU_OS_TICK <= TMU_OS_TICK_MAX 

//             //Initialzing PreLoad and TimerCount Variables
//             u32 Local_u32_TotalCounts = (TMU_OS_TICK* (u32)TMU_CPU_FREQUENCY) / (64);

//             u16_NumberOfOverFlows = (Local_u32_TotalCounts + 255) / (256);

//             u8_PreLoad =( 256UL - (Local_u32_TotalCounts % 256UL));

//             //Configuring Timer 
//             u16_TimerCounter = u16_NumberOfOverFlows;
//             TCNT0 = u8_PreLoad;

//         #else

//             #error TMU_OS_TICK is invalid
        
//         #endif


//     #elif TMU_TIMER_CHANNEL == TMU_TIMER_1

//         //1} Initializing Timer/Counter 1
//         //CTC ON OCR1A, OC1A AND OC1B ARE DISCONNECTED PS 64
//         TCCR1A = 0X00;
//         TCCR1B = 0x0B;

//         //Enabling PIF
//         TIMSK |= (1 << TIMSK_OCIE1A)

//         #if TMU_OS_TICK >= TMU_OS_TICK_MIN && TMU_OS_TICK <= TMU_OS_TICK_MAX 

//             u16 Local_u16_TotalNumberOfCounts = (TMU_OS_TICK * (u32)TMU_CPU_FREQUENCY) / (64);

//             OCR1AH = (Local_u16_TotalNumberOfCount >> 8);
//             OCR1AL = (u8)(Local_u16_TotalNumberOfCount);

//         #else

//             #error TMU_TIMER_CHANNEL is invalid

//         #endif



//     #elif TMU_TIMER_CHANNEL == TMU_TIMER_2

//         //1] Initialzing Timer/Counter 2

//         //Choosing Timer/Counter 2 Waveform Generation Mode to be Normal
//         //Bits contain 00
//         TCCR2 &= 0x00;

//         //Choosing PS to be 64 
//         //Bits contain 11
//         TCCR2 |= (3 >> TCCR2_CS20);

//         //Choosing OC2 to be disconnected
//         //Bits aleardy contain 00


//         //Choosing INT Mode
//         //Bit contains 1
//         TIMSK |= ( 1 << TIMSK_TOIE2);

         
//         #if TMU_OS_TICK >= TMU_OS_TICK_MIN && TMU_OS_TICK <= TMU_OS_TICK_MAX 

//             //Initialzing PreLoad and TimerCount Variables
//             u16 Local_u16_TotalNumberOfCounts = (TMU_OS_TICK* (u32)TMU_CPU_FREQUENCY) / (64);

//             u16 Local_u16_NumberOfOverFlows = (Local_u16_TotalNumberOfCounts + 255) / (256);

//             u8 Local_u8_PreLoad = 256UL - (Local_u16_TotalNumberOfCounts % 256UL);

//             //Assigining to Static variables
//             u16_NumberOfOverFlows = Local_u16_NumberOfOverFlows;
//             u16_TimerCounter = u16_NumberOfOverFlows;

//             u8_PreLoad = Local_u8_PreLoad;
//             TCNT2 = u8_PreLoad;
        
//         #else

//             #error TMU_OS_TICK is invalid
        
//         #endif


//     #else 
        
//         #error TMU_TIMER_CHANNEL is invalid

//     #endif 

//     Local_u8_ErrorFlag = ES_OK;

//     return Local_u8_ErrorFlag;
// }

// extern ErrorState_t TMU_enu_CreateTask()
// {
//     u8 Local_u8_ErrorFlag = ES_NOK;



//     return Local_u8_ErrorFlag;
// }

// extern ErrorState_t TMU_enu_killTask()
// {
//     u8 Local_u8_ErrorFlag = ES_NOK;



//     return Local_u8_ErrorFlag;
// }

// extern ErrorState_t TMU_enu_PauseTask()
// {
//     u8 Local_u8_ErrorFlag = ES_NOK;



//     return Local_u8_ErrorFlag;
// }

// extern ErrorState_t TMU_enu_ResumeTask()
// {
//     u8 Local_u8_ErrorFlag = ES_NOK;



//     return Local_u8_ErrorFlag;
// }

// extern ErrorState_t TMU_enu_RunScheduler()
// {
//     u8 Local_u8_ErrorFlag = ES_NOK;



//     return Local_u8_ErrorFlag;
// }




// //ISRs


// #if TMU_TIMER_CHANNEL == TMU_TIMER_0
//     void __vector_11 (void)__attribute__((signal));

//     void __vector_11 (void)
//     {
//         u16_TimerCounter--;

//         if(!u16_TimerCounter)
//         {
//             // //Resetting the Timer/Counter 0 Register
//             // TCNT0 = u8_PreLoad;

//             // //Resetting Overflow Counter
//             // u16_TimerCounter = u16_NumberOfOverFlows;

//             // //Incrementing OS Tick
//             // u32_SystemTicks++;

//             *((u8*)0x35) |= (1 << 7);
//         }
//     }

// #endif


// #if TMU_TIMER_CHANNEL == TMU_TIMER_2

//     void __vector_5 (void)__attribute__((signal));
//     void __vector_5 (void)
//     {
//         u16_TimerCounter--;
//         if(!u16_TimerCounter)
//         {
//             //Resetting the Timer/Counter 0 Register
//             TCNT2 = u8_PreLoad;

//             //Resetting Overflow Counter
//             u16_TimerCounter = u16_NumberOfOverFlows;

//             //Incrementing OS Tick
//             u32_SystemTicks++;
//         }

//     }

// #endif

// //Local Functions' implementaions