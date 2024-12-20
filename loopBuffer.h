#ifndef _LOOPBUFFER_H_
#define _LOOPBUFFER_H_

#include <stdint.h>
#include <stdbool.h>

void x_InitLoopBuffer();
int x_loopWrite(uint8_t* pu8I_Buff, int u32I_WriteLen);
int x_loopRead(uint8_t* pu8I_Buff, int u32I_ReadLen);

#define LOOPBUFFER_SIZE     (10U) //2MB
#endif
