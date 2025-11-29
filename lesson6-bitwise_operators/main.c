#include "cmsis/stm32g071xx.h"

#define RCC_IOPENR (int*)(RCC_BASE + 0x34)

// GPIO A
#define GPIOA_MODER (int*)(GPIOA_BASE + 0x0)
#define GPIOA_ODR (int*)(GPIOA_BASE + 0x14)
#define GPIOA_PIN10 (1<<10)                     // Pin D2 PA10

// GPIO B
#define GPIOB_MODER (int*)(GPIOB_BASE + 0x0)    // 0x50000400 + 0x0
#define GPIOB_ODR (int*)(GPIOB_BASE + 0x14)     // 0x50000400 + 0x14 = 0x50000414
#define GPIOB_PIN3 (1<<3)                       // Pin D3 PB3
#define GPIOB_PIN10 (1<<10)                     // Pin D4 PB10

int main(void) { 
    *RCC_IOPENR = 0x3;                          // Set bit 0 and bit 1 to 1 (GPIOAEN and GPIObEN respectively)
    *GPIOA_MODER = 0xEBDFFFFF;                  // Set bit 21 to 0
    *GPIOB_MODER = 0xFFDFFF7F;                  // Set bit 7 and bit 21 to 0
    
    // Blink LED
    while(1){
        *GPIOA_ODR |= GPIOA_PIN10;
        *GPIOB_ODR |= GPIOB_PIN3;
        *GPIOB_ODR |= GPIOB_PIN10;

        volatile int counter = 0;
        while (counter < 1000000) {
            counter++;
        }
        
        *GPIOA_ODR &= ~(GPIOA_PIN10);
        *GPIOB_ODR &= ~(GPIOB_PIN3);
        *GPIOB_ODR &= ~(GPIOB_PIN10);

        counter = 0;
        while (counter < 1000000) {
            counter++;
        }
    }
    return 0;
}