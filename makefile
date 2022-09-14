# TODO: actually create a makefile
# CC=i686-elf-gcc 
# ASM=i686-elf-as

# CCFLAGS=-std=gnu99 -ffreestanding -O2 -Wall -Wextra
# LDFLAGS=-ffreestanding -O2 -nostdlib

CC=gcc
ASM=as

CCFLAGS=-m32 -nostdlib -fno-builtin -fno-exceptions -ffreestanding -fno-leading-underscore -Wall -Wextra
ASFLAGS=--32
LDFLAGS=-m elf_i386

IDIR=include
ODIR=object
SDIR=src

SRCC=$(wildcard $(SDIR)/*.c)
OBJC=$(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRCC))
SRCA=$(wildcard $(SDIR)/*.s)
OBJA=$(patsubst $(SDIR)/%.s, $(ODIR)/%.o, $(SRCA))

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(CCFLAGS) $^ -I$(IDIR) -c -o $@

$(ODIR)/%.o: $(SDIR)/%.s
	$(AS) $(ASFLAGS) -o $@ $<

# link:
# 	$(CC) -T linker.ld -o ../object/myos.bin $(LDFLAGS) $(OBJ)

myos.bin: $(SDIR)/linker.ld $(OBJC) $(OBJA)
	ld $(LDFLAGS) -T $< -o $@ $(ODIR)/*.o
	./iso.sh

clean:
	rm ./object/*.o
	rm ./isodir/boot/*.bin

all: myos.bin
