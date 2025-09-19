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
#define pin_12_Pin GPIO_PIN_4
#define pin_12_GPIO_Port GPIOA
#define pin_1_Pin GPIO_PIN_5
#define pin_1_GPIO_Port GPIOA
#define pin_2_Pin GPIO_PIN_6
#define pin_2_GPIO_Port GPIOA
#define pin_3_Pin GPIO_PIN_7
#define pin_3_GPIO_Port GPIOA
#define pin_4_Pin GPIO_PIN_8
#define pin_4_GPIO_Port GPIOA
#define pin_5_Pin GPIO_PIN_9
#define pin_5_GPIO_Port GPIOA
#define pin_6_Pin GPIO_PIN_10
#define pin_6_GPIO_Port GPIOA
#define pin_7_Pin GPIO_PIN_11
#define pin_7_GPIO_Port GPIOA
#define pin_8_Pin GPIO_PIN_12
#define pin_8_GPIO_Port GPIOA
#define pin_9_Pin GPIO_PIN_13
#define pin_9_GPIO_Port GPIOA
#define pin_10_Pin GPIO_PIN_14
#define pin_10_GPIO_Port GPIOA
#define pin_11_Pin GPIO_PIN_15
#define pin_11_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
