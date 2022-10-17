/*
 * STORAGE_Def.h
 *
 *  Created on: Oct 16, 2022
 *      Author: Ben
 */

#ifndef INC_DEF_STORAGE_DEF_H_
#define INC_DEF_STORAGE_DEF_H_


typedef struct {
	CAN_Message Can_Messages[128]; //16*128=2048 bytes
	CAN_Input Can_Inputs[256];	//23*256=5888 bytes
	CAN_Output Can_Outputs[256]; //22*256=5632 bytes
	INPUT_Channel Input_Channels[16]; //22*256=5632 bytes
	OUTPUT_Channel Output_Channels[16]; //22*256=5632 bytes
} FLASH_Storage;




#endif /* INC_DEF_STORAGE_DEF_H_ */
