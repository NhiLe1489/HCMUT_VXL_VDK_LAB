/*
 * fsm.c
 *
 *  Created on: Oct 16, 2025
 *      Author: HP PAVILION
 */

#include "fsm.h"
#include "global.h"

void fsmRun() {
	switch (state) {
	case INIT:
		HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, 0);
		HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, 0);
		HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, 0);
		HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, 0);
		HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, 0);
		HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, 0);

		if (timer1_flag) {
			state = AUTO_RED_GREEN;
			count1 = redCount - 1;
			count2 = greenCount - 1;
			updateLedBuffer(redCount - 1, greenCount - 1);
			index_led = 0;
			update7SEG(index_led);
			setTimer1(100*greenCount);
			setTimer2(25);
			setTimer3(100);
		}
		break;

	case AUTO_RED_GREEN:
		ledRed1_ON();
		ledGreen2_ON();

		if (timer2_flag) {
			index_led = (index_led + 1) % 4;
			update7SEG(index_led);					// Display led
			setTimer2(25);							// Scan led
		}
		if (timer3_flag) {
			count1--;
			count2--;
			updateLedBuffer(count1, count2);
			setTimer3(100);							// Update counter
		}

		if (timer1_flag && !isButton1Pressed()) {
			state = AUTO_RED_YELLOW;
			count1 = yellowCount - 1;
			count2 = yellowCount - 1;
			updateLedBuffer(yellowCount - 1, yellowCount - 1);
			index_led = 0;
			update7SEG(index_led);
			setTimer1(100*yellowCount);
			setTimer2(25);
			setTimer3(100);
		}
		if (isButton1Pressed()) {
			state = SET_RED;
			setTimer1(4000);
		}
		break;

	case AUTO_RED_YELLOW:
		ledRed1_ON();
		ledYellow2_ON();

		if (timer2_flag) {
			index_led = (index_led + 1) % 4;
			update7SEG(index_led);
			setTimer2(25);
		}
		if (timer3_flag) {
			count1--;
			count2--;
			updateLedBuffer(count1, count2);
			setTimer3(100);
		}

		if (timer1_flag && !isButton1Pressed()) {
			state = AUTO_GREEN_RED;
			count1 = greenCount - 1;
			count2 = redCount - 1;
			updateLedBuffer(greenCount - 1, redCount - 1);
			index_led = 0;
			update7SEG(index_led);
			setTimer1(100*greenCount);
			setTimer2(25);
			setTimer3(100);
		}
		if (isButton1Pressed()) {
			state = SET_RED;
			setTimer1(4000);
		}
		break;

	case AUTO_GREEN_RED:
		ledGreen1_ON();
		ledRed2_ON();

		if (timer2_flag) {
			index_led = (index_led + 1) % 4;
			update7SEG(index_led);
			setTimer2(25);
		}
		if (timer3_flag) {
			count1--;
			count2--;
			updateLedBuffer(count1, count2);
			setTimer3(100);
		}

		if (timer1_flag && !isButton1Pressed()) {
			state = AUTO_YELLOW_RED;
			count1 = yellowCount - 1;
			count2 = yellowCount - 1;
			updateLedBuffer(yellowCount - 1, yellowCount - 1);
			index_led = 0;
			update7SEG(index_led);
			setTimer1(100*yellowCount);
			setTimer2(25);
			setTimer3(100);
		}
		if (isButton1Pressed()) {
			state = SET_RED;
			setTimer1(4000);
		}
		break;

	case AUTO_YELLOW_RED:
		ledYellow1_ON();
		ledRed2_ON();

		if (timer2_flag) {
			index_led = (index_led + 1) % 4;
			update7SEG(index_led);
			setTimer2(25);
		}
		if (timer3_flag) {
			count1--;
			count2--;
			updateLedBuffer(count1, count2);
			setTimer3(100);
		}

		if (timer1_flag && !isButton1Pressed()) {
			state = AUTO_RED_GREEN;
			count1 = redCount - 1;
			count2 = greenCount - 1;
			updateLedBuffer(redCount - 1, greenCount - 1);
			index_led = 0;
			update7SEG(index_led);
			setTimer1(100*greenCount);
			setTimer2(25);
			setTimer3(100);
		}
		if (isButton1Pressed()) {
			state = SET_RED;
			setTimer1(4000);
		}
		break;

	case SET_RED:
		setCounter(RED, 2);

		if (isButton3Pressed()) {					// Save new counter value
			redCount = counter;
		}
		if (isButton1Pressed()) {					// Change state
			counter = 1;
			state = SET_YELLOW;
			setTimer1(4000);
		}
		if (timer1_flag) {							// If time-out
			checkLightsLogic();
			counter = 1;

			state = AUTO_RED_GREEN;
			count1 = redCount - 1;
			count2 = greenCount - 1;
			updateLedBuffer(redCount - 1, greenCount - 1);
			index_led = 0;
			update7SEG(index_led);
			setTimer1(100*greenCount);
			setTimer2(25);
			setTimer3(100);
		}
		break;

	case SET_YELLOW:
		setCounter(YELLOW, 3);

		if (isButton3Pressed()) {
			yellowCount = counter;
		}
		if (isButton1Pressed()) {
			counter = 1;
			state = SET_GREEN;
			setTimer1(4000);
		}
		if (timer1_flag) {
			checkLightsLogic();
			counter = 1;

			state = AUTO_RED_GREEN;
			count1 = redCount - 1;
			count2 = greenCount - 1;
			updateLedBuffer(redCount - 1, greenCount - 1);
			index_led = 0;
			update7SEG(index_led);
			setTimer1(100*greenCount);
			setTimer2(25);
			setTimer3(100);
		}
		break;

	case SET_GREEN:
		setCounter(GREEN, 4);

		if (isButton3Pressed()) {
			greenCount = counter;
		}
		if (isButton1Pressed() || timer1_flag) {
			checkLightsLogic();
			counter = 1;

			state = AUTO_RED_GREEN;
			count1 = redCount - 1;
			count2 = greenCount - 1;
			updateLedBuffer(redCount - 1, greenCount - 1);
			index_led = 0;
			update7SEG(index_led);
			setTimer1(100*greenCount);
			setTimer2(25);
			setTimer3(100);
		}
		break;

	default:
		break;
	}
}
