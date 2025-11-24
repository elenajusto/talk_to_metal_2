int main(void) { 
    
    /* GPIO Ports Clock Enable */
    // RCC starts at 0x4002 1000
    // RCC_IOPENR is at 0x4002 1000 + 0x34
    // RCC_IOPENR default value: 0x0000 0000
    int *pointer_rcc_iopenr;
    pointer_rcc_iopenr = (int*)(0x40021000 + 0x34);

    // Set its value to 0x1 to turn bit 0 to 1
    *pointer_rcc_iopenr = 0x1;              

    /* NOTE: The clocks to I/O ports can individually be enabled through the RCC_IOPENR register. - 172/1384 RM0444 Rev 6 */
    /* NOTE: When the clock to a peripheral or I/O port is not active, the read and write accesses to its registers are not effective. - 172/1384 RM0444 Rev 6 */
    
    /* Set Port A Pin 10 to output mode */
    // GPIOA starts at 0x5000 0000
    // GPIOA_MODER is at 0x5000 0000 + 0x00
    // GPIOA_MODER default value:  0xEBFF FFFF 
    int *pointer_moder;
    pointer_moder = (int*)0x50000000;       // expect value 0xEBFF FFFF
    *pointer_moder = 0xEBDFFFFF;

    /* Write HIGH to Port A Pin 10 */
    // GPIOx_ODR address offset 0x14
    // Default value: 0x0000 0000
    // So GPIOA_ODR should be 0x5000 0000 + 0x14
    int *pointer_gpioa_odr;
    pointer_gpioa_odr = (int*)(0x50000000 + 0x14);

    // Set value to 0x400
    *pointer_gpioa_odr = 0x400;
    
    while(1);

    return 0;
}