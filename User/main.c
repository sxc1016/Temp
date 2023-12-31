#include "stm32f10x.h"
#include "bsp_usart.h"
#include "bsp_adc.h"
#include "delay.h"
#include "bsp_led.h"
#include "bsp_test.h"
#include "math.h"

// ADC1转换的电压值通过MDA方式传到SRAM
extern __IO uint16_t ADC_ConvertedValue[NOFCHANEL];

// 局部变量，用于保存转换计算后的电压值 	 
float ADC_ConvertedValueLocal[NOFCHANEL];        

// 软件延时
void Delay(__IO uint32_t nCount)
{
  for(; nCount != 0; nCount--);
} 

/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{		
	
	uint16_t i;
//	uint16_t data_1[300] = {0};
// 	float sum_1 = 0;
//	float sum_2 = 0;
//	float sum_3 = 0;
	float data = 0;
	// 配置串口
	USART_Config();
	
	// ADC 初始化
	ADCx_Init();
	LED_GPIO_Config();
	
	while (1)
	{			
//			LED_CH1_ON;
//			delay_ms(20);
//			LED_CH1_OFF;

//			for(i=0; i<300; i++)
//			{
//				data_1[i] = ADC_ConvertedValue[0];
//				delay_us(100);
//			}
//			for(i=0; i<300; i++)
//			{
//				printf("\r\n %f",(float)data_1[i]/4096*3.3);
//				delay_ms(1);
//			}
//			while(1);
		
//			for(i=3; i<230; i++)
//			{
//				sum_1 = sum_1 + (float)data_1[i]/4096*3.3;
//			}
//			for(i=20; i<40; i++)
//			{
//				sum_2 = sum_2 + (float)data_1[i]/4096*3.3;
//			}
//			for(i=40; i<60; i++)
//			{
//				sum_3 = sum_3 + (float)data_1[i]/4096*3.3;
//			}
//			data = sum_1 / ((float)data_1[3]/4096*3.3-(float)data_1[99]/4096*3.3);
//			printf("\r\n%f",data);
//			
//			data = (sum_1-sum_2)/(sum_2-sum_3);
//			printf("\r\n%f",100/log(data));
			

//			sum_1 = 0;
//			sum_2 = 0;
//			sum_3 = 0;
//			data = 0;
//			delay_ms(500);
//			ADC_ConvertedValueLocal[0] =(float) ADC_ConvertedValue[0]/4096*3.3;
//	
//			printf("\r\n CH0 value = %f V \r\n",ADC_ConvertedValueLocal[0]);
//			delay_ms(1000);
			data = get_data();
			data = data + get_data();
			data = data + get_data();
//			printf("\r\n%f",(393.75-4.26*(data/3)) );//第一次标定
//			printf("\r\n%f",(378.45611-4.01683*(data/3)) );//第二次标定
			printf("\r\n%f",(361.04135-3.8988*(data/3)) );//第三次前半段标定
			printf("\r\n%f",(419.39213-4.72538*(data/3)) );//第三次后半段标定
//			printf("\r\n%f",data/3 );
			delay_ms(500);

	 
	}
}
/*********************************************END OF FILE**********************/

