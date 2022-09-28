/*
J. Bajic - 2020.
*/

#ifndef FT5XX6_H
#define FT5XX6_H

#include "stm32f4xx_hal.h"

#define FT5XX6_ADDR				(0x38<<1)

#define INT_PORT				GPIOI
#define INT_PIN					GPIO_PIN_11

#define FT5XX6_FLIP_AXIS		1

/*Addr*/
#define FT5XX6_MODE 			0x00
#define FT5XX6_GEST_ID 			0x01
#define FT5XX6_TD_STATUS 		0x02
#define FT5XX6_TOUCH_DATA_PTR 	0x03
#define FT5XX6_TOUCH_DATA_LEN 	6		//6 bytes per touch point
#define FT5XX6_TOUCH_DATA_N		10  	// 10 points

#define FT5XX6_GEST_MOVE_UP     0x10	//16
#define FT5XX6_GEST_MOVE_LEFT   0x14	//20
#define FT5XX6_GEST_MOVE_DOWN   0x18	//24
#define FT5XX6_GEST_MOVE_RIGHT  0x1C	//28
#define FT5XX6_GEST_ZOOM_IN     0x48	//72
#define FT5XX6_GEST_ZOOM_OUT    0x49	//73
#define FT5XX6_GEST_NO_GESTURE  0x00	//0

#define FT5XX6_MAX_POINTS		10

/*Config*/
#define FT5XX6_TH_GROUP         0x80	//Threshold for touch detection
#define FT5XX6_TH_DIFF         	0x85	//Filter function coefficients
#define FT5XX6_CTRL             0x86	//Control register
#define FT5XX6_TIMEENTERMONITOR 0x87	//The time period of switching from Active mode to Monitor mode when there is no touching
#define FT5XX6_PERIODACTIVE     0x88	//Report rate in Active mode
#define FT5XX6_PERIODMONITOR   	0x89	//Report rate in Monitor mode
#define FT5XX6_RADIAN_VALUE     0x91	//The value of the minimum allowed angle while Rotating gesture mode
#define FT5XX6_OFFSET_LR       	0x92	// Maximum offset while Moving Left and Moving Right gesture
#define FT5XX6_OFFSET_UD      	0x93	// Maximum offset while Moving Up and Moving Down gesture
#define FT5XX6_DISTANCE_LR     	0x94	// Minimum distance while Moving Left and Moving Right gesture
#define FT5XX6_DISTANCE_UD     	0x95	// Minimum distance while Moving Up and Moving Down gesture
#define FT5XX6_DISTANCE_ZOOM    0x96	//Maximum distance while Zoom In and Zoom Out gesture
#define FT5XX6_LIB_VER_H       	0xA1	//High 8-bit of LIB Version info
#define	FT5XX6_LIB_VER_L        0xA2	//Low 8-bit of LIB Version info
#define FT5XX6_CIPHER         	0xA3 	//Chip Selecting
#define FT5XX6_GMODE            0xA4 	//Interrupt mode register (used when in interrupt mode)
#define FT5XX6_PWR_MODE         0xA5	//Current power mode the FT5336 system is in (R)
#define FT5XX6_FIRMID			0xA6	//FT5336 firmware version
#define FT5XX6_CHIP_ID			0xA8 	//FT5336 Chip identification register
#define FT5XX6_RELEASE_CODE_ID  0xAF	///Release code version
#define FT5XX6_STATE            0xBC 	//Current operating mode the FT5336 system is in (R)

#define FT5XX6_TIMEOUT			1000

/*touch point data*/
typedef struct {
  uint16_t x;
  uint16_t y;
  uint8_t pressure;
  uint8_t id;
  uint8_t event;
  uint8_t area;
} CTP_point_data;

//--------------------------------------------------------------------------------
uint8_t FT5XX6_Init(I2C_HandleTypeDef i2c_handle);
void FT5XX6_Write(uint8_t reg_addr, uint8_t byte_2_write);
uint8_t FT5XX6_Read(uint8_t reg_addr);
void FT5XX6_ReadMultiple(uint8_t reg_addr, uint8_t *buff, uint8_t num_of_bytes);
uint8_t FT5XX6_GetMode(void);
uint8_t FT5XX6_GetGeastureID(void);
uint8_t FT5XX6_GetNumOfTouches(void);
CTP_point_data FT5XX6_ReadPoint(uint8_t point_num);
//--------------------------------------------------------------------------------

#endif
