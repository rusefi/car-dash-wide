/*
 * extern.h
 *
 *  Created on: May 14, 2020
 *      Author: Dev
 */

#ifndef __EXTERN_H_
#define __EXTERN_H_

#include "Globals.h"

extern Statuses Current_Status;
extern FILE *FileBuffer;
extern uint8_t BufferIsSet;

extern uint8_t uartTransmitBufferSize;
extern uint8_t uartTransmitBuffer[128];



#endif /* INC_EXTERN_H_ */
