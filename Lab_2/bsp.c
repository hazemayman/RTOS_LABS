/* Board Support Package */
#include "bsp.h"
#include "stdint.h"
#include "stdbool.h"
#include "tm4c123gh6pm.h"
#include "system_TM4C123.h"

void SysTick_Handler(void){
  ++l_tickCtr;
}
void BSP_init(void) {
		SYSCTL_RCGCGPIO_R  = (1<<5);
		while((SYSCTL_PRGPIO_R & 1<<5)>>5 == 0){} 
		GPIO_PORTF_DIR_R = LED_RED  | LED_GREEN  | LED_BLUE;
		GPIO_PORTF_DEN_R = LED_RED  | LED_GREEN  | LED_BLUE;
    //waiting until clock is initiallized

		SystemCoreClockUpdate();  	
		NVIC_ST_RELOAD_R = (SystemCoreClock / BSP_TICKS_PER_SEC);
		NVIC_ST_CTRL_R = 7;
			__asm("CPSIE  I");
}
uint32_t BSP_tickCtr(void) {
    uint32_t tickCtr;

    __asm("CPSID  I");
    tickCtr = l_tickCtr;
    __asm("CPSIE  I");

    return tickCtr;
}

void BSP_ledRedOn(void) {
    GPIO_PORTF_DATA_BITS_R[LED_RED] = LED_RED;
}

void BSP_ledRedOff(void) {
   GPIO_PORTF_DATA_BITS_R[LED_RED] = 0;
}

void BSP_ledBlueOn(void) {
   GPIO_PORTF_DATA_BITS_R[LED_BLUE] = LED_BLUE;
}

void BSP_ledBlueOff(void) {
     GPIO_PORTF_DATA_BITS_R[LED_BLUE] = 0;
}

void BSP_ledGreenOn(void) {
      GPIO_PORTF_DATA_BITS_R[LED_GREEN] = LED_GREEN;
}

void BSP_ledGreenOff(void) {
    GPIO_PORTF_DATA_BITS_R[LED_GREEN] = 0;
}
void BSP_delay(uint32_t ticks) {
    uint32_t start = BSP_tickCtr();
    while ((BSP_tickCtr() - start) < ticks) {
    }
}
