#pragma once

#include "../../rpi/include/rpi.h"

#define BAUDRATE 115200
#define AUX_BASE        (PERIPHERAL_BASE + 0x215000)

#define AUX_ENABLES     (*(volatile unsigned int*)(AUX_BASE + 0x04))
#define AUX_MU_IO_REG   (*(volatile unsigned int*)(AUX_BASE + 0x40))
#define AUX_MU_IER_REG  (*(volatile unsigned int*)(AUX_BASE + 0x44))
#define AUX_MU_IIR_REG  (*(volatile unsigned int*)(AUX_BASE + 0x48))
#define AUX_MU_LCR_REG  (*(volatile unsigned int*)(AUX_BASE + 0x4C))
#define AUX_MU_MCR_REG  (*(volatile unsigned int*)(AUX_BASE + 0x50))
#define AUX_MU_LSR_REG  (*(volatile unsigned int*)(AUX_BASE + 0x54))
#define AUX_MU_CNTL_REG (*(volatile unsigned int*)(AUX_BASE + 0x60))
#define AUX_MU_BAUD_REG (*(volatile unsigned int*)(AUX_BASE + 0x68))

void uart_init();
void uart_send(unsigned int c);
void uart_puts(const char *s);
void uart_put_uint(unsigned int n);
int uart_read_line_blocking(char *buf, int maxlen, unsigned int timeout);
