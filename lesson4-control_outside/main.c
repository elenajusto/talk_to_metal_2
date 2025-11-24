int main(void) { 
    
    // GPIO port mode register (GPIOx_MODER)
    /* 
    MODEy[1:0]: Port x configuration I/O pin y (y = 15 to 0) 
    These bits are written by software to configure the I/O mode. 
    00: Input mode 
    01: General purpose output mode 
    10: Alternate function mode 
    11: Analog mode (reset state)
    */

    // Set Port A Pin 10 to output mode

    /*
    Port A starts at 0x5000 0000
    GPIOx_MODER has offset 0x00 from the start of port
    Pin 10 which is MODE10[1:0] is at Bit 20 and Bit 21
    We want Bit 20 and Bit 21 to be 01 (0x1)
    Bit 20 and Bit 21 default value is 11 (0xB)
    */
    int *pointer_moder;
    pointer_moder = (int*)0x50000000;             // directly assign this pointer to a the MODER register for GPIOA
    *pointer_moder = 0xEBDFFFFF;                  // assign it 0x1
    

    // While(1)
        // GPIO port output data register (GPIOx_ODR) - HIGH
        /*
        OD[15:0]: Port output data I/O pin y (y = 15 to 0) 
        These bits can be read and written by software.  
        Note: For atomic bit set/reset, the OD bits 
        can be individually set and/or reset by writing 
        to the GPIOx_BSRR register (x = A to D, F).
        */

        // Set Port A Pin 10 to 1

        // Delay

        // GPIO port output data register (GPIOx_ODR) - LOW

        // Set Port A Pin 10 to 0

    return 0;
}