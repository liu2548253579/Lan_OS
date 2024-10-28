#include "Timer_User.h"


/**
 * @brief 计时函数，更新计时器状态
 * 
 * @param Time 
 * @return uint8_t 
 */
void Time_Tick(Timer_Element *Time)
{
	if(Time->Dir==0)//正向计时
	{
		if(Time->Tick>=Time->Set){Time->En=0;}
		else{Time->Tick++;}
	}
	else//反向计时
	{
		if(Time->Tick>0)
		{
			if(Time->En==1){Time->Tick--;}
		}
		else if(Time->Tick==0)
		{
			Time->En=0;
		}
	}
}

/**
 * @brief 返回当前的计时器状态计时完毕返回1，未计时完毕返回0
 * 
 * @param Time 
 * @return uint8_t 
 */
uint8_t Get_Time_State(Timer_Element *Time)
{
	return !Time->En;
}



/**
 * @brief 重置计时器
 * 
 * @param Time 
 */
void Time_Reset(Timer_Element *Time)
{
	Time->En=1;
    Time->Tick=0;
}


/**
 * @brief 翻转计时器
 * 
 * @param Time 
 */
void Time_Toggle(Timer_Element *Time)
{
	Time->En=1;
    Time->Dir=!Time->Dir;
}


