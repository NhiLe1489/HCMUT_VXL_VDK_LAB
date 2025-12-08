/*
 * command_parser.h
 *
 *  Created on: Nov 18, 2025
 *      Author: HP PAVILION
 */

#ifndef INC_COMMAND_PARSER_H_
#define INC_COMMAND_PARSER_H_

#include <stdint.h>

#define CMD_NONE   0			// Invalid command
#define CMD_RST    1
#define CMD_OK     2

enum {
    CMD_WAIT_START,				// Wait for '!'
    CMD_RECEIVE					// Receive until '#'
};

extern uint8_t command_flag;	// active when receive valid command
extern uint8_t command_data;	// CMD_RST / CMD_OK / CMD_NONE

extern uint8_t temp;

void command_parser_reset();
void command_parser_fsm();

#endif /* INC_COMMAND_PARSER_H_ */
