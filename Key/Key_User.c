#include "Key_User.h"


#error "请在此处配置多击统计时间与长按时间的Tick值，Tick值单位由Key_Refresh函数的调用周期决定"
Key_Element key1={
    // .long_set=1000,//长按时间(Tick)
    // .time_set=500//统计多按时间(Tick)
};


/**
 * @brief 初始化按键GPIO
 * 
 */
void Key_Init(void)
{
    #error "请在此处配置按键GPIO或ADC按键"
    //EG: pinMode(KEY_GPIO, INPUT);//配置按键GPIO为输入模式

}


/**
 * @brief 清除按键状态
 * 
 * @param key 
 */
void Key_Reset(Key_Element *key)
{
    key->times=0;
    key->times_rec=0;
    key->times_ticking=0;
    key->tick_long=0;
    key->out=0;
    key->state=0;
    key->val_pre=0;
    key->bit=0;
    key->multi_state=0;
}


/**
 * @brief 读取按键状态,返回按键值(长按2，短按1，无按0)
 * 
 * @param key 
 */
void Read_Key(Key_Element* key)
{
    if(!key->bit&&!key->val_pre){key->state=0;}//没按下

    switch(key->state)//按键状态机
    {
        case 0:
            if(key->bit&&!key->val_pre){key->state=1;}//上升沿
            break;
        case 1:
            if(key->bit&&key->val_pre){key->state=2;}//持续按下
            break;
        case 2:
            if(!key->bit&&key->val_pre){key->state=3;}//下降沿
            break;
    }

    if(key->long_set!=0)//设置了长按时间
    {
        if(key->state==2){key->tick_long++;}//在持续按下的时候开始长按计时
        if(key->tick_long>=key->long_set){key->state=4;key->tick_long=0;}//超过长按时间判定为长按
    }

    if(key->state==3)//短按触发返回1
    {
        key->state=0;key->out=1;key->tick_long=0;
    }
    else if(key->state==4)//长按触发返回2
    {
        key->state=0;key->out=2;
    }
    else//无按返回0
    {
        key->out=0;
    }

    key->val_pre=key->bit;//传递上一次按键状态

    //单位时间内次数检测
    if(key->multi_state==0&&key->out==1){key->multi_state=1;}//第一次按下并开始计时
    if(key->multi_state==1)//计时中
    {
        key->times_ticking++;//计时
        if(key->times_ticking>=key->time_set){key->multi_state=2;key->times_ticking=0;}//计时结束
        else
        {
            if(key->out){key->times_rec++;}//次数暂存位自增
        }
    }
    if(key->multi_state==2){key->multi_state=0;key->times=key->times_rec;key->times_rec=0;}//返回按下次数
    else{key->times=0;}//时间未到或按键未按下返回0
}



/**
 * @brief 刷新按键状态
 * 
 */
void Key_Refresh(void)
{
    #error "请在此处将按键的开关量赋予key*.bit,并为key*添加Read_Key函数"
    //EG: key1.bit=digitalRead(KEY_GPIO);Read_Key(&key1);//读取按键状态

}

/**
 * @brief 获取按键单击
 */
uint8_t Get_Key_Clik(Key_Element* key)
{
    uint8_t temp;
    if(key->out!=0){temp=1;}else{temp=0;}
    return temp;
}

/**
 * @brief 获取按键长按
 */
uint8_t Get_Key_Long(Key_Element* key)
{
    uint8_t temp;
    if(key->out==2){temp=1;}else{temp=0;}
    return temp;
}

/**
 * @brief 获取按键连击次数
 */
uint8_t Get_Key_Times(Key_Element* key)
{
    return key->times;
}


/**
 * @brief 按键任务函数
 * 
 */
void Key_Task(void)
{


}
