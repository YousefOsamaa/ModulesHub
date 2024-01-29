//General local files
#include "../../LIB/ErrorStates.h"
#include "../../LIB/STD.h"

//Other needed peripherals
#include "../../MCAL/EXTI/EXTI_Interface.h"
#include "../../MCAL/Timer/Timer_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../LCD/LCD_Interface.h"

//ICU Module local files
#include "ICU_Config.h"
#include "ICU_Private.h"

static u8 LOC_u8_State = ICU_IDLE; //State by default IDLE 
static u32 LOC_u32_PeriodCounts; //Variable to store the  period counts in it
static u32 LOC_u32_TonCounts; //Variable to store Ton counts in it
static u32 LOC_au32_NumberOfOverflowsArray[3];  //To sotre the number of overflows performed by ICU_TIMER_USED (Total, Falling Edge, Second Rising Edge)
static u16 LOC_u16_Timer_PS;


extern ErrorState_t ICU_enu_Initialization()
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    //Initialize Timer peripheral: Timer0, Normal, PS 1024, and  Interrupt Mode
    Timer_enu_Initialization();
    Timer_enu_DisableInterruptMode(ICU_TIMER_USED, TIMER_NORMAL); //Disabling Timer Interrupt
    Timer_enu_SetCallBack(ICU_TIMER_USED, TIMER_NORMAL, vid_IncrementOverFlowCounter, NULL);//Setting Call Back Function
    
    //Initialize EXTI peripheral: EXTI0, INT Mode, Rising Edge
    EXTI_enu_Initialization();
    EXTI_enu_INTMode(ICU_EXTI_USED, EXTI_POLLING_MODE); //Preventing EXTI from causing an interrupt until ICU activation
    EXTI_enu_SetCallBack(ICU_EXTI_USED, vid_CapturingFunction, NULL); //Setting CapturingFunction as the EXTI ISR

    //Initialize ICU module 
    LOC_u8_State = ICU_IDLE; //State machine must start as IDLE until activation 


    return Local_u8_ErrorFlag;
}

extern ErrorState_t ICU_enu_StartCapture()
{
    u8 Local_u8_ErrorFlag = ES_NOK;
    
    if(LOC_u8_State == ICU_IDLE)
    {
        
        LOC_u8_State = ICU_FIRST_RISING_EDGE; //State machine will begin from the 'FIRS_RISING_EGDE' State
        
        Timer_enu_GetPSUsed(ICU_TIMER_USED, &LOC_u16_Timer_PS); //Acquiring Timer PS

        Timer_enu_EnableInterruptMode(ICU_TIMER_USED, TIMER_NORMAL); //Enabling Timer Interrupt 

        EXTI_enu_INTMode(ICU_EXTI_USED, EXTI_INT_MODE); //EXTI INT mode activated
    }

    return Local_u8_ErrorFlag;
}

extern ErrorState_t ICU_enu_CalculateParameters(f32* Copy_pf32_SignalParametersArray)
{
    u8 Local_u8_ErrorFlag = ES_NOK;
    f32 Local_f32_TimerFrequency = 16000000.0/LOC_u16_Timer_PS; 
    
    if(LOC_u8_State == ICU_IDLE)
    {

        LOC_u32_PeriodCounts += 256UL*LOC_au32_NumberOfOverflowsArray[2]; //Total Number of Period Counts

        LOC_u32_TonCounts += 256UL*LOC_au32_NumberOfOverflowsArray[1]; //Total Number of Duty Counts

        //Calculating Frequency in Hz
        if(LOC_u32_PeriodCounts != 0)
        {
            Copy_pf32_SignalParametersArray[0] = (Local_f32_TimerFrequency/LOC_u32_PeriodCounts);
        }
        else
        {
            Copy_pf32_SignalParametersArray[0] = 0; //No signal
        }

        if(LOC_u32_TonCounts != 0)
        {
            //Calculating Duty Ratio in %
            Copy_pf32_SignalParametersArray[1] = ((f32)LOC_u32_TonCounts*100UL)/(LOC_u32_PeriodCounts);
        }   
        else
        {
            Copy_pf32_SignalParametersArray[1] = 0; //No signal
        }
    
    }

    return Local_u8_ErrorFlag;
}

extern ErrorState_t ICU_enu_GetState(u8* Copy_pu8_SystemState)
{
    u8 Local_u8_ErrorFlag;

    if(Copy_pu8_SystemState)
    {
        *Copy_pu8_SystemState = LOC_u8_State;
    }
    else
    {
        Local_u8_ErrorFlag = ES_NULL_POINTER;
    }

    return Local_u8_ErrorFlag;
}

void vid_CapturingFunction(void* Copy_pvid_FunctionParameters)
{

    switch (LOC_u8_State)
    {
        
        
        case ICU_FIRST_RISING_EDGE:
        {
            
            Timer_enu_SetTCNTxValue(ICU_TIMER_USED, 0); //Resetig timer value

            Timer_enu_SetTovx(ICU_TIMER_USED); //Clearing Tov0 Flag

            EXTI_enu_ISC(ICU_EXTI_USED, EXTI_FALLING_EDGE); //Setting EXTI to Falling Edge

            LOC_au32_NumberOfOverflowsArray[0] = 0; //Resetting Overflow Counter

            LOC_u8_State = ICU_FALLING_EDGE;  //Setting state machine to Falling edge
            
            // Timer_enu_GetPSUsed(ICU_TIMER_USED, &LOC_u16_Timer_PS); //Acquiring Timer PS
            // LOC_au32_NumberOfOverflowsArray[1] = 0; //Resetting Overflow Counter
            // LOC_au32_NumberOfOverflowsArray[2] = 0; //Resetting Overflow Counter

            break;
        }

        case ICU_FALLING_EDGE:
        {
            Timer_enu_ReadTCNTxValue(ICU_TIMER_USED, &LOC_u32_TonCounts); //Saving Tcntx value in the Ton variable

            LCD_enu_WriteIntegerNum(LOC_u32_TonCounts, LCD_ROW_1, LCD_COLUMN_1, LCD_PAGE_1);
            LOC_au32_NumberOfOverflowsArray[1] = LOC_au32_NumberOfOverflowsArray[0];

            LCD_enu_WriteIntegerNum(LOC_au32_NumberOfOverflowsArray[1], LCD_ROW_1, LCD_COLUMN_8, LCD_PAGE_1);
            
            EXTI_enu_ISC(ICU_EXTI_USED, EXTI_RISING_EDGE); //Setting EXTI to Falling Edge
            
            LOC_u8_State = ICU_SECOND_RISING_EDGE; //Setting state machine to Falling edge

            //u8 Local_u8_Tov0 = 0;
            // Timer_enu_GetTovx(ICU_TIMER_USED, &Local_u8_Tov0);

            // if(Local_u8_Tov0)
            // {
            //     Timer_enu_SetTovx(ICU_TIMER_USED); //Clearing Flag

            //     LOC_au32_NumberOfOverflowsArray[1]++; //Recording Number Of Duty Overflows
            // }
           
            //LCD_enu_WriteFloatNum(LOC_u32_TonCounts, LCD_ROW_1, LCD_COLUMN_1, LCD_PAGE_1);
            
            //LCD_enu_WriteFloatNum(LOC_au32_NumberOfOverflowsArray[1], LCD_ROW_2, LCD_COLUMN_1, LCD_PAGE_1);
            

            break;
        }
        
        case ICU_SECOND_RISING_EDGE:
        {
            Timer_enu_ReadTCNTxValue(ICU_TIMER_USED, &LOC_u32_PeriodCounts ); //Saving Tcntx value in the Ton variable
                        
            LCD_enu_WriteIntegerNum(LOC_u32_PeriodCounts, LCD_ROW_2, LCD_COLUMN_1, LCD_PAGE_1);

            LOC_au32_NumberOfOverflowsArray[2] = LOC_au32_NumberOfOverflowsArray[0];
            
            LCD_enu_WriteIntegerNum(LOC_au32_NumberOfOverflowsArray[2], LCD_ROW_2, LCD_COLUMN_8, LCD_PAGE_1);
            
            #if ICU_MODE == ICU_SNGLE_CAPTURE_MODE
            EXTI_enu_INTMode(ICU_EXTI_USED, EXTI_POLLING_MODE); //Turning off ICU intil activation
            Timer_enu_DisableInterruptMode(ICU_TIMER_USED, TIMER_NORMAL);
            LOC_u8_State = ICU_IDLE;

            #else
            EXTI_enu_INTMode(ICU_EXTI_USED, EXTI_RISING_EDGE); //Turning off ICU intil activation
            LOC_u8_State = ICU_FIRST_RISING_EDGE;

            #endif

            break;

            // u8 Local_u8_Tov0 = 0;
            // Timer_enu_GetTovx(ICU_TIMER_USED, &Local_u8_Tov0);

            // if(Local_u8_Tov0)
            // {
            //     Timer_enu_SetTovx(ICU_TIMER_USED); //Clearing Flag

            //     LOC_au32_NumberOfOverflowsArray[2]++; //Recording Number Of Duty Overflows
            // }

           // LCD_enu_WriteFloatNum(LOC_u32_PeriodCounts, LCD_ROW_1, LCD_COLUMN_1, LCD_PAGE_1);

            //CD_enu_WriteFloatNum(LOC_au32_NumberOfOverflowsArray[2], LCD_ROW_2, LCD_COLUMN_1, LCD_PAGE_1);

        }
    
        case ICU_IDLE:
        {
            //Redundant case    
            break;
        }

        default:
        {
            break;
        }

    }
    
}

void vid_IncrementOverFlowCounter()
{

    LOC_au32_NumberOfOverflowsArray[0]++;

    DIO_enu_TogglePinValue(DIO_PIN_GROUP_C, DIO_PIN_1);
    
}
