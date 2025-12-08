/*
 * uart_communication.c
 *
 *  Created on: Nov 18, 2025
 *      Author: HP PAVILION
 */

#include "uart_communication.h"
#include "command_parser.h"
#include "timer.h"
#include "main.h"
#include <stdio.h>
#include <string.h>

static uint8_t uart_state = UART_IDLE;
static char uart_packet[30];

extern UART_HandleTypeDef huart2;

uint16_t ADC_value = 0;

void uart_send_string(char *s) {
    HAL_UART_Transmit(&huart2, (uint8_t*)s, strlen(s), 50);
}

void uart_communication_fsm() {

    switch (uart_state) {

    case UART_IDLE:
        if (command_flag == 1 && command_data == CMD_RST) {
            command_flag = 0;

            sprintf(uart_packet, "!ADC=%u#", ADC_value);
            uart_send_string(uart_packet);
            setTimer1(300);

            uart_state = UART_WAIT_OK;
        }
        break;

    case UART_WAIT_OK:
        if (command_flag == 1 && command_data == CMD_OK) {
            command_flag = 0;

            setTimer1(0);				// stop waiting
            uart_state = UART_IDLE;
        }
        else if (timer1_flag == 1) {
            uart_send_string(uart_packet);
            setTimer1(300);
        }
        break;
    }
}

