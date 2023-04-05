/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"
#include "app_touchgfx.h"
#include "usb_device.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
//#include <File_Handling.h>
#include <stdio.h>
#include "Globals.h"
#include "extern.h"
#include "sdram.h"
#include "WS2812/WS2812.hpp"

//Setup
#include "Setup/Dash/setupDash.h"
#include "Setup/Field/setupField.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
//#define LCD_ORIENTATION_LANDSCAPE 0x01

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;

CAN_HandleTypeDef hcan1;

CRC_HandleTypeDef hcrc;

DMA2D_HandleTypeDef hdma2d;

LTDC_HandleTypeDef hltdc;

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim13;

SDRAM_HandleTypeDef hsdram1;

/* Definitions for START_Task */
osThreadId_t START_TaskHandle;
const osThreadAttr_t START_Task_attributes = {
  .name = "START_Task",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for TouchGFXTask */
osThreadId_t TouchGFXTaskHandle;
const osThreadAttr_t TouchGFXTask_attributes = {
  .name = "TouchGFXTask",
  .stack_size = 2048 * 4,
  .priority = (osPriority_t) osPriorityHigh,
};
/* Definitions for LED_Task */
osThreadId_t LED_TaskHandle;
const osThreadAttr_t LED_Task_attributes = {
  .name = "LED_Task",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for CAN_Task */
osThreadId_t CAN_TaskHandle;
const osThreadAttr_t CAN_Task_attributes = {
  .name = "CAN_Task",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for ALERT_Task */
osThreadId_t ALERT_TaskHandle;
const osThreadAttr_t ALERT_Task_attributes = {
  .name = "ALERT_Task",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for RGB_Task */
osThreadId_t RGB_TaskHandle;
const osThreadAttr_t RGB_Task_attributes = {
  .name = "RGB_Task",
  .stack_size = 512 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* USER CODE BEGIN PV */
FMC_SDRAM_CommandTypeDef command;

Statuses Current_Status;

CAN_TxHeaderTypeDef TxHeader;
CAN_RxHeaderTypeDef RxHeader;
uint8_t TxData[8];
uint8_t RxData[8];

uint8_t uartTransmitBufferSize;
uint8_t uartTransmitBuffer[128];

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_LTDC_Init(void);
static void MX_DMA2D_Init(void);
static void MX_FMC_Init(void);
static void MX_CRC_Init(void);
static void MX_TIM13_Init(void);
static void MX_CAN1_Init(void);
static void MX_ADC1_Init(void);
static void MX_TIM1_Init(void);
void Start_START_Task(void *argument);
void TouchGFX_Task(void *argument);
void Start_LED_Task(void *argument);
void Start_CAN_Task(void *argument);
void Start_ALERT_Task(void *argument);
void Start_RGB_Task(void *argument);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
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
  MX_LTDC_Init();
  MX_DMA2D_Init();
  MX_FMC_Init();
  MX_CRC_Init();
  MX_TIM13_Init();
  MX_CAN1_Init();
  MX_ADC1_Init();
  MX_TIM1_Init();
  MX_TouchGFX_Init();
  /* Call PreOsInit function */
  MX_TouchGFX_PreOSInit();
  /* USER CODE BEGIN 2 */

  HAL_TIM_PWM_Start(&htim13, TIM_CHANNEL_1);
  initWS2812();

  /* USER CODE END 2 */

  /* Init scheduler */
  osKernelInitialize();

  /* USER CODE BEGIN RTOS_MUTEX */
	/* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
	/* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
	/* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
	/* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of START_Task */
  START_TaskHandle = osThreadNew(Start_START_Task, NULL, &START_Task_attributes);

  /* creation of TouchGFXTask */
  TouchGFXTaskHandle = osThreadNew(TouchGFX_Task, NULL, &TouchGFXTask_attributes);

  /* creation of LED_Task */
  LED_TaskHandle = osThreadNew(Start_LED_Task, NULL, &LED_Task_attributes);

  /* creation of CAN_Task */
  CAN_TaskHandle = osThreadNew(Start_CAN_Task, NULL, &CAN_Task_attributes);

  /* creation of ALERT_Task */
  ALERT_TaskHandle = osThreadNew(Start_ALERT_Task, NULL, &ALERT_Task_attributes);

  /* creation of RGB_Task */
  RGB_TaskHandle = osThreadNew(Start_RGB_Task, NULL, &RGB_Task_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
	/* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
	/* add events, ... */
  /* USER CODE END RTOS_EVENTS */

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

	while (1) {
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

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 6;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }

  /** Enables the Clock Security System
  */
  HAL_RCC_EnableCSS();
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_11;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief CAN1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_CAN1_Init(void)
{

  /* USER CODE BEGIN CAN1_Init 0 */

	CAN_FilterTypeDef sFilterConfig; //declare CAN filter structure
  /* USER CODE END CAN1_Init 0 */

  /* USER CODE BEGIN CAN1_Init 1 */

  /* USER CODE END CAN1_Init 1 */
  hcan1.Instance = CAN1;
  hcan1.Init.Prescaler = 12;
  hcan1.Init.Mode = CAN_MODE_NORMAL;
  hcan1.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan1.Init.TimeSeg1 = CAN_BS1_4TQ;
  hcan1.Init.TimeSeg2 = CAN_BS2_2TQ;
  hcan1.Init.TimeTriggeredMode = DISABLE;
  hcan1.Init.AutoBusOff = DISABLE;
  hcan1.Init.AutoWakeUp = DISABLE;
  hcan1.Init.AutoRetransmission = DISABLE;
  hcan1.Init.ReceiveFifoLocked = DISABLE;
  hcan1.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CAN1_Init 2 */
	sFilterConfig.FilterBank = 15;
	sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
	sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
	sFilterConfig.FilterIdHigh = 0x0000;
	sFilterConfig.FilterIdLow = 0x0000;
	sFilterConfig.FilterMaskIdHigh = 0x0000;
	sFilterConfig.FilterMaskIdLow = 0x0000;
	sFilterConfig.FilterFIFOAssignment = CAN_RX_FIFO0;
	sFilterConfig.FilterActivation = ENABLE;
	//sFilterConfig.SlaveStartFilterBank = 14;
	if (HAL_CAN_ConfigFilter(&hcan1, &sFilterConfig) != HAL_OK) {
		/* Filter configuration Error */
		Error_Handler();
	}
	if (HAL_CAN_Start(&hcan1) != HAL_OK) {
		/* Start Error */
		Error_Handler();
	}

	__HAL_RCC_CAN1_CLK_ENABLE();
	//__HAL_RCC_CAN2_CLK_ENABLE();
  /* USER CODE END CAN1_Init 2 */

}

/**
  * @brief CRC Initialization Function
  * @param None
  * @retval None
  */
static void MX_CRC_Init(void)
{

  /* USER CODE BEGIN CRC_Init 0 */

  /* USER CODE END CRC_Init 0 */

  /* USER CODE BEGIN CRC_Init 1 */

  /* USER CODE END CRC_Init 1 */
  hcrc.Instance = CRC;
  if (HAL_CRC_Init(&hcrc) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CRC_Init 2 */

  /* USER CODE END CRC_Init 2 */

}

/**
  * @brief DMA2D Initialization Function
  * @param None
  * @retval None
  */
static void MX_DMA2D_Init(void)
{

  /* USER CODE BEGIN DMA2D_Init 0 */

  /* USER CODE END DMA2D_Init 0 */

  /* USER CODE BEGIN DMA2D_Init 1 */

  /* USER CODE END DMA2D_Init 1 */
  hdma2d.Instance = DMA2D;
  hdma2d.Init.Mode = DMA2D_M2M_BLEND;
  hdma2d.Init.ColorMode = DMA2D_OUTPUT_RGB565;
  hdma2d.Init.OutputOffset = 0;
  hdma2d.LayerCfg[0].InputOffset = 0;
  hdma2d.LayerCfg[0].InputColorMode = DMA2D_INPUT_RGB565;
  hdma2d.LayerCfg[0].AlphaMode = DMA2D_NO_MODIF_ALPHA;
  hdma2d.LayerCfg[0].InputAlpha = 0;
  hdma2d.LayerCfg[1].InputOffset = 0;
  hdma2d.LayerCfg[1].InputColorMode = DMA2D_INPUT_RGB565;
  hdma2d.LayerCfg[1].AlphaMode = DMA2D_NO_MODIF_ALPHA;
  hdma2d.LayerCfg[1].InputAlpha = 0;
  if (HAL_DMA2D_Init(&hdma2d) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_DMA2D_ConfigLayer(&hdma2d, 0) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_DMA2D_ConfigLayer(&hdma2d, 1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN DMA2D_Init 2 */

  /* USER CODE END DMA2D_Init 2 */

}

/**
  * @brief LTDC Initialization Function
  * @param None
  * @retval None
  */
static void MX_LTDC_Init(void)
{

  /* USER CODE BEGIN LTDC_Init 0 */

  /* USER CODE END LTDC_Init 0 */

  LTDC_LayerCfgTypeDef pLayerCfg = {0};

  /* USER CODE BEGIN LTDC_Init 1 */

  /* USER CODE END LTDC_Init 1 */
  hltdc.Instance = LTDC;
  hltdc.Init.HSPolarity = LTDC_HSPOLARITY_AL;
  hltdc.Init.VSPolarity = LTDC_VSPOLARITY_AL;
  hltdc.Init.DEPolarity = LTDC_DEPOLARITY_AL;
  hltdc.Init.PCPolarity = LTDC_PCPOLARITY_IPC;
  hltdc.Init.HorizontalSync = 1;
  hltdc.Init.VerticalSync = 19;
  hltdc.Init.AccumulatedHBP = 3;
  hltdc.Init.AccumulatedVBP = 59;
  hltdc.Init.AccumulatedActiveW = 483;
  hltdc.Init.AccumulatedActiveH = 1339;
  hltdc.Init.TotalWidth = 485;
  hltdc.Init.TotalHeigh = 1349;
  hltdc.Init.Backcolor.Blue = 0;
  hltdc.Init.Backcolor.Green = 0;
  hltdc.Init.Backcolor.Red = 0;
  if (HAL_LTDC_Init(&hltdc) != HAL_OK)
  {
    Error_Handler();
  }
  pLayerCfg.WindowX0 = 0;
  pLayerCfg.WindowX1 = 480;
  pLayerCfg.WindowY0 = 0;
  pLayerCfg.WindowY1 = 1280;
  pLayerCfg.PixelFormat = LTDC_PIXEL_FORMAT_RGB565;
  pLayerCfg.Alpha = 255;
  pLayerCfg.Alpha0 = 0;
  pLayerCfg.BlendingFactor1 = LTDC_BLENDING_FACTOR1_PAxCA;
  pLayerCfg.BlendingFactor2 = LTDC_BLENDING_FACTOR2_PAxCA;
  pLayerCfg.FBStartAdress = 0xD0000000;
  pLayerCfg.ImageWidth = 480;
  pLayerCfg.ImageHeight = 1280;
  pLayerCfg.Backcolor.Blue = 0;
  pLayerCfg.Backcolor.Green = 0;
  pLayerCfg.Backcolor.Red = 0;
  if (HAL_LTDC_ConfigLayer(&hltdc, &pLayerCfg, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN LTDC_Init 2 */

  /* USER CODE END LTDC_Init 2 */

}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 0;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 210;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */

}

/**
  * @brief TIM13 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM13_Init(void)
{

  /* USER CODE BEGIN TIM13_Init 0 */

  /* USER CODE END TIM13_Init 0 */

  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM13_Init 1 */

  /* USER CODE END TIM13_Init 1 */
  htim13.Instance = TIM13;
  htim13.Init.Prescaler = 90-1;
  htim13.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim13.Init.Period = 1000-1;
  htim13.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim13.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim13) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim13) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim13, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM13_Init 2 */

  /* USER CODE END TIM13_Init 2 */
  HAL_TIM_MspPostInit(&htim13);

}

/* FMC initialization function */
static void MX_FMC_Init(void)
{

  /* USER CODE BEGIN FMC_Init 0 */

  /* USER CODE END FMC_Init 0 */

  FMC_SDRAM_TimingTypeDef SdramTiming = {0};

  /* USER CODE BEGIN FMC_Init 1 */

  /* USER CODE END FMC_Init 1 */

  /** Perform the SDRAM1 memory initialization sequence
  */
  hsdram1.Instance = FMC_SDRAM_DEVICE;
  /* hsdram1.Init */
  hsdram1.Init.SDBank = FMC_SDRAM_BANK2;
  hsdram1.Init.ColumnBitsNumber = FMC_SDRAM_COLUMN_BITS_NUM_9;
  hsdram1.Init.RowBitsNumber = FMC_SDRAM_ROW_BITS_NUM_13;
  hsdram1.Init.MemoryDataWidth = FMC_SDRAM_MEM_BUS_WIDTH_16;
  hsdram1.Init.InternalBankNumber = FMC_SDRAM_INTERN_BANKS_NUM_4;
  hsdram1.Init.CASLatency = FMC_SDRAM_CAS_LATENCY_3;
  hsdram1.Init.WriteProtection = FMC_SDRAM_WRITE_PROTECTION_DISABLE;
  hsdram1.Init.SDClockPeriod = FMC_SDRAM_CLOCK_PERIOD_2;
  hsdram1.Init.ReadBurst = FMC_SDRAM_RBURST_ENABLE;
  hsdram1.Init.ReadPipeDelay = FMC_SDRAM_RPIPE_DELAY_1;
  /* SdramTiming */
  SdramTiming.LoadToActiveDelay = 2;
  SdramTiming.ExitSelfRefreshDelay = 8;
  SdramTiming.SelfRefreshTime = 6;
  SdramTiming.RowCycleDelay = 7;
  SdramTiming.WriteRecoveryTime = 5;
  SdramTiming.RPDelay = 2;
  SdramTiming.RCDDelay = 2;

  if (HAL_SDRAM_Init(&hsdram1, &SdramTiming) != HAL_OK)
  {
    Error_Handler( );
  }

  /* USER CODE BEGIN FMC_Init 2 */
	FMC_SDRAM_CommandTypeDef command;
	if (SDRAM_Initialization_Sequence(&hsdram1, &command) != HAL_OK) {
		Error_Handler();
	}
  /* USER CODE END FMC_Init 2 */
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
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOI_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, LED_ACTIVE_Pin|LED_ALERT_Pin|LED_CAN1_Pin|LED_CAN2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(TOUCH_RST_PC13_GPIO_Port, TOUCH_RST_PC13_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOF, CAN1_S0_Pin|CAN2_S0_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(SD_CS_PIN_GPIO_Port, SD_CS_PIN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, IN_S0_Pin|IN_S1_Pin|IN_S2_Pin|PUD_E_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOG, IN_E_Pin|OUT_S0_Pin|PUD_S2_Pin|PUD_S1_Pin
                          |PUD_S0_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(SPI1_FLASH_GPIO_Port, SPI1_FLASH_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_ACTIVE_Pin LED_ALERT_Pin LED_CAN1_Pin LED_CAN2_Pin */
  GPIO_InitStruct.Pin = LED_ACTIVE_Pin|LED_ALERT_Pin|LED_CAN1_Pin|LED_CAN2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pin : TOUCH_RST_PC13_Pin */
  GPIO_InitStruct.Pin = TOUCH_RST_PC13_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(TOUCH_RST_PC13_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : TOUCH_INT_PI11_Pin */
  GPIO_InitStruct.Pin = TOUCH_INT_PI11_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(TOUCH_INT_PI11_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : CAN1_S0_Pin CAN2_S0_Pin */
  GPIO_InitStruct.Pin = CAN1_S0_Pin|CAN2_S0_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /*Configure GPIO pins : HALL_OUT_Pin BTN_2_PC6_Pin BTN_1_PC7_Pin BTN_4_PE5_Pin
                           BTN_3_PE4_Pin */
  GPIO_InitStruct.Pin = HALL_OUT_Pin|BTN_2_PC6_Pin|BTN_1_PC7_Pin|BTN_4_PE5_Pin
                          |BTN_3_PE4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : I2C2_SCL_PH4_Pin I2C2_SDA_PH5_Pin */
  GPIO_InitStruct.Pin = I2C2_SCL_PH4_Pin|I2C2_SDA_PH5_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF4_I2C2;
  HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);

  /*Configure GPIO pins : ESP_TX_Pin ESP_RX_Pin */
  GPIO_InitStruct.Pin = ESP_TX_Pin|ESP_RX_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF7_USART3;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PB12 PB13 */
  GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF9_CAN2;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PA8 */
  GPIO_InitStruct.Pin = GPIO_PIN_8;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : SD_CS_PIN_Pin */
  GPIO_InitStruct.Pin = SD_CS_PIN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(SD_CS_PIN_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PC10 PC11 PC12 */
  GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF6_SPI3;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : IN_S0_Pin IN_S1_Pin IN_S2_Pin PUD_E_Pin */
  GPIO_InitStruct.Pin = IN_S0_Pin|IN_S1_Pin|IN_S2_Pin|PUD_E_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : IN_E_Pin OUT_S0_Pin PUD_S2_Pin PUD_S1_Pin
                           PUD_S0_Pin */
  GPIO_InitStruct.Pin = IN_E_Pin|OUT_S0_Pin|PUD_S2_Pin|PUD_S1_Pin
                          |PUD_S0_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /*Configure GPIO pins : PB3 PB4 PB5 */
  GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : SPI1_FLASH_Pin */
  GPIO_InitStruct.Pin = SPI1_FLASH_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(SPI1_FLASH_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

float mapFloat(float x, float in_min, float in_max, float out_min,
		float out_max) {
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

long mapInt(float x, float in_min, float in_max, int out_min, int out_max) {
	return (int) ((x - in_min) * (out_max - out_min) / (in_max - in_min)
			+ out_min);
}

/* USER CODE END 4 */

/* USER CODE BEGIN Header_Start_START_Task */
/**
 * @brief  Function implementing the START_Task thread.
 * @param  argument: Not used
 * @retval None
 */
/* USER CODE END Header_Start_START_Task */
void Start_START_Task(void *argument)
{
  /* init code for USB_DEVICE */
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN 5 */
	//htim13.Instance->CCR1 = (htim13.Instance->ARR) * 0.99;
	Current_Status.LED_BRIGHTNESS = LED_DEFAULT_BRIGHTNESS;
	Current_Status.LCD_BRIGHTNESS = LCD_DEFAULT_BRIGHTNESS;
	Current_Status.LCD_BRIGHTNESS_CHANGED = 1;

	if (Current_Status.LCD_BRIGHTNESS_CHANGED == 1) {
		htim13.Instance->CCR1 = Current_Status.LCD_BRIGHTNESS;
		Current_Status.LCD_BRIGHTNESS_CHANGED = 0;
	}
	/* Infinite loop */
	for (;;) {
		osDelay(1);
	}
  /* USER CODE END 5 */
}

/* USER CODE BEGIN Header_TouchGFX_Task */
/**
 * @brief Function implementing the TouchGFXTask thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_TouchGFX_Task */
__weak void TouchGFX_Task(void *argument)
{
  /* USER CODE BEGIN TouchGFX_Task */
	/* Infinite loop */
	for (;;) {
		osDelay(1);
	}
  /* USER CODE END TouchGFX_Task */
}

/* USER CODE BEGIN Header_Start_LED_Task */
/**
 * @brief Function implementing the LED_Task thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_Start_LED_Task */
void Start_LED_Task(void *argument)
{
  /* USER CODE BEGIN Start_LED_Task */
	/* Infinite loop */
	for (;;) {
		HAL_GPIO_TogglePin(LED_ACTIVE_GPIO_Port, LED_ACTIVE_Pin);
		osDelay(100);
		HAL_GPIO_TogglePin(LED_ALERT_GPIO_Port, LED_ALERT_Pin);
		osDelay(100);
//		HAL_GPIO_TogglePin(CAN1_S0_GPIO_Port, CAN1_S0_Pin);
//		osDelay(100);
//		HAL_GPIO_TogglePin(CAN2_S0_GPIO_Port, CAN2_S0_Pin);
//		osDelay(100);

	}
  /* USER CODE END Start_LED_Task */
}

/* USER CODE BEGIN Header_Start_CAN_Task */
/**
 * @brief Function implementing the CAN_Task thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_Start_CAN_Task */
void Start_CAN_Task(void *argument)
{
  /* USER CODE BEGIN Start_CAN_Task */
	/* Infinite loop */
	Current_Status.CAN_PROTOCOL = CAN_AIM;
	Current_Status.PRES_UNIT = kPa;
	Current_Status.TEMP_UNIT = C;
	Current_Status.SPEED_UNIT = Kmh;
	HAL_GPIO_WritePin(CAN1_S0_GPIO_Port, CAN1_S0_Pin, SET);
	HAL_GPIO_WritePin(CAN2_S0_GPIO_Port, CAN2_S0_Pin, SET);

	//HAL_GPIO_WritePin(LED_CAN1_GPIO_Port, LED_CAN1_Pin, SET);

	for (;;) {
		if (CAN_ENABLED) {

			if (HAL_CAN_GetRxMessage(&hcan1, CAN_RX_FIFO0, &RxHeader, RxData)
					== HAL_OK) {
				switch (Current_Status.CAN_PROTOCOL) {
				case CAN_LINK:
					switch (RxHeader.StdId) {
					case 0x7E8:
						switch (RxData[2]) {
						case 0x05: //PID-0x05 Engine coolant temperature , range is -40 to 215 deg C , formula == A-40
							Current_Status.ECT = RxData[3] - 40;
							break;
						case 0x0B: // PID-0x0B , MAP , range is 0 to 255 kPa , Formula == A
							Current_Status.MAP = RxData[3];
							break;
						case 0x0C: // PID-0x0C , RPM  , range is 0 to 16383.75 rpm , Formula == 256A+B / 4
							Current_Status.RPM = (uint16_t) ((RxData[4] << 8)
									+ (RxData[3] & 0x00ff));
							break;
						case 0x0D: //PID-0x0D , Vehicle speed , range is 0 to 255 km/h , formula == A
							Current_Status.LF_SPEED = RxData[3];
							break;
						case 0x0E: //PID-0x0E , Ignition Timing advance, range is -64 to 63.5 BTDC , formula == A/2 - 64
							Current_Status.IGN_TIM = RxData[3] / 2 - 64;
							break;
						case 0x0F: //PID-0x0F , Inlet air temperature , range is -40 to 215 deg C, formula == A-40
							Current_Status.IAT = RxData[3] - 40;
							break;
						case 0x11: // PID-0x11 , TPS percentage, range is 0 to 100 percent, formula == 100/256 A
							Current_Status.TPS = 100 / 256 * RxData[3];
							break;
						case 0x13: //PID-0x13 , oxygen sensors present, A0-A3 == bank1 , A4-A7 == bank2
							break;
						case 0x1C: // PID-0x1C obd standard
							break;
						case 0x20: // PID-0x20 PIDs supported [21-40]
							break;
						case 0x22: // PID-0x22 Fuel /Pressure (Relative to manifold vacuum) , range is 0 to 5177.265 kPa , formula == 0.079(256A+B)
							Current_Status.FUELP = 0.079
									* (256 * (uint16_t) (RxData[4] << 8)
											+ (RxData[3] & 0x00ff));
							break;
						case 0x24: // PID-0x24 O2 sensor2, AB: fuel/air equivalence ratio, CD: voltage ,  Formula == (2/65536)(256A +B) , 8/65536(256C+D) , Range is 0 to <2 and 0 to >8V
							Current_Status.LAMBDA1 = (2 / 65536)
									* (256 * (uint16_t) (RxData[4] << 8)
											+ (RxData[3] & 0x00ff)); // , 8 / 65536 * (256 * (uint16_t)(RxData[5] << 8) + (RxData[6] & 0x00ff));
							break;
						case 0x25: // PID-0x25 O2 sensor2, AB fuel/air equivalence ratio, CD voltage ,  2/65536(256A +B) ,8/65536(256C+D) , range is 0 to <2 and 0 to >8V
							Current_Status.LAMBDA2 = (2 / 65536)
									* (256 * (uint16_t) (RxData[4] << 8)
											+ (RxData[3] & 0x00ff)); // , 8 / 65536 * (256 * (uint16_t)(RxData[5] << 8) + (RxData[6] & 0x00ff));
							break;
						case 0x33: // PID-0x33 Absolute Barometric pressure , range is 0 to 255 kPa , formula == A
							Current_Status.BARO = RxData[3];
							break;
						case 0x40: // PIDs supported [41-60]
							break;
						case 0x42: // PID-0x42 control module voltage, 256A+B / 1000 , range is 0 to 65.535v
							Current_Status.BATT = 256
									* (uint16_t) (RxData[4] << 8)
									+ (RxData[3] & 0x00ff) / 1000;
							break;
						case 0x46: // PID-0x46 Ambient Air Temperature , range is -40 to 215 deg C , formula == A-40
							break;
						case 0x52: // PID-0x52 Ethanol fuel % , range is 0 to 100% , formula == (100/255)A
							Current_Status.ETHANOL = 100 / 255 * RxData[3];
							break;
						case 0x5C: // PID-0x5C Engine oil temperature , range is -40 to 210 deg C , formula == A-40
							Current_Status.OILT = RxData[3] - 40;
							break;
						case 0x60: // PIDs supported [61-80]
							break;
						default:
							break;
						}
						break;
					case 0x3E8: //Link Dash
						switch (RxData[0]) {
						case 0:
							Current_Status.RPM = (uint16_t) ((RxData[3] << 8)
									+ (RxData[2] & 0x00ff));
							Current_Status.MAP = (uint16_t) ((RxData[5] << 8)
									+ (RxData[4] & 0x00ff));
							Current_Status.MGP = (uint16_t) ((RxData[7] << 8)
									+ (RxData[6] & 0x00ff));
							break;
						case 1:
							Current_Status.BARO = (uint16_t) ((RxData[3] << 8)
									+ (RxData[2] & 0x00ff));
							Current_Status.TPS = (uint16_t) ((RxData[5] << 8)
									+ (RxData[4] & 0x00ff));
							Current_Status.INJ_DC = (uint16_t) ((RxData[7] << 8)
									+ (RxData[6] & 0x00ff));
							break;
						case 2:
							Current_Status.INJ_DC_ST = (uint16_t) ((RxData[3]
									<< 8) + (RxData[2] & 0x00ff));
							Current_Status.INJ_PULSE = (uint16_t) ((RxData[5]
									<< 8) + (RxData[4] & 0x00ff));
							Current_Status.ECT = (uint16_t) ((RxData[7] << 8)
									+ (RxData[6] & 0x00ff));
							break;
						case 3:
							Current_Status.IAT = (uint16_t) ((RxData[3] << 8)
									+ (RxData[2] & 0x00ff));
							Current_Status.BATT = (uint16_t) ((RxData[5] << 8)
									+ (RxData[4] & 0x00ff));
							Current_Status.MAF = (uint16_t) ((RxData[7] << 8)
									+ (RxData[6] & 0x00ff));
							break;
						case 4:
							Current_Status.GEAR = (uint16_t) ((RxData[3] << 8)
									+ (RxData[2] & 0x00ff));
							Current_Status.INJ_TIM =
									(uint16_t) ((RxData[5] << 8)
											+ (RxData[4] & 0x00ff));
							Current_Status.IGN_TIM =
									(uint16_t) ((RxData[7] << 8)
											+ (RxData[6] & 0x00ff));
							break;
						case 5:
							Current_Status.CAM_I_L =
									(uint16_t) ((RxData[3] << 8)
											+ (RxData[2] & 0x00ff));
							Current_Status.CAM_I_R =
									(uint16_t) ((RxData[5] << 8)
											+ (RxData[4] & 0x00ff));
							Current_Status.CAM_E_L =
									(uint16_t) ((RxData[7] << 8)
											+ (RxData[6] & 0x00ff));
							break;
						case 6:
							Current_Status.CAM_E_R =
									(uint16_t) ((RxData[3] << 8)
											+ (RxData[2] & 0x00ff));
							Current_Status.LAMBDA1 =
									(uint16_t) ((RxData[5] << 8)
											+ (RxData[4] & 0x00ff));
							Current_Status.LAMBDA2 =
									(uint16_t) ((RxData[7] << 8)
											+ (RxData[6] & 0x00ff));
							break;
						case 7:
							Current_Status.TRIG1_ERROR = (uint16_t) ((RxData[3]
									<< 8) + (RxData[2] & 0x00ff));
							Current_Status.FAULT_CODES = (uint16_t) ((RxData[5]
									<< 8) + (RxData[4] & 0x00ff));
							Current_Status.FUELP = (uint16_t) ((RxData[7] << 8)
									+ (RxData[6] & 0x00ff));
							break;
						case 8:
							Current_Status.OILT = (uint16_t) ((RxData[3] << 8)
									+ (RxData[2] & 0x00ff));
							Current_Status.OILP = (uint16_t) ((RxData[5] << 8)
									+ (RxData[4] & 0x00ff));
							Current_Status.LF_SPEED = (uint16_t) ((RxData[7]
									<< 8) + (RxData[6] & 0x00ff));
							break;
						case 9:
							Current_Status.LR_SPEED = (uint16_t) ((RxData[3]
									<< 8) + (RxData[2] & 0x00ff));
							Current_Status.RF_SPEED = (uint16_t) ((RxData[5]
									<< 8) + (RxData[4] & 0x00ff));
							Current_Status.RR_SPEED = (uint16_t) ((RxData[7]
									<< 8) + (RxData[6] & 0x00ff));
							break;
						case 10:
							Current_Status.KNOCK1 = (uint16_t) ((RxData[3] << 8)
									+ (RxData[2] & 0x00ff));
							Current_Status.KNOCK2 = (uint16_t) ((RxData[5] << 8)
									+ (RxData[4] & 0x00ff));
							Current_Status.KNOCK3 = (uint16_t) ((RxData[7] << 8)
									+ (RxData[6] & 0x00ff));
							break;
						case 11:
							Current_Status.KNOCK4 = (uint16_t) ((RxData[3] << 8)
									+ (RxData[2] & 0x00ff));
							Current_Status.KNOCK5 = (uint16_t) ((RxData[5] << 8)
									+ (RxData[4] & 0x00ff));
							Current_Status.KNOCK6 = (uint16_t) ((RxData[7] << 8)
									+ (RxData[6] & 0x00ff));
							break;
						case 12:
							Current_Status.KNOCK7 = (uint16_t) ((RxData[3] << 8)
									+ (RxData[2] & 0x00ff));
							Current_Status.KNOCK8 = (uint16_t) ((RxData[5] << 8)
									+ (RxData[4] & 0x00ff));
							Current_Status.LIMITS = (uint16_t) ((RxData[7] << 8)
									+ (RxData[6] & 0x00ff));
							break;
						}
						break;
					}
					break;
				case CAN_AIM:
					switch (RxHeader.StdId) {
					case 0x5F0:
						Current_Status.RPM = (uint16_t) ((RxData[1] << 8) + (RxData[0] & 0x00ff));
						Current_Status.TPS = (uint16_t)((RxData[3] << 8) + (RxData[2] & 0x00ff)) / 65;
						break;
					case 0x5F2:
						Current_Status.IAT = (uint16_t)((RxData[1] << 8) + (RxData[0] & 0x00ff)) / 19 - 450;
						Current_Status.ECT = (uint16_t)((RxData[3] << 8) + (RxData[2] & 0x00ff)) / 19 - 450;
						Current_Status.FUELT = (uint16_t)((RxData[5] << 8) + (RxData[4] & 0x00ff)) / 19 - 450;
						Current_Status.OILT = (uint16_t)((RxData[7] << 8) + (RxData[6] & 0x00ff)) / 19 - 450;
						break;
					case 0x5F3:
						Current_Status.MAP = (uint16_t)((RxData[1] << 8) + (RxData[0] & 0x00ff)) / 10;
						Current_Status.BARO = (uint16_t)((RxData[3] << 8) + (RxData[2] & 0x00ff)) / 10;
						Current_Status.OILP = (uint16_t)((RxData[5] << 8) + (RxData[4] & 0x00ff)) * 100 / 100;
						Current_Status.FUELP = (uint16_t)((RxData[7] << 8) + (RxData[6] & 0x00ff)) * 100 / 2;
						break;
					case 0x5F4:
						Current_Status.BATT = (uint16_t)((RxData[3] << 8) + (RxData[2] & 0x00ff)) / 32;
						//Current_Status.GEAR = (uint16_t)((RxData[7] << 8) + (RxData[6] & 0x00ff));
						break;
					case 0x5F6:
						Current_Status.LAMBDA1 = (uint16_t)((RxData[1] << 8) + (RxData[0] & 0x00ff)) / 2;
						Current_Status.LAMBDA2 = (uint16_t)((RxData[3] << 8) + (RxData[2] & 0x00ff)) / 2;
						break;
					}
					break;
				default:
					break;
				}

				if(RxHeader.StdId == CAN_SETUP_ID)
				{
					switch (RxData[0]) {
						case 0x00: //READ START

							break;
						case 0xA0: //SETUP DEVICE

							break;
						case 0xB0: //SETUP FIELD
							//setAllFields(&RxData);
							break;
						case 0xC0: //SETUP CHANNEL

							break;
						case 0xD0: //SETUP ERROR

							break;
					}
				}

				Current_Status.RPM_100 = mapInt(Current_Status.RPM, 0,
						PROTECTION_RPM_HIGH, 0, 100);
				Current_Status.RPM_100 =
						Current_Status.RPM_100 >= 100 ?
								100 : Current_Status.RPM_100;
				Current_Status.RPM_180 = mapInt(Current_Status.RPM, 0,
						PROTECTION_RPM_HIGH, 0, 180);
				Current_Status.RPM_180 =
						Current_Status.RPM_180 >= 180 ?
								810 : Current_Status.RPM_180;
				Current_Status.RPM_270 = mapInt(Current_Status.RPM, 0,
						PROTECTION_RPM_HIGH, 0, 270);
				Current_Status.RPM_270 =
						Current_Status.RPM_270 >= 270 ?
								270 : Current_Status.RPM_270;
				Current_Status.RPM_240 = mapInt(Current_Status.RPM, 0,
						PROTECTION_RPM_HIGH, 0, 240);
				Current_Status.RPM_240 =
						Current_Status.RPM_240 >= 240 ?
								240 : Current_Status.RPM_240;
				Current_Status.RPM_360 = mapInt(Current_Status.RPM, 0,
						PROTECTION_RPM_HIGH, 0, 360);
				Current_Status.RPM_360 =
						Current_Status.RPM_360 >= 360 ?
								360 : Current_Status.RPM_360;

			}
			else {

			}
		} else {
			osDelay(60000);
		}
	}
  /* USER CODE END Start_CAN_Task */
}

/* USER CODE BEGIN Header_Start_ALERT_Task */
/**
* @brief Function implementing the ALERT_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Start_ALERT_Task */
void Start_ALERT_Task(void *argument)
{
  /* USER CODE BEGIN Start_ALERT_Task */
	strcpy(Current_Status.SCREEN_FIELDS[0].Label.Label, "Coolant Temperature");
	Current_Status.SCREEN_FIELDS[0].Label.X = 23;
	Current_Status.SCREEN_FIELDS[0].Label.Y = 81;
	Current_Status.SCREEN_FIELDS[0].Label.Width = 101;
	Current_Status.SCREEN_FIELDS[0].Label.Height = 30;
	Current_Status.SCREEN_FIELDS[0].Label.Alignment = LEFT;

	strcpy(Current_Status.SCREEN_FIELDS[0].Unit.Label, "°C");
	Current_Status.SCREEN_FIELDS[0].Unit.X = 390;
	Current_Status.SCREEN_FIELDS[0].Unit.Y = 81;
	Current_Status.SCREEN_FIELDS[0].Unit.Width = 101;
	Current_Status.SCREEN_FIELDS[0].Unit.Height = 30;
	Current_Status.SCREEN_FIELDS[0].Unit.Alignment = LEFT;

	strcpy(Current_Status.SCREEN_FIELDS[0].ValueDefault, "0");
	Current_Status.SCREEN_FIELDS[0].Value.X = 23;
	Current_Status.SCREEN_FIELDS[0].Value.Y = 4;
	Current_Status.SCREEN_FIELDS[0].Value.Width = 44;
	Current_Status.SCREEN_FIELDS[0].Value.Height = 96;
	Current_Status.SCREEN_FIELDS[0].Value.Alignment = LEFT;


	strcpy(Current_Status.SCREEN_FIELDS[1].Label.Label, "Intake Air Temperature");
	Current_Status.SCREEN_FIELDS[1].Label.X = 23;
	Current_Status.SCREEN_FIELDS[1].Label.Y = 196;
	Current_Status.SCREEN_FIELDS[1].Label.Width = 101;
	Current_Status.SCREEN_FIELDS[1].Label.Height = 30;
	Current_Status.SCREEN_FIELDS[1].Label.Alignment = LEFT;

	strcpy(Current_Status.SCREEN_FIELDS[1].Unit.Label, "°C");
	Current_Status.SCREEN_FIELDS[1].Unit.X = 355;
	Current_Status.SCREEN_FIELDS[1].Unit.Y = 196;
	Current_Status.SCREEN_FIELDS[1].Unit.Width = 101;
	Current_Status.SCREEN_FIELDS[1].Unit.Height = 30;
	Current_Status.SCREEN_FIELDS[1].Unit.Alignment = LEFT;

	strcpy(Current_Status.SCREEN_FIELDS[1].ValueDefault, "0");
	Current_Status.SCREEN_FIELDS[1].Value.X = 23;
	Current_Status.SCREEN_FIELDS[1].Value.Y = 119;
	Current_Status.SCREEN_FIELDS[1].Value.Width = 44;
	Current_Status.SCREEN_FIELDS[1].Value.Height = 96;
	Current_Status.SCREEN_FIELDS[1].Value.Alignment = LEFT;


	strcpy(Current_Status.SCREEN_FIELDS[2].Label.Label, "OIL Pressure");
	Current_Status.SCREEN_FIELDS[2].Label.X = 23;
	Current_Status.SCREEN_FIELDS[2].Label.Y = 315;
	Current_Status.SCREEN_FIELDS[2].Label.Width = 101;
	Current_Status.SCREEN_FIELDS[2].Label.Height = 30;
	Current_Status.SCREEN_FIELDS[2].Label.Alignment = LEFT;

	strcpy(Current_Status.SCREEN_FIELDS[2].Unit.Label, "kPa");
	Current_Status.SCREEN_FIELDS[2].Unit.X = 360;
	Current_Status.SCREEN_FIELDS[2].Unit.Y = 315;
	Current_Status.SCREEN_FIELDS[2].Unit.Width = 101;
	Current_Status.SCREEN_FIELDS[2].Unit.Height = 30;
	Current_Status.SCREEN_FIELDS[2].Unit.Alignment = LEFT;

	strcpy(Current_Status.SCREEN_FIELDS[2].ValueDefault, "0");
	Current_Status.SCREEN_FIELDS[2].Value.X = 23;
	Current_Status.SCREEN_FIELDS[2].Value.Y = 238;
	Current_Status.SCREEN_FIELDS[2].Value.Width = 44;
	Current_Status.SCREEN_FIELDS[2].Value.Height = 96;
	Current_Status.SCREEN_FIELDS[2].Value.Alignment = LEFT;


	strcpy(Current_Status.SCREEN_FIELDS[3].Label.Label, "FUEL Pressure");
	Current_Status.SCREEN_FIELDS[3].Label.X = 23;
	Current_Status.SCREEN_FIELDS[3].Label.Y = 430;
	Current_Status.SCREEN_FIELDS[3].Label.Width = 101;
	Current_Status.SCREEN_FIELDS[3].Label.Height = 30;
	Current_Status.SCREEN_FIELDS[3].Label.Alignment = LEFT;

	strcpy(Current_Status.SCREEN_FIELDS[3].Unit.Label, "°C");
	Current_Status.SCREEN_FIELDS[3].Unit.X = 450;
	Current_Status.SCREEN_FIELDS[3].Unit.Y = 430;
	Current_Status.SCREEN_FIELDS[3].Unit.Width = 101;
	Current_Status.SCREEN_FIELDS[3].Unit.Height = 30;
	Current_Status.SCREEN_FIELDS[3].Unit.Alignment = LEFT;

	strcpy(Current_Status.SCREEN_FIELDS[3].ValueDefault, "0");
	Current_Status.SCREEN_FIELDS[3].Value.X = 23;
	Current_Status.SCREEN_FIELDS[3].Value.Y = 353;
	Current_Status.SCREEN_FIELDS[3].Value.Width = 44;
	Current_Status.SCREEN_FIELDS[3].Value.Height = 96;
	Current_Status.SCREEN_FIELDS[3].Value.Alignment = LEFT;

	strcpy(Current_Status.SCREEN_FIELDS[4].Label.Label, "Manifold Pressure");
	Current_Status.SCREEN_FIELDS[4].Label.X = 1160;
	Current_Status.SCREEN_FIELDS[4].Label.Y = 81;
	Current_Status.SCREEN_FIELDS[4].Label.Width = 101;
	Current_Status.SCREEN_FIELDS[4].Label.Height = 30;
	Current_Status.SCREEN_FIELDS[4].Label.Alignment = LEFT;

	strcpy(Current_Status.SCREEN_FIELDS[4].Unit.Label, "°C");
	Current_Status.SCREEN_FIELDS[4].Unit.X = 825;
	Current_Status.SCREEN_FIELDS[4].Unit.Y = 81;
	Current_Status.SCREEN_FIELDS[4].Unit.Width = 101;
	Current_Status.SCREEN_FIELDS[4].Unit.Height = 30;
	Current_Status.SCREEN_FIELDS[4].Unit.Alignment = LEFT;

	strcpy(Current_Status.SCREEN_FIELDS[4].ValueDefault, "0");
	Current_Status.SCREEN_FIELDS[4].Value.X = 1220;
	Current_Status.SCREEN_FIELDS[4].Value.Y = 4;
	Current_Status.SCREEN_FIELDS[4].Value.Width = 44;
	Current_Status.SCREEN_FIELDS[4].Value.Height = 96;
	Current_Status.SCREEN_FIELDS[4].Value.Alignment = LEFT;


	strcpy(Current_Status.SCREEN_FIELDS[5].Label.Label, "Battery");
	Current_Status.SCREEN_FIELDS[5].Label.X = 1160;
	Current_Status.SCREEN_FIELDS[5].Label.Y = 196;
	Current_Status.SCREEN_FIELDS[5].Label.Width = 101;
	Current_Status.SCREEN_FIELDS[5].Label.Height = 30;
	Current_Status.SCREEN_FIELDS[5].Label.Alignment = LEFT;

	strcpy(Current_Status.SCREEN_FIELDS[5].Unit.Label, "°C");
	Current_Status.SCREEN_FIELDS[5].Unit.X = 868;
	Current_Status.SCREEN_FIELDS[5].Unit.Y = 196;
	Current_Status.SCREEN_FIELDS[5].Unit.Width = 101;
	Current_Status.SCREEN_FIELDS[5].Unit.Height = 30;
	Current_Status.SCREEN_FIELDS[5].Unit.Alignment = LEFT;

	strcpy(Current_Status.SCREEN_FIELDS[5].ValueDefault, "0");
	Current_Status.SCREEN_FIELDS[5].Value.X = 1220;
	Current_Status.SCREEN_FIELDS[5].Value.Y = 119;
	Current_Status.SCREEN_FIELDS[5].Value.Width = 44;
	Current_Status.SCREEN_FIELDS[5].Value.Height = 96;
	Current_Status.SCREEN_FIELDS[5].Value.Alignment = LEFT;


	strcpy(Current_Status.SCREEN_FIELDS[6].Label.Label, "Throttle Position");
	Current_Status.SCREEN_FIELDS[6].Label.X = 1160;
	Current_Status.SCREEN_FIELDS[6].Label.Y = 315;
	Current_Status.SCREEN_FIELDS[6].Label.Width = 101;
	Current_Status.SCREEN_FIELDS[6].Label.Height = 30;
	Current_Status.SCREEN_FIELDS[6].Label.Alignment = LEFT;

	strcpy(Current_Status.SCREEN_FIELDS[6].Unit.Label, "kPa");
	Current_Status.SCREEN_FIELDS[6].Unit.X = 858;
	Current_Status.SCREEN_FIELDS[6].Unit.Y = 315;
	Current_Status.SCREEN_FIELDS[6].Unit.Width = 101;
	Current_Status.SCREEN_FIELDS[6].Unit.Height = 30;
	Current_Status.SCREEN_FIELDS[6].Unit.Alignment = LEFT;

	strcpy(Current_Status.SCREEN_FIELDS[6].ValueDefault, "0");
	Current_Status.SCREEN_FIELDS[6].Value.X = 1220;
	Current_Status.SCREEN_FIELDS[6].Value.Y = 238;
	Current_Status.SCREEN_FIELDS[6].Value.Width = 44;
	Current_Status.SCREEN_FIELDS[6].Value.Height = 96;
	Current_Status.SCREEN_FIELDS[6].Value.Alignment = LEFT;


	strcpy(Current_Status.SCREEN_FIELDS[7].Label.Label, "Wideband");
	Current_Status.SCREEN_FIELDS[7].Label.X = 1160;
	Current_Status.SCREEN_FIELDS[7].Label.Y = 430;
	Current_Status.SCREEN_FIELDS[7].Label.Width = 101;
	Current_Status.SCREEN_FIELDS[7].Label.Height = 30;
	Current_Status.SCREEN_FIELDS[7].Label.Alignment = LEFT;

	strcpy(Current_Status.SCREEN_FIELDS[7].Unit.Label, "°C");
	Current_Status.SCREEN_FIELDS[7].Unit.X = 770;
	Current_Status.SCREEN_FIELDS[7].Unit.Y = 430;
	Current_Status.SCREEN_FIELDS[7].Unit.Width = 101;
	Current_Status.SCREEN_FIELDS[7].Unit.Height = 30;
	Current_Status.SCREEN_FIELDS[7].Unit.Alignment = LEFT;

	strcpy(Current_Status.SCREEN_FIELDS[7].ValueDefault, "0");
	Current_Status.SCREEN_FIELDS[7].Value.X = 1220;
	Current_Status.SCREEN_FIELDS[7].Value.Y = 353;
	Current_Status.SCREEN_FIELDS[7].Value.Width = 44;
	Current_Status.SCREEN_FIELDS[7].Value.Height = 96;
	Current_Status.SCREEN_FIELDS[7].Value.Alignment = LEFT;


//	Current_Status.SCREEN_FIELDS[1].Label.Label = "IAT";
//	Current_Status.SCREEN_FIELDS[1].Unit.Label = "°C";
//
//	Current_Status.SCREEN_FIELDS[2].Label.Label = "Oil Pressure";
//	Current_Status.SCREEN_FIELDS[2].Unit.Label = "kPa";
//
//	Current_Status.SCREEN_FIELDS[3].Label.Label = "Fuel Pressure";
//	Current_Status.SCREEN_FIELDS[3].Unit.Label = "kPa";
//
//	Current_Status.SCREEN_FIELDS[4].Label.Label = "MAP";
//	Current_Status.SCREEN_FIELDS[4].Unit.Label = "kPa";
//
//	Current_Status.SCREEN_FIELDS[5].Label.Label = "Battery";
//	Current_Status.SCREEN_FIELDS[5].Unit.Label = "V";
//
//	Current_Status.SCREEN_FIELDS[6].Label.Label = "TPS";
//	Current_Status.SCREEN_FIELDS[6].Unit.Label = "%";
//
//	Current_Status.SCREEN_FIELDS[7].Label.Label = "Wideband";
//	Current_Status.SCREEN_FIELDS[7].Unit.Label = "Lambda";

	TickType_t xStart, xEnd, xDifference;

  /* Infinite loop */
  for(;;)
  {
//		Current_Status.OK_L1 = true;
//		Current_Status.ALERT_L1 = false;
//		Current_Status.WARNING_L1 = false;
//		osDelay(100);
//		Current_Status.OK_L1 = false;
//		Current_Status.ALERT_L1 = false;
//		Current_Status.WARNING_L1 = true;
//		osDelay(100);
//		Current_Status.OK_L1 = false;
//		Current_Status.ALERT_L1 = true;
//		Current_Status.WARNING_L1 = false;
//		osDelay(100);
//		Current_Status.OK_L1 = false;
//		Current_Status.ALERT_L1 = false;
//		Current_Status.WARNING_L1 = false;
//		osDelay(100);
//
//		Current_Status.OK_L2 = true;
//		Current_Status.ALERT_L2 = false;
//		Current_Status.WARNING_L2 = false;
//		osDelay(100);
//		Current_Status.OK_L2 = false;
//		Current_Status.ALERT_L2 = false;
//		Current_Status.WARNING_L2 = true;
//		osDelay(100);
//		Current_Status.OK_L2 = false;
//		Current_Status.ALERT_L2 = true;
//		Current_Status.WARNING_L2 = false;
//		osDelay(100);
//		Current_Status.OK_L2 = false;
//		Current_Status.ALERT_L2 = false;
//		Current_Status.WARNING_L2 = false;
//		osDelay(100);
//
//		Current_Status.OK_L3 = true;
//		Current_Status.ALERT_L3 = false;
//		Current_Status.WARNING_L3 = false;
//		osDelay(100);
//		Current_Status.OK_L3 = false;
//		Current_Status.ALERT_L3 = false;
//		Current_Status.WARNING_L3 = true;
//		osDelay(100);
//		Current_Status.OK_L3 = false;
//		Current_Status.ALERT_L3 = true;
//		Current_Status.WARNING_L3 = false;
//		osDelay(100);
//		Current_Status.OK_L3 = false;
//		Current_Status.ALERT_L3 = false;
//		Current_Status.WARNING_L3 = false;
//		osDelay(100);
//
//		Current_Status.OK_L4 = true;
//		Current_Status.ALERT_L4 = false;
//		Current_Status.WARNING_L4 = false;
//		osDelay(100);
//		Current_Status.OK_L4 = false;
//		Current_Status.ALERT_L4 = false;
//		Current_Status.WARNING_L4 = true;
//		osDelay(100);
//		Current_Status.OK_L4 = false;
//		Current_Status.ALERT_L4 = true;
//		Current_Status.WARNING_L4 = false;
//		osDelay(100);
//		Current_Status.OK_L4 = false;
//		Current_Status.ALERT_L4 = false;
//		Current_Status.WARNING_L4 = false;
		osDelay(1);
  }
  /* USER CODE END Start_ALERT_Task */
}

/* USER CODE BEGIN Header_Start_RGB_Task */
/**
* @brief Function implementing the RGB_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Start_RGB_Task */
void Start_RGB_Task(void *argument)
{
  /* USER CODE BEGIN Start_RGB_Task */
		/* Infinite loop */
		for (;;) {
				if (RGB_ENABLED) {
					Current_Status.RPM = Current_Status.RPM >= PROTECTION_RPM_HIGH ? 0 : Current_Status.RPM;
					Current_Status.RPM = Current_Status.RPM + 100;

					Current_Status.ENGINE_PROTECTION = Current_Status.RPM >= PROTECTION_RPM_HIGH ? 1 : 0;


					clearWS2812All();
					uint8_t RPMLED = WS2812_LED_N;

					uint16_t lowRange = mapInt(Current_Status.RPM, PROTECTION_RPM_LOW, 0, RPMLED - PROTECTION_RPM_LED, 1);
					lowRange = lowRange > RPMLED - PROTECTION_RPM_LED ? RPMLED - PROTECTION_RPM_LED : lowRange;
					lowRange = lowRange < 1 ? 1 : lowRange;

					for (int i = 1; i <= lowRange; i++) {
						WS2812_RGB_t color;
						if (Current_Status.ENGINE_PROTECTION == 1) {
							color.red = 0;
							color.green = 255;
							color.blue = 0;
						} else {
							color.red = 0;
							color.green = 255;
							color.blue = 0;
						}
						setWS2812One((RPMLED - i) + (WS2812_LED_N - RPMLED), color);
					}

					if (Current_Status.RPM > PROTECTION_RPM_LOW) {
						uint16_t highRange = mapInt(Current_Status.RPM, PROTECTION_RPM_HIGH, PROTECTION_RPM_LOW, PROTECTION_RPM_LED, 1);
						for (int i = 1; i <= highRange; i++) {
							WS2812_RGB_t color;
							color.red = 255;
							color.green = 0;
							color.blue = 0;

							setWS2812One((PROTECTION_RPM_LED - i) + (WS2812_LED_N - RPMLED), color);
						}

						updateWS2812();
						osDelay(50);

						for (int i = 1; i <= highRange; i++) {
							WS2812_RGB_t color;
							color.red = 0;
							color.green = 0;
							color.blue = 0;

							setWS2812One((PROTECTION_RPM_LED - i) + (WS2812_LED_N - RPMLED), color);
						}
					}


					updateWS2812();
					osDelay(100);
				}
			}
  /* USER CODE END Start_RGB_Task */
}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM6 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM6) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */
  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1) {
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
