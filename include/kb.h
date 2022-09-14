#define KBSTATP 0x64
#define KBS_DIB 0x01
#define KBDATAP 0x60
#define KEY_BACKSPACE 0x0E
#define KEY_ENTER 0x1c
#define NA 0
#define KEY_SHIFT (1 << 0)
#define KEY_CTL (1 << 1)
#define KEY_ALT (1 << 2)
#define KEY_CAPSLOCK (1 << 3)
#define KEY_NUMLOCK (1 << 4)
#define KEY_SCROLLLOCK (1 << 5)
#define KEY_E0ESC (1 << 6)
#define KEY_HOME 0xE0
#define KEY_END 0xE1
#define KEY_UP 0xE2
#define KEY_DOWN 0xE3
#define KEY_LEFT 0xE4
#define KEY_RIGHT 0xE5
#define KEY_PGUP 0xE6
#define KEY_PGDN 0xE7
#define KEY_INS 0xE8
#define KEY_DEL 0xE9
#define KEY_F1 0x80
#define KEY_F2 0x81
#define KEY_F3 0x82
#define KEY_F4 0x83
#define KEY_F5 0x84
#define KEY_F6 0x85
#define KEY_F7 0x86
#define KEY_F8 0x87
#define KEY_F9 0x88
#define KEY_F10 0x89
#define KEY_F11 0x90
#define KEY_F12 0x91

static char map[128] =
{
    NA, KEY_E0ESC, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    '-', '=', KEY_BACKSPACE, NA, 'q', 'w', 'e', 'r', 't', 'y', 'u',
    'i', 'o', 'p', '[', ']', KEY_ENTER, 0, 'a', 's', 'd', 'f', 'g', 'h', 'j',
    'k', 'l', ';', '\'', '`', 0, '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm',
    ',', '.', '/', 0, 0, 0, ' ', 0, KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5,
    KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F10, 0, 0, KEY_HOME, KEY_UP,
    KEY_PGUP, '-', KEY_LEFT, '5', KEY_RIGHT, '+', KEY_END, KEY_DOWN,
    KEY_PGDN, KEY_INS, KEY_DEL, 0, 0, 0, KEY_F11, KEY_F12
};

void init_kb(void);

