build: main.elf

main.elf: 
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -std=c11 -g -O0 -c main.c -o main.o
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -std=c11 -g -O0 -c startup.c -o startup.o
	arm-none-eabi-gcc -nolibc -nostartfiles -T linker.ld main.o startup.o -o main.elf

flash:
	openocd -f /usr/share/openocd/scripts/interface/stlink.cfg -f /usr/share/openocd/scripts/target/stm32g0x.cfg 

killFlash:
	fuser -k 6666/tcp

clean:
	rm -f main.elf
	rm -f main.o
	rm -f startup.o