#ifndef __CAN_DEF_H
#define __CAN_DEF_H


#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdbool.h>


typedef enum {
	CAN_ENUM_MESSAGE_ID_STANDARD = 0,
	CAN_ENUM_MESSAGE_ID_EXTENDED,
	CAN_ENUM_MESSAGE_FORMAT_NORMAL,
	CAN_ENUM_MESSAGE_FORMAT_J1939,
	CAN_ENUM_MESSAGE_SIZE_1FRAME,
	CAN_ENUM_MESSAGE_SIZE_2FRAME,
	CAN_ENUM_MESSAGE_SIZE_4FRAME,
	CAN_ENUM_MESSAGE_SIZE_8FRAME,
	CAN_ENUM_BUS_0,
	CAN_ENUM_BUS_1,
	CAN_ENUM_BUS_2,
	CAN_ENUM_DATA_TYPE_UNSIGNED,
	CAN_ENUM_DATA_TYPE_SIGNED,
	CAN_ENUM_DATA_FORMAT_BIT8,
	CAN_ENUM_DATA_FORMAT_BIT16,
	CAN_ENUM_DATA_ENDIAN_LITTLE,
	CAN_ENUM_DATA_ENDIAN_BIG,
	CAN_ENUM_DATA_TIMEOUT_KEEP_VALUE,
	CAN_ENUM_DATA_TIMEOUT_SET_VALUE
} CAN_Enum;


typedef struct {
	char Label[10];
	CAN_Enum Bus; //CAN_0, CAN_1 or CAN_2
	uint8_t BaseId;
	CAN_Enum BaseIdType; //STANDARD or EXTENDED
	CAN_Enum Type; //NORMAL, J1939 ...
	CAN_Enum Size; //1FRAME, 2FRAME, 4FRAME or 8FRAME
	uint8_t Timeout;
} CAN_Message;

typedef struct {
	char Label[10];
	CAN_Message Message;
	uint8_t MessageOffset;
	CAN_Enum Type; //UNSIGNED or SIGNED
	CAN_Enum Format; // 8BIT or 16BIT
	CAN_Enum Endian; //LITTLE or BIG
	uint8_t ByteOffset;
	uint8_t Multiplier;
	uint8_t Divider;
	uint8_t DecimalPlaces;
	uint8_t Offset;
	uint8_t Default;
	CAN_Enum TimeoutAction; //KEEP or SET
	uint8_t TimeoutValue;

} CAN_Input;

typedef struct {
	char Label[10];
	CAN_Enum Bus; //CAN_0, CAN_1 or CAN_2
	uint8_t BaseId;
	CAN_Enum BaseIdType; //STANDARD or EXTENDED
	uint8_t Frequency;
	uint8_t Data[8];
} CAN_Output;



#ifdef __cplusplus
}
#endif

#endif // CAN_DEF_H
