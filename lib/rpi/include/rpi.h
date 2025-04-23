#pragma once

#define PERIPHERAL_BASE 0x20000000
//#define PERIPHERAL_BASE 0x3F000000
#define CORE_FREQ 250000000
#define BAUDRATE 115200

// Function to delay for a given number of cycles
void delay(int);
void delay_us(unsigned int us);
