#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/KEYPAD/Keypad_Interface.h"
#include "../MCAL/EXTI/EXTI_Interface.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/SREG/SREG_Interface.h"
 
void tog (void)
{
	DIO_enu_TogglePinValue(DIO_PIN_GROUP_C , DIO_PIN_7);
}

int 
main(void)
{
	DIO_enu_SetPinDiretion(DIO_PIN_GROUP_D , DIO_PIN_2 , DIO_PIN_READ);
	DIO_enu_SetPinState(DIO_PIN_GROUP_D , DIO_PIN_2 , DIO_FLOAT);
	
	DIO_enu_SetPinDiretion(DIO_PIN_GROUP_C , DIO_PIN_7 , DIO_PIN_WRITE);
	EXTI_enuInit();

	EXTI_enuSetCallBack(EXTI_INT1 , tog);

	SREG_vid_EnableBitI();

	
	while(1);
}