/*
 * button.h
 *
 *  Created on: Oct 15, 2025
 *      Author: HP PAVILION
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

int isButton1Pressed();
void readButton1();

int isButton2Pressed();
void readButton2();

int isButton3Pressed();
void readButton3();

#endif /* INC_BUTTON_H_ */
