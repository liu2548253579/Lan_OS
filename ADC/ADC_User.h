#ifndef __ADC_USER_H__
#define __ADC_USER_H__

#include "stdint.h"

#define ADC_CHANNEL_NUM 4 //ADC通道数量
#define ADC_VREF 3.300f //ADC参考电压
#define ADC_RESOLUTION 4095.000f //ADC采样精度

#define VBAT_MAX_VOL 4.2f //电池百分比最大电压
#define VBAT_MIN_VOL 3.2f //电池百分比最小电压

#define VDD_VREF 1.200f //VDD参考电压
#define VDD_TRIM 0.000f //VDD校准电压

typedef struct
{
    uint8_t Level;//电池电量阶段
    uint8_t Percent;//电池电量百分比
    uint32_t Val;//ADC采样值RAW值
    float VOL;//实际电压值
}ADC_Bat_Element;

extern uint8_t ADC_Count;//ADC轮询标志


void ADC_Init(void);
void ADC_Task(void);


#endif /* __ADC_USER_H__ */
