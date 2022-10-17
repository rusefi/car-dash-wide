#ifndef __GLOBALS_H
#define __GLOBALS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdbool.h>
#include <Def/CAN_Def.h>
#include <Def/UNIT_Def.h>
#include <Def/IO_Def.h>
#include <Def/STORAGE_Def.h>


#define BH1750_ENABLED			0
#define GPS_ENABLED				1
#define CAN_ENABLED				1
#define RGB_ENABLED				1
#define UART_ENABLED			0
#define IND_ENABLED 			0
#define ALERT_ENABLED  			0

#define LED_NUMBER				24
#define LED_DEFAULT_BRIGHTNESS		2

#define LCD_DEFAULT_BRIGHTNESS	400

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

#define USE_1024x600
//#define USE_800x480

#ifdef USE_1024x600
	#define LCD_RES_X  1024
	#define LCD_RES_Y  600
#else
	#define LCD_RES_X  800
	#define LCD_RES_Y  480
#endif

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


	uint8_t CELL[16];

} Statuses;

#ifdef __cplusplus
}
#endif

#endif // GLOBALS_H
