#!/bin/bash

mkdir week01
echo "Vladimir" > week01/file.txt
link week01/file.txt _ex2.txt
find week01/file.txt -inum $(stat -c '%i' _ex2.txt) > ex2.txt
find week01/file.txt -inum $(stat -c '%i' _ex2.txt) -exec rm {} \; >> ex2.txt
cat ex2.txt
