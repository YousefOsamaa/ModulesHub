#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "SW_Config.h"
#include "SW_Private.h"


extern Switch_t SW_astr_SwList [];
extern u8 SW_u8_SwCount;

//Functions' implementations
extern ErrorState_t SW_enu_Initialization(void)
{
    u8 Local_u8_ErrorFlag = ES_NOK;
    u8 Local_u8_Index;

    for (Local_u8_Index = 0; Local_u8_Index < SW_u8_SwCount; Local_u8_Index++)
    {
        
       Local_u8_ErrorFlag = DIO_enu_SetPinDiretion(SW_astr_SwList[Local_u8_Index].SW_Group,SW_astr_SwList[Local_u8_Index].SW_Pin,DIO_LOW);
       if(Local_u8_ErrorFlag != ES_OK)
       {
        break;
       }
       Local_u8_ErrorFlag = (SW_astr_SwList[Local_u8_Index].SW_Group,SW_astr_SwList[Local_u8_Index].SW_Pin,SW_astr_SwList[Local_u8_Index].SW_IResistorState);

        if(Local_u8_ErrorFlag != ES_OK)
       {
        break;
       }
    }

    Local_u8_ErrorFlag = ES_OK;


    return Local_u8_ErrorFlag;
}

extern ErrorState_t SW_enu_GetSwValue(u8 Copy_u8_SwitchNumber, u8* Copy_pu8_SwitchValue)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    if(Copy_pu8_SwitchValue)
    {
        if(Copy_u8_SwitchNumber <= SW_u8_SwCount)
        {
            Local_u8_ErrorFlag  = DIO_enu_GetPinValue(SW_astr_SwList[Copy_u8_SwitchNumber].SW_Group,SW_astr_SwList[Copy_u8_SwitchNumber].SW_Pin,Copy_pu8_SwitchValue);
        }
        else
        {
            Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
        }
    }
    else
    {
        Local_u8_ErrorFlag = ES_NULL_POINTER;
    }


    return Local_u8_ErrorFlag;

}
