/*
 * IO_Def.h
 *
 *  Created on: Oct 16, 2022
 *      Author: Ben
 */

#ifndef INC_DEF_SCREEN_DEF_H_
#define INC_DEF_SCREEN_DEF_H_

typedef enum {
	LEFT = 0,
	CENTER,
	RIGHT
} Align;

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
} DataChannelEnum;

typedef struct {
	char Label[32];
	int16_t X;
	int16_t Y;
	int16_t Width;
	int16_t Height;
	Align Alignment;
	uint8_t Label_Error_RGB [3];
	uint8_t Label_Warning_RGB [3];
	uint8_t Label_OK_RGB [3];
	uint8_t Label_Default_RGB [3];
} FIELD_Settings;

typedef struct {
	uint8_t Enabled;
	FIELD_Settings Label;
	FIELD_Settings Unit;
	FIELD_Settings Value;
	uint8_t Background_Error_RGB [3];
	uint8_t Background_Warning_RGB [3];
	uint8_t Background_OK_RGB [3];
	uint8_t Background_Default_RGB [3];

	DataChannelEnum DataChannel;
	int16_t ValueDefault;

} SCREEN_Channel;



#endif /* INC_DEF_SCREEN_DEF_H_ */
