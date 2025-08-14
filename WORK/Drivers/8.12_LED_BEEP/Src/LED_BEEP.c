#include "LED_BEEP.h"

/*WATER_LED*/
void LED_WATER(int msec)
{
	LED1_ON;
	HAL_Delay(msec);
	LED1_OFF;
	LED2_ON;
	HAL_Delay(msec);
	LED2_OFF;
	LED3_ON;
	HAL_Delay(msec);
	LED3_OFF;
	LED4_ON;
	HAL_Delay(msec);
	LED4_OFF;
	HAL_Delay(msec);
}
void LED12_WATER(int msec)
{
	LED1_ON;
	HAL_Delay(msec);
	LED1_OFF;
	LED2_ON;
	HAL_Delay(msec);
	LED2_OFF;
	HAL_Delay(msec);
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
