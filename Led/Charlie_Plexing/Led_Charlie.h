#ifndef __LED_CHARLIE_H__
#define __LED_CHARLIE_H__

#include "stdint.h"
#include "Led_User.h"

void LED_Charlie_ALL_OFF(void);
void LED_Charlie_ReFresh(void);

/* GPIO = 3 的情况
 *         GPIO1   GPIO2   GPIO3   高电平
 * GPIO1   禁用    LED1    LED2
 * GPIO2   LED3    禁用    LED4
 * GPIO3   LED5    LED6    禁用
 * 低电平
 * 共可控制6个LED
 */

/* GPIO = 4 的情况
 *         GPIO1   GPIO2   GPIO3   GPIO4   高电平
 * GPIO1   禁用    LED1    LED2    LED3
 * GPIO2   LED4    禁用    LED5    LED6
 * GPIO3   LED7    LED8    禁用    LED9
 * GPIO4   LED10   LED11   LED12   禁用
 * 低电平
 * 共可控制12个LED
 */

/* GPIO = 5 的情况
 *         GPIO1   GPIO2   GPIO3   GPIO4   GPIO5   高电平
 * GPIO1   禁用    LED1    LED2    LED3    LED4
 * GPIO2   LED5    禁用    LED6    LED7    LED8
 * GPIO3   LED9    LED10   禁用    LED11   LED12
 * GPIO4   LED13   LED14   LED15   禁用    LED16
 * GPIO5   LED17   LED18   LED19   LED20   禁用
 * 低电平
 * 共可控制20个LED
 */

/* GPIO = 6 的情况
 *         GPIO1   GPIO2   GPIO3   GPIO4   GPIO5   GPIO6   高电平
 * GPIO1   禁用    LED1    LED2    LED3    LED4    LED5
 * GPIO2   LED6    禁用    LED7    LED8    LED9    LED10
 * GPIO3   LED11   LED12   禁用    LED13   LED14   LED15
 * GPIO4   LED16   LED17   LED18   禁用    LED19   LED20
 * GPIO5   LED21   LED22   LED23   LED24   禁用    LED25
 * GPIO6   LED26   LED27   LED28   LED29   LED30   禁用
 * 低电平
 * 共可控制30个LED
 */

/* GPIO = 7 的情况
 *         GPIO1   GPIO2   GPIO3   GPIO4   GPIO5   GPIO6   GPIO7   高电平
 * GPIO1   禁用    LED1    LED2    LED3    LED4    LED5    LED6
 * GPIO2   LED7    禁用    LED8    LED9    LED10   LED11   LED12
 * GPIO3   LED13   LED14   禁用    LED15   LED16   LED17   LED18
 * GPIO4   LED19   LED20   LED21   禁用    LED22   LED23   LED24
 * GPIO5   LED25   LED26   LED27   LED28   禁用    LED29   LED30
 * GPIO6   LED31   LED32   LED33   LED34   LED35   禁用    LED36
 * GPIO7   LED37   LED38   LED39   LED40   LED41   LED42   禁用
 * 低电平
 * 共可控制42个LED
 */

/* GPIO = 8 的情况
 *         GPIO1   GPIO2   GPIO3   GPIO4   GPIO5   GPIO6   GPIO7   GPIO8   高电平
 * GPIO1   禁用    LED1    LED2    LED3    LED4    LED5    LED6    LED7
 * GPIO2   LED8    禁用    LED9    LED10   LED11   LED12   LED13   LED14
 * GPIO3   LED15   LED16   禁用    LED17   LED18   LED19   LED20   LED21
 * GPIO4   LED22   LED23   LED24   禁用    LED25   LED26   LED27   LED28
 * GPIO5   LED29   LED30   LED31   LED32   禁用    LED33   LED34   LED35
 * GPIO6   LED36   LED37   LED38   LED39   LED40   禁用    LED41   LED42
 * GPIO7   LED43   LED44   LED45   LED46   LED47   LED48   禁用    LED49
 * GPIO8   LED50   LED51   LED52   LED53   LED54   LED55   LED56   禁用
 * 低电平
 * 共可控制56个LED
 */

/*
 * 总结：
 * GPIO数量与可控制的LED数量关系：
 * GPIO数量    LED数量
 *   3          6
 *   4          12
 *   5          20
 *   6          30
 *   7          42
 *   8          56
 * 
 * 计算公式：LED数量 = n*(n-1)，其中n为GPIO数量
 * 实现原理参照:https://en.wikipedia.org/wiki/Charlieplexing
 */

#endif /* __LED_CHARLIE_H__ */
