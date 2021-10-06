gcc ex2.c -o ex2
./ex2 &
vmstat 1

# Findings
# When the OS is run out of virtual memory it starts using the swap memory which correspond to disk space.
# We can see this in altering si and so fields.