/*
 * task.c
 *
 *  Created on: Nov 12, 2025
 *      Author: HP PAVILION
 */
#include "task.h"

void TASK_LED_BLINK(void){
	HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
}

void TASK_ScanButtons(void) {
    for (int i = 0; i < 4; ++i) {
        getKeyInput(i);
    }
}
void TASK_SoftwareTimer(void) {
    timerRun();
}
void TASK_FSM(void) {
    fsm_automatic_run();
    fsm_manual();
}
