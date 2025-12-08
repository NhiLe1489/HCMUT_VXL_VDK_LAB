/*
 * fsm_manual.c
 *
 *  Created on: Oct 12, 2025
 *      Author: HP PAVILION
 */

#include "fsm_manual.h"


void handle_apply_initial(void) {

    setTrafficLightDefault(0);
    setTrafficLightDefault(1);

    if (handle_pattern == 0) {
        HAL_GPIO_WritePin(GPIOA, RED1_Pin,   RESET);
        HAL_GPIO_WritePin(GPIOA, GREEN2_Pin, RESET);
    } else {
        HAL_GPIO_WritePin(GPIOA, GREEN1_Pin, RESET);
        HAL_GPIO_WritePin(GPIOA, RED2_Pin,   RESET);
    }
}
int is_valid_combo(int red, int green, int yellow) {
   return ((red - green) == yellow);
}
void start_edit_session() {
   new_RED    = RED_DURATION;
   new_YELLOW = YELLOW_DURATION;
   new_GREEN  = GREEN_DURATION;
   editing = 1;
}

void changeMode(int mode){
	setTrafficLightDefault(0);
	setTrafficLightDefault(1);
	MODE = mode;
	setTimer(2, 25);
}

void end_edit_session_and_maybe_commit(void) {
    if (!editing) return;
    if (is_valid_combo(new_RED, new_GREEN, new_YELLOW)) {
        RED_DURATION    = new_RED;
        YELLOW_DURATION = new_YELLOW;
        GREEN_DURATION  = new_GREEN;
    }
    editing = 0;
}

void displayDuration(int mode, int duration){
	display7SEG(0, mode);
	display7SEG(1, 0);
	display7SEG(2, duration%10);
	display7SEG(3, (int) (duration/10));
}

void fsm_manual(){
	switch(MODE){
	case MODE_2:
		displayDuration(2, tempDuration);
		if (isButtonPressed(0) == 1){
			tempDuration = YELLOW_DURATION;
			changeMode(MODE_3);
		}
		if (isButtonPressed(1) == 1){
			tempDuration++;
			tempDuration %= 100;
		}
		if (isButtonPressed(2) == 1){
			new_RED = tempDuration;
		}
		if (timer_flag[2] == 1){
			HAL_GPIO_TogglePin(GPIOA, RED1_Pin);
			HAL_GPIO_TogglePin(GPIOA, RED2_Pin);
			setTimer(2, 25);
		}
		break;
	case MODE_3:
		displayDuration(3, tempDuration);
		if (isButtonPressed(0) == 1){
			tempDuration = GREEN_DURATION;
			changeMode(MODE_4);
		}
		if (isButtonPressed(1) == 1){
			tempDuration++;
			tempDuration %= 100;
		}
		if (isButtonPressed(2) == 1){
			new_YELLOW = tempDuration;
		}
		if (timer_flag[2] == 1){
			HAL_GPIO_TogglePin(GPIOA, YELLOW1_Pin);
			HAL_GPIO_TogglePin(GPIOA, YELLOW2_Pin);
			setTimer(2, 25);
		}
		break;
	case MODE_4:
		displayDuration(4, tempDuration);
		if (isButtonPressed(0) == 1){
			end_edit_session_and_maybe_commit();
			LED_STATE[0] = INIT_STATE;
			LED_STATE[1] = INIT_STATE;
			changeMode(MODE_1);
		}
		if (isButtonPressed(1) == 1){
			tempDuration++;
			tempDuration %= 100;
		}
		if (isButtonPressed(2) == 1){
			new_GREEN = tempDuration;
		}
		if (timer_flag[2] == 1){
			HAL_GPIO_TogglePin(GPIOA, GREEN1_Pin);
			HAL_GPIO_TogglePin(GPIOA, GREEN2_Pin);
			setTimer(2, 25);
		}
		break;


	}
}
