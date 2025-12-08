/*
 * software_timer.h
 *
 *  Created on: Oct 12, 2025
 *      Author: HP PAVILION
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include <global_value.h>


extern int timerCounter[4];
extern int timer_flag[4]   ;

void setTimer(int type, int duration);

void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
