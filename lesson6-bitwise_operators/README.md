# Bitwise Operators in C
Before proceeding further, as per the video lecture, I imported a headerfile consisting of the definitions for the STM32G071's peripheral registers so that I don't have to keep defining them manually.

This is located in `cmsis/stm32g071xx.h`.

Since this register file is from CMSIS, it has further dependecies on some of the CMSIS core header file (such as those that define the Cortex M0's core/lower level functions). These are the rest of the files in the `cmsis` folders.

Because I am lazy and have previously had a hard time understanding the CMSIS documentation, I downloaded each file that the compiler complained was missing from here https://github.com/STMicroelectronics/STM32CubeG0/tree/master/Drivers/CMSIS/Core/Include, until it stopped compiling and hence I believe I have reached minimal CMSIS use.

We are now blinking Port A and Port B connected LED's on a breadboard! Using direct reference to memory addresse (provided by CMSIS header files), basic bit shift operations and basic cpu cycle waste delay.

Furthermore since we have the memory addresses of the registers (Clock, Mode, Output Data) we are able to verify the bits we are manipulating using the memory debugger and see how it physically corresponds to a real life component!

![blink](images/image.png)