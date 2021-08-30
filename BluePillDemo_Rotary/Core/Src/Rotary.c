/*
 * Rotary.c
 *
 *  Created on: 2021. aug. 29.
 *      Author: pokot
 */

#include "stm32f1xx_hal.h"

TIM_HandleTypeDef htim2;

static void MX_TIM2_Init(void);
static void MX_GPIO_Init(void);

void init_rotary_encoder()
{
	MX_GPIO_Init();
	MX_TIM2_Init();
	HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_ALL);
    //GPIO_InitTypeDef GPIO_InitStruct;
    /**
      * @brief TIM2 Initialization Function
      * @param None
      * @retval None
      */
}
    static void MX_TIM2_Init(void)
    {

      /* USER CODE BEGIN TIM2_Init 0 */

      /* USER CODE END TIM2_Init 0 */

      TIM_Encoder_InitTypeDef sConfig = {0};
      TIM_MasterConfigTypeDef sMasterConfig = {0};

      /* USER CODE BEGIN TIM2_Init 1 */

      /* USER CODE END TIM2_Init 1 */
      htim2.Instance = TIM2;
      htim2.Init.Prescaler = 0;
      htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
      htim2.Init.Period = 65535;
      htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
      htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
      sConfig.EncoderMode = TIM_ENCODERMODE_TI12;
      sConfig.IC1Polarity = TIM_ICPOLARITY_RISING;
      sConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
      sConfig.IC1Prescaler = TIM_ICPSC_DIV1;
      sConfig.IC1Filter = 10;
      sConfig.IC2Polarity = TIM_ICPOLARITY_RISING;
      sConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
      sConfig.IC2Prescaler = TIM_ICPSC_DIV1;
      sConfig.IC2Filter = 10;
      if (HAL_TIM_Encoder_Init(&htim2, &sConfig) != HAL_OK)
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

      /* GPIO Ports Clock Enable */
      __HAL_RCC_GPIOD_CLK_ENABLE();
      __HAL_RCC_GPIOA_CLK_ENABLE();

      /*Configure GPIO pin : PA2 */
      GPIO_InitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2;
      GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
      GPIO_InitStruct.Pull = GPIO_NOPULL;
      HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    }





