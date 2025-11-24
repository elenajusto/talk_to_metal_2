#define RCC (0x40021000)
#define RCC_IOPENR (int*)(RCC + 0x34)
#define GPIOA (0x50000000)
#define GPIOA_MODER (int*)(GPIOA + 0x0)
#define GPIOA_ODR (int*)(GPIOA + 0x14)

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