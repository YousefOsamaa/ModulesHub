#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_

ErrorState_t EXTI_enuInit(void);

ErrorState_t EXTI_enuSetSenseLevel(u8 Copy_u8IntPin , u8 Copy_u8SenseLevel);

ErrorState_t EXTI_enuEnableInterrupt(u8 Copy_u8IntPin);

ErrorState_t EXTI_enuDisableInterrupt(u8 Copy_u8IntPin);

ErrorState_t EXTI_enuSetCallBack(u8 Copy_u8IntPin , void(*Copy_pFunAppFun)(void));

#define EXTI_INT0                   0
#define EXTI_INT1                   1
#define EXTI_INT2                   2

#endif /* MCAL_EXTI_EXTI_INT_H_ */
