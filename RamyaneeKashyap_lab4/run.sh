#!/usr/bin/bash

nasm -f elf sum.asm
gcc -m32 -c add.c
gcc -m32 -o a.out add.o sum.o
./a.out