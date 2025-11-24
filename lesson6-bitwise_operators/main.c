#include "cmsis/stm32g071xx.h"

#define RCC_IOPENR (int*)(RCC_BASE + 0x34)
#define GPIOA_MODER (int*)(GPIOA_BASE + 0x0)
#define GPIOA_ODR (int*)(GPIOA_BASE + 0x14)

int main(void) { 
    *RCC_IOPENR = 0x1;
    *GPIOA_MODER = 0xEBDFFFFF;

    while(1){
        *GPIOA_ODR = 0x400;

        volatile int counter = 0;
        while (counter < 1000000) {
            counter++;
        }
        
        *GPIOA_ODR = 0x0;

        counter = 0;
        while (counter < 1000000) {
            counter++;
        }
    }
    return 0;
}