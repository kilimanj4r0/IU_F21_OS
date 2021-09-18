#!/bin/bash

# Run "ex2_exec_wo_race_cond.sh"
# Write "0\n" into the file "ex2_data.txt" before execution!

# After running: multiple occurences of some numbers does not appear. 
# Race condition does not happen because the process before working with a file locks the file.
# Therefore, other processes have no access to the file.
# File "ex2_data.txt" is the critical region.

if test ! -f ex2_data.txt # if no data file, create it
then 
  echo 0 > ex2_data.txt
fi

while [ -f ex2_data.txt.lock ] # if there is another process using this file (lock file exists), do nothing (wait)
do
    :
done

touch ex2_data.txt.lock # lock

value=$(tail -1 ex2_data.txt | grep -Eo ^[0-9]+$) # taking the last number
echo $((value + 1)) >> ex2_data.txt # appending the (last number + 1) to the data file

rm -rf ex2_data.txt.lock # unlock