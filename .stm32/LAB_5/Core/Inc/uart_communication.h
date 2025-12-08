/*
 * uart_communication.h
 *
 *  Created on: Nov 18, 2025
 *      Author: HP PAVILION
 */

#ifndef INC_UART_COMMUNICATION_H_
#define INC_UART_COMMUNICATION_H_

#include <stdint.h>

enum {
    UART_IDLE,
    UART_WAIT_OK
};

extern uint8_t command_flag;
extern uint8_t command_data;
extern uint16_t ADC_value;

void uart_communication_fsm();

#endif /* INC_UART_COMMUNICATION_H_ */
