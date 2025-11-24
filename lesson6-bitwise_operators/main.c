#include "cmsis/stm32g071xx.h"

#define RCC_IOPENR (int*)(RCC_BASE + 0x34)
#define GPIOA_MODER (int*)(GPIOA_BASE + 0x0)
#define GPIOA_ODR (int*)(GPIOA_BASE + 0x14)

#define GPIOA_PIN10 (1<<10)
#define GPIOA_PIN2 (1<<2)
#define GPIOA_PIN4 (1<<4)
#define GPIOA_PIN6 (1<<6)

int main(void) { 
    *RCC_IOPENR = 0x1;
    *GPIOA_MODER = 0xEBDFFFFF;

    // Debug examples to be seen in memory viewer
    *GPIOA_ODR |= GPIOA_PIN2;
    *GPIOA_ODR |= GPIOA_PIN4;
    *GPIOA_ODR |= GPIOA_PIN6;

    *GPIOA_ODR &= ~(GPIOA_PIN2);
    *GPIOA_ODR &= ~(GPIOA_PIN4);
    *GPIOA_ODR &= ~(GPIOA_PIN6);
    
    // Blink LED
    while(1){
        *GPIOA_ODR |= GPIOA_PIN10;

        volatile int counter = 0;
        while (counter < 1000000) {
            counter++;
        }
        
        *GPIOA_ODR &= ~(GPIOA_PIN10);

        counter = 0;
        while (counter < 1000000) {
            counter++;
        }
    }
    return 0;
}