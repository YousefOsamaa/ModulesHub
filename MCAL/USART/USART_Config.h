#ifndef USART_CONFIG_FILE
#define USART_CONFIG_FILE


//Options: USART_BR_9600, USART_BR_38_4_K, and USART_BR_115_2_K
#define USART_BAUDE_RATE   USART_BR_9600 

//Options USART_ENABLE_TX_ONLY, USART_ENABLE_RX_ONLY, USART_EABLE_TX_RX, and USART_DISABLE_TX_RX 
#define USART_COMMUNICATION_MODE  USART_ENABLE_TX_ONLY

//Options: USART_SYNCHRONOUS_MODE, USART_NORMAL_ASYNCHRONOUS_MODE, and USART_DOUBLE_SPEED_ASYNCHRONOUS_MODE
#define USART_MODE    USART_NORMAL_ASYNCHRONOUS_MODE

//Options: USART_5_BITS, USART_6_BITS, USART_7_BITS, USART_8_BITS, and USART_9_BITS, 
#define USART_CHARACTER_SIZE   USART_8_BITS

//Options: USART_1_STOP_BIT and USART_2_STOP_BITS
#define USART_NUMBER_OF_STOP_BITS  USART_1_STOP_BIT

//Options  USART_RXC_INTERRUPT_MODE, USART_TXC_INTERRUPT_MODE, USART_EDRE_INTERRUPT_MODE, USART_POLLING_MODE
#define USART_INTERRUPT_MODE  USART_EDRE_INTERRUPT_MODE


#endif