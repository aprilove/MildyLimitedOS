#include "../include/string.h"
#include "../include/kb.h"
#include "../include/types.h"
#include "../include/vga.h"
#define BUFFER_SIZE 1024

char buffer[BUFFER_SIZE];

void init_kb(void)
{
    char c, *s;
    uint8_t ch;
    strcpy(&buffer[strlen(buffer)], "");
    printPrompt();
    while (1)
    {
        while (ch = scan())
        {
            if (ch == KEY_ENTER)
            {
                // strcpy(buffer, tolower(buffer));
                if (strlen(buffer) > 0)
                {
                    if (strcmp(buffer, "hello") == 0)
                    {
                        printf("hello");
                    }
                    printPrompt();
                    memset(buffer, 0, BUFFER_SIZE);
                    strcpy(&buffer[strlen(buffer)], "");
                    break;
                }
            }
            else if (ch == KEY_BACKSPACE)
            {
                // add bkpsc support and idt, irq, and isrs
            }
            else
            {
                c = map[ch];
                *s;
                s = ctos(s, c);
                printf("%s", s);
                strcpy(&buffer[strlen(buffer)], s);
                if (ch == 0x2A || ch == 0x36)
                {
                    printf("shift");
                }
                moveCursor(get_terminal_row(), get_terminal_col());
            }
        }
    }
}
