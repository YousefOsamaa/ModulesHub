// #ifndef TMU_PRIVATE_FILE
// #define TMU_PRIVATE_FILE

// //Timer/Counter 0 Control Register 
// #define TCCR0 *(volatile u8*)0x53
// typedef enum
// {

//  TCCR0_CS00  ,  //Bit0 Clock Selection for Timer/Counter 0   
//  TCCR0_CS01  ,  //Bit1 Clock Selection for Timer/Counter 0
//  TCCR0_CS02  ,  //Bit2 Clock Selection for Timer/Counter 0
//  TCCR0_WGM01 ,  //Bit1 Mode Selection for Timer/Counter 0
//  TCCR0_COM00 ,  //Bit0 Compare Match Output Timer/Counter 0 (OCR0 behavior)
//  TCCR0_COM01 ,  //Bit1 Compare Match Output Timer/Counter 0 (OCR0 behavior)
//  TCCR0_WGM00 ,  //Bit0 Mode Selection for Timer/Counter 0   
//  TCCR0_FOC0     //Force Output Compare Timer/Counter 0 (OCR0) 

// }TCCR0_t;

// //Timer/Counter 0 Regiser 
// #define TCNT0 *(volatile u8*)0x52
// typedef enum
// {

//  TCNT0_B0,    //Timer/Counter 0 register Bit 0  
//  TCNT0_B1,    //Timer/Counter 0 register Bit 1 
//  TCNT0_B2,    //Timer/Counter 0 register Bit 2  
//  TCNT0_B3,    //Timer/Counter 0 register Bit 3  
//  TCNT0_B4,    //Timer/Counter 0 register Bit 4  
//  TCNT0_B5,    //Timer/Counter 0 register Bit 5  
//  TCNT0_B6,    //Timer/Counter 0 register Bit 6  
//  TCNT0_B7     //Timer/Counter 0 register Bit 7      

// }TCNTO_t;

// //Timer/Counter 0 Output Compare Register 
// #define OCR0  *(volatile u8*)0x5C
// typedef enum
// {
//  OCR0_B0 ,  //Timer/Counter 0 compare register Bit 0
//  OCR0_B1 ,  //Timer/Counter 0 compare register Bit 1
//  OCR0_B2 ,  //Timer/Counter 0 compare register Bit 2
//  OCR0_B3 ,  //Timer/Counter 0 compare register Bit 3
//  OCR0_B4 ,  //Timer/Counter 0 compare register Bit 4
//  OCR0_B5 ,  //Timer/Counter 0 compare register Bit 5
//  OCR0_B6 ,  //Timer/Counter 0 compare register Bit 6
//  OCR0_B7    //Timer/Counter 0 compare register Bit 7 

// }OCR0_t;

// //Timer/Counter 2 Control Registe
// #define TCCR2 *(volatile u8*)0x45
// typedef enum
// {

// TCCR2_CS20  , //Bit0 Clock Selection for Timer/Counter 2
// TCCR2_CS21  , //Bit1 Clock Selection for Timer/Counter 2
// TCCR2_CS22  , //Bit2 Clock Selection for Timer/Counter 2
// TCCR2_WGM21 , //Bit1 Mode Selection for Timer/Counter 2
// TCCR2_COM20 , //Bit0 Compare Match Output Timer/Counter 2 (OCR2 behavior)
// TCCR2_COM21 , //Bit1 Compare Match Output Timer/Counter 2 (OCR2 behavior)
// TCCR2_WGM20 , //Bit0 Mode Selection for Timer/Counter 2
// TCCR2_FOC2  , //Force Output Compare Timer/Counter 2 (OCR2) 

// }TCCR2_t;

// //Timer/Counter 2 Regiser
// #define TCNT2 *(volatile u8*)0x44
// typedef enum
// {

//  TCNT2_B0 , //Timer/Counter 2 register Bit 0
//  TCNT2_B1 , //Timer/Counter 2 register Bit 1
//  TCNT2_B2 , //Timer/Counter 2 register Bit 2
//  TCNT2_B3 , //Timer/Counter 2 register Bit 3
//  TCNT2_B4 , //Timer/Counter 2 register Bit 4
//  TCNT2_B5 , //Timer/Counter 2 register Bit 5
//  TCNT2_B6 , //Timer/Counter 2 register Bit 6
//  TCNT2_B7 , //Timer/Counter 2 register Bit 7

// }TCNT2_t;


// //Timer/Counter 2 Output Compare Register 
// #define OCR2  *(volatile u8*)0x43
// typedef enum
// {

//  OCR2_B0 , //Timer/Counter 0 compare register Bit 0 
//  OCR2_B1 , //Timer/Counter 0 compare register Bit 1
//  OCR2_B2 , //Timer/Counter 0 compare register Bit 2
//  OCR2_B3 , //Timer/Counter 0 compare register Bit 3
//  OCR2_B4 , //Timer/Counter 0 compare register Bit 4
//  OCR2_B5 , //Timer/Counter 0 compare register Bit 5
//  OCR2_B6 , //Timer/Counter 0 compare register Bit 6
//  OCR2_B7 , //Timer/Counter 0 compare register Bit 7 

// }OCR2_t;

// //Timer/Counter 1 Control Register A
// #define TCCR1A *(volatile u8*)0x4F;
// typedef enum
// {

//     TCCR1A_WGM10 ,
//     TCCR1A_WGM11 ,
//     TCCR1A_FOC1B ,
//     TCCR1A_FOC1A ,
//     TCCR1A_COM1B0 ,
//     TCCR1A_COM1B1 ,
//     TCCR1A_COM1A0 ,
//     TCCR1A_COM1A1 ,

// } TCCR1A_t;

// //Timer/Counter 1 Control Register B
// #define TCCR1B *(volatile u8*)0x4E;
// typedef enum
// {

//     TCCR1B_CS10 ,
//     TCCR1B_CS11 ,
//     TCCR1B_CS12 ,
//     TCCR1B_WGM12 ,
//     TCCR1B_WGM13 ,
//     TCCR1B_RESERVED ,
//     TCCR1B_ICES1 ,
//     TCCR1B_ICNC1 ,

// } TCCR1B_t;

// //Timer/Counter 1 Output Compare Register A High Byte
// #define OCR1AH *(volatile u8*)0x4B;
// typedef enum
// {

//     OCR1AH_B0 ,
//     OCR1AH_B1 ,
//     OCR1AH_B2 ,
//     OCR1AH_B3 ,
//     OCR1AH_B4 ,
//     OCR1AH_B5 ,
//     OCR1AH_B6 ,
//     OCR1AH_B7 ,

// } OCR1AH_t;

// //Timer/Counter 1 Output Compare Register A Low Byte
// #define OCR1LH *(volatile u8*)0x4A;
// typedef enum
// {

//     OCR1LH_B0 ,
//     OCR1LH_B1 ,
//     OCR1LH_B2 ,
//     OCR1LH_B3 ,
//     OCR1LH_B4 ,
//     OCR1LH_B5 ,
//     OCR1LH_B6 ,
//     OCR1LH_B7 ,

// } OCR1LH_t;


// //Timer/Counter  Interrurpt Mask Register (TIMSK) FOR TIMER0, 1, AND 2 
// #define TIMSK *(volatile u8*)0x59
// typedef enum
// {

//  TIMSK_TOIE0  ,  //Timer/Counter 0 Overflow Interrupt Enable
//  TIMSK_OCIE0  ,  //Timer/Counter 0 Output Compare Match Interrupt Enable
//  TIMSK_TOIE1  ,  
//  TIMSK_OCIE1B ,  
//  TIMSK_OCIE1A ,  
//  TIMSK_TICIE1  ,  
//  TIMSK_TOIE2  ,   //Timer/Counter 2 Overflow Interrupt Enable
//  TIMSK_OCIE2  ,   //Timer/Counter 0 Output Compare Match Interrupt Enable

// }TIMSK_t;


// //Timer/Counter  Interrupt Flag Register (TIFR)
// #define TIFR  *(volatile u8*)0x58
// typedef enum
// {

//  TIFR_TOV0  =   0 , //Timer/Counter 0 Overflow Flag 
//  TIFR_OCF0  =   1 , //Output Compare Flag 0 FOR Timer/Counter 0
//  TIFR_TOV2  =   6 , //Timer/Counter 2  Overflow Flag
//  TIFR_OCF2  =   7 , //Output Compare Flag 2 FOR Timer/Counter 2

// }TIFR_t;


// //Available timer Channels
// #define TMU_TIMER_0  0
// #define TMU_TIMER_1  1
// #define TMU_TIMER_2  2

// ///OS Tick Range in ms
// #define TMU_OS_TICK_MIN 1
// #define TMU_OS_TICK_MAX 200


// //Local Functions' prototypes




// #endif