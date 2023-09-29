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
		0x00, // row1 --> 0000 0000
		0x3F, // row2 --> 0011 1111
		0x7F, // row3 --> 0111 1111
		0xCC, // row4 --> 1100 1100
		0xCC, // row5 --> 1100 1100
		0x7F, // row6 --> 0111 1111
		0x3F, // row7 --> 0011 1111
		0x00, // row8 --> 0000 0000
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

void updateLEDMatrix(int check, int j, int index)
{
	if (check == 0)
	{
		writeCOL(index);
		writeROW(index);
	}
	else
	{
		writeCOL((index+j)%8);
		writeROW(index);
	}
}
