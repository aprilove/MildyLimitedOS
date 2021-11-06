[org 0x7e00]

jmp EnterProtectedMode

jmp $

%include "./Sector1/print.asm"

EnterProtectedMode:
    ; disable int
    cli
    jmp $

EnableA20:
    in al, 0x92
    or al, 2
    out 0x92 al
    ret

times 2048-($-$$) db 0
