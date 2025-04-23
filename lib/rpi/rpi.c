void delay(int count) {
    for (int i = 0; i < count; i++) {
        asm volatile("nop");
    }
}

// Simpele delay in microseconden (ruwe loop op 700MHz core clock)
void delay_us(unsigned int us) {
    delay(us * 7);
}