/*
 * Author: J.Bajic - 2020
 */


#ifndef TARGET_TOUCH_H
#define TARGET_TOUCH_H

#include "stm32f4xx_hal.h"
#include "FT5XX6.h"

#define TP_MIN_PRESSURE 50

typedef struct {
  uint16_t x;
  uint16_t y;
  uint8_t p; //weight pressure for FT5XX6
} TOUCH_Data;

// TOUCH
void TOUCH_Init(void);
uint8_t TOUCH_IsPressed(void);
void TOUCH_Set(void);
void TOUCH_Reset(void);
TOUCH_Data TOUCH_GetData(void);

#endif /* TARGET_TOUCH_H */
