#ifndef GLOBALS_H
#define GLOBALS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

#define BH1750_ENABLED			0
#define GPS_ENABLED				1
#define CAN_ENABLED				1
#define RGB_ENABLED				1
#define UART_ENABLED			0
#define IND_ENABLED 			1
#define ALERT_ENABLED  			1

#define LED_NUMBER				46
#define LED_DEFAULT_BRIGHTNESS		5

#define LCD_DEFAULT_BRIGHTNESS	1000

#define LCD_RPM_HIGH 			8000

#define PROTECTION_RPM_LOW 		6500
#define PROTECTION_RPM_HIGH 	7800

#define PROTECTION_RPM_LED 		6

#define PROTECTION_OIL_LOW 		40
#define PROTECTION_FUEL_LOW 	40

#define PSI_TO_BAR 				0.0689476f
#define BAR_TO_PSI 				14.5038f
#define KPA_TO_BAR 				0.01f
#define KPA_TO_PSI 				0.145038f

#define AFR_TO_LAMBDA 			14.7f

#define SYSTEM_DEBUG_COUNT 		4
#define SYSTEM_DEBUG_LENGTH 	64

typedef enum {
	CAN_LINK = 0,
	CAN_MX5
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

typedef struct {
	uint16_t Enabled;
	char Label[10];
	char Unit[10];
	uint16_t Offset;
	uint16_t Multiplier;
	uint16_t Divider;
	uint16_t DecimalPlaces;
	uint16_t DefaultValue;
	uint16_t Channel;
} FieldDef;

//
//typedef struct {
//
//	uint16_t TPS;
//	uint16_t MAP;
//	uint16_t BOOST;
//	uint16_t BARO;
//	uint16_t CLT;
//	uint16_t IAT;
//	uint16_t SPEED;
//	uint16_t BATTERY;
//
//	uint16_t EGT1;
//	uint16_t EGT2;
//	uint16_t EGT3;
//	uint16_t EGT4;
//	uint16_t EGT5;
//	uint16_t EGT6;
//	uint16_t EGT7;
//	uint16_t EGT8;
//
//	uint16_t ANALOG1;
//	uint16_t ANALOG2;
//	uint16_t ANALOG3;
//	uint16_t ANALOG4;
//	uint16_t ANALOG5;
//	uint16_t ANALOG6;
//	uint16_t ANALOG7;
//	uint16_t ANALOG8;
//
//	uint16_t DIGITAL1;
//	uint16_t DIGITAL2;
//	uint16_t DIGITAL3;
//	uint16_t DIGITAL4;
//	uint16_t DIGITAL5;
//	uint16_t DIGITAL6;
//	uint16_t DIGITAL7;
//	uint16_t DIGITAL8;
//
//	uint16_t IGNANGLE;
//	uint16_t IGNDWELL;
//	uint16_t INJPW;
//	uint16_t INJDC;
//	uint16_t SECINJPW;
//	uint16_t SECINJDC;
//	uint16_t KNOCKLVL;
//	uint16_t LAMBDA1;
//	uint16_t LAMBDA2;
//	uint16_t AFR1;
//	uint16_t AFR2;
//
//	uint16_t OILPRESS;
//	uint16_t OILTEMP;
//	uint16_t FUELTEMP;
//	uint16_t FUELPRESS;
//	uint16_t WATERPRESS;
//
//	uint16_t MPG;
//	uint16_t L100KM;
//
//} ECU;
//
//typedef struct {
//	uint16_t CLT_ERROR;
//	uint16_t IAT_ERROR;
//	uint16_t MAP_ERROR;
//	uint16_t TPS_ERROR;
//	uint16_t BARO_ERROR;
//	uint16_t EGT_ERROR;
//	uint16_t KNOCK_ERROR;
//
//} ERRORS;
//
//
//typedef struct {
//	uint16_t CHN_ID;
//	uint16_t CHN_CAN_ID;
//	uint16_t CHN_CAN_TYPE;
//	uint16_t CHN_CAN_FORMAT;
//	uint16_t CHN_CAN_ENDIAN;
//	uint16_t CHN_CAN_OFFSET;
//	uint16_t CHN_DATA_MULTIPLIER;
//	uint16_t CHN_DATA_DIVIDER;
//	uint16_t CHN_DATA_OFFSET;
//	uint16_t CHN_DATA_DEFAULT;
//	uint16_t CHN_DATA_TIMEOUT;
//} CHANNEL;

//typedef struct {
//	uint16_t CLT_LOW;
//	uint16_t CLT_HIGH;
//
//	uint16_t IAT_LOW;
//	uint16_t IAT_HIGH;
//
//	uint16_t RPM_LOW;
//	uint16_t RPM_HIGH;
//
//	uint16_t MAP_LOW;
//	uint16_t MAP_HIGH;
//
//	uint16_t LAMBDA_LOW;
//	uint16_t LAMBDA_HIGH;
//
//	uint16_t OIL_P_LOW;
//	uint16_t OIL_P_HIGH;
//
//	uint16_t FUEL_P_LOW;
//	uint16_t FUEL_P_HIGH;
//
//	uint16_t OIL_T_LOW;
//	uint16_t OIL_T_HIGH;
//
//	uint16_t FUEL_T_LOW;
//	uint16_t FUEL_T_HIGH;
//
//	uint16_t EGT_LOW;
//	uint16_t EGT_HIGH;
//
//	uint16_t KNOCK_LOW;
//	uint16_t KNOCK_HIGH;
//
//	uint16_t BATTERY_LOW;
//	uint16_t BATTERY_HIGH;
//} FLAGS;

typedef struct {
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
	uint16_t ECT;
	uint16_t IAT;
	uint16_t ETHANOL;
	int16_t MAP;
	uint16_t BARO;
	uint16_t BATT;
	uint16_t FUELP;
	uint16_t OILP;
	uint16_t FUELT;
	uint16_t OILT;

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
	uint16_t LCD_BRIGHTNESS;
	uint8_t LCD_BRIGHTNESS_CHANGED;
	uint8_t CAN_PROTOCOL;

	//BTN
	uint8_t BTN_TOP_RIGHT;
	uint8_t BTN_TOP_LEFT;
	uint8_t BTN_BOTTOM_RIGHT;
	uint8_t BTN_BOTTOM_LEFT;

} Statuses;

#ifdef __cplusplus
}
#endif

#endif // GLOBALS_H
