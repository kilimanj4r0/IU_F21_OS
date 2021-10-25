#!/bin/bash

echo "Vladimir" > _ex3.txt
ls -l
chmod a-x _ex3.txt
ls -l
chmod uo=rwx _ex3.txt
ls -l
chmod g=rwx _ex3.txt
ls -l
nano ex3.txt
