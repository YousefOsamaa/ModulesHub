#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/KEYPAD/Keypad_Interface.h"
#include "../MCAL/EXTI/EXTI_Interface.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/SREG/SREG_Interface.h"
#include <util/delay.h>
 
void tog (void)
{
	DIO_enu_TogglePinValue(DIO_PIN_GROUP_C , DIO_PIN_7);
	_delay_ms(2000);
}

int 
main(void)
{
	DIO_enu_SetPinDiretion(DIO_PIN_GROUP_D , DIO_PIN_2 , DIO_PIN_READ);
	DIO_enu_SetPinState(DIO_PIN_GROUP_D , DIO_PIN_2 , DIO_FLOAT);
	
	DIO_enu_SetPinDiretion(DIO_PIN_GROUP_C , DIO_PIN_7 , DIO_PIN_WRITE);
	DIO_enu_SetPinValue(DIO_PIN_GROUP_C , DIO_PIN_7 , DIO_LOW);
	
	_delay_ms(2000);

	EXTI_enu_Initialization();

	EXTI_enu_SetCallBack(EXTI_INT1 , tog);


	SREG_vid_EnableBitI();

	EXTI_enu_SeTPIF(EXTI_INT1, EXTI_HIGH);	
	
	while(1)
	{	

	}

	
}