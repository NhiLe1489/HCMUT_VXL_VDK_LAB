/*
 * fsm_automatic.c
 *
 *  Created on: Oct 12, 2025
 *      Author: HP PAVILION
 */


#include "fsm_automatic.h"

void fsm_automatic(int lane){
	if (timerCounter[lane] % 100 == 0){
		int remaining_time = timerCounter[lane] / 100;
		display7SEG(lane*2, remaining_time % 10);
		display7SEG(lane*2+1, (int) (remaining_time / 10));
	}
	switch(LED_STATE[lane]){
		case INIT_STATE:
			setTrafficLightDefault(lane);
			if (lane == 0){
				LED_STATE[lane] = RED_STATE;
				setTimer(lane, RED_DURATION*100);
			}
			else{
				LED_STATE[lane] = GREEN_STATE;
				setTimer(lane, GREEN_DURATION*100);
			}
			break;
		case RED_STATE:
			setRed_LED(lane);
			if(timer_flag[lane] == 1){
				LED_STATE[lane] = GREEN_STATE;
				setTimer(lane, GREEN_DURATION*100);
			}
			break;
		case GREEN_STATE:
			setGreen_LED(lane);
			if(timer_flag[lane] == 1){
				LED_STATE[lane] = YELLOW_STATE;
				setTimer(lane, YELLOW_DURATION*100);
			}
			break;
		case YELLOW_STATE:
			setAmber_LED(lane);
			if(timer_flag[lane] == 1){
				LED_STATE[lane] = RED_STATE;
				setTimer(lane, RED_DURATION*100);
			}
			break;
		default:
			break;
	}
}
void fsm_automatic_run(){
	if(MODE == MODE_1){
		fsm_automatic(0);
		fsm_automatic(1);
	    if (isButtonPressed(0) == 1){
	    	start_edit_session();
	        tempDuration = RED_DURATION;
	        changeMode(MODE_2);
	    }
	    if (isButtonPressed(3) == 1){
			changeMode(MODE_HANDLE);
			handle_pattern = 0;
			handle_apply_initial();
			display7SEG_off_all();
			setTimer(2, 25);
		}
	}
}
