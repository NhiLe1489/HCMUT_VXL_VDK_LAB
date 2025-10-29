/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @course			: MPU - MCU
  * @lab number		: 2
  * @exercises		: 1 to 10
  * @brief          : Led multiplex and led matrix
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
#include "timer.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
GPIO_TypeDef* COL_PORT[8] = {GPIOA, GPIOA, GPIOA, GPIOA, GPIOA, GPIOA, GPIOA, GPIOA};
uint16_t COL_PIN[8] = {enm0_Pin, enm1_Pin, enm2_Pin, enm3_Pin,
                       enm4_Pin, enm5_Pin, enm6_Pin, enm7_Pin};

GPIO_TypeDef* ROW_PORT[8] = {GPIOB, GPIOB, GPIOB, GPIOB, GPIOB, GPIOB, GPIOB, GPIOB};
uint16_t ROW_PIN[8] = {row0_Pin, row1_Pin, row2_Pin, row3_Pin,
                       row4_Pin, row5_Pin, row6_Pin, row7_Pin};
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */
const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {1, 2, 3, 4};
int hour = 12, minute = 34, second = 50;

const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;
int current_col = 0;
uint8_t matrix_buffer[8];

uint8_t letter_A[8] = {
  0b00000000,
  0b00000000,
  0b01111100,
  0b00010010,
  0b00010010,
  0b01111100,
  0b00000000,
  0b00000000
};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void display7SEG(int num) {
	switch (num) {
	case 0:
		HAL_GPIO_WritePin(seg_a_GPIO_Port, seg_a_Pin, 0);
		HAL_GPIO_WritePin(seg_b_GPIO_Port, seg_b_Pin, 0);
		HAL_GPIO_WritePin(seg_c_GPIO_Port, seg_c_Pin, 0);
		HAL_GPIO_WritePin(seg_d_GPIO_Port, seg_d_Pin, 0);
		HAL_GPIO_WritePin(seg_e_GPIO_Port, seg_e_Pin, 0);
		HAL_GPIO_WritePin(seg_f_GPIO_Port, seg_f_Pin, 0);
		HAL_GPIO_WritePin(seg_g_GPIO_Port, seg_g_Pin, 1);
		break;
	case 1:
		HAL_GPIO_WritePin(seg_a_GPIO_Port, seg_a_Pin, 1);
		HAL_GPIO_WritePin(seg_b_GPIO_Port, seg_b_Pin, 0);
		HAL_GPIO_WritePin(seg_c_GPIO_Port, seg_c_Pin, 0);
		HAL_GPIO_WritePin(seg_d_GPIO_Port, seg_d_Pin, 1);
		HAL_GPIO_WritePin(seg_e_GPIO_Port, seg_e_Pin, 1);
		HAL_GPIO_WritePin(seg_f_GPIO_Port, seg_f_Pin, 1);
		HAL_GPIO_WritePin(seg_g_GPIO_Port, seg_g_Pin, 1);
		break;
	case 2:
		HAL_GPIO_WritePin(seg_a_GPIO_Port, seg_a_Pin, 0);
		HAL_GPIO_WritePin(seg_b_GPIO_Port, seg_b_Pin, 0);
		HAL_GPIO_WritePin(seg_c_GPIO_Port, seg_c_Pin, 1);
		HAL_GPIO_WritePin(seg_d_GPIO_Port, seg_d_Pin, 0);
		HAL_GPIO_WritePin(seg_e_GPIO_Port, seg_e_Pin, 0);
		HAL_GPIO_WritePin(seg_f_GPIO_Port, seg_f_Pin, 1);
		HAL_GPIO_WritePin(seg_g_GPIO_Port, seg_g_Pin, 0);
		break;
	case 3:
		HAL_GPIO_WritePin(seg_a_GPIO_Port, seg_a_Pin, 0);
		HAL_GPIO_WritePin(seg_b_GPIO_Port, seg_b_Pin, 0);
		HAL_GPIO_WritePin(seg_c_GPIO_Port, seg_c_Pin, 0);
		HAL_GPIO_WritePin(seg_d_GPIO_Port, seg_d_Pin, 0);
		HAL_GPIO_WritePin(seg_e_GPIO_Port, seg_e_Pin, 1);
		HAL_GPIO_WritePin(seg_f_GPIO_Port, seg_f_Pin, 1);
		HAL_GPIO_WritePin(seg_g_GPIO_Port, seg_g_Pin, 0);
		break;
	case 4:
		HAL_GPIO_WritePin(seg_a_GPIO_Port, seg_a_Pin, 1);
		HAL_GPIO_WritePin(seg_b_GPIO_Port, seg_b_Pin, 0);
		HAL_GPIO_WritePin(seg_c_GPIO_Port, seg_c_Pin, 0);
		HAL_GPIO_WritePin(seg_d_GPIO_Port, seg_d_Pin, 1);
		HAL_GPIO_WritePin(seg_e_GPIO_Port, seg_e_Pin, 1);
		HAL_GPIO_WritePin(seg_f_GPIO_Port, seg_f_Pin, 0);
		HAL_GPIO_WritePin(seg_g_GPIO_Port, seg_g_Pin, 0);
		break;
	case 5:
		HAL_GPIO_WritePin(seg_a_GPIO_Port, seg_a_Pin, 0);
		HAL_GPIO_WritePin(seg_b_GPIO_Port, seg_b_Pin, 1);
		HAL_GPIO_WritePin(seg_c_GPIO_Port, seg_c_Pin, 0);
		HAL_GPIO_WritePin(seg_d_GPIO_Port, seg_d_Pin, 0);
		HAL_GPIO_WritePin(seg_e_GPIO_Port, seg_e_Pin, 1);
		HAL_GPIO_WritePin(seg_f_GPIO_Port, seg_f_Pin, 0);
		HAL_GPIO_WritePin(seg_g_GPIO_Port, seg_g_Pin, 0);
		break;
	case 6:
		HAL_GPIO_WritePin(seg_a_GPIO_Port, seg_a_Pin, 0);
		HAL_GPIO_WritePin(seg_b_GPIO_Port, seg_b_Pin, 1);
		HAL_GPIO_WritePin(seg_c_GPIO_Port, seg_c_Pin, 0);
		HAL_GPIO_WritePin(seg_d_GPIO_Port, seg_d_Pin, 0);
		HAL_GPIO_WritePin(seg_e_GPIO_Port, seg_e_Pin, 0);
		HAL_GPIO_WritePin(seg_f_GPIO_Port, seg_f_Pin, 0);
		HAL_GPIO_WritePin(seg_g_GPIO_Port, seg_g_Pin, 0);
		break;
	case 7:
		HAL_GPIO_WritePin(seg_a_GPIO_Port, seg_a_Pin, 0);
		HAL_GPIO_WritePin(seg_b_GPIO_Port, seg_b_Pin, 0);
		HAL_GPIO_WritePin(seg_c_GPIO_Port, seg_c_Pin, 0);
		HAL_GPIO_WritePin(seg_d_GPIO_Port, seg_d_Pin, 1);
		HAL_GPIO_WritePin(seg_e_GPIO_Port, seg_e_Pin, 1);
		HAL_GPIO_WritePin(seg_f_GPIO_Port, seg_f_Pin, 1);
		HAL_GPIO_WritePin(seg_g_GPIO_Port, seg_g_Pin, 1);
		break;
	case 8:
		HAL_GPIO_WritePin(seg_a_GPIO_Port, seg_a_Pin, 0);
		HAL_GPIO_WritePin(seg_b_GPIO_Port, seg_b_Pin, 0);
		HAL_GPIO_WritePin(seg_c_GPIO_Port, seg_c_Pin, 0);
		HAL_GPIO_WritePin(seg_d_GPIO_Port, seg_d_Pin, 0);
		HAL_GPIO_WritePin(seg_e_GPIO_Port, seg_e_Pin, 0);
		HAL_GPIO_WritePin(seg_f_GPIO_Port, seg_f_Pin, 0);
		HAL_GPIO_WritePin(seg_g_GPIO_Port, seg_g_Pin, 0);
		break;
	case 9:
		HAL_GPIO_WritePin(seg_a_GPIO_Port, seg_a_Pin, 0);
		HAL_GPIO_WritePin(seg_b_GPIO_Port, seg_b_Pin, 0);
		HAL_GPIO_WritePin(seg_c_GPIO_Port, seg_c_Pin, 0);
		HAL_GPIO_WritePin(seg_d_GPIO_Port, seg_d_Pin, 0);
		HAL_GPIO_WritePin(seg_e_GPIO_Port, seg_e_Pin, 1);
		HAL_GPIO_WritePin(seg_f_GPIO_Port, seg_f_Pin, 0);
		HAL_GPIO_WritePin(seg_g_GPIO_Port, seg_g_Pin, 0);
		break;
	default:
		HAL_GPIO_WritePin(seg_a_GPIO_Port, seg_a_Pin, 1);
		HAL_GPIO_WritePin(seg_b_GPIO_Port, seg_b_Pin, 1);
		HAL_GPIO_WritePin(seg_c_GPIO_Port, seg_c_Pin, 1);
		HAL_GPIO_WritePin(seg_d_GPIO_Port, seg_d_Pin, 1);
		HAL_GPIO_WritePin(seg_e_GPIO_Port, seg_e_Pin, 1);
		HAL_GPIO_WritePin(seg_f_GPIO_Port, seg_f_Pin, 1);
		HAL_GPIO_WritePin(seg_g_GPIO_Port, seg_g_Pin, 1);
	}
}
void ex1() {
	static uint8_t segled1_on = 1;
	if (segled1_on) {
		HAL_GPIO_WritePin(en_0_GPIO_Port, en_0_Pin, 0);
		HAL_GPIO_WritePin(en_1_GPIO_Port, en_1_Pin, 1);
		display7SEG(1);
	}
	else {
		HAL_GPIO_WritePin(en_0_GPIO_Port, en_0_Pin, 1);
		HAL_GPIO_WritePin(en_1_GPIO_Port, en_1_Pin, 0);
		display7SEG(2);
	}

	if (timer1_flag == 1) {
		segled1_on = !segled1_on;
		setTimer1(50);						// setTimer1() resets timer1_flag
	}
}
void ex2() {
	static uint8_t state1 = 0;				// 4 7segment leds
	static uint8_t state2 = 1;				// blink 2 leds DOT

	switch (state1) {
	 case 0:
		HAL_GPIO_WritePin(en_0_GPIO_Port, en_0_Pin, 0);
		HAL_GPIO_WritePin(en_1_GPIO_Port, en_1_Pin, 1);
		HAL_GPIO_WritePin(en_2_GPIO_Port, en_2_Pin, 1);
		HAL_GPIO_WritePin(en_3_GPIO_Port, en_3_Pin, 1);
		display7SEG(1);
		break;
	 case 1:
		HAL_GPIO_WritePin(en_0_GPIO_Port, en_0_Pin, 1);
		HAL_GPIO_WritePin(en_1_GPIO_Port, en_1_Pin, 0);
		HAL_GPIO_WritePin(en_2_GPIO_Port, en_2_Pin, 1);
		HAL_GPIO_WritePin(en_3_GPIO_Port, en_3_Pin, 1);
		display7SEG(2);
		break;
	 case 2:
		HAL_GPIO_WritePin(en_0_GPIO_Port, en_0_Pin, 1);
		HAL_GPIO_WritePin(en_1_GPIO_Port, en_1_Pin, 1);
		HAL_GPIO_WritePin(en_2_GPIO_Port, en_2_Pin, 0);
		HAL_GPIO_WritePin(en_3_GPIO_Port, en_3_Pin, 1);
		display7SEG(3);
		break;
	 case 3:
		HAL_GPIO_WritePin(en_0_GPIO_Port, en_0_Pin, 1);
		HAL_GPIO_WritePin(en_1_GPIO_Port, en_1_Pin, 1);
		HAL_GPIO_WritePin(en_2_GPIO_Port, en_2_Pin, 1);
		HAL_GPIO_WritePin(en_3_GPIO_Port, en_3_Pin, 0);
		display7SEG(0);
		break;
	 default:
		display7SEG(9);
	}

	if (state2) {
		HAL_GPIO_WritePin(DOT_GPIO_Port, DOT_Pin, 0);
	}
	else {
		HAL_GPIO_WritePin(DOT_GPIO_Port, DOT_Pin, 1);
	}

	if (timer1_flag == 1) {
		state1++;
		if (state1 > 3) {
			state1 = 0;
		}
		setTimer1(50);						// setTimer1() resets timer1_flag
	}
	if (timer2_flag == 1) {
		state2 = !state2;
		setTimer2(100);
	}
}
void update7SEG(int index){
	switch (index){
		case 0:
			HAL_GPIO_WritePin(en_0_GPIO_Port, en_0_Pin, 0);
			HAL_GPIO_WritePin(en_1_GPIO_Port, en_1_Pin, 1);
			HAL_GPIO_WritePin(en_2_GPIO_Port, en_2_Pin, 1);
			HAL_GPIO_WritePin(en_3_GPIO_Port, en_3_Pin, 1);
			display7SEG(led_buffer[0]);
			break;
		case 1:
			HAL_GPIO_WritePin(en_0_GPIO_Port, en_0_Pin, 1);
			HAL_GPIO_WritePin(en_1_GPIO_Port, en_1_Pin, 0);
			HAL_GPIO_WritePin(en_2_GPIO_Port, en_2_Pin, 1);
			HAL_GPIO_WritePin(en_3_GPIO_Port, en_3_Pin, 1);
			display7SEG(led_buffer[1]);
			break;
		case 2:
			HAL_GPIO_WritePin(en_0_GPIO_Port, en_0_Pin, 1);
			HAL_GPIO_WritePin(en_1_GPIO_Port, en_1_Pin, 1);
			HAL_GPIO_WritePin(en_2_GPIO_Port, en_2_Pin, 0);
			HAL_GPIO_WritePin(en_3_GPIO_Port, en_3_Pin, 1);
			display7SEG(led_buffer[2]);
			break;
		case 3:
			HAL_GPIO_WritePin(en_0_GPIO_Port, en_0_Pin, 1);
			HAL_GPIO_WritePin(en_1_GPIO_Port, en_1_Pin, 1);
			HAL_GPIO_WritePin(en_2_GPIO_Port, en_2_Pin, 1);
			HAL_GPIO_WritePin(en_3_GPIO_Port, en_3_Pin, 0);
			display7SEG(led_buffer[3]);
			break;
		default:
			display7SEG(9);
	}
}
void ex3() {
	if (timer1_flag == 1) {
		update7SEG(index_led);
		index_led++;
		if (index_led >= MAX_LED) {
			index_led = 0;
		}
		setTimer1(50);
	}
}
void ex4() {
	static uint8_t blink_dot = 1;
	if (blink_dot) {
		HAL_GPIO_WritePin(DOT_GPIO_Port, DOT_Pin, 0);
	}
	else {
		HAL_GPIO_WritePin(DOT_GPIO_Port, DOT_Pin, 1);
	}

	if (timer1_flag == 1) {
		update7SEG(index_led);
		index_led++;
		if (index_led >= MAX_LED) {
			index_led = 0;
		}
		setTimer1(25);
	}
	if (timer2_flag == 1) {
		blink_dot = !blink_dot;
		setTimer2(100);
	}
}
void updateClockBuffer() {
    led_buffer[0] = hour / 10;
    led_buffer[1] = hour % 10;
    led_buffer[2] = minute / 10;
    led_buffer[3] = minute % 10;
}
void ex7() {
	second++;
	if (second >= 60) {
		second = 0;
		minute++;
	}
	if(minute >= 60) {
		minute = 0;
		hour++;
	}
	if(hour >= 24){
		hour = 0;
	}
	updateClockBuffer();
}
void ex8() {
	static uint8_t blink_dot = 1;

	if (blink_dot) {
		HAL_GPIO_WritePin(DOT_GPIO_Port, DOT_Pin, 0);
	}
	else {
		HAL_GPIO_WritePin(DOT_GPIO_Port, DOT_Pin, 1);
	}

	if (timer1_flag == 1) {
		update7SEG(index_led);
		index_led++;
		if (index_led >= MAX_LED) {
			index_led = 0;
		}
		setTimer1(25);
	}
	if (timer2_flag == 1) {
		blink_dot = !blink_dot;
		ex7();
		setTimer2(100);
	}
}
void clearAllMatrix() {
	for (int i = 0; i < 8; i++) {
		HAL_GPIO_WritePin(COL_PORT[i], COL_PIN[i], 1);
		HAL_GPIO_WritePin(ROW_PORT[i], ROW_PIN[i], 1);
	}
}
void updateLEDMatrix(int index){
	clearAllMatrix();

	for (int row = 0; row < 8; row++) {
		if (matrix_buffer[index] & (1 << row))			// check (<row>th bit in matrix_buffer == 1) ?
			HAL_GPIO_WritePin(ROW_PORT[row], ROW_PIN[row], 0);
		else
			HAL_GPIO_WritePin(ROW_PORT[row], ROW_PIN[row], 1);
	}
	HAL_GPIO_WritePin(COL_PORT[index], COL_PIN[index], 0);
}
void ex9() {
	if (timer1_flag) {
		updateLEDMatrix(index_led_matrix);
		index_led_matrix++;
		if (index_led_matrix >= MAX_LED_MATRIX)
			index_led_matrix = 0;
		setTimer1(4);
	}
}
void shiftLeft() {
	for (int i = 0; i < 7; i++) {
		matrix_buffer[i] = matrix_buffer[i + 1];
	}
	matrix_buffer[7] = 0;
}
void ex10() {
	ex9();
	if (timer2_flag) {
		shiftLeft();
		setTimer2(33);
	}
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
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim2);
  HAL_GPIO_WritePin(en_0_GPIO_Port, en_0_Pin, 1);
  HAL_GPIO_WritePin(en_1_GPIO_Port, en_1_Pin, 1);
  HAL_GPIO_WritePin(en_2_GPIO_Port, en_2_Pin, 1);
  HAL_GPIO_WritePin(en_3_GPIO_Port, en_3_Pin, 1);

  clearAllMatrix();
  for (int i = 0; i < 8; i++) {
	  matrix_buffer[i] = letter_A[i];
  }

  //setTimer1(50);					// ex1,2,3
  //setTimer2(100);					// ex2,4,8
  //setTimer1(25);					// ex4,8
  setTimer1(4);					// ex9,10
  setTimer2(33);					// ex10

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  while (1)
  {
	 ex10();
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
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

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
  HAL_GPIO_WritePin(GPIOA, enm0_Pin|enm1_Pin|DOT_Pin|LED_RED_Pin
                          |en_0_Pin|en_1_Pin|en_2_Pin|en_3_Pin
                          |enm2_Pin|enm3_Pin|enm4_Pin|enm5_Pin
                          |enm6_Pin|enm7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, seg_a_Pin|seg_b_Pin|seg_c_Pin|row2_Pin
                          |row3_Pin|row4_Pin|row5_Pin|row6_Pin
                          |row7_Pin|seg_d_Pin|seg_e_Pin|seg_f_Pin
                          |seg_g_Pin|row0_Pin|row1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : enm0_Pin enm1_Pin DOT_Pin LED_RED_Pin
                           en_0_Pin en_1_Pin en_2_Pin en_3_Pin
                           enm2_Pin enm3_Pin enm4_Pin enm5_Pin
                           enm6_Pin enm7_Pin */
  GPIO_InitStruct.Pin = enm0_Pin|enm1_Pin|DOT_Pin|LED_RED_Pin
                          |en_0_Pin|en_1_Pin|en_2_Pin|en_3_Pin
                          |enm2_Pin|enm3_Pin|enm4_Pin|enm5_Pin
                          |enm6_Pin|enm7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : seg_a_Pin seg_b_Pin seg_c_Pin row2_Pin
                           row3_Pin row4_Pin row5_Pin row6_Pin
                           row7_Pin seg_d_Pin seg_e_Pin seg_f_Pin
                           seg_g_Pin row0_Pin row1_Pin */
  GPIO_InitStruct.Pin = seg_a_Pin|seg_b_Pin|seg_c_Pin|row2_Pin
                          |row3_Pin|row4_Pin|row5_Pin|row6_Pin
                          |row7_Pin|seg_d_Pin|seg_e_Pin|seg_f_Pin
                          |seg_g_Pin|row0_Pin|row1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
//int counter = 100;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	timerRun();
}
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
