#ifndef __KEY_USER_H__
#define __KEY_USER_H__

#include <stdint.h>



typedef struct 
{
    uint8_t bit;//输入的按键bit

    uint8_t val_pre;//上一次按键值
    uint8_t state;//按键状态
    uint8_t multi_state;//多击状态

    uint32_t long_set;//设置长按触发时间(长按倒计时用)
    uint32_t time_set;//设置按键次数统计倒计时(统计单位时间按下次数用)

    uint8_t times_rec;//触发次数暂存位

    uint32_t tick_long;//长按计数
    uint32_t times_ticking;//长按计数上一次时间


    uint8_t times;//按键单位时间内触发次数
    uint8_t out;//按键输出值(长按2，短按1，无按0)
    
}Key_Element;


extern Key_Element key1;

void Key_Init(void);
void Key_Reset(Key_Element *key);
void Key_Refresh(void);

uint8_t Get_Key_Clik(Key_Element* key);
uint8_t Get_Key_Long(Key_Element* key);
uint8_t Get_Key_Times(Key_Element* key);

void Key_Task(void);


#endif /* __KEY_USER_H__ */

