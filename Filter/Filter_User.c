#include "Filter_User.h"


/**
 * @brief 低通滤波器
 */
void LowPass_Filter (LowPass_Filter_Element *lowpass)
{
    lowpass->out=((float)lowpass->value*0.3f)+((float)lowpass->pre*0.7f);
    lowpass->pre=lowpass->value;
}



/**
 * @brief 滑动均值滤波器
 */
void Slip_Filter (Slip_Filter_Element *slip)
{
    uint64_t Filter_value = 0;
    if(++slip->count >= slip->Sample_num){slip->count = 0;}//累计样本数
    slip->record[slip->count] = slip->value;//记录样本值
    for (uint16_t i = 0; i < slip->Sample_num; i++)
    {
        Filter_value+= slip->record[i];//累加数据
    }
    slip->out = (Filter_value/slip->Sample_num);//输出滤波结果
}

