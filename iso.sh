if grub-file --is-x86-multiboot ./myos.bin; then
  echo multiboot confirmed
else
  echo the file is not multiboot
fi

cp ./myos.bin isodir/boot/myos.bin

grub-mkrescue -o myos.iso isodir
