#ifndef __WS2812_H
#define __WS2812_H

#pragma once

#include "extern.h"
#include "stm32f4xx_hal.h"

TIM_HandleTypeDef htim1;

#define WS2812_NUM_LEDS_CH1		LED_NUMBER

#define  WS2812_TIM_PERIODE   	htim1.Instance->ARR //52  // F_PWM 84000000/800000 = 225 -> 800 kHz (1.25us)

#define  WS2812_LO_TIME        	(WS2812_TIM_PERIODE / (1.25 / 0.22)) - 1	  //(1.25 / 0.22) 0.220us - 0.380us
#define  WS2812_HI_TIME         (WS2812_TIM_PERIODE / (1.25 / 0.58)) - 1  //(1.25 / 0.58) 0.580us - 1us

//--------------------------------------------------------------
// RGB LED Farbdefinition (3 x 8bit)
//--------------------------------------------------------------
typedef struct {
  uint8_t red;    // 0...255 (als PWM-Wert)
  uint8_t green;  // 0...255 (als PWM-Wert)
  uint8_t blue;   // 0...255 (als PWM-Wert)
}WS2812_RGB_t;

WS2812_RGB_t WS2812_LED_BUF_CH1[WS2812_NUM_LEDS_CH1];

#define WS2812_BUFLEN	(WS2812_NUM_LEDS_CH1+2)*24

//Interrupt Callback
void DMA_Callback(void);

//Library Interface
void WS2812_Refresh(void);
void WS2812_Clear(uint8_t refresh);
void WS2812_One_RGB(uint32_t nr, WS2812_RGB_t rgb_col, uint8_t refresh);
void WS2812_All_RGB(WS2812_RGB_t rgb_col, uint8_t refresh);


#endif // __WS2812_H


