/*
 * button.c
 *
 *  Created on: Oct 15, 2025
 *      Author: HP PAVILION
 */

#include "button.h"

int button1_flag = 0;
int firstRead1 = NORMAL_STATE;
int secondRead1 = NORMAL_STATE;
int thirdRead1 = NORMAL_STATE;
int lastState1 = NORMAL_STATE;

int button2_flag = 0;
int firstRead2 = NORMAL_STATE;
int secondRead2 = NORMAL_STATE;
int thirdRead2 = NORMAL_STATE;
int lastState2 = NORMAL_STATE;

int button3_flag = 0;
int firstRead3 = NORMAL_STATE;
int secondRead3 = NORMAL_STATE;
int thirdRead3 = NORMAL_STATE;
int lastState3 = NORMAL_STATE;

int timeLongPress1 = 200;			// long press 2s
int timeLongPress2 = 200;
int timeLongPress3 = 200;

int isButton1Pressed(){
	if (button1_flag) {
		button1_flag = 0;
		return 1;
	}
	return 0;
}

int isButton2Pressed(){
	if (button2_flag) {
		button2_flag = 0;
		return 1;
	}
	return 0;
}

int isButton3Pressed(){
	if (button3_flag) {
		button3_flag = 0;
		return 1;
	}
	return 0;
}

void readButton1() {
	firstRead1 = secondRead1;
	secondRead1 = thirdRead1;
	thirdRead1 = HAL_GPIO_ReadPin(button1_GPIO_Port, button1_Pin);

	if ((firstRead1 == secondRead1) && (secondRead1 == thirdRead1)) {
		if (lastState1 != thirdRead1) {
			lastState1 = thirdRead1;
			if (thirdRead1 == PRESSED_STATE) {
				button1_flag = 1;
				timeLongPress1 = 200;
			}
		}
		else {
			timeLongPress1--;
			if (timeLongPress1 == 0) {
				lastState1 = NORMAL_STATE;
			}
		}
	}
}

void readButton2() {
	firstRead2 = secondRead2;
	secondRead2 = thirdRead2;
	thirdRead2 = HAL_GPIO_ReadPin(button2_GPIO_Port, button2_Pin);

	if ((firstRead2 == secondRead2) && (secondRead2 == thirdRead2)) {
		if (lastState2 != thirdRead2) {
			lastState2 = thirdRead2;
			if (thirdRead2 == PRESSED_STATE) {
				button2_flag = 1;
				timeLongPress2 = 200;
			}
		}
		else {
			timeLongPress2--;
			if (timeLongPress2 == 0) {
				lastState2 = NORMAL_STATE;
			}
		}
	}
}

void readButton3() {
	firstRead3 = secondRead3;
	secondRead3 = thirdRead3;
	thirdRead3 = HAL_GPIO_ReadPin(button3_GPIO_Port, button3_Pin);

	if ((firstRead3 == secondRead3) && (secondRead3 == thirdRead3)) {
		if (lastState3 != thirdRead3) {
			lastState3 = thirdRead3;
			if (thirdRead3 == PRESSED_STATE) {
				button3_flag = 1;
				timeLongPress3 = 200;
			}
		}
		else {
			timeLongPress3--;
			if (timeLongPress3 == 0) {
				lastState3 = NORMAL_STATE;
			}
		}
	}
}
