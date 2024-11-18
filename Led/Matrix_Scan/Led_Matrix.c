#include "Led_Matrix.h"

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
LED_Element  LED5={
    // .LED_Pin=GPIO_PIN_5,
    // .LED_Port=GPIOB
};
LED_Element  LED6={
    // .LED_Pin=GPIO_PIN_6,
    // .LED_Port=GPIOB
};
LED_Element  LED7={
    // .LED_Pin=GPIO_PIN_7,
    // .LED_Port=GPIOB
};
LED_Element  LED8={
    // .LED_Pin=GPIO_PIN_8,
    // .LED_Port=GPIOB
};



void LED_Matrix_ALL_OFF(void)
{
    LED_Set_Input(&LED1);
    LED_Set_Input(&LED2);
    LED_Set_Input(&LED3);
    LED_Set_Input(&LED4);
    LED_Set_Input(&LED5);
    LED_Set_Input(&LED6);
    LED_Set_Input(&LED7);
    LED_Set_Input(&LED8);
}

/*
 * GPIO矩阵对应关系表:
 * 
 *           GPIO5   GPIO6   GPIO7   GPIO8   高电平
 * GPIO1     LED1    LED2    LED3    LED4
 * GPIO2     LED5    LED6    LED7    LED8
 * GPIO3     LED9    LED10   LED11   LED12
 * GPIO4     LED13   LED14   LED15   LED16
 * 低电平
 *
 */

void LED_Matrix_ReFresh(void)
{
    static uint8_t Columns = 0;
    if(++Columns >= 4){Columns = 0;}

    LED_Matrix_ALL_OFF();//消隐

    switch (Columns)
    {
        case 0:
            LED_Set_Output(&LED1,0);//选择第一行
            if(Get_Bit(LED_Data[0],0)){LED_Set_Output(&LED5,1);}else{LED_Set_Output(&LED5,0);}//显示第一列
            if(Get_Bit(LED_Data[0],1)){LED_Set_Output(&LED6,1);}else{LED_Set_Output(&LED6,0);}//显示第二列
            if(Get_Bit(LED_Data[0],2)){LED_Set_Output(&LED7,1);}else{LED_Set_Output(&LED7,0);}//显示第三列
            if(Get_Bit(LED_Data[0],3)){LED_Set_Output(&LED8,1);}else{LED_Set_Output(&LED8,0);}//显示第四列
            break;

        case 1:
            LED_Set_Output(&LED2,0);//选择第二行
            if(Get_Bit(LED_Data[0],4)){LED_Set_Output(&LED5,1);}else{LED_Set_Output(&LED5,0);}//显示第一列
            if(Get_Bit(LED_Data[0],5)){LED_Set_Output(&LED6,1);}else{LED_Set_Output(&LED6,0);}//显示第二列
            if(Get_Bit(LED_Data[0],6)){LED_Set_Output(&LED7,1);}else{LED_Set_Output(&LED7,0);}//显示第三列
            if(Get_Bit(LED_Data[0],7)){LED_Set_Output(&LED8,1);}else{LED_Set_Output(&LED8,0);}//显示第四列
            break;

        case 2:
            LED_Set_Output(&LED3,0);//选择第三行
            if(Get_Bit(LED_Data[1],0)){LED_Set_Output(&LED5,1);}else{LED_Set_Output(&LED5,0);}//显示第一列
            if(Get_Bit(LED_Data[1],1)){LED_Set_Output(&LED6,1);}else{LED_Set_Output(&LED6,0);}//显示第二列
            if(Get_Bit(LED_Data[1],2)){LED_Set_Output(&LED7,1);}else{LED_Set_Output(&LED7,0);}//显示第三列
            if(Get_Bit(LED_Data[1],3)){LED_Set_Output(&LED8,1);}else{LED_Set_Output(&LED8,0);}//显示第四列
            break;

        case 3:
            LED_Set_Output(&LED4,0);//选择第四行
            if(Get_Bit(LED_Data[1],4)){LED_Set_Output(&LED5,1);}else{LED_Set_Output(&LED5,0);}//显示第一列
            if(Get_Bit(LED_Data[1],5)){LED_Set_Output(&LED6,1);}else{LED_Set_Output(&LED6,0);}//显示第二列
            if(Get_Bit(LED_Data[1],6)){LED_Set_Output(&LED7,1);}else{LED_Set_Output(&LED7,0);}//显示第三列
            if(Get_Bit(LED_Data[1],7)){LED_Set_Output(&LED8,1);}else{LED_Set_Output(&LED8,0);}//显示第四列
            break;

        default:
            LED_Matrix_ALL_OFF();
            break;
    }
}

