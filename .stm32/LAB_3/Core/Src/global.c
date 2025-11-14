/*
 * global.c
 *
 *  Created on: Oct 16, 2025
 *      Author: HP PAVILION
 */

#include "global.h"

state_t state = INIT;
int numDisplay[4];
int counter = 1;			// For setCounter()
int count1 = 0;
int count2 = 0;
int index_led = 0;

int redCount = 5;
int yellowCount = 2;
int greenCount = 3;

void ledRed1_ON() {
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, 1);
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, 0);
	HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, 0);
}

void ledGreen1_ON() {
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, 0);
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, 1);
	HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, 0);
}

void ledYellow1_ON() {
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, 0);
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, 0);
	HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, 1);
}

void ledRed2_ON() {
	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, 1);
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, 0);
	HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, 0);
}

void ledGreen2_ON() {
	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, 0);
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, 1);
	HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, 0);
}

void ledYellow2_ON() {
	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, 0);
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, 0);
	HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, 1);
}

void display7SEG(int num) {
	switch (num) {
	case 0:
		HAL_GPIO_WritePin(seg_a_GPIO_Port, seg_a_Pin, 0);
		HAL_GPIO_WritePin(seg_b_GPIO_Port, seg_b_Pin, 0);
		HAL_GPIO_WritePin(seg_c_GPIO_Port, seg_c_Pin, 0);
		HAL_GPIO_WritePin(seg_d_GPIO_Port, seg_d_Pin, 0);
		HAL_GPIO_WritePin(seg_e_GPIO_Port, seg_e_Pin, 0);
		HAL_GPIO_WritePin(seg_f_GPIO_Port, seg_f_Pin, 0);
		HAL_GPIO_WritePin(seg_g_GPIO_Port, seg_g_Pin, 1);
		break;
	case 1:
		HAL_GPIO_WritePin(seg_a_GPIO_Port, seg_a_Pin, 1);
		HAL_GPIO_WritePin(seg_b_GPIO_Port, seg_b_Pin, 0);
		HAL_GPIO_WritePin(seg_c_GPIO_Port, seg_c_Pin, 0);
		HAL_GPIO_WritePin(seg_d_GPIO_Port, seg_d_Pin, 1);
		HAL_GPIO_WritePin(seg_e_GPIO_Port, seg_e_Pin, 1);
		HAL_GPIO_WritePin(seg_f_GPIO_Port, seg_f_Pin, 1);
		HAL_GPIO_WritePin(seg_g_GPIO_Port, seg_g_Pin, 1);
		break;
	case 2:
		HAL_GPIO_WritePin(seg_a_GPIO_Port, seg_a_Pin, 0);
		HAL_GPIO_WritePin(seg_b_GPIO_Port, seg_b_Pin, 0);
		HAL_GPIO_WritePin(seg_c_GPIO_Port, seg_c_Pin, 1);
		HAL_GPIO_WritePin(seg_d_GPIO_Port, seg_d_Pin, 0);
		HAL_GPIO_WritePin(seg_e_GPIO_Port, seg_e_Pin, 0);
		HAL_GPIO_WritePin(seg_f_GPIO_Port, seg_f_Pin, 1);
		HAL_GPIO_WritePin(seg_g_GPIO_Port, seg_g_Pin, 0);
		break;
	case 3:
		HAL_GPIO_WritePin(seg_a_GPIO_Port, seg_a_Pin, 0);
		HAL_GPIO_WritePin(seg_b_GPIO_Port, seg_b_Pin, 0);
		HAL_GPIO_WritePin(seg_c_GPIO_Port, seg_c_Pin, 0);
		HAL_GPIO_WritePin(seg_d_GPIO_Port, seg_d_Pin, 0);
		HAL_GPIO_WritePin(seg_e_GPIO_Port, seg_e_Pin, 1);
		HAL_GPIO_WritePin(seg_f_GPIO_Port, seg_f_Pin, 1);
		HAL_GPIO_WritePin(seg_g_GPIO_Port, seg_g_Pin, 0);
		break;
	case 4:
		HAL_GPIO_WritePin(seg_a_GPIO_Port, seg_a_Pin, 1);
		HAL_GPIO_WritePin(seg_b_GPIO_Port, seg_b_Pin, 0);
		HAL_GPIO_WritePin(seg_c_GPIO_Port, seg_c_Pin, 0);
		HAL_GPIO_WritePin(seg_d_GPIO_Port, seg_d_Pin, 1);
		HAL_GPIO_WritePin(seg_e_GPIO_Port, seg_e_Pin, 1);
		HAL_GPIO_WritePin(seg_f_GPIO_Port, seg_f_Pin, 0);
		HAL_GPIO_WritePin(seg_g_GPIO_Port, seg_g_Pin, 0);
		break;
	case 5:
		HAL_GPIO_WritePin(seg_a_GPIO_Port, seg_a_Pin, 0);
		HAL_GPIO_WritePin(seg_b_GPIO_Port, seg_b_Pin, 1);
		HAL_GPIO_WritePin(seg_c_GPIO_Port, seg_c_Pin, 0);
		HAL_GPIO_WritePin(seg_d_GPIO_Port, seg_d_Pin, 0);
		HAL_GPIO_WritePin(seg_e_GPIO_Port, seg_e_Pin, 1);
		HAL_GPIO_WritePin(seg_f_GPIO_Port, seg_f_Pin, 0);
		HAL_GPIO_WritePin(seg_g_GPIO_Port, seg_g_Pin, 0);
		break;
	case 6:
		HAL_GPIO_WritePin(seg_a_GPIO_Port, seg_a_Pin, 0);
		HAL_GPIO_WritePin(seg_b_GPIO_Port, seg_b_Pin, 1);
		HAL_GPIO_WritePin(seg_c_GPIO_Port, seg_c_Pin, 0);
		HAL_GPIO_WritePin(seg_d_GPIO_Port, seg_d_Pin, 0);
		HAL_GPIO_WritePin(seg_e_GPIO_Port, seg_e_Pin, 0);
		HAL_GPIO_WritePin(seg_f_GPIO_Port, seg_f_Pin, 0);
		HAL_GPIO_WritePin(seg_g_GPIO_Port, seg_g_Pin, 0);
		break;
	case 7:
		HAL_GPIO_WritePin(seg_a_GPIO_Port, seg_a_Pin, 0);
		HAL_GPIO_WritePin(seg_b_GPIO_Port, seg_b_Pin, 0);
		HAL_GPIO_WritePin(seg_c_GPIO_Port, seg_c_Pin, 0);
		HAL_GPIO_WritePin(seg_d_GPIO_Port, seg_d_Pin, 1);
		HAL_GPIO_WritePin(seg_e_GPIO_Port, seg_e_Pin, 1);
		HAL_GPIO_WritePin(seg_f_GPIO_Port, seg_f_Pin, 1);
		HAL_GPIO_WritePin(seg_g_GPIO_Port, seg_g_Pin, 1);
		break;
	case 8:
		HAL_GPIO_WritePin(seg_a_GPIO_Port, seg_a_Pin, 0);
		HAL_GPIO_WritePin(seg_b_GPIO_Port, seg_b_Pin, 0);
		HAL_GPIO_WritePin(seg_c_GPIO_Port, seg_c_Pin, 0);
		HAL_GPIO_WritePin(seg_d_GPIO_Port, seg_d_Pin, 0);
		HAL_GPIO_WritePin(seg_e_GPIO_Port, seg_e_Pin, 0);
		HAL_GPIO_WritePin(seg_f_GPIO_Port, seg_f_Pin, 0);
		HAL_GPIO_WritePin(seg_g_GPIO_Port, seg_g_Pin, 0);
		break;
	case 9:
		HAL_GPIO_WritePin(seg_a_GPIO_Port, seg_a_Pin, 0);
		HAL_GPIO_WritePin(seg_b_GPIO_Port, seg_b_Pin, 0);
		HAL_GPIO_WritePin(seg_c_GPIO_Port, seg_c_Pin, 0);
		HAL_GPIO_WritePin(seg_d_GPIO_Port, seg_d_Pin, 0);
		HAL_GPIO_WritePin(seg_e_GPIO_Port, seg_e_Pin, 1);
		HAL_GPIO_WritePin(seg_f_GPIO_Port, seg_f_Pin, 0);
		HAL_GPIO_WritePin(seg_g_GPIO_Port, seg_g_Pin, 0);
		break;
	default:
		HAL_GPIO_WritePin(seg_a_GPIO_Port, seg_a_Pin, 1);
		HAL_GPIO_WritePin(seg_b_GPIO_Port, seg_b_Pin, 1);
		HAL_GPIO_WritePin(seg_c_GPIO_Port, seg_c_Pin, 1);
		HAL_GPIO_WritePin(seg_d_GPIO_Port, seg_d_Pin, 1);
		HAL_GPIO_WritePin(seg_e_GPIO_Port, seg_e_Pin, 1);
		HAL_GPIO_WritePin(seg_f_GPIO_Port, seg_f_Pin, 1);
		HAL_GPIO_WritePin(seg_g_GPIO_Port, seg_g_Pin, 1);
	}
}

void update7SEG(int index) {
	switch (index){
		case 0:
			HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, 0);
			HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, 1);
			HAL_GPIO_WritePin(en2_GPIO_Port, en2_Pin, 1);
			HAL_GPIO_WritePin(en3_GPIO_Port, en3_Pin, 1);
			display7SEG(numDisplay[0]);
			break;
		case 1:
			HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, 1);
			HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, 0);
			HAL_GPIO_WritePin(en2_GPIO_Port, en2_Pin, 1);
			HAL_GPIO_WritePin(en3_GPIO_Port, en3_Pin, 1);
			display7SEG(numDisplay[1]);
			break;
		case 2:
			HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, 1);
			HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, 1);
			HAL_GPIO_WritePin(en2_GPIO_Port, en2_Pin, 0);
			HAL_GPIO_WritePin(en3_GPIO_Port, en3_Pin, 1);
			display7SEG(numDisplay[2]);
			break;
		case 3:
			HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, 1);
			HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, 1);
			HAL_GPIO_WritePin(en2_GPIO_Port, en2_Pin, 1);
			HAL_GPIO_WritePin(en3_GPIO_Port, en3_Pin, 0);
			display7SEG(numDisplay[3]);
			break;
		default:
			display7SEG(9);
	}
}

void updateLedBuffer(int counter1, int counter2) {
    numDisplay[0] = counter1 / 10;
    numDisplay[1] = counter1 % 10;
    numDisplay[2] = counter2 / 10;
    numDisplay[3] = counter2 % 10;
}

void setCounter(color_t color, int mode) {		// Switching time: 0.25s, set and display blink leds, mode, counter
	static int index = 0;
	numDisplay[0] = 0;
	numDisplay[1] = mode;

	// SET
	switch (color) {
		case RED:
			HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, 0);
			HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, 0);
			HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, 0);
			HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, 0);

			HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, 1);
			HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, 1);

			if (isButton2Pressed()) {
				counter++;
			}
			numDisplay[2] = counter / 10;
			numDisplay[3] = counter % 10;
			break;

		case YELLOW:
			HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, 0);
			HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, 0);
			HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, 0);
			HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, 0);

			HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, 1);
			HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, 1);

			if (isButton2Pressed()) {
				counter++;
			}
			numDisplay[2] = counter / 10;
			numDisplay[3] = counter % 10;
			break;

		case GREEN:
			HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, 0);
			HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, 0);
			HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, 0);
			HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, 0);

			HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, 1);
			HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, 1);

			if (isButton2Pressed()) {
				counter++;
			}
			numDisplay[2] = counter / 10;
			numDisplay[3] = counter % 10;
			break;

		default:
			break;
	}

	// DISPLAY
	if (timer2_flag) {
		update7SEG(index);
		index = (index + 1) % 4;

		switch (color) {
			case RED:
				HAL_GPIO_TogglePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin);
				HAL_GPIO_TogglePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin);
				break;

			case YELLOW:
				HAL_GPIO_TogglePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin);
				HAL_GPIO_TogglePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin);
				break;

			case GREEN:
				HAL_GPIO_TogglePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin);
				HAL_GPIO_TogglePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin);
				break;

			default:
				break;
		}
		setTimer2(25);
	}
}

void checkLightsLogic() {
	if (redCount != greenCount + yellowCount) {
		redCount = 5;
		yellowCount = 2;
		greenCount = 3;
	}
}
