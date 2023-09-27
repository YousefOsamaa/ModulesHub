#include "../LIB/STD.h"
#include "../MCAL/ADC/ADC_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/SREG/SREG_Interface.h"
#include <util/delay.h>
	
struct x
{
	u16 Data;
	u8 Flag;
};


void adc (void* Copy_pvid_Parameters)
{
	ADC_enu_ReadData(&((struct x*)Copy_pvid_Parameters)->Data);

	((struct x*)Copy_pvid_Parameters)->Flag  = True;
}
int main(void)
{
	struct x Param ={0, False};

	DIO_enu_SetPinDiretion(DIO_PIN_GROUP_A, DIO_PIN_0, DIO_PIN_READ);
	DIO_enu_SetPinState(DIO_PIN_GROUP_A, DIO_PIN_0, DIO_FLOAT);

	DIO_enu_SetPinDiretion(DIO_PIN_GROUP_C, DIO_PIN_0, DIO_PIN_WRITE);
	DIO_enu_SetPinValue(DIO_PIN_GROUP_C, DIO_PIN_0, DIO_LOW);

	LCD_enu_Initialization();

	ADC_enu_Initialization();

	ADC_enu_SetCallBack(adc, &Param);

	SREG_vid_EnableBitI();

	LCD_enu_GoToPosition(LCD_ROW_1,LCD_COLUMN_1,LCD_PAGE_1);
	LCD_enu_SendString("Volt = ");

	LCD_enu_GoToPosition(LCD_ROW_1, LCD_COLUMN_12, LCD_PAGE_1);
	LCD_enu_SendString(" mV");

	ADC_enu_StartConversion();

	while(1)
	{
		u16 Local_u8_Data;


		if (Param.Flag)
		{
			Param.Flag = False;
			LCD_enu_GoToPosition(LCD_ROW_1,LCD_COLUMN_8, LCD_PAGE_1);
			LCD_enu_SendString("    ");

			Param.Data = Param.Data * ((f32)5000/1024);

			LCD_enu_WriteIntegerNum(Param.Data, LCD_ROW_1, LCD_COLUMN_8, LCD_PAGE_1);

		}



	}
	
	
	return 0;
}
