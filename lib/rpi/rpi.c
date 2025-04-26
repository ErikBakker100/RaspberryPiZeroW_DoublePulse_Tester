void delay(unsigned int count) {
    asm volatile(
        "cmp %[cnt], #0\n"            // compare with 0
        "beq 2f\n"                    // if zero, skip the loop
        "1: subs %[cnt], %[cnt], #1\n" // decrement
        "bne 1b\n"                    // loop if not zero
        "2:\n"
        : [cnt] "+r" (count)
        :
        : "cc"
    );
}
