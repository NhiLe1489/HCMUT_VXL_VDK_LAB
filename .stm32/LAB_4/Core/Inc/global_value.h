/*
 * global_value.h
 *
 *  Created on: Oct 12, 2025
 *      Author: HP PAVILION
 */

#ifndef INC_GLOBAL_VALUE_H_
#define INC_GLOBAL_VALUE_H_
#include "fsm_automatic.h"
#include "main.h"
#include "display_led.h"
#include "button.h"
#include "fsm_manual.h"

#include "software_timer.h"

#define INIT_STATE 1
#define RED_STATE 2
#define GREEN_STATE 3
#define YELLOW_STATE 4

#define MODE_1 11
#define MODE_2 12
#define MODE_3 13
#define MODE_4 14
#define MODE_HANDLE 15

extern int LED_STATE [2];
extern int MODE;
extern int RED_DURATION;
extern int YELLOW_DURATION;
extern int GREEN_DURATION;
extern int new_RED, new_YELLOW, new_GREEN;
extern int editing;
extern int handle_pattern;
extern int tempDuration;

#endif /* INC_GLOBAL_VALUE_H_ */
