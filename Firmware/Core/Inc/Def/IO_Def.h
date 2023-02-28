/*
 * IO_Def.h
 *
 *  Created on: Oct 16, 2022
 *      Author: Ben
 */

#ifndef INC_DEF_IO_DEF_H_
#define INC_DEF_IO_DEF_H_


typedef enum {
	ACTIVE_LOW = 0,
	ACTIVE_LOW_ROTARY,
	ACTIVE_HIGH,
	ACTIVE_HIGH_LINEAR, // 2x2 map
	ACTIVE_HIGH_CALIBRATED //2x16 map
} Input_Type;

typedef enum {
	UP_1M = 0,
	UP_1K,
	UP_10K,
	UP_2K49, //TEMP
	DOWN_1M,
	DOWN_1K,
	DOWN_10K,
	DOWN_2K49, //TEMP
} Input_Pull;


typedef enum {
	ON_OFF = 0,
	PWM
} Output_Type;

typedef enum {
	SINGLE = 0,
	DOUBLE,
	TRIPLE,
	QUADRUPLE
} Output_Group_Type;

typedef enum {
	CAN = 0,
	INPUT,
	SCREEN
} Output_Trigger_Type;


typedef struct {
	uint8_t Label[10];
	uint8_t Unit[10];
	uint8_t Enabled;
	Input_Type Type;
	Input_Pull PullValue;
	uint16_t CalibratedRange[2][16];
} INPUT_Channel;


typedef struct {
	uint8_t Label[10];
	uint8_t Unit[10];
	uint8_t Enabled;
	Input_Type Type;
	Output_Group_Type PinType;
	uint16_t PinRange[4];

	Output_Trigger_Type TriggerType;
	uint8_t TriggerId;

	uint16_t InrushCurrent;
	uint16_t InrushTime;
	uint16_t MaxCurrent;
	uint16_t MinCurrent;

	uint16_t RetryCount;
	uint16_t RetryEvery;
	uint16_t RetryForever;

	uint8_t Frequency;
	uint8_t DutyCycle;
	uint8_t SoftStartTime;

	uint8_t DefaultValue;
} OUTPUT_Channel;



#endif /* INC_DEF_IO_DEF_H_ */
