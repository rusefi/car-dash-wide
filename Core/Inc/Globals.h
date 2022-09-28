#ifndef __GLOBALS_H
#define __GLOBALS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdbool.h>


#define GPS_ENABLED				0
#define CAN_ENABLED				1
#define RGB_ENABLED				1
#define UART_ENABLED			0
#define IND_ENABLED 			0
#define ALERT_ENABLED  			0

#define LED_NUMBER				14
#define LED_DEFAULT_BRIGHTNESS		2

#define LCD_DEFAULT_BRIGHTNESS	1000

#define LCD_RPM_HIGH 			8000

#define PROTECTION_RPM_LOW 		6500
#define PROTECTION_RPM_HIGH 	7800

#define PROTECTION_RPM_LED 		6

#define PROTECTION_OIL_LOW 		40
#define PROTECTION_FUEL_LOW 	40

#define PSI_TO_BAR 				0.0689476f
#define PSI_TO_KPA 				6.89476f
#define BAR_TO_PSI 				14.5038f
#define BAR_TO_KPA 				100.0f
#define KPA_TO_BAR 				0.01f
#define KPA_TO_PSI 				0.145038f

#define AFR_TO_LAMBDA 			0.06802721088f

#define SYSTEM_DEBUG_COUNT 		4
#define SYSTEM_DEBUG_LENGTH 	64


#define USE_1024x600
#ifdef USE_1024x600
	#define LCD_RES_X  1024
	#define LCD_RES_Y  600
#endif

typedef enum {
	kPa = 0,
	BAR,
	PSI,
	C,
	F,
	Kmh,
	Mph,
	Lambda,
	Afr
} UnitDefEnum;


typedef enum {
	CAN_LINK = 0,
	CAN_AIM,
	CAN_MX5,
	CAN_BMW_PHEV
} CANDefEnum;

typedef enum {
	CH_MGP = 0,
	CH_INJ_DC,
	CH_INJ_DC_ST,
	CH_INJ_PULSE,
	CH_MAF,
	CH_INJ_TIM,
	CH_IGN_TIM,
	CH_CAM_I_L,
	CH_CAM_I_R,
	CH_CAM_E_L,
	CH_CAM_E_R,
	CH_LAMBDA1,
	CH_LAMBDA2,
	CH_TRIG1_ERROR,
	CH_FAULT_CODES,
	CH_LF_SPEED,
	CH_LR_SPEED,
	CH_RF_SPEED,
	CH_RR_SPEED,
	CH_KNOCK1,
	CH_KNOCK2,
	CH_KNOCK3,
	CH_KNOCK4,
	CH_KNOCK5,
	CH_KNOCK6,
	CH_KNOCK7,
	CH_KNOCK8,
	CH_LIMITS,
	CH_TPS,
	CH_ECT,
	CH_IAT,
	CH_ETHANOL,
	CH_MAP,
	CH_BARO,
	CH_BATT,
	CH_FUELP,
	CH_OILP,
	CH_FUELT,
	CH_OILT
} ChannelEnum;

struct RGBLED {
	uint8_t enabled;
	int color;
};


typedef enum {
	ACTIVE_LOW = 0,
	ACTIVE_LOW_ROTARY,
	ACTIVE_HIGH,
	ACTIVE_HIGH_LINEAR, // 2x2 map
	ACTIVE_HIGH_CALIBRATED //2x16 map
} InputTypeEnum;

typedef enum {
	UP_1M = 0,
	UP_1K,
	UP_10K,
	UP_2K49, //TEMP
	DOWN_1M,
	DOWN_1K,
	DOWN_10K,
	DOWN_2K49, //TEMP
} InputPullEnum;


typedef enum {
	ON_OFF = 0,
	PWM
} OutputTypeEnum;

typedef enum {
	SINGLE = 0,
	DOUBLE,
	TRIPLE,
	QUADRUPLE
} OutputPinTypeEnum;

typedef enum {
	CAN = 0,
	INPUT,
	SCREEN
} OutputTriggerTypeEnum;

typedef struct {
	uint8_t Id;
	char Label[10];
	char Unit[10];
	bool Enabled;
	InputTypeEnum Type;
	InputPullEnum PullValue;
	uint16_t CalibratedRange[2][16];
} InputDef;


typedef struct {
	uint8_t Id;
	char Label[10];
	char Unit[10];
	bool Enabled;
	OutputTypeEnum Type;
	OutputPinTypeEnum PinType;
	uint16_t PinRange[4];

	OutputTriggerTypeEnum TriggerType;
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

	bool DefaultValue;
} OutputDef;



typedef struct {
	uint8_t Id;
	char Label[10];
	char Unit[10];
	bool Enabled;
	uint8_t CanId;
	uint8_t StartByte;
	uint8_t EndByte;
} CANDef;

typedef struct {
	uint8_t Id;
	char Label[10];
	char Unit[10];
	bool Enabled;
	uint16_t Offset;
	uint16_t Multiplier;
	uint16_t Divider;
	uint16_t DecimalPlaces;
	uint16_t DefaultValue;
} FieldDef;

typedef struct {
	bool ENABLED;
	uint32_t TICK;
	bool BALANCE;
	bool IGNORE;
	uint32_t ERROR;
	uint16_t CELLS[16];
	uint16_t TEMPS[4];
	uint16_t TEMPOFF;
	uint16_t VOLTAGE;
	uint16_t LOWEST_CELL_VOLTAGE;
	uint8_t LOWEST_CELL_ID;
	uint16_t HIGHEST_CELL_VOLTAGE;
	uint8_t HIGHEST_CELL_ID;
} ModuleDef;

typedef struct {

	uint8_t PRES_UNIT;
	uint8_t TEMP_UNIT;
	uint8_t SPEED_UNIT;


	uint16_t RPM;
	uint16_t RPM_100;
	uint16_t RPM_180;
	uint16_t RPM_240;
	uint16_t RPM_270;
	uint16_t RPM_360;
	uint16_t RPM_RGB;


	uint16_t MGP;
	uint16_t INJ_DC;
	uint16_t INJ_DC_ST;
	uint16_t INJ_PULSE;
	uint16_t MAF;
	uint16_t INJ_TIM;
	uint16_t IGN_TIM;
	uint16_t CAM_I_L;
	uint16_t CAM_I_R;
	uint16_t CAM_E_L;
	uint16_t CAM_E_R;
	uint16_t LAMBDA1;
	uint16_t LAMBDA2;
	uint16_t TRIG1_ERROR;
	uint16_t FAULT_CODES;
	uint16_t LF_SPEED;
	uint16_t LR_SPEED;
	uint16_t RF_SPEED;
	uint16_t RR_SPEED;
	uint16_t KNOCK1;
	uint16_t KNOCK2;
	uint16_t KNOCK3;
	uint16_t KNOCK4;
	uint16_t KNOCK5;
	uint16_t KNOCK6;
	uint16_t KNOCK7;
	uint16_t KNOCK8;
	uint16_t LIMITS;

	uint16_t TPS;
	int16_t ECT;
	int16_t IAT;
	uint16_t ETHANOL;
	int16_t MAP;
	uint16_t BARO;
	uint16_t BATT;
	uint16_t FUELP;
	uint16_t OILP;
	int16_t FUELT;
	int16_t OILT;

	uint16_t BH1750_LUX;

	uint16_t GPS_LATITUDE;
	uint16_t GPS_LONGITUDE;
	uint16_t GPS_FIXED;
	uint16_t GPS_SATTELITES;
	uint16_t GPS_ALTITUDE;
	uint16_t GPS_SPEED;

	uint16_t GEAR;
	uint8_t ENGINE_PROTECTION;

	uint16_t IND_LEFT;
	uint16_t IND_HIGH;
	uint16_t IND_FUEL;
	uint16_t IND_OIL;
	uint16_t IND_BATT;
	uint16_t IND_PARK;
	uint16_t IND_DTC;
	uint16_t IND_ECT;
	uint16_t IND_LOW;
	uint16_t IND_RIGHT;


	char * SYSTEM_DEBUG_MESSAGE[SYSTEM_DEBUG_COUNT];

	uint16_t LED_BRIGHTNESS;
	uint8_t LED_BRIGHTNESS_CHANGED;
	uint16_t LCD_BRIGHTNESS;
	uint8_t LCD_BRIGHTNESS_CHANGED;
	uint8_t CAN_PROTOCOL;

	//BTN
	uint8_t BTN_TOP_RIGHT;
	uint8_t BTN_TOP_LEFT;
	uint8_t BTN_BOTTOM_RIGHT;
	uint8_t BTN_BOTTOM_LEFT;


	ModuleDef BATTERY_MODULES[6];
	uint16_t BATTERY_VOLTAGE;

} Statuses;

#ifdef __cplusplus
}
#endif

#endif // GLOBALS_H
