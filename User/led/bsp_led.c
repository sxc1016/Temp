#include "bsp_led.h"   

 /**
  * @brief  ��ʼ������LED��IO
  * @param  ��
  * @retval ��
  */
void LED_GPIO_Config(void)
{		
	
		/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
		GPIO_InitTypeDef GPIO_InitStructure;

				

		/*����LED��ص�GPIO����ʱ��*/
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO | LED_CH1_GPIO_CLK | LED_CH2_GPIO_CLK | LED_CH3_GPIO_CLK, ENABLE);
	
		GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
	
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = LED_CH1_GPIO_PIN;	
		/*��������ģʽΪͨ���������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
		/*������������Ϊ50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(LED_CH1_GPIO_PORT, &GPIO_InitStructure);	
		
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = LED_CH2_GPIO_PIN;
		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(LED_CH2_GPIO_PORT, &GPIO_InitStructure);
		
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = LED_CH3_GPIO_PIN;
		/*���ÿ⺯������ʼ��GPIOF*/
		GPIO_Init(LED_CH3_GPIO_PORT, &GPIO_InitStructure);


}

/*********************************************END OF FILE**********************/
