#include "bsp_led.h"   

 /**
  * @brief  初始化控制LED的IO
  * @param  无
  * @retval 无
  */
void LED_GPIO_Config(void)
{		
	
		/*定义一个GPIO_InitTypeDef类型的结构体*/
		GPIO_InitTypeDef GPIO_InitStructure;

				

		/*开启LED相关的GPIO外设时钟*/
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO | LED_CH1_GPIO_CLK | LED_CH2_GPIO_CLK | LED_CH3_GPIO_CLK, ENABLE);
	
		GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
	
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = LED_CH1_GPIO_PIN;	
		/*设置引脚模式为通用推挽输出*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
		/*设置引脚速率为50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
		/*调用库函数，初始化GPIO*/
		GPIO_Init(LED_CH1_GPIO_PORT, &GPIO_InitStructure);	
		
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = LED_CH2_GPIO_PIN;
		/*调用库函数，初始化GPIO*/
		GPIO_Init(LED_CH2_GPIO_PORT, &GPIO_InitStructure);
		
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = LED_CH3_GPIO_PIN;
		/*调用库函数，初始化GPIOF*/
		GPIO_Init(LED_CH3_GPIO_PORT, &GPIO_InitStructure);


}

/*********************************************END OF FILE**********************/
