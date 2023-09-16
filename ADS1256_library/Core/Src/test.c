/*
 * test.c
 *
 *  Created on: Dec 8, 2022
 *      Author: anup
 */
#include "main.h"
#include "test.h"
#include "stdio.h"
#include "string.h"

extern UART_HandleTypeDef huart1;

char file[10] = "data.txt";
char logdata[4096];
int count = 0;
int n = 0;
int id = 0;
int f = 0;
int g = 0;

int _write(int fd, char *data, int len) {
	HAL_UART_Transmit(&huart1, (uint8_t*) data, len, HAL_MAX_DELAY);
	return len;
}

void print(char *data) {
//	HAL_UART_Transmit(&huart1, (uint8_t*) data, len, HAL_MAX_DELAY);
}


void loop() {
	printf("Hello its STM32F103R8T6\n");
	HAL_Delay(2000);
}

