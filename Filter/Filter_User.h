#ifndef __FILTER_USER_H__
#define __FILTER_USER_H__

#include "stdint.h"

//定义低通滤波器结构体
typedef struct
{
    uint16_t value;//输入数据
    uint16_t pre;//前一时刻输入数据
    uint16_t out;//输出数据
}LowPass_Filter_Element;

//定义滑动均值滤波器结构体
typedef struct
{
    uint16_t Sample_num;//采样次数
    uint16_t count;//计数器
    uint16_t value;//输入数据
    uint16_t out;//输出数据
    uint16_t record[60];//记录数组
}Slip_Filter_Element;




void LowPass_Filter (LowPass_Filter_Element *lowpass);
void Slip_Filter (Slip_Filter_Element *slip);



#endif /* __FILTER_USER_H__ */

