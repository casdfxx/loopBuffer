#include "loopBuffer.h"

//#define LOOPBUFFER_SIZE     (2*1024*1024U) //2MB


static uint8_t u8S_Loopbuffer[LOOPBUFFER_SIZE];
static uint32_t u32S_WriteIndex, u32S_ReadIndex;

void x_InitLoopBuffer(){
    u32S_WriteIndex  = u32S_ReadIndex    = 0;
}

/*
* @brief: write array to u8S_Loopbuffer
* @param  : pu8I_Buff----data will be store. u32I_WriteLen----how many number will be copy.
* @return : real write
*/
int x_loopWrite(uint8_t* pu8I_Buff, int u32I_WriteLen){
    int u32O_Ret    = 0;

    while(u32O_Ret<u32I_WriteLen){

        if((u32S_WriteIndex+1) != u32S_ReadIndex){
            if(u32S_WriteIndex+1 < LOOPBUFFER_SIZE){
                u8S_Loopbuffer[++u32S_WriteIndex]   = pu8I_Buff[u32O_Ret];
            }else{
                if(0 != u32S_ReadIndex){
                    u32S_WriteIndex = 0;
                    u8S_Loopbuffer[u32S_WriteIndex]   = pu8I_Buff[u32O_Ret];
                }else{
                    break;
                }
            }
        }else{
            break;
        }
        u32O_Ret++;
    }
    return u32O_Ret;
}

/*
* @brief: read array from u8S_Loopbuffer
* @param  : pu8I_Buff----data will be read to. u32I_ReadLen----how many number will be read.
* @return : real read
*/
int x_loopRead(uint8_t* pu8I_Buff, int u32I_ReadLen){
    int u32O_Ret    = 0;

    while(u32O_Ret<u32I_ReadLen){

        if((u32S_ReadIndex) != u32S_WriteIndex){
            if(u32S_ReadIndex+1 < LOOPBUFFER_SIZE){
                pu8I_Buff[u32O_Ret] = u8S_Loopbuffer[++u32S_ReadIndex];
            }else{
                if(0 != u32S_WriteIndex){
                    u32S_ReadIndex = 0;
                    pu8I_Buff[u32O_Ret] = u8S_Loopbuffer[u32S_ReadIndex];
                }else{
                    break;
                }
            }
        }else{
            break;
        }
        u32O_Ret++;
    }
    return u32O_Ret;
}

