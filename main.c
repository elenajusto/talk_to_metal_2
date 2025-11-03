int counter = 0;

int main(void) { 
    int *pointer_integer;               // pointer_integer is a pointer (variable to a memory address) to an integer variable
    pointer_integer = &counter;         // pointer_integer is now tracking the memory address for the counter variable

    while (*pointer_integer < 21) {     // de-referencing allows us to susbtitue the value stored at the pointer/address 
        (*pointer_integer)++;
    }
    return 0;
}