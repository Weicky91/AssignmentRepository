#include "LED_BEEP.h"

/*WATER_LED*/
void LED_WATER(void)
{
	LED1_ON;
	HAL_Delay(200);
	LED1_OFF;
	LED2_ON;
	HAL_Delay(200);
	LED2_OFF;
	LED3_ON;
	HAL_Delay(200);
	LED3_OFF;
	LED4_ON;
	HAL_Delay(200);
	LED4_OFF;
	HAL_Delay(100);
}
/*BEEP_AlARM*/
void BEEP_ALARM(int times)
{
	while(times>0)
	{
		BEEP_ON;
		HAL_Delay(50);
		BEEP_OFF;
		HAL_Delay(50);
		times--;
	}
}
