/*
 * user.c
 *
 *  Created on: Sep 13, 2023
 *      Author: anup
 */
#include "main.h"
#include "stdio.h"
#include "string.h"

extern TIM_HandleTypeDef htim2;
extern UART_HandleTypeDef huart1;

uint8_t END_MSG[35] = "Overflow Reached! Counter Reset!\n\r";

void setup() {
	HAL_TIM_Base_Start_IT(&htim2);
}

void loop() {
	uint8_t MSG[20] = { '\0' };
	uint16_t CounterTicks = 0;
	// Read The Counter Ticks Register
	CounterTicks = TIM2->CNT;
	// Print The Ticks Count Via UART1
	sprintf(MSG, "Ticks = %d\n", CounterTicks);
	HAL_UART_Transmit(&huart1, MSG, sizeof(MSG), 100);
	HAL_Delay(100);
}

// Counter Overflow ISR Handler
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	HAL_UART_Transmit(&huart1, END_MSG, sizeof(END_MSG), 100);
}
