/**
 * @file ws2812.h
 *
 * @date 25.03.2025
 * @author Benas Brazdziunas
 */

#ifndef WS2812_HPP_
#define WS2812_HPP_

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include "stm32f4xx_hal.h"


#define CONCAT_SYMBOLS(s1, s2) s1##s2
#define CONCAT_EXPANDED_SYMBOLS(s1, s2) CONCAT_SYMBOLS(s1, s2)

#define WS2812_LED_N    22 // Number of LEDs
#define WS2812_PORT     GPIOA
#define WS2812_PIN      2
#define WS2812_TIM_N    2  // timer, 1-11
#define WS2812_TIM_CH   3 // timer channel, 0-3

#define WS2812_PWM_TIMER CONCAT_EXPANDED_SYMBOLS(TIM, WS2812_TIM_N)
#define WS2812_PWM_TIM_CH CONCAT_EXPANDED_SYMBOLS(TIM_CHANNEL_, WS2812_TIM_CH)
#define WS2812_PWM_DRIVER CONCAT_EXPANDED_SYMBOLS(htim, WS2812_TIM_N)
#define WS2812_PWM_PIN CONCAT_EXPANDED_SYMBOLS(GPIO_PIN_, WS2812_PIN)

#define WS2812_BUFLEN ((WS2812_LED_N + 4) * 24)

#define WS2812_PWM_FREQUENCY (HAL_RCC_GetHCLKFreq() / 2)
#define WS2812_PWM_PERIOD (WS2812_PWM_FREQUENCY / 800000)

#define WS2812_DUTYCYCLE_0 (WS2812_PWM_FREQUENCY / (1000000000 / 300))
#define WS2812_DUTYCYCLE_1 (WS2812_PWM_FREQUENCY / (1000000000 / 700))


typedef struct {
  uint8_t red;
  uint8_t green;
  uint8_t blue;
} WS2812_RGB_t;

void initWS2812();

void clearWS2812One(uint32_t num);
void clearWS2812All();
void setWS2812One(uint32_t num, WS2812_RGB_t rgb_col);
void setWS2812All(WS2812_RGB_t rgb_col);
void setWS2812Brightness(uint8_t num);

void DMA1_Stream1_IRQHandler(void);

void updateWS2812();

void ConfigureTimerPeripheral();
void ConfigureTimerGPIO(void);
void ConfigureTimerChannel(void);
void ConfigureDMA(void);


#ifdef __cplusplus
}
#endif

#endif /* WS2812_HPP_ */

