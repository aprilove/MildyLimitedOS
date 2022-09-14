#!/bin/bash

if [ "$1" == "kernel" ];
then
    qemu-system-i386 -kernel myos.bin
else
    qemu-system-i386 -cdrom myos.iso
fi

