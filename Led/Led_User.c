#include "Led_User.h"

uint8_t LED_Data[2] = {0x00,0x00}; // LED显示数据

void LED_Pin_Clock_Enable(void)
{
    #error "请在此处配置LED驱动引脚时钟使能"
    __HAL_RCC_GPIOA_CLK_ENABLE();
    // __HAL_RCC_GPIOB_CLK_ENABLE();
    // __HAL_RCC_GPIOC_CLK_ENABLE();
    // __HAL_RCC_GPIOD_CLK_ENABLE();
    // __HAL_RCC_GPIOE_CLK_ENABLE();
    // __HAL_RCC_GPIOF_CLK_ENABLE();
}


void LED_Set_Input(LED_Element *led)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    LED_Pin_Clock_Enable();
    GPIO_InitStruct.Pin = led->LED_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(led->LED_Port, &GPIO_InitStruct);
    HAL_GPIO_WritePin(led->LED_Port, led->LED_Pin, GPIO_PIN_RESET);
}


void LED_Set_Output(LED_Element *led, uint8_t state)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    LED_Pin_Clock_Enable();
    GPIO_InitStruct.Pin = led->LED_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;//GPIO_SPEED_FREQ_VERY_HIGH
    HAL_GPIO_Init(led->LED_Port, &GPIO_InitStruct);
    HAL_GPIO_WritePin(led->LED_Port, led->LED_Pin, state);
}

uint8_t Get_Bit(uint8_t data_led, uint8_t bit_index) 
{
    if (bit_index >= 8) {return 0;}// 如果索引超出范围，返回 0
    return ((data_led >> bit_index) & 0x01) ? 1 : 0;// 使用位掩码取出指定位并确保返回值为 0 或 1
}

void LED_Task(void)
{
    #error "请在此处修改LED_Data参数以配置灯光效果"
    //EG: LED_Data[0]|=BIT0|BIT1;

}


