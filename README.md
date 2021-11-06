# MildyLimitedOS
A very limited OS that is currently in development

Compiler options <br />
nasm Sector1/boot.asm -f bin -o boot.bin <br />
nasm Sectors/kernel.asm -f bin -o kernel.bin <br />
cat boot.bin kernel.bin > bootloader.bin