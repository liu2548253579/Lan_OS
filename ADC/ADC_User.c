#include "ADC_User.h"

uint8_t ADC_Count=0;

/**
 * @brief 初始化ADC引脚
 */
void ADC_GPIO_Init(void)
{
    /*
    GPIO_InitTypeDef GPIO_InitStruct;
    __HAL_RCC_GPIOA_CLK_ENABLE();
    GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
    */

}

/**
 * @brief 初始化ADC
 */
void ADC_Init(void)
{
    ADC_GPIO_Init();
    ADC_Count=0;

}


/**
 * @brief 根据ADC采样值计算电压值
 */
float Get_ADC_Vol(uint32_t Adc_Val,const float Vol_Div)
{
    float temp;
    temp=((float)Adc_Val * ADC_VREF / ADC_RESOLUTION)/Vol_Div;
    return  temp;
}

/**
 * @brief 根据内部Vref通道反推VDD电压
 */
float Get_VDD_Vol(float Vdd_Adc,float Vref)
{
    float Vdd_Dat=(((Vref/Vdd_Adc)*ADC_RESOLUTION))+VDD_TRIM;
    return Vdd_Dat;
}


/*
 * @brief 根据最小电压、最大电压、当前电压计算电池电量百分比
 */
uint8_t Get_BAT_Percent(float Vol_Bat,const float Min_Vol,const float Max_Vol) 
{
    uint8_t temp; //电池电量百分比
    // 确保输入电压在有效范围内
    if (Vol_Bat <= Min_Vol){return 0;}
    if (Vol_Bat >= Max_Vol){return 100;}
    temp = (float)((Vol_Bat - Min_Vol) / (Max_Vol - Min_Vol)) * 100.0f;    // 计算电量百分比
    return temp;
}

/**
 * @brief 根据电压值计算电池等级
 */
uint8_t Get_BAT_Level(float Vol_Bat)
{
    uint8_t temp;
    if(Vol_Bat>3.9f)
    {
        temp=4;
    }
    else if(Vol_Bat>3.65f)
    {
        temp=3;
    }
    else if(Vol_Bat>3.4f)
    {
        temp=2;
    }
    else if(Vol_Bat>3.0f)
    {
        temp=1;
    }
    else
    {
        temp=0;
    }

    return temp;
}


/**
 * @brief 刷新ADC采样值
 */
void ADC_Refresh(void)
{
    if(ADC_Count==0){}
    else if (ADC_Count==1){}
    else if (ADC_Count==2){}
    else if (ADC_Count==3){}
    if(++ADC_Count>=ADC_CHANNEL_NUM){ADC_Count=0;}
}

/**
 * @brief ADC任务
 */
void ADC_Task(void)
{

}

