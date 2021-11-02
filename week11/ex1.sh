#!/bin/bash

fallocate -l 50M lofs.img
ls
losetup -f lofs.img
mkfs.ext4 $(losetup -a | grep 'lofs.img' | awk '{print $1}' | cut -d ':' -f 1)
mkdir lofsdisk
mount $(losetup -a | grep 'lofs.img' | awk '{print $1}' | cut -d ':' -f 1) ./lofsdisk
df -h
chmod 777 lofsdisk/
