#ifndef __BSP_H__
#define __BSP_H__
#include "stdint.h"
#include "stdbool.h"
/* Board Support Package for the EK-TM4C123GXL board */
#define BSP_TICKS_PER_SEC 10U
/* system clock setting [Hz] */
#define SYS_CLOCK_HZ 16000000U

/* on-board LEDs */
#define LED_RED   (1<<1)
#define LED_BLUE  (1<<2)
#define LED_GREEN (1<<3)
#define BSP_TICKS_PER_SEC 10

void BSP_init (void);
void SystickHandler (void);
void BSP_delay(uint32_t ticks);
void BSP_ledRedOn(void);
void BSP_ledRedOff(void);
void BSP_ledBlueOn(void);
void BSP_ledBlueOff(void);
void BSP_ledGreenOn(void);
void BSP_ledGreenOff(void);

static uint32_t volatile l_tickCtr;
#endif // __BSP_H__