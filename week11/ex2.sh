#!/bin/bash

cd lofsdisk/
echo "Vladimr" > file1
echo "Makharev" > file2
ls
cat file1
cat file2
gcc ex2.c -o ex2.out
man chroot
man cp
ldd ex2.out
mkdir lib64
mkdir lib
mkdir lib64/x86_64-linux-gnu/
cp /lib/x86_64-linux-gnu/libc.so.6 lib/x86_64-linux-gnu/libc.so.6
cp /lib64/ld-linux-x86-64.so.2 lib64/ld-linux-x86-64.so.2
chroot . ./ex2.out > ex2.txt
./ex2.out >> ex2.txt
cat ex2.txt
