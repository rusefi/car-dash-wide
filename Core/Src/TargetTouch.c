/*
 * Author: J.Bajic - 2020
 */

#include <TargetTouch.h>

static uint8_t isTransmittingData = 0;
static uint8_t isPressed = 0;

extern I2C_HandleTypeDef hi2c2;  //i2c port for touch screen
//=============================================================================
// TOUCH
//=============================================================================
void TOUCH_Init(void)
{
	// Configure touch GPIOs externally (CubeMx)
	  FT5XX6_Init(hi2c2);
}

uint8_t TOUCH_IsPressed(void)
{
    return isPressed;
}
void TOUCH_Set(void)
{
    isPressed=1;
}

void TOUCH_Reset(void)
{
	if(HAL_GPIO_ReadPin(INT_PORT,INT_PIN)==GPIO_PIN_SET) //reset touch state if INT goes high
		isPressed=0;
}

TOUCH_Data TOUCH_GetData(void)
{
	TOUCH_Data td={0,0,0};
	CTP_point_data cpd=FT5XX6_ReadPoint(0);   // only reading first touch point

	td.x=cpd.x;
	td.y=cpd.y;
	td.p=cpd.pressure;

	return td;
}
