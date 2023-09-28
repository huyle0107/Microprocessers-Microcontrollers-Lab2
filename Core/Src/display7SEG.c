/*
 * display7SEG.c
 *
 *  Created on: Sep 14, 2023
 *      Author: Admin
 */

#include "main.h"
#include "display7SEG.h"

uint8_t segment7display[10] = {
		0x02,  // 0 --> 0000 0010
		0x9E,  // 1 --> 1001 1110
		0x24,  // 2 --> 0010 0100
		0x0C,  // 3 --> 0000 1100
		0x98,  // 4 --> 1001 1000
		0x48,  // 5 --> 0100 1000
		0x40,  // 6 --> 0100 0000
		0x1E,  // 7 --> 0001 1110
		0x00,  // 8 --> 0000 0000
		0x08,  // 9 --> 0000 1000
};

void display7SEG(int counter)
{
	uint8_t number = segment7display[counter];
	HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, (number>>7) & 0x01);
	HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, (number>>6) & 0x01);
	HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, (number>>5) & 0x01);
	HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, (number>>4) & 0x01);
	HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, (number>>3) & 0x01);
	HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, (number>>2) & 0x01);
	HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, (number>>1) & 0x01);
}
