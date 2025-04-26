#pragma once

// Peripheral base address for Raspberry Pi Zero (ARM I/O base)
#define PERIPHERAL_BASE 0x20000000
//#define PERIPHERAL_BASE 0x3F000000
#define CORE_FREQ 250000000 // 700MHz for Raspberry Pi Zero

// Function to delay for a given number of cycles
void delay(unsigned int);
