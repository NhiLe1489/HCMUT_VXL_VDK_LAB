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
#define enm0_Pin GPIO_PIN_2
#define enm0_GPIO_Port GPIOA
#define enm1_Pin GPIO_PIN_3
#define enm1_GPIO_Port GPIOA
#define DOT_Pin GPIO_PIN_4
#define DOT_GPIO_Port GPIOA
#define LED_RED_Pin GPIO_PIN_5
#define LED_RED_GPIO_Port GPIOA
#define en_0_Pin GPIO_PIN_6
#define en_0_GPIO_Port GPIOA
#define en_1_Pin GPIO_PIN_7
#define en_1_GPIO_Port GPIOA
#define seg_a_Pin GPIO_PIN_0
#define seg_a_GPIO_Port GPIOB
#define seg_b_Pin GPIO_PIN_1
#define seg_b_GPIO_Port GPIOB
#define seg_c_Pin GPIO_PIN_2
#define seg_c_GPIO_Port GPIOB
#define row2_Pin GPIO_PIN_10
#define row2_GPIO_Port GPIOB
#define row3_Pin GPIO_PIN_11
#define row3_GPIO_Port GPIOB
#define row4_Pin GPIO_PIN_12
#define row4_GPIO_Port GPIOB
#define row5_Pin GPIO_PIN_13
#define row5_GPIO_Port GPIOB
#define row6_Pin GPIO_PIN_14
#define row6_GPIO_Port GPIOB
#define row7_Pin GPIO_PIN_15
#define row7_GPIO_Port GPIOB
#define en_2_Pin GPIO_PIN_8
#define en_2_GPIO_Port GPIOA
#define en_3_Pin GPIO_PIN_9
#define en_3_GPIO_Port GPIOA
#define enm2_Pin GPIO_PIN_10
#define enm2_GPIO_Port GPIOA
#define enm3_Pin GPIO_PIN_11
#define enm3_GPIO_Port GPIOA
#define enm4_Pin GPIO_PIN_12
#define enm4_GPIO_Port GPIOA
#define enm5_Pin GPIO_PIN_13
#define enm5_GPIO_Port GPIOA
#define enm6_Pin GPIO_PIN_14
#define enm6_GPIO_Port GPIOA
#define enm7_Pin GPIO_PIN_15
#define enm7_GPIO_Port GPIOA
#define seg_d_Pin GPIO_PIN_3
#define seg_d_GPIO_Port GPIOB
#define seg_e_Pin GPIO_PIN_4
#define seg_e_GPIO_Port GPIOB
#define seg_f_Pin GPIO_PIN_5
#define seg_f_GPIO_Port GPIOB
#define seg_g_Pin GPIO_PIN_6
#define seg_g_GPIO_Port GPIOB
#define row0_Pin GPIO_PIN_8
#define row0_GPIO_Port GPIOB
#define row1_Pin GPIO_PIN_9
#define row1_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
