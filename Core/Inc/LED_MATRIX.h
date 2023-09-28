/*
 * LED_MATRIX.h
 *
 *  Created on: Sep 23, 2023
 *      Author: Admin
 */

#ifndef INC_LED_MATRIX_H_
#define INC_LED_MATRIX_H_

extern int MAX_LED_MATRIX;

void writeCOL(int i);
void writeROW(int i);
void updateLEDMatrix(int index);

#endif /* INC_LED_MATRIX_H_ */
