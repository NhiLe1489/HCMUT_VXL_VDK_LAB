/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @course			: MPU - MCU
  * @lab number		: 1
  * @exercises		: 1 to 5
  * @brief          : traffic light + 7-segment led
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef enum {
	RED,
	YELLOW,
	GREEN
} lightState;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void test() {
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, 0);
	HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, 1);
	HAL_Delay(2000);

	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, 1);
	HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, 0);
	HAL_Delay(2000);
}
void ex1() {
	static uint8_t counter = 2;
	static uint8_t first_run = 1;

	if (first_run) {
	  HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, 0);				// Init: LED_RED ON
	  HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, 1);		// Init: LED_YELLOW OFF
	  first_run = 0;
	}
	if (counter == 0) {
	  HAL_GPIO_TogglePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin);
	  HAL_GPIO_TogglePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin);
	  counter = 2;
	}
	counter--;
	HAL_Delay(1000);
}
void ex2() {
	  static uint8_t counter = 10;

	  if (counter == 10) {
		  HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, 0);				// Init: LED_RED ON
		  HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, 1);		// Init: LED_YELLOW OFF
		  HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, 1);	    	// Init: LED_GREEN OFF
	  }
	  else if (counter == 5) {
		  HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, 1);
		  HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, 0);
	  }
	  else if (counter == 2) {
		  HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, 1);
		  HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, 0);
	  }

	  counter--;
	  if (counter == 0) {
		  counter = 10;
	  }
	  HAL_Delay(1000);
}
void ex3() {
	static uint8_t counter = 10;

	if (counter == 10) {
		HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, 1);
		HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, 0);
		HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, 0);

		HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, 0);
		HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, 0);
		HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, 1);
	}
	else if (counter == 7) {
		HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, 1);
		HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, 0);
	}
	else if (counter == 5) {
		HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, 0);
		HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, 1);

		HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, 1);
		HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, 0);
	}
	else if (counter == 2) {
		HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, 1);
		HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, 0);
	}
	counter--;
	if (counter == 0) {
	  counter = 10;
	}
	HAL_Delay(1000);
}
void display7SEG_1(int8_t num) {
	switch (num) {
	case 0:
		HAL_GPIO_WritePin(seg_a_1_GPIO_Port, seg_a_1_Pin, 0);
		HAL_GPIO_WritePin(seg_b_1_GPIO_Port, seg_b_1_Pin, 0);
		HAL_GPIO_WritePin(seg_c_1_GPIO_Port, seg_c_1_Pin, 0);
		HAL_GPIO_WritePin(seg_d_1_GPIO_Port, seg_d_1_Pin, 0);
		HAL_GPIO_WritePin(seg_e_1_GPIO_Port, seg_e_1_Pin, 0);
		HAL_GPIO_WritePin(seg_f_1_GPIO_Port, seg_f_1_Pin, 0);
		HAL_GPIO_WritePin(seg_g_1_GPIO_Port, seg_g_1_Pin, 1);
		break;
	case 1:
		HAL_GPIO_WritePin(seg_a_1_GPIO_Port, seg_a_1_Pin, 1);
		HAL_GPIO_WritePin(seg_b_1_GPIO_Port, seg_b_1_Pin, 0);
		HAL_GPIO_WritePin(seg_c_1_GPIO_Port, seg_c_1_Pin, 0);
		HAL_GPIO_WritePin(seg_d_1_GPIO_Port, seg_d_1_Pin, 1);
		HAL_GPIO_WritePin(seg_e_1_GPIO_Port, seg_e_1_Pin, 1);
		HAL_GPIO_WritePin(seg_f_1_GPIO_Port, seg_f_1_Pin, 1);
		HAL_GPIO_WritePin(seg_g_1_GPIO_Port, seg_g_1_Pin, 1);
		break;
	case 2:
		HAL_GPIO_WritePin(seg_a_1_GPIO_Port, seg_a_1_Pin, 0);
		HAL_GPIO_WritePin(seg_b_1_GPIO_Port, seg_b_1_Pin, 0);
		HAL_GPIO_WritePin(seg_c_1_GPIO_Port, seg_c_1_Pin, 1);
		HAL_GPIO_WritePin(seg_d_1_GPIO_Port, seg_d_1_Pin, 0);
		HAL_GPIO_WritePin(seg_e_1_GPIO_Port, seg_e_1_Pin, 0);
		HAL_GPIO_WritePin(seg_f_1_GPIO_Port, seg_f_1_Pin, 1);
		HAL_GPIO_WritePin(seg_g_1_GPIO_Port, seg_g_1_Pin, 0);
		break;
	case 3:
		HAL_GPIO_WritePin(seg_a_1_GPIO_Port, seg_a_1_Pin, 0);
		HAL_GPIO_WritePin(seg_b_1_GPIO_Port, seg_b_1_Pin, 0);
		HAL_GPIO_WritePin(seg_c_1_GPIO_Port, seg_c_1_Pin, 0);
		HAL_GPIO_WritePin(seg_d_1_GPIO_Port, seg_d_1_Pin, 0);
		HAL_GPIO_WritePin(seg_e_1_GPIO_Port, seg_e_1_Pin, 1);
		HAL_GPIO_WritePin(seg_f_1_GPIO_Port, seg_f_1_Pin, 1);
		HAL_GPIO_WritePin(seg_g_1_GPIO_Port, seg_g_1_Pin, 0);
		break;
	case 4:
		HAL_GPIO_WritePin(seg_a_1_GPIO_Port, seg_a_1_Pin, 1);
		HAL_GPIO_WritePin(seg_b_1_GPIO_Port, seg_b_1_Pin, 0);
		HAL_GPIO_WritePin(seg_c_1_GPIO_Port, seg_c_1_Pin, 0);
		HAL_GPIO_WritePin(seg_d_1_GPIO_Port, seg_d_1_Pin, 1);
		HAL_GPIO_WritePin(seg_e_1_GPIO_Port, seg_e_1_Pin, 1);
		HAL_GPIO_WritePin(seg_f_1_GPIO_Port, seg_f_1_Pin, 0);
		HAL_GPIO_WritePin(seg_g_1_GPIO_Port, seg_g_1_Pin, 0);
		break;
	case 5:
		HAL_GPIO_WritePin(seg_a_1_GPIO_Port, seg_a_1_Pin, 0);
		HAL_GPIO_WritePin(seg_b_1_GPIO_Port, seg_b_1_Pin, 1);
		HAL_GPIO_WritePin(seg_c_1_GPIO_Port, seg_c_1_Pin, 0);
		HAL_GPIO_WritePin(seg_d_1_GPIO_Port, seg_d_1_Pin, 0);
		HAL_GPIO_WritePin(seg_e_1_GPIO_Port, seg_e_1_Pin, 1);
		HAL_GPIO_WritePin(seg_f_1_GPIO_Port, seg_f_1_Pin, 0);
		HAL_GPIO_WritePin(seg_g_1_GPIO_Port, seg_g_1_Pin, 0);
		break;
	case 6:
		HAL_GPIO_WritePin(seg_a_1_GPIO_Port, seg_a_1_Pin, 0);
		HAL_GPIO_WritePin(seg_b_1_GPIO_Port, seg_b_1_Pin, 1);
		HAL_GPIO_WritePin(seg_c_1_GPIO_Port, seg_c_1_Pin, 0);
		HAL_GPIO_WritePin(seg_d_1_GPIO_Port, seg_d_1_Pin, 0);
		HAL_GPIO_WritePin(seg_e_1_GPIO_Port, seg_e_1_Pin, 0);
		HAL_GPIO_WritePin(seg_f_1_GPIO_Port, seg_f_1_Pin, 0);
		HAL_GPIO_WritePin(seg_g_1_GPIO_Port, seg_g_1_Pin, 0);
		break;
	case 7:
		HAL_GPIO_WritePin(seg_a_1_GPIO_Port, seg_a_1_Pin, 0);
		HAL_GPIO_WritePin(seg_b_1_GPIO_Port, seg_b_1_Pin, 0);
		HAL_GPIO_WritePin(seg_c_1_GPIO_Port, seg_c_1_Pin, 0);
		HAL_GPIO_WritePin(seg_d_1_GPIO_Port, seg_d_1_Pin, 1);
		HAL_GPIO_WritePin(seg_e_1_GPIO_Port, seg_e_1_Pin, 1);
		HAL_GPIO_WritePin(seg_f_1_GPIO_Port, seg_f_1_Pin, 1);
		HAL_GPIO_WritePin(seg_g_1_GPIO_Port, seg_g_1_Pin, 1);
		break;
	case 8:
		HAL_GPIO_WritePin(seg_a_1_GPIO_Port, seg_a_1_Pin, 0);
		HAL_GPIO_WritePin(seg_b_1_GPIO_Port, seg_b_1_Pin, 0);
		HAL_GPIO_WritePin(seg_c_1_GPIO_Port, seg_c_1_Pin, 0);
		HAL_GPIO_WritePin(seg_d_1_GPIO_Port, seg_d_1_Pin, 0);
		HAL_GPIO_WritePin(seg_e_1_GPIO_Port, seg_e_1_Pin, 0);
		HAL_GPIO_WritePin(seg_f_1_GPIO_Port, seg_f_1_Pin, 0);
		HAL_GPIO_WritePin(seg_g_1_GPIO_Port, seg_g_1_Pin, 0);
		break;
	case 9:
		HAL_GPIO_WritePin(seg_a_1_GPIO_Port, seg_a_1_Pin, 0);
		HAL_GPIO_WritePin(seg_b_1_GPIO_Port, seg_b_1_Pin, 0);
		HAL_GPIO_WritePin(seg_c_1_GPIO_Port, seg_c_1_Pin, 0);
		HAL_GPIO_WritePin(seg_d_1_GPIO_Port, seg_d_1_Pin, 0);
		HAL_GPIO_WritePin(seg_e_1_GPIO_Port, seg_e_1_Pin, 1);
		HAL_GPIO_WritePin(seg_f_1_GPIO_Port, seg_f_1_Pin, 0);
		HAL_GPIO_WritePin(seg_g_1_GPIO_Port, seg_g_1_Pin, 0);
		break;
	default:
		HAL_GPIO_WritePin(seg_a_1_GPIO_Port, seg_a_1_Pin, 1);
		HAL_GPIO_WritePin(seg_b_1_GPIO_Port, seg_b_1_Pin, 1);
		HAL_GPIO_WritePin(seg_c_1_GPIO_Port, seg_c_1_Pin, 1);
		HAL_GPIO_WritePin(seg_d_1_GPIO_Port, seg_d_1_Pin, 1);
		HAL_GPIO_WritePin(seg_e_1_GPIO_Port, seg_e_1_Pin, 1);
		HAL_GPIO_WritePin(seg_f_1_GPIO_Port, seg_f_1_Pin, 1);
		HAL_GPIO_WritePin(seg_g_1_GPIO_Port, seg_g_1_Pin, 1);
	}
}
void display7SEG_2(int8_t num) {
	switch (num) {
	case 0:
		HAL_GPIO_WritePin(seg_a_2_GPIO_Port, seg_a_2_Pin, 0);
		HAL_GPIO_WritePin(seg_b_2_GPIO_Port, seg_b_2_Pin, 0);
		HAL_GPIO_WritePin(seg_c_2_GPIO_Port, seg_c_2_Pin, 0);
		HAL_GPIO_WritePin(seg_d_2_GPIO_Port, seg_d_2_Pin, 0);
		HAL_GPIO_WritePin(seg_e_2_GPIO_Port, seg_e_2_Pin, 0);
		HAL_GPIO_WritePin(seg_f_2_GPIO_Port, seg_f_2_Pin, 0);
		HAL_GPIO_WritePin(seg_g_2_GPIO_Port, seg_g_2_Pin, 1);
		break;
	case 1:
		HAL_GPIO_WritePin(seg_a_2_GPIO_Port, seg_a_2_Pin, 1);
		HAL_GPIO_WritePin(seg_b_2_GPIO_Port, seg_b_2_Pin, 0);
		HAL_GPIO_WritePin(seg_c_2_GPIO_Port, seg_c_2_Pin, 0);
		HAL_GPIO_WritePin(seg_d_2_GPIO_Port, seg_d_2_Pin, 1);
		HAL_GPIO_WritePin(seg_e_2_GPIO_Port, seg_e_2_Pin, 1);
		HAL_GPIO_WritePin(seg_f_2_GPIO_Port, seg_f_2_Pin, 1);
		HAL_GPIO_WritePin(seg_g_2_GPIO_Port, seg_g_2_Pin, 1);
		break;
	case 2:
		HAL_GPIO_WritePin(seg_a_2_GPIO_Port, seg_a_2_Pin, 0);
		HAL_GPIO_WritePin(seg_b_2_GPIO_Port, seg_b_2_Pin, 0);
		HAL_GPIO_WritePin(seg_c_2_GPIO_Port, seg_c_2_Pin, 1);
		HAL_GPIO_WritePin(seg_d_2_GPIO_Port, seg_d_2_Pin, 0);
		HAL_GPIO_WritePin(seg_e_2_GPIO_Port, seg_e_2_Pin, 0);
		HAL_GPIO_WritePin(seg_f_2_GPIO_Port, seg_f_2_Pin, 1);
		HAL_GPIO_WritePin(seg_g_2_GPIO_Port, seg_g_2_Pin, 0);
		break;
	case 3:
		HAL_GPIO_WritePin(seg_a_2_GPIO_Port, seg_a_2_Pin, 0);
		HAL_GPIO_WritePin(seg_b_2_GPIO_Port, seg_b_2_Pin, 0);
		HAL_GPIO_WritePin(seg_c_2_GPIO_Port, seg_c_2_Pin, 0);
		HAL_GPIO_WritePin(seg_d_2_GPIO_Port, seg_d_2_Pin, 0);
		HAL_GPIO_WritePin(seg_e_2_GPIO_Port, seg_e_2_Pin, 1);
		HAL_GPIO_WritePin(seg_f_2_GPIO_Port, seg_f_2_Pin, 1);
		HAL_GPIO_WritePin(seg_g_2_GPIO_Port, seg_g_2_Pin, 0);
		break;
	case 4:
		HAL_GPIO_WritePin(seg_a_2_GPIO_Port, seg_a_2_Pin, 1);
		HAL_GPIO_WritePin(seg_b_2_GPIO_Port, seg_b_2_Pin, 0);
		HAL_GPIO_WritePin(seg_c_2_GPIO_Port, seg_c_2_Pin, 0);
		HAL_GPIO_WritePin(seg_d_2_GPIO_Port, seg_d_2_Pin, 1);
		HAL_GPIO_WritePin(seg_e_2_GPIO_Port, seg_e_2_Pin, 1);
		HAL_GPIO_WritePin(seg_f_2_GPIO_Port, seg_f_2_Pin, 0);
		HAL_GPIO_WritePin(seg_g_2_GPIO_Port, seg_g_2_Pin, 0);
		break;
	case 5:
		HAL_GPIO_WritePin(seg_a_2_GPIO_Port, seg_a_2_Pin, 0);
		HAL_GPIO_WritePin(seg_b_2_GPIO_Port, seg_b_2_Pin, 1);
		HAL_GPIO_WritePin(seg_c_2_GPIO_Port, seg_c_2_Pin, 0);
		HAL_GPIO_WritePin(seg_d_2_GPIO_Port, seg_d_2_Pin, 0);
		HAL_GPIO_WritePin(seg_e_2_GPIO_Port, seg_e_2_Pin, 1);
		HAL_GPIO_WritePin(seg_f_2_GPIO_Port, seg_f_2_Pin, 0);
		HAL_GPIO_WritePin(seg_g_2_GPIO_Port, seg_g_2_Pin, 0);
		break;
	case 6:
		HAL_GPIO_WritePin(seg_a_2_GPIO_Port, seg_a_2_Pin, 0);
		HAL_GPIO_WritePin(seg_b_2_GPIO_Port, seg_b_2_Pin, 1);
		HAL_GPIO_WritePin(seg_c_2_GPIO_Port, seg_c_2_Pin, 0);
		HAL_GPIO_WritePin(seg_d_2_GPIO_Port, seg_d_2_Pin, 0);
		HAL_GPIO_WritePin(seg_e_2_GPIO_Port, seg_e_2_Pin, 0);
		HAL_GPIO_WritePin(seg_f_2_GPIO_Port, seg_f_2_Pin, 0);
		HAL_GPIO_WritePin(seg_g_2_GPIO_Port, seg_g_2_Pin, 0);
		break;
	case 7:
		HAL_GPIO_WritePin(seg_a_2_GPIO_Port, seg_a_2_Pin, 0);
		HAL_GPIO_WritePin(seg_b_2_GPIO_Port, seg_b_2_Pin, 0);
		HAL_GPIO_WritePin(seg_c_2_GPIO_Port, seg_c_2_Pin, 0);
		HAL_GPIO_WritePin(seg_d_2_GPIO_Port, seg_d_2_Pin, 1);
		HAL_GPIO_WritePin(seg_e_2_GPIO_Port, seg_e_2_Pin, 1);
		HAL_GPIO_WritePin(seg_f_2_GPIO_Port, seg_f_2_Pin, 1);
		HAL_GPIO_WritePin(seg_g_2_GPIO_Port, seg_g_2_Pin, 1);
		break;
	case 8:
		HAL_GPIO_WritePin(seg_a_2_GPIO_Port, seg_a_2_Pin, 0);
		HAL_GPIO_WritePin(seg_b_2_GPIO_Port, seg_b_2_Pin, 0);
		HAL_GPIO_WritePin(seg_c_2_GPIO_Port, seg_c_2_Pin, 0);
		HAL_GPIO_WritePin(seg_d_2_GPIO_Port, seg_d_2_Pin, 0);
		HAL_GPIO_WritePin(seg_e_2_GPIO_Port, seg_e_2_Pin, 0);
		HAL_GPIO_WritePin(seg_f_2_GPIO_Port, seg_f_2_Pin, 0);
		HAL_GPIO_WritePin(seg_g_2_GPIO_Port, seg_g_2_Pin, 0);
		break;
	case 9:
		HAL_GPIO_WritePin(seg_a_2_GPIO_Port, seg_a_2_Pin, 0);
		HAL_GPIO_WritePin(seg_b_2_GPIO_Port, seg_b_2_Pin, 0);
		HAL_GPIO_WritePin(seg_c_2_GPIO_Port, seg_c_2_Pin, 0);
		HAL_GPIO_WritePin(seg_d_2_GPIO_Port, seg_d_2_Pin, 0);
		HAL_GPIO_WritePin(seg_e_2_GPIO_Port, seg_e_2_Pin, 1);
		HAL_GPIO_WritePin(seg_f_2_GPIO_Port, seg_f_2_Pin, 0);
		HAL_GPIO_WritePin(seg_g_2_GPIO_Port, seg_g_2_Pin, 0);
		break;
	default:
		HAL_GPIO_WritePin(seg_a_2_GPIO_Port, seg_a_2_Pin, 1);
		HAL_GPIO_WritePin(seg_b_2_GPIO_Port, seg_b_2_Pin, 1);
		HAL_GPIO_WritePin(seg_c_2_GPIO_Port, seg_c_2_Pin, 1);
		HAL_GPIO_WritePin(seg_d_2_GPIO_Port, seg_d_2_Pin, 1);
		HAL_GPIO_WritePin(seg_e_2_GPIO_Port, seg_e_2_Pin, 1);
		HAL_GPIO_WritePin(seg_f_2_GPIO_Port, seg_f_2_Pin, 1);
		HAL_GPIO_WritePin(seg_g_2_GPIO_Port, seg_g_2_Pin, 1);
	}
}
void ex4() {
	 static int8_t counter = 10;
	 if (counter >= 10) counter = 0;
	 display7SEG_1(counter++);
	 HAL_Delay(1000);
}
void ex5() {
	static int8_t count_1 = 4;
	static int8_t count_2 = 2;
	static lightState state_1 = RED;		// Red first
	static lightState state_2 = GREEN;		// Green first

	if (count_1 < 0) {
		if (state_1 == RED) {
			count_1 = 2;
			state_1 = GREEN;
		}
		else if (state_1 == GREEN) {
			count_1 = 1;
			state_1 = YELLOW;
		}
		else if (state_1 == YELLOW) {
			count_1 = 4;
			state_1 = RED;
		}
	}

	if (count_2 < 0) {
		if (state_2 == GREEN) {
			count_2 = 1;
			state_2 = YELLOW;
		}
		else if (state_2 == YELLOW) {
			count_2 = 4;
			state_2 = RED;
		}
		else if (state_2 == RED) {
			count_2 = 2;
			state_2 = GREEN;
		}
	}
	display7SEG_1(count_1--);
	display7SEG_2(count_2--);
	ex3();
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	ex1();

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin|LED_YELLOW_1_Pin|LED_GREEN_1_Pin|LED_RED_2_Pin
                          |LED_YELLOW_2_Pin|LED_GREEN_2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, seg_a_1_Pin|seg_b_1_Pin|seg_c_1_Pin|seg_d_2_Pin
                          |seg_e_2_Pin|seg_f_2_Pin|seg_g_2_Pin|seg_d_1_Pin
                          |seg_e_1_Pin|seg_f_1_Pin|seg_g_1_Pin|seg_a_2_Pin
                          |seg_b_2_Pin|seg_c_2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_RED_1_Pin LED_YELLOW_1_Pin LED_GREEN_1_Pin LED_RED_2_Pin
                           LED_YELLOW_2_Pin LED_GREEN_2_Pin */
  GPIO_InitStruct.Pin = LED_RED_1_Pin|LED_YELLOW_1_Pin|LED_GREEN_1_Pin|LED_RED_2_Pin
                          |LED_YELLOW_2_Pin|LED_GREEN_2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : seg_a_1_Pin seg_b_1_Pin seg_c_1_Pin seg_d_2_Pin
                           seg_e_2_Pin seg_f_2_Pin seg_g_2_Pin seg_d_1_Pin
                           seg_e_1_Pin seg_f_1_Pin seg_g_1_Pin seg_a_2_Pin
                           seg_b_2_Pin seg_c_2_Pin */
  GPIO_InitStruct.Pin = seg_a_1_Pin|seg_b_1_Pin|seg_c_1_Pin|seg_d_2_Pin
                          |seg_e_2_Pin|seg_f_2_Pin|seg_g_2_Pin|seg_d_1_Pin
                          |seg_e_1_Pin|seg_f_1_Pin|seg_g_1_Pin|seg_a_2_Pin
                          |seg_b_2_Pin|seg_c_2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
