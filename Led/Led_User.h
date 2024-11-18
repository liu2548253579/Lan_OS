#ifndef __LED_USER_H__
#define __LED_USER_H__

#include "Led_Charlie.h"
#include "Led_Matrix.h"
#include "stdint.h"


typedef struct 
{
    uint16_t LED_Pin;
    GPIO_TypeDef * LED_Port;
}LED_Element;


extern uint8_t LED_Data[2];

uint8_t Get_Bit(uint8_t data_led, uint8_t bit_index);
void LED_Set_Input(LED_Element *led);
void LED_Set_Output(LED_Element *led, uint8_t state);
void LED_Task(void);




#endif /* __LED_USER_H__ */
