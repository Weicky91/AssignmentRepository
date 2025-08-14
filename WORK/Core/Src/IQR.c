#include "main.h"
#include "usart.h"
#include "stm32f4xx_hal_uart.h"

uint8_t u1_rx_data_temp=1;
uint8_t u2_rx_data_temp=1; 
uint8_t buff[9]={0};
uint8_t buff2[14]={0};
int buff_add=0;
void HAL_UART_RxCplCallback(UART_HandleTypeDef* huart)
{
	if(huart->Instance==USART1)
	{
		buff[0]=u1_rx_data_temp;
		HAL_UART_Receive_IT(&huart1,&u1_rx_data_temp,1);
		/*multi word trans and receive*/
//		HAL_UART_Receive_IT(&huart1,buff+buff_add,1);
//		buff_add++;
	}
	if(huart->Instance==USART2)
	{
		HAL_UART_Receive_DMA(&huart2,&u2_rx_data_temp,1);
	}
}