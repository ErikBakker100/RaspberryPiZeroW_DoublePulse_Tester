#pragma once

#include "../../rpi/include/rpi.h"

#define GPIO_BASE       (PERIPHERAL_BASE + 0x200000)

#define GPFSEL0         ((volatile unsigned int*)(GPIO_BASE + 0x00))
#define GPFSEL1         ((volatile unsigned int*)(GPIO_BASE + 0x04))
#define GPFSEL2         ((volatile unsigned int*)(GPIO_BASE + 0x08))
#define GPFSEL3         ((volatile unsigned int*)(GPIO_BASE + 0x0C))
#define GPFSEL4         ((volatile unsigned int*)(GPIO_BASE + 0x10))
#define GPFSEL5         ((volatile unsigned int*)(GPIO_BASE + 0x14))
#define GPSET0          ((volatile unsigned int*)(GPIO_BASE + 0x1C))
#define GPSET1          ((volatile unsigned int*)(GPIO_BASE + 0x20))
#define GPCLR0          ((volatile unsigned int*)(GPIO_BASE + 0x28))
#define GPCLR1          ((volatile unsigned int*)(GPIO_BASE + 0x2C))
#define GPLEV0          ((volatile unsigned int*)(GPIO_BASE + 0x34))
#define GPLEV1          ((volatile unsigned int*)(GPIO_BASE + 0x38))
#define GPPUD           ((volatile unsigned int*)(GPIO_BASE + 0x94))
#define GPPUDCLK0       ((volatile unsigned int*)(GPIO_BASE + 0x98))

#define GPIO_IN	    0
#define GPIO_OUT	1
#define LOW    0
#define HIGH   1

void gpio_init(int pin, int mode);
void gpio_write(int pin, int stat);
