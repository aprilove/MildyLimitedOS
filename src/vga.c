#include "../include/vga.h"
#include "../include/utils.h"
#include "../include/string.h"

#include "stdarg.h"

static inline uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg) 
{
    return fg | bg << 4;
}
 
static inline uint16_t vga_entry(unsigned char uc, uint8_t color) 
{
    return (uint16_t) uc | (uint16_t) color << 8;
}
 
static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
 
size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;

uint16_t get_terminal_row(void)
{
    return terminal_row;
}

uint16_t get_terminal_col(void)
{
    return terminal_column;
}

void terminal_initialize(void) 
{
    terminal_row = 0;
    terminal_column = 0;
    terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
    terminal_buffer = (uint16_t*) 0xB8000;
    for (size_t y = 0; y < VGA_HEIGHT; y++) {
        for (size_t x = 0; x < VGA_WIDTH; x++) {
            const size_t index = y * VGA_WIDTH + x;
            terminal_buffer[index] = vga_entry(' ', terminal_color);
        }
    }
}
 
void terminal_setcolor(uint8_t color) 
{
    terminal_color = color;
}
 
void terminal_putentryat(char c, uint8_t color, size_t x, size_t y) 
{
    const size_t index = y * VGA_WIDTH + x;
    terminal_buffer[index] = vga_entry(c, color);
}
 
void terminal_putchar(char c) 
{
    terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
    if (++terminal_column == VGA_WIDTH) {
        terminal_column = 0;
        ++terminal_row;
    } else if (c == '\n') {
        ++terminal_row;
        terminal_column = 0;
    }
    if (terminal_row == VGA_HEIGHT) {
        terminal_row = 0;
    }
}
 
void terminal_write(const char* data, size_t size) 
{
    for (size_t i = 0; i < size; i++)
        terminal_putchar(data[i]);
}
 
void terminal_writestring(const char* data) 
{
    terminal_write(data, strlen(data));
}

void terminal_clear()
{
    // note that this will fail for very very weird screens with too many pixels
    for (uint64_t i = 0; i < VGA_WIDTH * VGA_HEIGHT; ++i)
    {
        terminal_buffer[i] = VGA_COLOR_BLACK;
    }
}

void moveCursor(uint16_t row, uint16_t col)
{
    unsigned short pos = (row * VGA_WIDTH) + col;
    outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    outb(FB_DATA_PORT, (unsigned char)(pos & 0xFF));
    outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    outb(FB_DATA_PORT, (unsigned char)((pos >> 8) & 0xFF));
}

int putchar(int ic)
{
    char c = (char)ic;
    terminal_write(&c, sizeof(c));
    return ic;
}

static void print(const char *data, size_t data_length)
{
    size_t i;
    for (i = 0; i < data_length; i++)
        putchar((int)((const unsigned char *)data)[i]);
}

uint8_t scan(void)
{
    unsigned char bk;
    static uint8_t key = 0;
    uint8_t ch = inb(0x60); // keyboard port
    bk = ch & 0x80;
    ch = ch & 0x7f;
    if (bk)
    {
        return key = 0;
    }
    else if (ch != key)
    {
        return key = ch;
    }
    else
    {
        return 0;
    }
}

#undef printf

uint8_t printf(const char *format, ...)
{
    va_list parameters;
    va_start(parameters, format);
    int written = 0;
    size_t amount;
    int rejected_bad_specifier = 0;
    while (*format != '\0')
    {
        if (*format != '%')
        {
        print_c:
            amount = 1;
            while (format[amount] && format[amount] != '%')
                amount++;
            print(format, amount);
            format += amount;
            written += amount;
            continue;
        }
        const char *format_begun_at = format;
        if (*(++format) == '%')
            goto print_c;
        if (rejected_bad_specifier)
        {
        incomprehensible_conversion:
            rejected_bad_specifier = 1;
            format = format_begun_at;
            goto print_c;
        }
        if (*format == 'c')
        {
            format++;
            char c = (char)va_arg(parameters, int /* char promotes to int */);
            print(&c, sizeof(c));
        }
        else if (*format == 'd')
        {
            format++;
            char *s;
            itoa(s, va_arg(parameters, int), 10);
            print(s, strlen(s));
        }
        else if (*format == 'x')
        {
            format++;
            char *s;
            itoa(s, va_arg(parameters, unsigned int), 16);
            print("0x", 2);
            print(s, strlen(s));
        }
        else if (*format == 'p')
        {
            format++;
            char *s;
            const void *ptr = va_arg(parameters, void *);
            uintptr_t uptr = (uintptr_t)ptr;
            itoa(s, uptr, 16);
            print("0x", 2);
            print(s, strlen(s));
        }
        else if (*format == 's')
        {
            format++;
            const char *s = va_arg(parameters, const char *);
            print(s, strlen(s));
        }
        else
        {
            goto incomprehensible_conversion;
        }
    }
    va_end(parameters);
    return written;

}

void printPrompt(void)
{
    printf("\n > ");
    moveCursor(get_terminal_row(), get_terminal_col());
}

