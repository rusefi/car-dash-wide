/*
J. Bajic - 2020.
*/

#include "FT5XX6.h"

static I2C_HandleTypeDef hi2c;

//=============================================================================
// Init touch panel driver
//=============================================================================
uint8_t FT5XX6_Init(I2C_HandleTypeDef i2c_handle)
{
	hi2c=i2c_handle;

	if(HAL_I2C_IsDeviceReady(&hi2c,FT5XX6_ADDR, 5, FT5XX6_TIMEOUT) == HAL_OK )
	{
		FT5XX6_Write(FT5XX6_MODE,0);		//working mode
		FT5XX6_Write(FT5XX6_GMODE,0);		//polling mode
		return 1;
	}
	else
		return 0;
}
//=============================================================================
// Write data to touch panel driver
//=============================================================================
void FT5XX6_Write(uint8_t reg_addr, uint8_t byte_2_write)
{
	uint8_t data[2];

    data[0] = reg_addr;
    data[1] = byte_2_write;

	HAL_I2C_Master_Transmit(&hi2c, FT5XX6_ADDR, (uint8_t *)data, 2, FT5XX6_TIMEOUT);
}
//=============================================================================
// Read data from touch panel driver - SINGLE BYTE
//=============================================================================
uint8_t FT5XX6_Read(uint8_t reg_addr)
{
	uint8_t data;

	HAL_I2C_Mem_Read(&hi2c,FT5XX6_ADDR, reg_addr,1,&data,1,FT5XX6_TIMEOUT);

	return data;
}
//=============================================================================
// Read data from touch panel driver - MULTIPLE BYTES
//=============================================================================
void FT5XX6_ReadMultiple(uint8_t reg_addr, uint8_t *buff, uint8_t num_of_bytes)
{
	HAL_I2C_Mem_Read(&hi2c,FT5XX6_ADDR, reg_addr,1,buff,num_of_bytes,FT5XX6_TIMEOUT);
}
//=============================================================================
// Get operating mode
//=============================================================================
uint8_t FT5XX6_GetMode(void)
{
	return FT5XX6_Read(FT5XX6_MODE);
}
//=============================================================================
// Get touch gesture ID
//=============================================================================
uint8_t FT5XX6_GetGeastureID(void)
{
	return FT5XX6_Read(FT5XX6_GEST_ID);
}
//=============================================================================
// Get number of touches
//=============================================================================
uint8_t FT5XX6_GetNumOfTouches(void)
{
	return FT5XX6_Read(FT5XX6_TD_STATUS);
}
//=============================================================================
// Read single touch point data
//=============================================================================
CTP_point_data FT5XX6_ReadPoint(uint8_t point_num)
{
	uint8_t data[FT5XX6_TOUCH_DATA_LEN];
	uint8_t reg_addr=FT5XX6_TOUCH_DATA_PTR+(point_num*FT5XX6_TOUCH_DATA_LEN);  //6 bytes per point
	CTP_point_data point={0,0,0,0,0,0};

	HAL_I2C_Mem_Read(&hi2c,FT5XX6_ADDR, reg_addr,1,data,FT5XX6_TOUCH_DATA_LEN,1000);

	point.event=(data[0]&0xC0)>>6;
	point.y= FT5XX6_FLIP_AXIS == 1 ? (data[0]&0x0F)<<8|data[1] : (data[2]&0x0F)<<8|data[3];
	point.id=(data[2]&0xF0)>>4;
	point.x=FT5XX6_FLIP_AXIS == 1 ? (data[2]&0x0F)<<8|data[3] : (data[0]&0x0F)<<8|data[1];
	point.pressure=data[4];
	point.area=(data[5]&0xF0)>>4;

	return point;
}

