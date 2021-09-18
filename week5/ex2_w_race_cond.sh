#!/bin/bash

# Run "ex2_exec_w_race_cond.sh"
# Write "0\n" into the file "ex2_data.txt" before execution!

# After running: multiple occurences of some numbers appear. 
# Several processes are run simultaneously => race condition happens.
# File "ex2_data.txt" is the critical region.

if test ! -f ex2_data.txt # if no data file, create it
then 
  echo 0 > ex2_data.txt
fi

for i in 'seq 1 128'; # instead of while true, let program ends
do
    value=$(tail -1 ex2_data.txt | grep -Eo ^[0-9]+$) # taking the last number
	echo $((value + 1)) >> ex2_data.txt # appending the (last number + 1) to the data file
done