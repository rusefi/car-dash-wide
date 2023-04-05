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
#define LED_ACTIVE_Pin GPIO_PIN_2
#define LED_ACTIVE_GPIO_Port GPIOE
#define LED_ALERT_Pin GPIO_PIN_3
#define LED_ALERT_GPIO_Port GPIOE
#define LED_CAN1_Pin GPIO_PIN_4
#define LED_CAN1_GPIO_Port GPIOE
#define LED_CAN2_Pin GPIO_PIN_5
#define LED_CAN2_GPIO_Port GPIOE
#define TOUCH_RST_PC13_Pin GPIO_PIN_13
#define TOUCH_RST_PC13_GPIO_Port GPIOC
#define LCD_VS_PI9_Pin GPIO_PIN_9
#define LCD_VS_PI9_GPIO_Port GPIOI
#define LCD_HS_PI10_Pin GPIO_PIN_10
#define LCD_HS_PI10_GPIO_Port GPIOI
#define TOUCH_INT_PI11_Pin GPIO_PIN_11
#define TOUCH_INT_PI11_GPIO_Port GPIOI
#define SDRAM_A0_PF0_Pin GPIO_PIN_0
#define SDRAM_A0_PF0_GPIO_Port GPIOF
#define SDRAM_A1_PF1_Pin GPIO_PIN_1
#define SDRAM_A1_PF1_GPIO_Port GPIOF
#define SDRAM_A2_PF2_Pin GPIO_PIN_2
#define SDRAM_A2_PF2_GPIO_Port GPIOF
#define SDRAM_A3_PF3_Pin GPIO_PIN_3
#define SDRAM_A3_PF3_GPIO_Port GPIOF
#define SDRAM_A4_PF4_Pin GPIO_PIN_4
#define SDRAM_A4_PF4_GPIO_Port GPIOF
#define SDRAM_A5_PF5_Pin GPIO_PIN_5
#define SDRAM_A5_PF5_GPIO_Port GPIOF
#define CAN1_S0_Pin GPIO_PIN_6
#define CAN1_S0_GPIO_Port GPIOF
#define CAN2_S0_Pin GPIO_PIN_7
#define CAN2_S0_GPIO_Port GPIOF
#define LCD_BL_PF8_Pin GPIO_PIN_8
#define LCD_BL_PF8_GPIO_Port GPIOF
#define LCD_DE_PF10_Pin GPIO_PIN_10
#define LCD_DE_PF10_GPIO_Port GPIOF
#define OSC_IN_Pin GPIO_PIN_0
#define OSC_IN_GPIO_Port GPIOH
#define OSC_OUT_Pin GPIO_PIN_1
#define OSC_OUT_GPIO_Port GPIOH
#define SDRAM_WE_PC0_Pin GPIO_PIN_0
#define SDRAM_WE_PC0_GPIO_Port GPIOC
#define ADC_OUT_1_Pin GPIO_PIN_1
#define ADC_OUT_1_GPIO_Port GPIOC
#define HALL_OUT_Pin GPIO_PIN_2
#define HALL_OUT_GPIO_Port GPIOC
#define BRV_CPU_Pin GPIO_PIN_0
#define BRV_CPU_GPIO_Port GPIOA
#define I2C2_SCL_PH4_Pin GPIO_PIN_4
#define I2C2_SCL_PH4_GPIO_Port GPIOH
#define I2C2_SDA_PH5_Pin GPIO_PIN_5
#define I2C2_SDA_PH5_GPIO_Port GPIOH
#define LCD_R6_PB1_Pin GPIO_PIN_1
#define LCD_R6_PB1_GPIO_Port GPIOB
#define SDRAM_RAS_PF11_Pin GPIO_PIN_11
#define SDRAM_RAS_PF11_GPIO_Port GPIOF
#define SDRAM_A6_PF12_Pin GPIO_PIN_12
#define SDRAM_A6_PF12_GPIO_Port GPIOF
#define SDRAM_A7_PF13_Pin GPIO_PIN_13
#define SDRAM_A7_PF13_GPIO_Port GPIOF
#define SDRAM_A8_PF14_Pin GPIO_PIN_14
#define SDRAM_A8_PF14_GPIO_Port GPIOF
#define SDRAM_A9_PF15_Pin GPIO_PIN_15
#define SDRAM_A9_PF15_GPIO_Port GPIOF
#define SDRAM_A10_PG0_Pin GPIO_PIN_0
#define SDRAM_A10_PG0_GPIO_Port GPIOG
#define SDRAM_A11_PG1_Pin GPIO_PIN_1
#define SDRAM_A11_PG1_GPIO_Port GPIOG
#define SDRAM_D4_PE7_Pin GPIO_PIN_7
#define SDRAM_D4_PE7_GPIO_Port GPIOE
#define SDRAM_D5_PE8_Pin GPIO_PIN_8
#define SDRAM_D5_PE8_GPIO_Port GPIOE
#define SDRAM_D6_PE9_Pin GPIO_PIN_9
#define SDRAM_D6_PE9_GPIO_Port GPIOE
#define SDRAM_D7_PE10_Pin GPIO_PIN_10
#define SDRAM_D7_PE10_GPIO_Port GPIOE
#define SDRAM_D8_PE11_Pin GPIO_PIN_11
#define SDRAM_D8_PE11_GPIO_Port GPIOE
#define SDRAM_D9_PE12_Pin GPIO_PIN_12
#define SDRAM_D9_PE12_GPIO_Port GPIOE
#define SDRAM_D10_PE13_Pin GPIO_PIN_13
#define SDRAM_D10_PE13_GPIO_Port GPIOE
#define SDRAM_D11_PE14_Pin GPIO_PIN_14
#define SDRAM_D11_PE14_GPIO_Port GPIOE
#define SDRAM_D12_PE15_Pin GPIO_PIN_15
#define SDRAM_D12_PE15_GPIO_Port GPIOE
#define ESP_TX_Pin GPIO_PIN_10
#define ESP_TX_GPIO_Port GPIOB
#define ESP_RX_Pin GPIO_PIN_11
#define ESP_RX_GPIO_Port GPIOB
#define SDRAM_CS_PH6_Pin GPIO_PIN_6
#define SDRAM_CS_PH6_GPIO_Port GPIOH
#define SDRAM_CKE_PH7_Pin GPIO_PIN_7
#define SDRAM_CKE_PH7_GPIO_Port GPIOH
#define LCD_R2_PH8_Pin GPIO_PIN_8
#define LCD_R2_PH8_GPIO_Port GPIOH
#define LCD_R3_PH9_Pin GPIO_PIN_9
#define LCD_R3_PH9_GPIO_Port GPIOH
#define LCD_R4_PH10_Pin GPIO_PIN_10
#define LCD_R4_PH10_GPIO_Port GPIOH
#define LCD_R5_PH11_Pin GPIO_PIN_11
#define LCD_R5_PH11_GPIO_Port GPIOH
#define SDRAM_D13_PD8_Pin GPIO_PIN_8
#define SDRAM_D13_PD8_GPIO_Port GPIOD
#define SDRAM_D14_PD9_Pin GPIO_PIN_9
#define SDRAM_D14_PD9_GPIO_Port GPIOD
#define SDRAM_D15_PD10_Pin GPIO_PIN_10
#define SDRAM_D15_PD10_GPIO_Port GPIOD
#define SDRAM_D0_PD14_Pin GPIO_PIN_14
#define SDRAM_D0_PD14_GPIO_Port GPIOD
#define SDRAM_D1_PD15_Pin GPIO_PIN_15
#define SDRAM_D1_PD15_GPIO_Port GPIOD
#define SDRAM_A12_PG2_Pin GPIO_PIN_2
#define SDRAM_A12_PG2_GPIO_Port GPIOG
#define SDRAM_BA0_PG4_Pin GPIO_PIN_4
#define SDRAM_BA0_PG4_GPIO_Port GPIOG
#define SDRAM_BA1_PG5_Pin GPIO_PIN_5
#define SDRAM_BA1_PG5_GPIO_Port GPIOG
#define LCD_R7_PG6_Pin GPIO_PIN_6
#define LCD_R7_PG6_GPIO_Port GPIOG
#define LCD_CLK_PG7_Pin GPIO_PIN_7
#define LCD_CLK_PG7_GPIO_Port GPIOG
#define SDRAM_CLK_PG8_Pin GPIO_PIN_8
#define SDRAM_CLK_PG8_GPIO_Port GPIOG
#define BTN_2_PC6_Pin GPIO_PIN_6
#define BTN_2_PC6_GPIO_Port GPIOC
#define BTN_1_PC7_Pin GPIO_PIN_7
#define BTN_1_PC7_GPIO_Port GPIOC
#define BTN_4_PE5_Pin GPIO_PIN_8
#define BTN_4_PE5_GPIO_Port GPIOC
#define BTN_3_PE4_Pin GPIO_PIN_9
#define BTN_3_PE4_GPIO_Port GPIOC
#define USB_OTG__Pin GPIO_PIN_11
#define USB_OTG__GPIO_Port GPIOA
#define USB_OTG_A12_Pin GPIO_PIN_12
#define USB_OTG_A12_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define LCD_G2_PH13_Pin GPIO_PIN_13
#define LCD_G2_PH13_GPIO_Port GPIOH
#define LCD_G3_PH14_Pin GPIO_PIN_14
#define LCD_G3_PH14_GPIO_Port GPIOH
#define LCD_G4_PH15_Pin GPIO_PIN_15
#define LCD_G4_PH15_GPIO_Port GPIOH
#define LCD_G5_PI0_Pin GPIO_PIN_0
#define LCD_G5_PI0_GPIO_Port GPIOI
#define LCD_G6_PI1_Pin GPIO_PIN_1
#define LCD_G6_PI1_GPIO_Port GPIOI
#define LCD_G7_PI2_Pin GPIO_PIN_2
#define LCD_G7_PI2_GPIO_Port GPIOI
#define SD_CS_PIN_Pin GPIO_PIN_3
#define SD_CS_PIN_GPIO_Port GPIOI
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define SDRAM_D2_PD0_Pin GPIO_PIN_0
#define SDRAM_D2_PD0_GPIO_Port GPIOD
#define SDRAM_D3_PD1_Pin GPIO_PIN_1
#define SDRAM_D3_PD1_GPIO_Port GPIOD
#define IN_S0_Pin GPIO_PIN_2
#define IN_S0_GPIO_Port GPIOD
#define IN_S1_Pin GPIO_PIN_3
#define IN_S1_GPIO_Port GPIOD
#define IN_S2_Pin GPIO_PIN_4
#define IN_S2_GPIO_Port GPIOD
#define LCD_B2_PD6_Pin GPIO_PIN_6
#define LCD_B2_PD6_GPIO_Port GPIOD
#define PUD_E_Pin GPIO_PIN_7
#define PUD_E_GPIO_Port GPIOD
#define IN_E_Pin GPIO_PIN_9
#define IN_E_GPIO_Port GPIOG
#define OUT_S0_Pin GPIO_PIN_10
#define OUT_S0_GPIO_Port GPIOG
#define LCD_B3_PG11_Pin GPIO_PIN_11
#define LCD_B3_PG11_GPIO_Port GPIOG
#define PUD_S2_Pin GPIO_PIN_12
#define PUD_S2_GPIO_Port GPIOG
#define PUD_S1_Pin GPIO_PIN_13
#define PUD_S1_GPIO_Port GPIOG
#define PUD_S0_Pin GPIO_PIN_14
#define PUD_S0_GPIO_Port GPIOG
#define SDRAM_CAS_PG15_Pin GPIO_PIN_15
#define SDRAM_CAS_PG15_GPIO_Port GPIOG
#define SPI1_FLASH_Pin GPIO_PIN_7
#define SPI1_FLASH_GPIO_Port GPIOB
#define SDRAM_NBL0_PE0_Pin GPIO_PIN_0
#define SDRAM_NBL0_PE0_GPIO_Port GPIOE
#define SDRAM_NBL1_PE1_Pin GPIO_PIN_1
#define SDRAM_NBL1_PE1_GPIO_Port GPIOE
#define LCD_B4_PI4_Pin GPIO_PIN_4
#define LCD_B4_PI4_GPIO_Port GPIOI
#define LCD_B5_PI5_Pin GPIO_PIN_5
#define LCD_B5_PI5_GPIO_Port GPIOI
#define LCD_B6_PI6_Pin GPIO_PIN_6
#define LCD_B6_PI6_GPIO_Port GPIOI
#define LCD_B7_PI7_Pin GPIO_PIN_7
#define LCD_B7_PI7_GPIO_Port GPIOI
/* USER CODE BEGIN Private defines */
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
