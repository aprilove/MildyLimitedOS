[org 0x7e00]

jmp $

%include "./Sector1/print.asm"

ExtendSpaceSuccess:
    db 'Success we are in extended space',0

times 2048-($-$$) db 0
