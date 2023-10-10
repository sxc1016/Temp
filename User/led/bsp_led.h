#ifndef __LED_H
#define	__LED_H


#include "stm32f10x.h"


// ͨ��1,LD����ܿ������Ŷ���
#define LED_CH1_GPIO_PORT	    	GPIOA			              /* GPIO�˿� */
#define LED_CH1_GPIO_CLK 	   		RCC_APB2Periph_GPIOA		/* GPIO�˿�ʱ�� */
#define LED_CH1_GPIO_PIN			GPIO_Pin_11			        /* ���ӵ�ʱ���ߵ�GPIO */

// ͨ��2,LD����ܿ������Ŷ���
#define LED_CH2_GPIO_PORT    		GPIOA			              /* GPIO�˿� */
#define LED_CH2_GPIO_CLK 	   	 	RCC_APB2Periph_GPIOA		/* GPIO�˿�ʱ�� */
#define LED_CH2_GPIO_PIN			GPIO_Pin_12			        /* ���ӵ�ʱ���ߵ�GPIO */

// ͨ��3,LD����ܿ������Ŷ���
#define LED_CH3_GPIO_PORT   		GPIOA			              /* GPIO�˿� */
#define LED_CH3_GPIO_CLK 	    	RCC_APB2Periph_GPIOA		/* GPIO�˿�ʱ�� */
#define LED_CH3_GPIO_PIN			GPIO_Pin_15			        /* ���ӵ�ʱ���ߵ�GPIO */


/** the macro definition to trigger the led on or off 
  * 1 - off
  *0 - on
  */
#define ON  0
#define OFF 1

#define LED_CH1_ON			GPIO_SetBits(LED_CH1_GPIO_PORT,LED_CH1_GPIO_PIN)
#define LED_CH1_OFF			GPIO_ResetBits(LED_CH1_GPIO_PORT,LED_CH1_GPIO_PIN)

#define LED_CH2_ON			GPIO_SetBits(LED_CH2_GPIO_PORT,LED_CH2_GPIO_PIN)
#define LED_CH2_OFF			GPIO_ResetBits(LED_CH2_GPIO_PORT,LED_CH2_GPIO_PIN)

#define LED_CH3_ON			GPIO_SetBits(LED_CH3_GPIO_PORT,LED_CH3_GPIO_PIN)
#define LED_CH3_OFF			GPIO_ResetBits(LED_CH3_GPIO_PORT,LED_CH3_GPIO_PIN)

////��
//#define LED_CH1_ON  \
//					LED1(ON);\
//					LED2(OFF)\
//					LED3(OFF)

////��
//#define LED_CH2_ON		\
//					LED1(OFF);\
//					LED2(ON)\
//					LED3(OFF)

////��
//#define LED_CH3_ON	\
//					LED1(OFF);\
//					LED2(OFF)\
//					LED3(ON)


//					
////��(ȫ���ر�)
//#define LED_OFF	\
//					LED1(OFF);\
//					LED2(OFF)\
//					LED3(OFF)

void LED_GPIO_Config(void);

#endif /* __LED_H */
