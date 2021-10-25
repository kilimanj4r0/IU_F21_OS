#!/bin/bash

mkdir tmp
cd tmp/
touch file1
touch file2
ls
cd ..
ln tmp/file1 link1
ls -i tmp/file1
gcc ex4.c -o ex4
./ex4 > ex4.txt
