/*
 * display7SEG.h
 *
 *  Created on: Sep 21, 2023
 *      Author: Admin
 */

#ifndef INC_DISPLAY7SEG_H_
#define INC_DISPLAY7SEG_H_

void clearAll7SEG();
void clearAllEN();
void display7SEG(int counter);
void update7SEG(int index);
void updateClockBuffer(int hour, int minute);

#endif /* INC_DISPLAY7SEG_H_ */
