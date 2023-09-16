/*
 * user.c
 *
 *  Created on: Sep 13, 2023
 *      Author: anup
 */
#include "main.h"
#include "user.h"
#include "stdio.h"
#include "string.h"

extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart1;

uint16_t AD_VAL = 0;

int _write(int fd, char *data, int len) {
	HAL_UART_Transmit(&huart1, (uint8_t*) data, len, HAL_MAX_DELAY);
	return len;
}

void ADC_setup() {
	HAL_ADCEx_Calibration_Start(&hadc1);
	printf("setting up the ADCs \n");
	HAL_ADC_Start_IT(&hadc1);
}

void Read_ADC() {

}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc) {

	// Read & Update The ADC Result
	AD_VAL = HAL_ADC_GetValue(&hadc1);
	printf("ADC value is %d\n", AD_VAL);
}
