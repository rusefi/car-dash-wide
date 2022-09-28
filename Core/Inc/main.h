/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f4xx_hal.h"

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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

void Neopixel_setup(void);
void show_neopixels();
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BTN_1_Pin GPIO_PIN_2
#define BTN_1_GPIO_Port GPIOE
#define BTN_2_Pin GPIO_PIN_3
#define BTN_2_GPIO_Port GPIOE
#define TOUCH_EN_Pin GPIO_PIN_11
#define TOUCH_EN_GPIO_Port GPIOI
#define TOUCH_EN_EXTI_IRQn EXTI15_10_IRQn
#define HALL_OUT_1_PI12_Pin GPIO_PIN_12
#define HALL_OUT_1_PI12_GPIO_Port GPIOI
#define MULTISENSE_ADC_Pin GPIO_PIN_1
#define MULTISENSE_ADC_GPIO_Port GPIOC
#define OUT_S0_Pin GPIO_PIN_2
#define OUT_S0_GPIO_Port GPIOH
#define OUT_E_Pin GPIO_PIN_3
#define OUT_E_GPIO_Port GPIOH
#define MULTISENSE_EN5_Pin GPIO_PIN_3
#define MULTISENSE_EN5_GPIO_Port GPIOJ
#define BTN_3_Pin GPIO_PIN_6
#define BTN_3_GPIO_Port GPIOJ
#define BTN_4_Pin GPIO_PIN_7
#define BTN_4_GPIO_Port GPIOJ
#define MULTISENSE_RST_Pin GPIO_PIN_2
#define MULTISENSE_RST_GPIO_Port GPIOK
#define SDIO_ENT_Pin GPIO_PIN_3
#define SDIO_ENT_GPIO_Port GPIOG
#define LED_PI3_Pin GPIO_PIN_3
#define LED_PI3_GPIO_Port GPIOI
#define PUD_S0_Pin GPIO_PIN_3
#define PUD_S0_GPIO_Port GPIOD
#define PUD_S1_Pin GPIO_PIN_4
#define PUD_S1_GPIO_Port GPIOD
#define PUD_S2_Pin GPIO_PIN_5
#define PUD_S2_GPIO_Port GPIOD
#define PUD_E_Pin GPIO_PIN_7
#define PUD_E_GPIO_Port GPIOD
#define LED_PJ12_Pin GPIO_PIN_12
#define LED_PJ12_GPIO_Port GPIOJ
#define LED_PJ13_Pin GPIO_PIN_13
#define LED_PJ13_GPIO_Port GPIOJ
#define LED_PJ14_Pin GPIO_PIN_14
#define LED_PJ14_GPIO_Port GPIOJ
#define LED_PJ15_Pin GPIO_PIN_15
#define LED_PJ15_GPIO_Port GPIOJ
#define IN_E_Pin GPIO_PIN_9
#define IN_E_GPIO_Port GPIOG
#define IN_S0_Pin GPIO_PIN_10
#define IN_S0_GPIO_Port GPIOG
#define IN_S1_Pin GPIO_PIN_12
#define IN_S1_GPIO_Port GPIOG
#define IN_S2_Pin GPIO_PIN_13
#define IN_S2_GPIO_Port GPIOG
#define IN_S3_Pin GPIO_PIN_14
#define IN_S3_GPIO_Port GPIOG
#define MULTISENSE_SEL0_Pin GPIO_PIN_3
#define MULTISENSE_SEL0_GPIO_Port GPIOK
#define MULTISENSE_SEL1_Pin GPIO_PIN_4
#define MULTISENSE_SEL1_GPIO_Port GPIOK
#define CAN2_SEL0_Pin GPIO_PIN_5
#define CAN2_SEL0_GPIO_Port GPIOK
#define CAN1_SEL0_Pin GPIO_PIN_6
#define CAN1_SEL0_GPIO_Port GPIOK
#define CAN2_SEL0K7_Pin GPIO_PIN_7
#define CAN2_SEL0K7_GPIO_Port GPIOK
/* USER CODE BEGIN Private defines */
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
