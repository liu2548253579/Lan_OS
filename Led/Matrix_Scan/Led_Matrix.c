#include "Led_Matrix.h"

uint8_t LED_Data[2] = {0x00,0x00}; // LED显示数据

//宏定义快速操作GPIO
#define LED_Pin1(State) digitalWrite(GPIO1,State)
#define LED_Pin2(State) digitalWrite(GPIO2,State)
#define LED_Pin3(State) digitalWrite(GPIO3,State)
#define LED_Pin4(State) digitalWrite(GPIO4,State)
#define LED_Pin5(State) digitalWrite(GPIO5,State)
#define LED_Pin6(State) digitalWrite(GPIO6,State)
#define LED_Pin7(State) digitalWrite(GPIO7,State)
#define LED_Pin8(State) digitalWrite(GPIO8,State)


uint8_t Get_Bit(uint8_t data_led, uint8_t bit_index) {
    if (bit_index >= 8) {
        return 0; // 如果索引超出范围，返回 0
    }
    // 使用位掩码取出指定位并确保返回值为 0 或 1
    return ((data_led >> bit_index) & 0x01) ? 1 : 0;
}


void LED_Init(void)
{
    //初始化GPIO为输出
    PinMode(GPIO1,OUTPUT);
    PinMode(GPIO2,OUTPUT);
    PinMode(GPIO3,OUTPUT);
    PinMode(GPIO4,OUTPUT);
    PinMode(GPIO5,OUTPUT);
    PinMode(GPIO6,OUTPUT);
    PinMode(GPIO7,OUTPUT);
    PinMode(GPIO8,OUTPUT);
}

void LED_ALL_OFF(void)
{
    LED_Pin1(1);LED_Pin2(1);LED_Pin3(1);LED_Pin4(1);
    LED_Pin5(0);LED_Pin6(0);LED_Pin7(0);LED_Pin8(0);
}

void LED_Task(void)
{
    static uint8_t Columns = 0;
    if(++Columns >= 4){Columns = 0;}

    LED_ALL_OFF();//消隐

    switch (Columns)
    {
        case 0:
            LED_Pin1(0);//选择第一行
            if(Get_Bit(LED_Data[0],0)){LED_Pin5(1);}else{LED_Pin5(0);}//显示第一列
            if(Get_Bit(LED_Data[0],1)){LED_Pin6(1);}else{LED_Pin6(0);}//显示第二列
            if(Get_Bit(LED_Data[0],2)){LED_Pin7(1);}else{LED_Pin7(0);}//显示第三列
            if(Get_Bit(LED_Data[0],3)){LED_Pin8(1);}else{LED_Pin8(0);}//显示第四列
            break;

        case 1:
            LED_Pin2(0);//选择第二行
            if(Get_Bit(LED_Data[0],4)){LED_Pin5(1);}else{LED_Pin5(0);}//显示第一列
            if(Get_Bit(LED_Data[0],5)){LED_Pin6(1);}else{LED_Pin6(0);}//显示第二列
            if(Get_Bit(LED_Data[0],6)){LED_Pin7(1);}else{LED_Pin7(0);}//显示第三列
            if(Get_Bit(LED_Data[0],7)){LED_Pin8(1);}else{LED_Pin8(0);}//显示第四列
            break;

        case 2:
            LED_Pin3(0);//选择第三行
            if(Get_Bit(LED_Data[1],0)){LED_Pin5(1);}else{LED_Pin5(0);}//显示第一列
            if(Get_Bit(LED_Data[1],1)){LED_Pin6(1);}else{LED_Pin6(0);}//显示第二列
            if(Get_Bit(LED_Data[1],2)){LED_Pin7(1);}else{LED_Pin7(0);}//显示第三列
            if(Get_Bit(LED_Data[1],3)){LED_Pin8(1);}else{LED_Pin8(0);}//显示第四列
            break;

        case 3:
            LED_Pin4(0);//选择第四行
            if(Get_Bit(LED_Data[1],4)){LED_Pin5(1);}else{LED_Pin5(0);}//显示第一列
            if(Get_Bit(LED_Data[1],5)){LED_Pin6(1);}else{LED_Pin6(0);}//显示第二列
            if(Get_Bit(LED_Data[1],6)){LED_Pin7(1);}else{LED_Pin7(0);}//显示第三列
            if(Get_Bit(LED_Data[1],7)){LED_Pin8(1);}else{LED_Pin8(0);}//显示第四列
            break;

        default:
            LED_ALL_OFF();
            break;
    }
}

