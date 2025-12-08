/*
 * display_led.h
 *
 *  Created on: Oct 12, 2025
 *      Author: HP PAVILION
 */

#ifndef INC_DISPLAY_LED_H_
#define INC_DISPLAY_LED_H_

#include "main.h"
#include "fsm_manual.h"
#include "global_value.h"
#include "display_led.h"
#include "fsm_automatic.h"

void setTrafficLightDefault(int lane);
void setRed_LED(int lane);
void setGreen_LED(int lane);
void setAmber_LED(int lane);

void display7SEG(int type, int num);
void display7SEG_off_all();
#endif /* INC_DISPLAY_LED_H_ */
