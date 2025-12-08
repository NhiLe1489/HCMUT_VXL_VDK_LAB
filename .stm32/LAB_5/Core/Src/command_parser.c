/*
 * command_parser.c
 *
 *  Created on: Nov 18, 2025
 *      Author: HP PAVILION
 */

#include "command_parser.h"
#include <string.h>

uint8_t command_flag = 0;
uint8_t command_data = CMD_NONE;

uint8_t parser_state = CMD_WAIT_START;
char cmd_buffer[10];
uint8_t cmd_index = 0;
extern uint8_t temp;

void command_parser_reset() {
    parser_state = CMD_WAIT_START;
    cmd_index = 0;
    command_flag = 0;
    command_data = CMD_NONE;
}

void command_parser_fsm() {

    switch (parser_state) {

    case CMD_WAIT_START:
        if (temp == '!') {
            cmd_index = 0;
            cmd_buffer[cmd_index++] = temp;
            parser_state = CMD_RECEIVE;
        }
        break;

    case CMD_RECEIVE:
        if (temp == 8) {						// backspace
            if (cmd_index > 1) {
                cmd_index--;
                cmd_buffer[cmd_index] = '\0';
            }
            break;
        }

        cmd_buffer[cmd_index++] = temp;

        if (cmd_index >= sizeof(cmd_buffer)) {
            command_parser_reset();
            break;
        }

        if (temp == '#') {
            cmd_buffer[cmd_index] = '\0';

            parser_state = CMD_WAIT_START;
            cmd_index = 0;

            if (strcmp(cmd_buffer, "!RST#") == 0) {
                command_flag = 1;
                command_data = CMD_RST;
            }
            else if (strcmp(cmd_buffer, "!OK#") == 0) {
                command_flag = 1;
                command_data = CMD_OK;
            }
            else {
                command_flag = 0;
                command_data = CMD_NONE;
            }
        }

        break;
    }
}
