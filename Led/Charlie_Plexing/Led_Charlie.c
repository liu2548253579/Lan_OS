#include "Led_Charlie.h"

uint8_t LED_Data[2] = {0x00,0x00}; // LED显示数据


void LED_Set_Output(uint16_t GPIO_Pin, uint8_t State)
{
    PinMode(GPIO_Pin,OUTPUT);
    digitalWrite(GPIO_Pin,State);
}

void LED_Set_Analog(uint16_t GPIO_Pin)
{
    PinMode(GPIO_Pin,ANALOG);
}

uint8_t Get_Bit(uint8_t data_led, uint8_t bit_index) {
    if (bit_index >= 8) {
        return 0; // 如果索引超出范围，返回 0
    }
    // 使用位掩码取出指定位并确保返回值为 0 或 1
    return ((data_led >> bit_index) & 0x01) ? 1 : 0;
}


void LED_ALL_OFF(void)
{
    LED_Set_Analog(GPIO1);
    LED_Set_Analog(GPIO2);
    LED_Set_Analog(GPIO3);
    LED_Set_Analog(GPIO4);
}

void LED_Task(void)
{
    static uint8_t i,trig;

    if(trig)
    {
        trig=0;
        LED_ALL_OFF();
    }
    else
    {   
        trig=1;
        i+=1;if(i>=12){i=0;}
        if(i==0)
        {
            if(Get_Bit(LED_Data[0],0))//LED1
            {
                LED_Set_Output(GPIO1,0);
                LED_Set_Output(GPIO2,1);
            }else{LED_ALL_OFF();}
        }
        if (i==1)
        {
            if(Get_Bit(LED_Data[0],1))
            {
                LED_Set_Output(GPIO1,0);
                LED_Set_Output(GPIO3,1);
            }else{LED_ALL_OFF();}
        }
        if (i==2)
        {
            if(Get_Bit(LED_Data[0],2))
            {
                LED_Set_Output(GPIO1,0);
                LED_Set_Output(GPIO4,1);
            }else{LED_ALL_OFF();}
        }
        if (i==3)
        {
            if(Get_Bit(LED_Data[0],3))
            {
                LED_Set_Output(GPIO2,0);
                LED_Set_Output(GPIO1,1);
            }else{LED_ALL_OFF();}
        }
        if (i==4)
        {
            if(Get_Bit(LED_Data[0],4))
            {
                LED_Set_Output(GPIO2,0);
                LED_Set_Output(GPIO3,1);
            }else{LED_ALL_OFF();}
        }
        if (i==5)
        {
            if(Get_Bit(LED_Data[0],5))
            {
                LED_Set_Output(GPIO2,0);
                LED_Set_Output(GPIO4,1);
            }else{LED_ALL_OFF();}
        }
        if (i==6)
        {
            if(Get_Bit(LED_Data[0],6))
            {
                LED_Set_Output(GPIO3,0);
                LED_Set_Output(GPIO1,1);
            }else{LED_ALL_OFF();}
        }
        if (i==7)
        {
            if(Get_Bit(LED_Data[0],7))
            {
                LED_Set_Output(GPIO3,0);
                LED_Set_Output(GPIO2,1);
            }else{LED_ALL_OFF();}
        }


        if (i==8)
        {
            if(Get_Bit(LED_Data[1],0))
            {
                LED_Set_Output(GPIO3,0);
                LED_Set_Output(GPIO4,1);
            }else{LED_ALL_OFF();}
        }
        if (i==9)
        {
            if(Get_Bit(LED_Data[1],1))
            {
                LED_Set_Output(GPIO4,0);
                LED_Set_Output(GPIO1,1);
            }else{LED_ALL_OFF();}
        }
        if (i==10)
        {
            if(Get_Bit(LED_Data[1],2))
            {
                LED_Set_Output(GPIO4,0);
                LED_Set_Output(GPIO2,1);
            }else{LED_ALL_OFF();}
        }
        if (i==11)
        {
            if(Get_Bit(LED_Data[1],3))
            {
                LED_Set_Output(GPIO4,0);
                LED_Set_Output(GPIO3,1);
            }else{LED_ALL_OFF();}
        }
    }

}