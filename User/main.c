#include "stm32f10x.h"
#include "bsp_usart.h"
#include "bsp_adc.h"
#include "delay.h"
#include "bsp_led.h"
#include "bsp_test.h"


// ADC1ת���ĵ�ѹֵͨ��MDA��ʽ����SRAM
extern __IO uint16_t ADC_ConvertedValue[NOFCHANEL];

// �ֲ����������ڱ���ת�������ĵ�ѹֵ 	 
float ADC_ConvertedValueLocal[NOFCHANEL];        

// ������ʱ
void Delay(__IO uint32_t nCount)
{
  for(; nCount != 0; nCount--);
} 

/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{		
	
	uint16_t i;
	uint16_t data_1[300] = {0};
// 	float sum_1 = 0;
//	float sum_2 = 0;
	float data = 0;
	// ���ô���
	USART_Config();
	
	// ADC ��ʼ��
	ADCx_Init();
	LED_GPIO_Config();
	
	while (1)
	{			
			LED_CH1_ON;
			delay_ms(15);
			LED_CH1_OFF;

			for(i=0; i<300; i++)
			{
				data_1[i] = ADC_ConvertedValue[0];
				delay_us(100);
			}
			for(i=0; i<300; i++)
			{
				printf("\r\n %f",(float)data_1[i]/4096*3.3);
				delay_ms(1);
			}
			while(1);
		
//			for(i=0; i<20; i++)
//			{
//				sum_1 = sum_1 + ( (float)data_1[i]/4096*3.3 );
//			}
//			for(i=0; i<40; i++)
//			{
//				sum_2 = sum_2 + ( (float)data_1[i]/4096*3.3 );
//			}
//			data = (sum_1 - sum_2) / (data_1[40] - data_1[20]);
//			printf("\r\n CH0 value = %f V \r\n",data);
//			
//			sum_1 = 0;
//			sum_2 = 0;
//			data = 0;
//			ADC_ConvertedValueLocal[0] =(float) ADC_ConvertedValue[0]/4096*3.3;
//	
//			printf("\r\n CH0 value = %f V \r\n",ADC_ConvertedValueLocal[0]);

			data = get_data();
			data = data + get_data();
			data = data + get_data();
			data = data + get_data();
			data = data + get_data();
			data = data + get_data();
			printf("\r\n%f",data/6);
			delay_ms(200);

	 
	}
}
/*********************************************END OF FILE**********************/
