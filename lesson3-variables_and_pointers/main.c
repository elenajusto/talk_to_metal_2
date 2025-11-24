int main(void) { 
    int *pointer_integer_1;               // a pointer (variable to a memory address) to an integer variable
    *pointer_integer_1 = 0xDEADBEEF;      // assign the memory located at this pointer to the value 0xDEADBEEF

    int *pointer_integer_2;
    pointer_integer_2 = (int*)0x20000040;   // directly assign this pointer to a specific RAM memory adddress
    *pointer_integer_2 = 0xCAFED00D;        // assign this piece of memory the value 0xCAFED00D

    int *pointer_integer_3;
    pointer_integer_3 = (int*)pointer_integer_2+1;    // assign this pointer near pinter 2
    *pointer_integer_3 = 0xCAFEBABE;                // assign it 0xCAFEBABE

    return 0;
}