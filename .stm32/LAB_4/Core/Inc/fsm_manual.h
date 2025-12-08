/*
 * fsm_manual.h
 *
 *  Created on: Oct 12, 2025
 *      Author: HP PAVILION
 */

#ifndef INC_FSM_MANUAL_H_
#define INC_FSM_MANUAL_H_

#include "fsm_manual.h"
#include "global_value.h"
#include "display_led.h"
#include "fsm_automatic.h"
#include "software_timer.h"

void fsm_manual();
int is_valid_combo(int red, int green, int yellow) ;
void start_edit_session();
void changeMode(int mode);
void handle_apply_initial(void);
void end_edit_session_and_maybe_commit(void);
void displayDuration(int mode, int duration);

#endif /* INC_FSM_MANUAL_H_ */
