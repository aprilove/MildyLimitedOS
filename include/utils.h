#ifndef UTILS_H
#define UTILS_H
#include "types.h"

#define FB_COMMAND_PORT 0x3d4
#define FB_DATA_PORT 0x3d5
#define FB_HIGH_BYTE_COMMAND 0x0e
#define FB_LOW_BYTE_COMMAND 0x0f

#define KBRD_INTRFC 0x64

#define KBRD_BIT_KDATA 0
#define KBRD_BIT_UDATA 1

#define KBRD_IO 0x60
#define KBRD_RESET 0xFE


void seed(uint32_t s);

uint32_t rand(void);

void memset(void *dst, uint8_t v, size_t n);

// https://wiki.osdev.org/Inline_Assembly/Examples
static inline void outb(uint16_t port, uint8_t val)
{
    asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
    /* There's an outb %al, $imm8  encoding, for compile-time constant port numbers that fit in 8b.  (N constraint).
     * Wider immediate constants would be truncated at assemble-time (e.g. "i" constraint).
     * The  outb  %al, %dx  encoding is the only option for all other cases.
     * %1 expands to %dx because  port  is a uint16_t.  %w1 could be used if we had the port number a wider C type */
}

static inline uint8_t inb(uint16_t port)
{
    uint8_t ret;
    asm volatile ( "inb %1, %0"
                   : "=a"(ret)
                   : "Nd"(port) );
    return ret;
}

#endif
