/*
 * user.c
 *
 *  Created on: Sep 13, 2023
 *      Author: anup
 */

#include "main.h"
#include "user.h"

extern TIM_HandleTypeDef htim2;

void setup() {
	//Start the timer
	HAL_TIM_Base_Start_IT(&htim2);
}

void loop() {

}

//interrupt service routine
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
}
