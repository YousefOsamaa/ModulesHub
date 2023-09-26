#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/KEYPAD/Keypad_Interface.h"
 
 int main (void)
 {
	LCD_enu_Initialization();
	Keypad_enu_Initialization();
	
	u8 character= 'A';
	while (1)
	{
		Keypad_enu_GetButtonPressedValue(&character);
		LCD_enu_SendData(character);
	
	}
	 return 0;
 }
