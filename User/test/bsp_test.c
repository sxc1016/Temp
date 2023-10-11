#include "bsp_test.h"   
#include "bsp_led.h"
#include "delay.h"

// ADC1转换的电压值通过MDA方式传到SRAM
extern __IO uint16_t ADC_ConvertedValue[2];
// 局部变量，用于保存转换计算后的电压值 	 
extern float ADC_ConvertedValueLocal[2]; 


float get_data(void)
{
	uint8_t i;
	uint16_t data_1[230] = {0};
	float sum_1 = 0;
	float Data;
	
	LED_CH1_ON;
	delay_ms(20);
	LED_CH1_OFF;
	
	for(i=0; i<230; i++)
	{
		data_1[i] = ADC_ConvertedValue[0];
		delay_us(100);
	}
	
	for(i=3; i<230; i++)
	{
		sum_1 = sum_1 + (float)data_1[i]/4096*3.3;
	}
	
	Data = sum_1/(  (float)data_1[3]/4096*3.3 -  (float)data_1[229]/4096*3.3);

	return Data;
	delay_ms(100);
}