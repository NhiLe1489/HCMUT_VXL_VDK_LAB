/*
 * button.h
 *
 *  Created on: Oct 13, 2025
 *      Author: HP PAVILION
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

int isButtonPressed();

void subKeyProcess(int button);
void getKeyInput();


#endif /* INC_BUTTON_H_ */
