/**
 * @file WS2812.cpp
 * @brief WS2812 RGB LED driver
 *
 * @date 25.03.2023
 * @author Benas Brazdziunas
 */

#include "WS2812.hpp"


static WS2812_RGB_t WS2812_LED_BUF[WS2812_LED_N];
static uint32_t WS2812_TIM_BUF[WS2812_BUFLEN];
static uint8_t WS2812_BRIGHTNESS = 5;
static bool WS2812_INVERT_ORDER = true;
static bool WS2812_DMA_READY = false;

TIM_HandleTypeDef WS2812_PWM_DRIVER;
DMA_HandleTypeDef WS2812_PWM_DMA;

extern void DMA1_Stream1_IRQHandler(void);

void initWS2812()
{

	uint32_t freq = HAL_RCC_GetHCLKFreq();
	ConfigureTimerGPIO();
	ConfigureTimerPeripheral();
	ConfigureDMA();
	ConfigureTimerChannel();
	//HAL_TIM_PWM_Start(&WS2812_PWM_DRIVER, WS2812_PWM_TIM_CH);
	HAL_TIM_PWM_Start_DMA(&WS2812_PWM_DRIVER, WS2812_PWM_TIM_CH, (uint32_t *)WS2812_TIM_BUF, WS2812_BUFLEN);
}

/**
 * Set one LEDs to 0 (off)
 */
void clearWS2812One(uint32_t num)
{
	if (num < WS2812_LED_N)
	{
		WS2812_LED_BUF[num] = (WS2812_RGB_t){0, 0, 0};
	}
}

/**
 * Set all LEDs to 0 (off)
 */
void clearWS2812All()
{
	for (uint16_t num = 0; num < WS2812_LED_N; num++)
	{
		WS2812_LED_BUF[num] = (WS2812_RGB_t){0, 0, 0};
	}
}

/**
 * Set one LED (R, G, B values).
 */
void setWS2812One(uint32_t num, WS2812_RGB_t rgb_col)
{
	if (num < WS2812_LED_N)
	{
		WS2812_LED_BUF[num] = rgb_col;
	}
}

/**
 * Set all LEDs (R, G, B values).
 */
void setWS2812All(WS2812_RGB_t rgb_col)
{
	for (uint16_t num = 0; num < WS2812_LED_N; num++)
	{
		WS2812_LED_BUF[num] = rgb_col;
	}
}

/**
 * Set all LEDs Brightness.
 */
void setWS2812Brightness(uint8_t num)
{
	num = num >= 100 ? 100 : num;
	num = num <= 0 ? 0 : num;
	WS2812_BRIGHTNESS = num;
}

/**
 * Calculate Timer DMA buffer
 */
void updateWS2812()
{
    while(!WS2812_DMA_READY);

    uint32_t pos = WS2812_INVERT_ORDER ? (WS2812_LED_N * 24) : 0;

	for (uint32_t num = 0; num < WS2812_LED_N; num++)
	{
		WS2812_RGB_t led = WS2812_LED_BUF[num];
		float brightness = WS2812_BRIGHTNESS / 100.0;

		led.red = (uint8_t)(led.red * brightness);
		led.green = (uint8_t)(led.green * brightness);
		led.blue = (uint8_t)(led.blue * brightness);

		if(WS2812_INVERT_ORDER)
		{
			// Col:Blue , Bit:7..0
			WS2812_TIM_BUF[pos--] = ((led.blue & 0x80) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos--] = ((led.blue & 0x40) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos--] = ((led.blue & 0x20) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos--] = ((led.blue & 0x10) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos--] = ((led.blue & 0x08) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos--] = ((led.blue & 0x04) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos--] = ((led.blue & 0x02) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos--] = ((led.blue & 0x01) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;

			// Col:Red , Bit:7..0
			WS2812_TIM_BUF[pos--] = ((led.red & 0x80) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos--] = ((led.red & 0x40) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos--] = ((led.red & 0x20) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos--] = ((led.red & 0x10) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos--] = ((led.red & 0x08) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos--] = ((led.red & 0x04) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos--] = ((led.red & 0x02) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos--] = ((led.red & 0x01) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;

			// Col:Green , Bit:7..0
			WS2812_TIM_BUF[pos--] = ((led.green & 0x80) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos--] = ((led.green & 0x40) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos--] = ((led.green & 0x20) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos--] = ((led.green & 0x10) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos--] = ((led.green & 0x08) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos--] = ((led.green & 0x04) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos--] = ((led.green & 0x02) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos--] = ((led.green & 0x01) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;

		} else {

			// Col:Green , Bit:7..0
			WS2812_TIM_BUF[pos++] = ((led.green & 0x80) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos++] = ((led.green & 0x40) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos++] = ((led.green & 0x20) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos++] = ((led.green & 0x10) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos++] = ((led.green & 0x08) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos++] = ((led.green & 0x04) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos++] = ((led.green & 0x02) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos++] = ((led.green & 0x01) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;

			// Col:Red , Bit:7..0
			WS2812_TIM_BUF[pos++] = ((led.red & 0x80) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos++] = ((led.red & 0x40) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos++] = ((led.red & 0x20) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos++] = ((led.red & 0x10) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos++] = ((led.red & 0x08) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos++] = ((led.red & 0x04) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos++] = ((led.red & 0x02) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos++] = ((led.red & 0x01) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;

			// Col:Blue , Bit:7..0
			WS2812_TIM_BUF[pos++] = ((led.blue & 0x80) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos++] = ((led.blue & 0x40) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos++] = ((led.blue & 0x20) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos++] = ((led.blue & 0x10) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos++] = ((led.blue & 0x08) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos++] = ((led.blue & 0x04) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos++] = ((led.blue & 0x02) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
			WS2812_TIM_BUF[pos++] = ((led.blue & 0x01) != 0) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
		}
	}
	HAL_TIM_PWM_Start_DMA(&WS2812_PWM_DRIVER, WS2812_PWM_TIM_CH, (uint32_t *)WS2812_TIM_BUF, WS2812_BUFLEN);
	WS2812_DMA_READY = false;
}

void ConfigureTimerPeripheral()
{
	TIM_ClockConfigTypeDef sClockSourceConfig = {0};

	__HAL_RCC_TIM2_CLK_ENABLE();

	WS2812_PWM_DRIVER.Instance = WS2812_PWM_TIMER;
	WS2812_PWM_DRIVER.Init.CounterMode = TIM_COUNTERMODE_UP;
	WS2812_PWM_DRIVER.Init.RepetitionCounter = 0;
	WS2812_PWM_DRIVER.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	WS2812_PWM_DRIVER.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	WS2812_PWM_DRIVER.Init.Period = WS2812_PWM_PERIOD - 1;
	WS2812_PWM_DRIVER.Init.Prescaler = 0;

	if (HAL_TIM_Base_Init(&WS2812_PWM_DRIVER) != HAL_OK)
	{
		return;
	}


	sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if (HAL_TIM_ConfigClockSource(&WS2812_PWM_DRIVER, &sClockSourceConfig) != HAL_OK)
	{
		return;
	}

	ConfigureDMA();

	if (HAL_TIM_PWM_Init(&WS2812_PWM_DRIVER) != HAL_OK)
	{
		return;
	}
}

void ConfigureTimerGPIO(void)
{


	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

	GPIO_InitStruct.Alternate = GPIO_AF1_TIM2;

	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitStruct.Pin = WS2812_PWM_PIN;

	HAL_GPIO_Init(WS2812_PORT, &GPIO_InitStruct);
}

void ConfigureTimerChannel(void)
{
	TIM_OC_InitTypeDef sConfigOC = {0};

	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.Pulse = 0;//WS2812_PWM_PERIOD / 2;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
	sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;

	// Configure channel
	if (HAL_TIM_PWM_ConfigChannel(&WS2812_PWM_DRIVER, &sConfigOC, WS2812_PWM_TIM_CH) != HAL_OK)
	{
		return;
	}
}

void ConfigureDMA(void)
{
	// See DMA mapping on page 226 in Reference Manual

	/* Enable DMA clock */
	__HAL_RCC_DMA1_CLK_ENABLE();
	/*##- 3- Configure DMA #####################################################*/
	/*********************** Configure DMA parameters ***************************/
	WS2812_PWM_DMA.Instance = DMA1_Stream1;
	WS2812_PWM_DMA.Init.Channel = DMA_CHANNEL_3;

	WS2812_PWM_DMA.Init.Direction           = DMA_MEMORY_TO_PERIPH;
	WS2812_PWM_DMA.Init.PeriphInc           = DMA_PINC_DISABLE;
	WS2812_PWM_DMA.Init.MemInc              = DMA_MINC_ENABLE;
	WS2812_PWM_DMA.Init.PeriphDataAlignment = DMA_PDATAALIGN_WORD;
	WS2812_PWM_DMA.Init.MemDataAlignment    = DMA_PDATAALIGN_WORD;
	WS2812_PWM_DMA.Init.Mode                = DMA_NORMAL;
	WS2812_PWM_DMA.Init.Priority            = DMA_PRIORITY_LOW;
	WS2812_PWM_DMA.Init.FIFOMode 		 	= DMA_FIFOMODE_DISABLE;

	/* Associate the DMA handle */
	__HAL_LINKDMA(&WS2812_PWM_DRIVER, hdma[TIM_DMA_ID_CC3], WS2812_PWM_DMA);
//
//	/* Initialize DMA handle */
	HAL_DMA_Init(WS2812_PWM_DRIVER.hdma[TIM_DMA_ID_CC3]);
//
//	/* NVIC configuration for DMA transfer complete interrupt */
	HAL_NVIC_SetPriority(DMA1_Stream1_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(DMA1_Stream1_IRQn);
//
}

void DMA1_Stream1_IRQHandler(void)
{
	WS2812_DMA_READY = true;
	HAL_DMA_IRQHandler(WS2812_PWM_DRIVER.hdma[TIM_DMA_ID_CC3]);
}
