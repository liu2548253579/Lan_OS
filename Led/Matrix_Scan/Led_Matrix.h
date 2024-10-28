#ifndef __LED_MATRIX_H__
#define __LED_MATRIX_H__

#include "stdint.h"

#define BIT_0 0x01
#define BIT_1 0x02
#define BIT_2 0x04
#define BIT_3 0x08
#define BIT_4 0x10
#define BIT_5 0x20
#define BIT_6 0x40
#define BIT_7 0x80


extern uint8_t LED_Data[2];


void LED_Init(void);
void LED_Task(void);




#endif /* __LED_MATRIX_H__ */
