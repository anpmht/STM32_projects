/*
 * user.c
 *
 *  Created on: Sep 13, 2023
 *      Author: anup
 */
#include "main.h"
#include "user.h"
#include "string.h"
#include "stdio.h"

extern ADC_HandleTypeDef hadc1;
extern DMA_HandleTypeDef hdma_adc1;
extern UART_HandleTypeDef huart1;

uint32_t AD_RES[2];
int _write(int fd, char *data, int len) {
	HAL_UART_Transmit(&huart1, (uint8_t*) data, len, HAL_MAX_DELAY);
	return len;
}

void Setup() {
	printf("this is setup \n");
	HAL_ADCEx_Calibration_Start(&hadc1);
	printf("callibration complete \n");
	HAL_ADC_Start_DMA(&hadc1, AD_RES, 2);
	printf("DMA started \n");
}

void loop() {
	printf("ADC value is %ld adn %ld \n",AD_RES[0],AD_RES[1]);
}

