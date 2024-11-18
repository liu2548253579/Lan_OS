#include "LowPower_User.h"

uint8_t LowPower_Flag = 0;

/**
 * @brief 配置时钟为正常工作时钟
 */
void Norm_SystemClockConfig(void)
{

}



/**
 * @brief 配置时钟为低功耗时钟
 */
void LowPower_SystemClockConfig(void)
{

}



/**
 * @brief 中断唤醒控制
 */
void Exti_Config(void)
{
    /*
    GPIO_InitTypeDef  GPIO_InitStruct;
    __HAL_RCC_GPIOB_CLK_ENABLE();                
    //充电
    GPIO_InitStruct.Mode  = GPIO_MODE_IT_RISING;   
    GPIO_InitStruct.Pull  = GPIO_NOPULL;           
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;  
    GPIO_InitStruct.Pin = GPIO_PIN_5;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    //按键
    GPIO_InitStruct.Mode  = GPIO_MODE_IT_FALLING;   
    GPIO_InitStruct.Pull  = GPIO_PULLUP;           
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH; 
    GPIO_InitStruct.Pin = GPIO_PIN_8;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    HAL_NVIC_EnableIRQ(EXTI4_15_IRQn);         
    HAL_NVIC_SetPriority(EXTI4_15_IRQn, 0, 0);   
    */
}

/**
 * @brief 设置所有GPIO为浮空输入
 * @warning 注意boot与nrst不设置,调试的时候SWD引脚也不设置，否则容易调试失败
 */
void Set_GPIO_Floating(void)
{
    //设置全部IO浮空输入
    /*EG:
    GPIO_InitTypeDef  GPIO_InitStruct;
    __HAL_RCC_GPIOA_CLK_ENABLE();                                       
    GPIO_InitStruct.Mode  = GPIO_MODE_ANALOG;   
    GPIO_InitStruct.Pull  = GPIO_NOPULL;      
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;  
    GPIO_InitStruct.Pin = GPIO_PIN_All;//SWDIO和SWCLK不设置 &~(GPIO_PIN_13)&~(GPIO_PIN_14) 
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    __HAL_RCC_GPIOB_CLK_ENABLE();                                       
    GPIO_InitStruct.Mode  = GPIO_MODE_ANALOG;   
    GPIO_InitStruct.Pull  = GPIO_NOPULL;    
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;   
    GPIO_InitStruct.Pin = GPIO_PIN_All;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    __HAL_RCC_GPIOF_CLK_ENABLE();                                       
    GPIO_InitStruct.Mode  = GPIO_MODE_ANALOG;   
    GPIO_InitStruct.Pull  = GPIO_NOPULL;      
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;  
    GPIO_InitStruct.Pin = GPIO_PIN_All;//BOOT与NRST不设置 &~(GPIO_PIN_2)&~(GPIO_PIN_4)
    HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);  
    */
}

/**
 * @brief 关闭所有外设
 */
void DeInit_Peripherals(void)
{
    /*EG:
    HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_3);
    HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_4);

	HAL_TIM_Base_Stop_IT(&htim1);
	HAL_ADC_Stop_IT(&AdcHandle);

	HAL_UART_DeInit(&Uart_Handle);
	HAL_TIM_Base_DeInit(&htim1);
	HAL_TIM_PWM_DeInit(&htim3);
	HAL_ADC_DeInit(&AdcHandle);

    __HAL_RCC_ADC_CLK_DISABLE();                            
    __HAL_RCC_TIM1_CLK_DISABLE();                        
	__HAL_RCC_TIM3_CLK_DISABLE();                    
	__HAL_RCC_USART1_CLK_DISABLE();                    
	__HAL_RCC_USART2_CLK_DISABLE();                         

	__HAL_RCC_FLASH_CLK_DISABLE();                        
	__HAL_RCC_SRAM_CLK_DISABLE();
	__HAL_RCC_CRC_CLK_DISABLE();
	__HAL_RCC_DBGMCU_CLK_DISABLE();
	__HAL_RCC_I2C_CLK_DISABLE();
	__HAL_RCC_LPTIM_CLK_DISABLE();
	__HAL_RCC_LSI_DISABLE();

	__HAL_RCC_GPIOA_CLK_DISABLE();
	__HAL_RCC_GPIOB_CLK_DISABLE();
	__HAL_RCC_GPIOF_CLK_DISABLE();

    HAL_NVIC_DisableIRQ(TIM1_BRK_UP_TRG_COM_IRQn);
    HAL_NVIC_DisableIRQ(DMA1_Channel1_IRQn);
    HAL_NVIC_DisableIRQ(DMA1_Channel2_3_IRQn);
    HAL_NVIC_DisableIRQ(ADC_COMP_IRQn);
    */

}

/**
 * @brief 低功耗模式任务
 * @note 该函数只能在循环中调用，否则会导致HardFault
 */
void LowPower_Task(void)
{
    if(LowPower_Flag == 1)
    {
        Set_GPIO_LowPower();//所有GPIO浮空输入
        DeInit_Peripherals();//关外设关中断
        Exti_Config();//按键中断唤醒初始化
        LowPower_SystemClockConfig(); //配置低功耗时钟
        /*
        //进入低功耗模式 
        HAL_SuspendTick();//关闭SysTick
        HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);        
        Norm_SystemClockConfig(); //恢复系统时钟
        HAL_ResumeTick();
        HAL_Delay(200); //等待时钟稳定
        //退出低功耗模式 

        HAL_NVIC_DisableIRQ(EXTI4_15_IRQn);//禁用唤醒中断
        // Peripheral_Init();//初始化外设
        */
        LowPower_Flag = 0;
    }
}



















