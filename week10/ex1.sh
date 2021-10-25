#!/bin/bash

echo "Vladimir" >  _ex1.txt
ln _ex1.txt _ex1_1.txt
ls -i
ln _ex1.txt _ex1_2.txt
ls -i > ex1.txt
cat ex1.txt
