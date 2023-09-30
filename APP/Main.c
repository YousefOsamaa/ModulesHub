#include "../MCAL/Timer/Timer_Interface.h"
#include "../MCAL/SREG/SREG_Interface.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/EXTI/EXTI_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/SW/SW_Interface.h"





int main()
{
	//Configuring Oc0
	DIO_enu_SetPinDiretion(DIO_PIN_GROUP_B, DIO_PIN_3, DIO_PIN_WRITE);

	Timer_enu_SetDutyCycleForPWM(TIMER_0, TIMER_FAST_PWM, TIMER_FAST_PWM_INVERTING, 0.35);
	

	//Initializng timer0
	Timer_enu_Initialization();

	while (1)
	{

	}
	

	return 0;
}




















//Counter Code
// typedef struct 
// {
// 	u8 Flag;
// }Counter_t;

// void LOC_vid_MaximumReached(void* Copy_pvid_ParametersPointer)
// {
// 	((Counter_t*)Copy_pvid_ParametersPointer)->Flag = True;
// }

// int main (void)
// {
	
// 	Counter_t Local_str_Counter = {False};
// 	u16 Local_u8_Count;

	

// 	//Placing '10' value in OCR0 register
// 	Timer_enu_SetOCRxValue(TIMER_0,10);

// 	//Initializing Timer
// 	Timer_enu_Initialization();

// 	//initializing Timer call back function for Timer/Counter 0 compare match
// 	Timer_enu_SetCallBack(TIMER_0, TIMER_CTC, LOC_vid_MaximumReached, &Local_str_Counter);
	
// 	//LCD initialization
// 	LCD_enu_Initialization();

// 	//SEtting GIE
// 	SREG_vid_EnableBitI();

// 	//Configuring T0 pin 
// 	DIO_enu_SetPinDiretion(DIO_PIN_GROUP_B, DIO_PIN_0, DIO_PIN_READ);
// 	DIO_enu_SetPinValue(DIO_PIN_GROUP_B, DIO_PIN_0, DIO_FLOAT);

// 	while (1)
// 	{
// 		//Reading Count
// 		Timer_enu_ReadTCNTxValue(TIMER_0,&Local_u8_Count);

// 		LCD_enu_WriteIntegerNum(Local_u8_Count,LCD_ROW_1,LCD_COLUMN_1,LCD_PAGE_1);

// 		if(Local_str_Counter.Flag)
// 		{
// 			LCD_enu_GoToPosition(LCD_ROW_1,LCD_COLUMN_1,LCD_PAGE_1);

// 			LCD_enu_SendString("Maximum reached");
			
// 			_delay_ms(1000);

// 			Local_str_Counter.Flag = False;
// 		}

// 	}



// 	return 0;
// }
