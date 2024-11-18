#include "Led_Charlie.h"

#error "请在此处修改LED的驱动引脚"
LED_Element  LED1={
    // .LED_Pin=GPIO_PIN_1,
    // .LED_Port=GPIOA
};
LED_Element  LED2={
    // .LED_Pin=GPIO_PIN_2,
    // .LED_Port=GPIOA
};
LED_Element  LED3={
    // .LED_Pin=GPIO_PIN_3,
    // .LED_Port=GPIOA
};
LED_Element  LED4={
    // .LED_Pin=GPIO_PIN_4,
    // .LED_Port=GPIOA
};

void LED_Charlie_ALL_OFF(void)
{
    LED_Set_Input(&LED1);
    LED_Set_Input(&LED2);
    LED_Set_Input(&LED3);
    LED_Set_Input(&LED4);
}


/*
 * GPIO查理复用(Charlieplexing)对应关系表:
 *           GPIO1   GPIO2   GPIO3   GPIO4   高电平
 * GPIO1     禁用    LED1    LED2    LED3
 * GPIO2     LED4    禁用    LED5    LED6
 * GPIO3     LED7    LED8    禁用    LED9
 * GPIO4     LED10   LED11   LED12   禁用
 * 低电平
 */

void LED_Charlie_ReFresh(void)
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
                LED_Set_Output(&LED1,0);
                LED_Set_Output(&LED2,1);
            }else{LED_ALL_OFF();}
        }
        if (i==1)
        {
            if(Get_Bit(LED_Data[0],1))
            {
                LED_Set_Output(&LED1,0);
                LED_Set_Output(&LED3,1);
            }else{LED_ALL_OFF();}
        }
        if (i==2)
        {
            if(Get_Bit(LED_Data[0],2))
            {
                LED_Set_Output(&LED1,0);
                LED_Set_Output(&LED4,1);
            }else{LED_ALL_OFF();}
        }
        if (i==3)
        {
            if(Get_Bit(LED_Data[0],3))
            {
                LED_Set_Output(&LED2,0);
                LED_Set_Output(&LED1,1);
            }else{LED_ALL_OFF();}
        }
        if (i==4)
        {
            if(Get_Bit(LED_Data[0],4))
            {
                LED_Set_Output(&LED2,0);
                LED_Set_Output(&LED3,1);
            }else{LED_ALL_OFF();}
        }
        if (i==5)
        {
            if(Get_Bit(LED_Data[0],5))
            {
                LED_Set_Output(&LED2,0);
                LED_Set_Output(&LED4,1);
            }else{LED_ALL_OFF();}
        }
        if (i==6)
        {
            if(Get_Bit(LED_Data[0],6))
            {
                LED_Set_Output(&LED3,0);
                LED_Set_Output(&LED1,1);
            }else{LED_ALL_OFF();}
        }
        if (i==7)
        {
            if(Get_Bit(LED_Data[0],7))
            {
                LED_Set_Output(&LED3,0);
                LED_Set_Output(&LED2,1);
            }else{LED_ALL_OFF();}
        }


        if (i==8)
        {
            if(Get_Bit(LED_Data[1],0))
            {
                LED_Set_Output(&LED3,0);
                LED_Set_Output(&LED4,1);
            }else{LED_ALL_OFF();}
        }
        if (i==9)
        {
            if(Get_Bit(LED_Data[1],1))
            {
                LED_Set_Output(&LED4,0);
                LED_Set_Output(&LED1,1);
            }else{LED_ALL_OFF();}
        }
        if (i==10)
        {
            if(Get_Bit(LED_Data[1],2))
            {
                LED_Set_Output(&LED4,0);
                LED_Set_Output(&LED2,1);
            }else{LED_ALL_OFF();}
        }
        if (i==11)
        {
            if(Get_Bit(LED_Data[1],3))
            {
                LED_Set_Output(&LED4,0);
                LED_Set_Output(&LED3,1);
            }else{LED_ALL_OFF();}
        }
    }
}

