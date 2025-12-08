/*
 * global_value.c
 *
 *  Created on: Oct 12, 2025
 *      Author: HP PAVILION
 */

#include "global_value.h"

int LED_STATE [2] = {INIT_STATE, INIT_STATE};
int MODE = MODE_1;


int RED_DURATION = 5;
int YELLOW_DURATION = 2;
int GREEN_DURATION = 3;
int new_RED, new_YELLOW, new_GREEN;
int editing = 0;
int handle_pattern = 0;
int tempDuration = 0;
