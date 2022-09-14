#include "../include/vga.h"
#include "../include/kb.h"

int main(void) 
{
    terminal_initialize();

    printf("Hello!");
    init_kb();
    return 0;
}

