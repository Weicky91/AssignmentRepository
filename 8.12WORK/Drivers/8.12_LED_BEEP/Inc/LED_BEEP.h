#ifndef LED_BEEP_H_
#define LED_BEEP_H_

/*----------------------------------include-----------------------------------*/
#include "gpio.h"
#include "main.h"
#include "stm32f4xx_hal_gpio.h"

#define BEEP_PORT GPIOA
#define LED_PORT  GPIOA

#define LED1_PIN  GPIO_PIN_4
#define LED2_PIN  GPIO_PIN_5
#define LED3_PIN  GPIO_PIN_6
#define LED4_PIN  GPIO_PIN_7
#define BEEP_PIN  GPIO_PIN_8

#define BEEP_ON HAL_GPIO_WritePin(BEEP_PORT, BEEP_PIN, GPIO_PIN_SET)
#define BEEP_OFF HAL_GPIO_WritePin(BEEP_PORT, BEEP_PIN, GPIO_PIN_RESET)

#define LED1_ON HAL_GPIO_WritePin(LED_PORT, LED1_PIN, GPIO_PIN_SET)
#define LED1_OFF HAL_GPIO_WritePin(LED_PORT, LED1_PIN, GPIO_PIN_RESET)

#define LED2_ON HAL_GPIO_WritePin(LED_PORT, LED2_PIN, GPIO_PIN_SET)
#define LED2_OFF HAL_GPIO_WritePin(LED_PORT, LED2_PIN, GPIO_PIN_RESET)

#define LED3_ON HAL_GPIO_WritePin(LED_PORT, LED3_PIN, GPIO_PIN_SET)
#define LED3_OFF HAL_GPIO_WritePin(LED_PORT, LED3_PIN, GPIO_PIN_RESET)

#define LED4_ON HAL_GPIO_WritePin(LED_PORT, LED4_PIN, GPIO_PIN_SET)
#define LED4_OFF HAL_GPIO_WritePin(LED_PORT, LED4_PIN, GPIO_PIN_RESET)

/*functions*/
/*WATER_LED*/
void LED_WATER(void);
/*BEEP_AlARM*/
void BEEP_ALARM(int times);

#endif
