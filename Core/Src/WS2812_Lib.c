/**
 * WS2812 Neopixel LED driver for STM32
 * Based upon the WS2812 Library for STM32F4 from Uwe Becker, http://mikrocontroller.bplaced.net/wordpress/?page_id=3665
 *
 * @Author: Nicolas Dammin, 2016
 */
#include "WS2812_Lib.h"

uint16_t WS2812_TIM_BUF[WS2812_BUFLEN];
uint8_t dma_ready = 1;

void DMA_Callback(void) {
	dma_ready = 1;
}
/**
 * Internal function, calculates the HI or LO values for the 800 kHz WS2812 signal and puts them into a buffer for the Timer-DMA
 *
 */
void calcBuf(void)
{
  uint32_t n;
  uint32_t pos;

  pos=0;
  // set timings for all LEDs
  for(n=0;n<WS2812_NUM_LEDS_CH1;n++) {

	WS2812_RGB_t led = WS2812_LED_BUF_CH1[n];
	float brightness = Current_Status.LED_BRIGHTNESS / 100.0;

    led.red = (uint8_t)(led.red * brightness);
    led.green = (uint8_t)(led.green * brightness);
    led.blue = (uint8_t)(led.blue * brightness);

    // Col:Red , Bit:7..0
    WS2812_TIM_BUF[pos++]=((led.red&0x80) != 0)?WS2812_HI_TIME:WS2812_LO_TIME;
	WS2812_TIM_BUF[pos++]=((led.red&0x40) != 0)?WS2812_HI_TIME:WS2812_LO_TIME;
	WS2812_TIM_BUF[pos++]=((led.red&0x20) != 0)?WS2812_HI_TIME:WS2812_LO_TIME;
	WS2812_TIM_BUF[pos++]=((led.red&0x10) != 0)?WS2812_HI_TIME:WS2812_LO_TIME;
	WS2812_TIM_BUF[pos++]=((led.red&0x08) != 0)?WS2812_HI_TIME:WS2812_LO_TIME;
	WS2812_TIM_BUF[pos++]=((led.red&0x04) != 0)?WS2812_HI_TIME:WS2812_LO_TIME;
	WS2812_TIM_BUF[pos++]=((led.red&0x02) != 0)?WS2812_HI_TIME:WS2812_LO_TIME;
	WS2812_TIM_BUF[pos++]=((led.red&0x01) != 0)?WS2812_HI_TIME:WS2812_LO_TIME;

    // Col:Green , Bit:7..0
    WS2812_TIM_BUF[pos++]=((led.green&0x80) != 0)?WS2812_HI_TIME:WS2812_LO_TIME;
    WS2812_TIM_BUF[pos++]=((led.green&0x40) != 0)?WS2812_HI_TIME:WS2812_LO_TIME;
    WS2812_TIM_BUF[pos++]=((led.green&0x20) != 0)?WS2812_HI_TIME:WS2812_LO_TIME;
    WS2812_TIM_BUF[pos++]=((led.green&0x10) != 0)?WS2812_HI_TIME:WS2812_LO_TIME;
    WS2812_TIM_BUF[pos++]=((led.green&0x08) != 0)?WS2812_HI_TIME:WS2812_LO_TIME;
    WS2812_TIM_BUF[pos++]=((led.green&0x04) != 0)?WS2812_HI_TIME:WS2812_LO_TIME;
    WS2812_TIM_BUF[pos++]=((led.green&0x02) != 0)?WS2812_HI_TIME:WS2812_LO_TIME;
    WS2812_TIM_BUF[pos++]=((led.green&0x01) != 0)?WS2812_HI_TIME:WS2812_LO_TIME;

	// Col:Blue , Bit:7..0
	WS2812_TIM_BUF[pos++]=((led.blue&0x80) != 0)?WS2812_HI_TIME:WS2812_LO_TIME;
	WS2812_TIM_BUF[pos++]=((led.blue&0x40) != 0)?WS2812_HI_TIME:WS2812_LO_TIME;
	WS2812_TIM_BUF[pos++]=((led.blue&0x20) != 0)?WS2812_HI_TIME:WS2812_LO_TIME;
	WS2812_TIM_BUF[pos++]=((led.blue&0x10) != 0)?WS2812_HI_TIME:WS2812_LO_TIME;
	WS2812_TIM_BUF[pos++]=((led.blue&0x08) != 0)?WS2812_HI_TIME:WS2812_LO_TIME;
	WS2812_TIM_BUF[pos++]=((led.blue&0x04) != 0)?WS2812_HI_TIME:WS2812_LO_TIME;
	WS2812_TIM_BUF[pos++]=((led.blue&0x02) != 0)?WS2812_HI_TIME:WS2812_LO_TIME;
	WS2812_TIM_BUF[pos++]=((led.blue&0x01) != 0)?WS2812_HI_TIME:WS2812_LO_TIME;
  }

  // short pause after all LEDs have been updated
//  for(n=0;n<(WS2812_NUM_LEDS_CH1+2);n++) {
//    WS2812_TIM_BUF[pos++]=0;
//  }
}

/**
 * Internal function; start DMA transfer
 */
void startDMA(void) {
	dma_ready = 0;
	  if (HAL_TIM_PWM_Start_DMA(&htim1, TIM_CHANNEL_1, (uint32_t *)WS2812_TIM_BUF, WS2812_BUFLEN) != HAL_OK)
	  {

	  }
}

void WS2812_Refresh(void) {
	while(!dma_ready);
	calcBuf();
	startDMA();
}

/**
 * Set all LEDs to 0 (off) and update
 */
void WS2812_Clear(uint8_t refresh) {
	uint16_t num;

	for(num = 0; num < WS2812_NUM_LEDS_CH1; num++) {
		WS2812_LED_BUF_CH1[num] = (WS2812_RGB_t){0,0,0};
	}

	 if(refresh==1) WS2812_Refresh();
}

/**
 * Set one LED (R, G, B values). If refresh == 1, update LEDs, otherwise just update buffer (if several function calls are to be done before refresh)
 */
void WS2812_One_RGB(uint32_t nr, WS2812_RGB_t rgb_col, uint8_t refresh)
{
  if(nr<WS2812_NUM_LEDS_CH1) {
	  WS2812_LED_BUF_CH1[nr]=rgb_col;

    if(refresh==1) WS2812_Refresh();
  }
}

/**
 * Set all LEDs (R, G, B values). If refresh == 1, update LEDs, otherwise just update buffer (if several function calls are to be done before refresh)
 */
void WS2812_All_RGB(WS2812_RGB_t rgb_col, uint8_t refresh)
{
  uint32_t n;

  for(n=0;n<WS2812_NUM_LEDS_CH1;n++) {
	  WS2812_LED_BUF_CH1[n]=rgb_col;
  }
  if(refresh==1) WS2812_Refresh();
}

