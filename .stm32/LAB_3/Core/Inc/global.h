/*
 * global.h
 *  @brief          : _run functions and sub-functions
 *  @created on     : Oct 16, 2025
 *  @author         : HP PAVILION
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "timer.h"

typedef enum
{
	INIT,
	AUTO_RED_GREEN,
	AUTO_RED_YELLOW,
	AUTO_GREEN_RED,
	AUTO_YELLOW_RED,
	SET_RED,
	SET_YELLOW,
	SET_GREEN
} state_t;

typedef enum
{
	RED,
	YELLOW,
	GREEN
} color_t;

extern state_t state;
extern int numDisplay[4];
extern int counter;			// For setCounter()
extern int count1;
extern int count2;
extern int index_led;

extern int redCount;
extern int yellowCount;
extern int greenCount;


void ledRed1_ON();
void ledGreen1_ON();
void ledYellow1_ON();
void ledRed2_ON();
void ledGreen2_ON();
void ledYellow2_ON();

void display7SEG(int num);
void update7SEG(int index);

void updateLedBuffer(int counter1, int counter2);
void setCounter(color_t color, int mode);
void checkLightsLogic();

#endif /* INC_GLOBAL_H_ */
