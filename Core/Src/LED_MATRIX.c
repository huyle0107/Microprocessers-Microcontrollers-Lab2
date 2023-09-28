/*
 * LED_MATRIX.c
 *
 *  Created on: Sep 23, 2023
 *      Author: Admin
 */

#include "main.h"
#include "LED_MATRIX.h"

int MAX_LED_MATRIX = 8;

uint8_t COL[8] = {
		0x80, // col1 --> 1000 0000
		0x40, // col2 --> 0100 0000
		0x20, // col3 --> 0010 0000
		0x10, // col4 --> 0001 0000
		0x08, // col5 --> 0000 1000
		0x04, // col6 --> 0000 0100
		0x02, // col7 --> 0000 0010
		0x01, // col8 --> 0000 0001
};

uint8_t A[8] = {
		0x18, // row1 --> 0001 1000
		0x3C, // row2 --> 0011 1100
		0x66, // row3 --> 0110 0110
		0x66, // row4 --> 0110 0110
		0x7E, // row5 --> 0111 1110
		0x7E, // row6 --> 0111 1110
		0x66, // row7 --> 0110 0110
		0x66  // row8 --> 0110 0110
};

void writeCOL(int i)
{
	HAL_GPIO_WritePin(GPIOA, ENM0_Pin, (COL[i] >> 7) & 0x01);
	HAL_GPIO_WritePin(GPIOA, ENM1_Pin, (COL[i] >> 6) & 0x01);
	HAL_GPIO_WritePin(GPIOA, ENM2_Pin, (COL[i] >> 5) & 0x01);
	HAL_GPIO_WritePin(GPIOA, ENM3_Pin, (COL[i] >> 4) & 0x01);
	HAL_GPIO_WritePin(GPIOA, ENM4_Pin, (COL[i] >> 3) & 0x01);
	HAL_GPIO_WritePin(GPIOA, ENM5_Pin, (COL[i] >> 2) & 0x01);
	HAL_GPIO_WritePin(GPIOA, ENM6_Pin, (COL[i] >> 1) & 0x01);
	HAL_GPIO_WritePin(GPIOA, ENM7_Pin, (COL[i] >> 0) & 0x01);
}

void writeROW(int i)
{
	HAL_GPIO_WritePin(GPIOB, ROW0_Pin, (A[i] >> 7) & 0x01);
	HAL_GPIO_WritePin(GPIOB, ROW1_Pin, (A[i] >> 6) & 0x01);
	HAL_GPIO_WritePin(GPIOB, ROW2_Pin, (A[i] >> 5) & 0x01);
	HAL_GPIO_WritePin(GPIOB, ROW3_Pin, (A[i] >> 4) & 0x01);
	HAL_GPIO_WritePin(GPIOB, ROW4_Pin, (A[i] >> 3) & 0x01);
	HAL_GPIO_WritePin(GPIOB, ROW5_Pin, (A[i] >> 2) & 0x01);
	HAL_GPIO_WritePin(GPIOB, ROW6_Pin, (A[i] >> 1) & 0x01);
	HAL_GPIO_WritePin(GPIOB, ROW7_Pin, (A[i] >> 0) & 0x01);
}

void updateLEDMatrix(int index)
{
	writeCOL(index);
	writeROW(index);
}
