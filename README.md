# MildyLimitedOS
A very limited OS that is currently in development

Compiler options
nasm Sector1/boot.asm -f bin -o boot.bin
nasm Sectors/extended.asm -f bin -o extended.bin
cat boot.bin extended.bin > bootloader.bin