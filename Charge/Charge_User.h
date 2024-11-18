#ifndef __CHARGE_USER_H__
#define __CHARGE_USER_H__

#include "stdint.h"

typedef struct
{
    uint8_t Vin;//是否接入电源{0:未接入 1:已接入}
    uint8_t Vin_Pre;//电源之前状态
    uint8_t State;//充电状态{0:充电中 1:充满}
}
Charge_Element;

extern Charge_Element Charge_Data;


void Charge_Init(void);
void Charge_Task(Charge_Element *Charge);






#endif /* __CHARGE_USER_H__ */
