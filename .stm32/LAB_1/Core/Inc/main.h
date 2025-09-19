/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_RED_1_Pin GPIO_PIN_5
#define LED_RED_1_GPIO_Port GPIOA
#define LED_YELLOW_1_Pin GPIO_PIN_6
#define LED_YELLOW_1_GPIO_Port GPIOA
#define LED_GREEN_1_Pin GPIO_PIN_7
#define LED_GREEN_1_GPIO_Port GPIOA
#define seg_a_1_Pin GPIO_PIN_0
#define seg_a_1_GPIO_Port GPIOB
#define seg_b_1_Pin GPIO_PIN_1
#define seg_b_1_GPIO_Port GPIOB
#define seg_c_1_Pin GPIO_PIN_2
#define seg_c_1_GPIO_Port GPIOB
#define seg_d_2_Pin GPIO_PIN_10
#define seg_d_2_GPIO_Port GPIOB
#define seg_e_2_Pin GPIO_PIN_11
#define seg_e_2_GPIO_Port GPIOB
#define seg_f_2_Pin GPIO_PIN_12
#define seg_f_2_GPIO_Port GPIOB
#define seg_g_2_Pin GPIO_PIN_13
#define seg_g_2_GPIO_Port GPIOB
#define LED_RED_2_Pin GPIO_PIN_8
#define LED_RED_2_GPIO_Port GPIOA
#define LED_YELLOW_2_Pin GPIO_PIN_9
#define LED_YELLOW_2_GPIO_Port GPIOA
#define LED_GREEN_2_Pin GPIO_PIN_10
#define LED_GREEN_2_GPIO_Port GPIOA
#define seg_d_1_Pin GPIO_PIN_3
#define seg_d_1_GPIO_Port GPIOB
#define seg_e_1_Pin GPIO_PIN_4
#define seg_e_1_GPIO_Port GPIOB
#define seg_f_1_Pin GPIO_PIN_5
#define seg_f_1_GPIO_Port GPIOB
#define seg_g_1_Pin GPIO_PIN_6
#define seg_g_1_GPIO_Port GPIOB
#define seg_a_2_Pin GPIO_PIN_7
#define seg_a_2_GPIO_Port GPIOB
#define seg_b_2_Pin GPIO_PIN_8
#define seg_b_2_GPIO_Port GPIOB
#define seg_c_2_Pin GPIO_PIN_9
#define seg_c_2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
