#!/bin/sh

set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/intros.kernel isodir/boot/intros.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "intros" {
    multiboot /boot/intros.kernel
}
EOF
grub-mkrescue -o intros.iso isodir