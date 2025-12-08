/*
 * display_led.c
 *
 *  Created on: Oct 12, 2025
 *      Author: HP PAVILION
 */


#include "display_led.h"

int16_t REDLIGHT [2] = {RED1_Pin, RED2_Pin};
uint16_t GREENLIGHT [2] = {GREEN1_Pin, GREEN2_Pin};
uint16_t AMBERLIGHT [2] = {YELLOW1_Pin, YELLOW2_Pin};
uint16_t BIT [16] = {BIT0_Pin, BIT1_Pin, BIT2_Pin, BIT3_Pin, BIT4_Pin,
		BIT5_Pin, BIT6_Pin, BIT7_Pin, BIT8_Pin, BIT9_Pin, BIT10_Pin,
		BIT11_Pin, BIT12_Pin, BIT13_Pin, BIT14_Pin, BIT15_Pin};

void setTrafficLightDefault(int lane){
	HAL_GPIO_WritePin(GPIOA, REDLIGHT[lane], SET);
	HAL_GPIO_WritePin(GPIOA, GREENLIGHT[lane], SET);
	HAL_GPIO_WritePin(GPIOA, AMBERLIGHT[lane], SET);
}

void setRed_LED (int lane){
	HAL_GPIO_WritePin(GPIOA, REDLIGHT[lane], GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GREENLIGHT[lane], GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, AMBERLIGHT[lane], GPIO_PIN_SET);
}
void setGreen_LED (int lane){
	HAL_GPIO_WritePin(GPIOA, REDLIGHT[lane], GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GREENLIGHT[lane], GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, AMBERLIGHT[lane], GPIO_PIN_SET);
}
void setAmber_LED (int lane){
	HAL_GPIO_WritePin(GPIOA, REDLIGHT[lane], GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GREENLIGHT[lane], GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, AMBERLIGHT[lane], GPIO_PIN_RESET);
}
void displaySEG(int bit, uint16_t type){
    GPIO_TypeDef *GPIO = (bit >= 9)? GPIOB : GPIOA;
    HAL_GPIO_WritePin(GPIO, BIT[bit], type);
}

void display7SEG(int type, int num){
	switch(num){
		case 0:
			displaySEG(type*4, GPIO_PIN_RESET);
			displaySEG(type*4+1, GPIO_PIN_RESET);
			displaySEG(type*4+2, GPIO_PIN_RESET);
			displaySEG(type*4+3, GPIO_PIN_RESET);
			break;
		case 1:
			displaySEG(type*4, GPIO_PIN_SET);
			displaySEG(type*4+1, GPIO_PIN_RESET);
			displaySEG(type*4+2, GPIO_PIN_RESET);
			displaySEG(type*4+3, GPIO_PIN_RESET);
			break;
		case 2:
			displaySEG(type*4, GPIO_PIN_RESET);
			displaySEG(type*4+1, GPIO_PIN_SET);
			displaySEG(type*4+2, GPIO_PIN_RESET);
			displaySEG(type*4+3, GPIO_PIN_RESET);
			break;
		case 3:
			displaySEG(type*4, GPIO_PIN_SET);
			displaySEG(type*4+1, GPIO_PIN_SET);
			displaySEG(type*4+2, GPIO_PIN_RESET);
			displaySEG(type*4+3, GPIO_PIN_RESET);
			break;
		case 4:
			displaySEG(type*4, GPIO_PIN_RESET);
			displaySEG(type*4+1, GPIO_PIN_RESET);
			displaySEG(type*4+2, GPIO_PIN_SET);
			displaySEG(type*4+3, GPIO_PIN_RESET);
			break;
		case 5:
			displaySEG(type*4, GPIO_PIN_SET);
			displaySEG(type*4+1, GPIO_PIN_RESET);
			displaySEG(type*4+2, GPIO_PIN_SET);
			displaySEG(type*4+3, GPIO_PIN_RESET);
			break;
		case 6:
			displaySEG(type*4, GPIO_PIN_RESET);
			displaySEG(type*4+1, GPIO_PIN_SET);
			displaySEG(type*4+2, GPIO_PIN_SET);
			displaySEG(type*4+3, GPIO_PIN_RESET);
			break;
		case 7:
			displaySEG(type*4, GPIO_PIN_SET);
			displaySEG(type*4+1, GPIO_PIN_SET);
			displaySEG(type*4+2, GPIO_PIN_SET);
			displaySEG(type*4+3, GPIO_PIN_RESET);
			break;
		case 8:
			displaySEG(type*4, GPIO_PIN_RESET);
			displaySEG(type*4+1, GPIO_PIN_RESET);
			displaySEG(type*4+2, GPIO_PIN_RESET);
			displaySEG(type*4+3, GPIO_PIN_SET);
			break;
		case 9:
			displaySEG(type*4, GPIO_PIN_SET);
			displaySEG(type*4+1, GPIO_PIN_RESET);
			displaySEG(type*4+2, GPIO_PIN_RESET);
			displaySEG(type*4+3, GPIO_PIN_SET);
			break;
		default:
			displaySEG(type*4, GPIO_PIN_RESET);
			displaySEG(type*4+1, GPIO_PIN_RESET);
			displaySEG(type*4+2, GPIO_PIN_RESET);
			displaySEG(type*4+3, GPIO_PIN_SET);
			break;
	}
}
void display7SEG_blank(int type){
    displaySEG(type*4,   GPIO_PIN_SET);
    displaySEG(type*4+1, GPIO_PIN_SET);
    displaySEG(type*4+2, GPIO_PIN_SET);
    displaySEG(type*4+3, GPIO_PIN_SET);
}
void display7SEG_off_all(){
    for (int i = 0; i < 16; ++i){
        GPIO_TypeDef *GPIO = (i >= 9) ? GPIOB : GPIOA;
        HAL_GPIO_WritePin(GPIO, BIT[i], GPIO_PIN_SET);
    }
}
