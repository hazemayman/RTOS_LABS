#include "bsp.h"
#include "stdint.h"
#include "stdbool.h"
#include "tm4c123gh6pm.h"
//uint32_t stack_blinky1[40] __attribute__ ((aligned (8)));
//uint32_t *sp_blinky1 = &stack_blinky1[40];
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

//uint32_t stack_blinky2[40] __attribute__ ((aligned (8)));
//uint32_t *sp_blinky2 = &stack_blinky2[40];
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
	volatile int run = 0;
	if(run){
		  main_blinky1();
	}
	else{
		  main_blinky2();
	}
  

  while(1){}
  return 0;
}
