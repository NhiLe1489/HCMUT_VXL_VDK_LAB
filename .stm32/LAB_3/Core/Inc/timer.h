/*
 * timer.h
 *
 *  Created on: Sep 30, 2025
 *      Author: HP PAVILION
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;

void setTimer1(int duration);		// Set time for each state
void setTimer2(int duration);		// 7-segment led scanning duration (0.25ms)
void setTimer3(int duration);		// 7-segment led update countdown values (1s)

void timerRun();

#endif /* INC_TIMER_H_ */
