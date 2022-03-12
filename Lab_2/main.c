#include "bsp.h"
#include "stdint.h"
#include "stdbool.h"
#include "tm4c123gh6pm.h"
uint32_t stack_blinky1[40]; //__attribute__ ((aligned (8)));
uint32_t *sp_blinky1 = &stack_blinky1[40];
void main_blinky1(void);
void main_blinky2(void);
void main_blinky1() {
    for(;;) {
        BSP_ledRedOn();
        BSP_delay(5);
        BSP_ledRedOff();
        BSP_delay(5);
    }
}

uint32_t stack_blinky2[40];//__attribute__ ((aligned (8)));
uint32_t *sp_blinky2 = &stack_blinky2[40];
void main_blinky2() {
    for(;;) {
        BSP_ledBlueOn();
        BSP_delay(10);
        BSP_ledBlueOff();
        BSP_delay(10);
    }
}


int main()
{
			
		BSP_init();
	  *(--sp_blinky1) = (1U << 24);  // xPSR 
    *(--sp_blinky1) = (uint32_t)&main_blinky1; // PC 
    *(--sp_blinky1) = 0x0000000EU; // LR  
    *(--sp_blinky1) = 0x0000000CU; // R12 
    *(--sp_blinky1) = 0x00000003U; // R3  
    *(--sp_blinky1) = 0x00000002U; // R2  
    *(--sp_blinky1) = 0x00000001U; // R1  
    *(--sp_blinky1) = 0x00000000U; // R0  

    *(--sp_blinky2) = (1U << 24);   // xPSR 
    *(--sp_blinky2) = (uint32_t)&main_blinky2; // PC 
    *(--sp_blinky2) = 0x0000000EU; // LR  
    *(--sp_blinky2) = 0x0000000CU; // R12 
    *(--sp_blinky2) = 0x00000003U; // R3  
    *(--sp_blinky2) = 0x00000002U; // R2  
    *(--sp_blinky2) = 0x00000001U; // R1  
    *(--sp_blinky2) = 0x00000000U; // R0  



  while(1){}
  return 0;
}
