PrintString:
    mov ah, 0x0e
    .Loop:
    cmp [bx], byte 0
    je .Exit
        mov al, [bx] ; https://stackoverflow.com/questions/48608423/what-do-square-brackets-mean-in-x86-assembly/48608575
        int 0x10
        inc bx
        jmp .Loop
    int 0x10
    .Exit:
    ret

TestString:
    db 'TestString',0