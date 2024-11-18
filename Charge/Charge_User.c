#include "Charge_User.h"


#error "请在此处配置USB接入GPIO和充电状态GPIO"

#define VIN_STATE 1
#define CHARGE_STATE 1
/*EG:
#define VIN_STATE HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5)
#define CHARGE_STATE HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15)
*/

/**
 * @brief  充电管理初始化函数
 */
void Charge_Init(void)
{
    //USB接入GPIO初始化{0:未接入 1:已接入}
    //充电状态GPIO初始化(需要上拉){0:充电中 1:充满}

    /*EG:
    GPIO_InitTypeDef GPIO_InitStruct;
    __HAL_RCC_GPIOB_CLK_ENABLE();
    GPIO_InitStruct.Pin = GPIO_PIN_5;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    __HAL_RCC_GPIOA_CLK_ENABLE();
    GPIO_InitStruct.Pin = GPIO_PIN_15;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
    */

}


/**
 * @brief  充电管理任务函数
 */
void Charge_Task(Charge_Element *Charge)
{
    Charge->Vin=VIN_STATE;

    if(Charge->Vin==1)
    {
        Charge->State=CHARGE_STATE;
    }
    else
    {   
        Charge->State=0;
    }
}









