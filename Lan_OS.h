#ifndef __LAN_OS_H__
#define __LAN_OS_H__

#include "stdint.h"

/* 功能模块开关配置 */
#define ENABLE  1
#define DISABLE 0

/* 模块使能配置 */
#define USE_FILTER    DISABLE    /* 滤波器模块 */
#define USE_KEY       DISABLE    /* 按键模块 */
#define USE_LED       DISABLE    /* LED模块 */
#define USE_TIMER     DISABLE    /* 定时器模块 */

/* 模块头文件包含 */
#if (USE_FILTER == ENABLE)
    #include "Filter_User.h"
#endif

#if (USE_KEY == ENABLE)
    #include "Key_User.h"
#endif

#if (USE_LED == ENABLE)
    #include "Led_User.h"
#endif

#if (USE_TIMER == ENABLE)
    #include "Timer_User.h"
#endif

#define BIT_0 0x01
#define BIT_1 0x02
#define BIT_2 0x04
#define BIT_3 0x08
#define BIT_4 0x10
#define BIT_5 0x20
#define BIT_6 0x40
#define BIT_7 0x80


void Peripheral_Init(void);


#endif /* __LAN_OS_H__ */
