#ifndef __TIMER_USER_H__
#define __TIMER_USER_H__


#include "stdint.h"



typedef struct
{
    volatile uint8_t En;//使能
    volatile uint8_t Dir;//方向
    volatile uint32_t Set;//时间设置
    volatile uint32_t Tick;
}Timer_Element;



void Time_Tick(Timer_Element *Time);
uint8_t Get_Time_State(Timer_Element *Time);
void Time_Reset(Timer_Element *Time);
void Time_Toggle(Timer_Element *Time);

#endif /* __TIMER_USER_H__ */
