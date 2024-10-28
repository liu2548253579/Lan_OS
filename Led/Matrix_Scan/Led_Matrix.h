#ifndef __LED_MATRIX_H__
#define __LED_MATRIX_H__

#include "stdint.h"
#include "Led_User.h"


void LED_Matrix_ALL_OFF(void);
void LED_Matrix_ReFresh(void);



/* 3x3 矩阵情况 (3行3列，共6个GPIO)
 *           GPIO4   GPIO5   GPIO6   高电平
 * GPIO1     LED1    LED2    LED3
 * GPIO2     LED4    LED5    LED6
 * GPIO3     LED7    LED8    LED9
 * 低电平
 * 共可控制9个LED
 */

/* 4x4 矩阵情况 (4行4列，共8个GPIO)
 *           GPIO5   GPIO6   GPIO7   GPIO8   高电平
 * GPIO1     LED1    LED2    LED3    LED4
 * GPIO2     LED5    LED6    LED7    LED8
 * GPIO3     LED9    LED10   LED11   LED12
 * GPIO4     LED13   LED14   LED15   LED16
 * 低电平
 * 共可控制16个LED
 */

/* 5x5 矩阵情况 (5行5列，共10个GPIO)
 *           GPIO6   GPIO7   GPIO8   GPIO9   GPIO10  高电平
 * GPIO1     LED1    LED2    LED3    LED4    LED5
 * GPIO2     LED6    LED7    LED8    LED9    LED10
 * GPIO3     LED11   LED12   LED13   LED14   LED15
 * GPIO4     LED16   LED17   LED18   LED19   LED20
 * GPIO5     LED21   LED22   LED23   LED24   LED25
 * 低电平
 * 共可控制25个LED
 */

/* 6x6 矩阵情况 (6行6列，共12个GPIO)
 *           GPIO7   GPIO8   GPIO9   GPIO10  GPIO11  GPIO12  高电平
 * GPIO1     LED1    LED2    LED3    LED4    LED5    LED6
 * GPIO2     LED7    LED8    LED9    LED10   LED11   LED12
 * GPIO3     LED13   LED14   LED15   LED16   LED17   LED18
 * GPIO4     LED19   LED20   LED21   LED22   LED23   LED24
 * GPIO5     LED25   LED26   LED27   LED28   LED29   LED30
 * GPIO6     LED31   LED32   LED33   LED34   LED35   LED36
 * 低电平
 * 共可控制36个LED
 */

/* 7x7 矩阵情况 (7行7列，共14个GPIO)
 *           GPIO8   GPIO9   GPIO10  GPIO11  GPIO12  GPIO13  GPIO14  高电平
 * GPIO1     LED1    LED2    LED3    LED4    LED5    LED6    LED7
 * GPIO2     LED8    LED9    LED10   LED11   LED12   LED13   LED14
 * GPIO3     LED15   LED16   LED17   LED18   LED19   LED20   LED21
 * GPIO4     LED22   LED23   LED24   LED25   LED26   LED27   LED28
 * GPIO5     LED29   LED30   LED31   LED32   LED33   LED34   LED35
 * GPIO6     LED36   LED37   LED38   LED39   LED40   LED41   LED42
 * GPIO7     LED43   LED44   LED45   LED46   LED47   LED48   LED49
 * 低电平
 * 共可控制49个LED
 */

/* 8x8 矩阵情况 (8行8列，共16个GPIO)
 *           GPIO9   GPIO10  GPIO11  GPIO12  GPIO13  GPIO14  GPIO15  GPIO16  高电平
 * GPIO1     LED1    LED2    LED3    LED4    LED5    LED6    LED7    LED8
 * GPIO2     LED9    LED10   LED11   LED12   LED13   LED14   LED15   LED16
 * GPIO3     LED17   LED18   LED19   LED20   LED21   LED22   LED23   LED24
 * GPIO4     LED25   LED26   LED27   LED28   LED29   LED30   LED31   LED32
 * GPIO5     LED33   LED34   LED35   LED36   LED37   LED38   LED39   LED40
 * GPIO6     LED41   LED42   LED43   LED44   LED45   LED46   LED47   LED48
 * GPIO7     LED49   LED50   LED51   LED52   LED53   LED54   LED55   LED56
 * GPIO8     LED57   LED58   LED59   LED60   LED61   LED62   LED63   LED64
 * 低电平
 * 共可控制64个LED
 */

/*
 * 总结：
 * 矩阵大小与所需GPIO数量和可控制的LED数量关系：
 * 矩阵大小    所需GPIO数量    LED数量
 *   3x3          6             9
 *   4x4          8             16
 *   5x5          10            25
 *   6x6          12            36
 *   7x7          14            49
 *   8x8          16            64
 * 
 * 计算公式：
 * LED数量 = n*n，其中n为矩阵的行数(或列数)
 * 所需GPIO数量 = n + n = 2n，其中n为矩阵的行数(或列数)
 * 实现原理参照:https://en.wikipedia.org/wiki/Dot_matrix
 */


#endif /* __LED_MATRIX_H__ */
