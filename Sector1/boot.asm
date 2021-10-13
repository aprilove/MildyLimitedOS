[org 0x7c00]

mov [BOOT_DISK], dl

mov bp, 0x7c00
mov sp, bp

mov bx, TestString
call PrintString

call ReadDisk

mov ah, 0x0e
mov al, [PROGRAM_SPACE]
int 0x10

jmp $

%include "Sector1/print.asm"
%include "Sector1/disk.asm"

times 510-($-$$) db 0
db 0x55, 0xaa