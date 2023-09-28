#include "../MCAL/Timer/Timer_Interface.h"
#include "../MCAL/SREG/SREG_Interface.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/EXTI/EXTI_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"
#include <util/delay.h>

#define LED_LIGHT_STATE  1
#define LED_DIM_STATE    0

typedef struct 
{
	u8 Counter;
	u8 Flag;
}Counter_t;

void LOC_vid_IncrementCounter(void* Copy_pvid_ParametersPointer)
{

}

int main (void)
{
	
	Counter_t Local_str_Counter = {0, False};

	//Configuring OC0 pin
	DIO_enu_SetPinDiretion(DIO_PIN_GROUP_B, DIO_PIN_3, DIO_PIN_WRITE);
	DIO_enu_SetPinValue(DIO_PIN_GROUP_B, DIO_PIN_3, DIO_LOW);
	
	//EXTI intialization
	EXTI_enu_Initialization();
	
	//initializing ETI call back function for INT0
	//EXTI_enu_SetCallBack(EXTI_INT0,);;

	//Placing '10' value in OCR0 register
	Timer_enu_SetOCRxValue(TIMER_0,10);

	//Initializing Timer
	Timer_enu_Initialization();
	
	//Initializing call back function
	Timer_enu_SetCallBack(TIMER_0,TIMER_CTC,LOC_vid_IncrementCounter, &Local_str_Counter);
	
	//LCD initialization
	LCD_enu_Initialization();

	
	//SEtting GIE
	SREG_vid_EnableBitI();


	while (1)
	{

	}



	return 0;
}
