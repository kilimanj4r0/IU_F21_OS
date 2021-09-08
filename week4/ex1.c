#include <stdio.h>
#include <stdlib.h>

int main() {
	int n = rand() % 10;
	int pid = fork();
	switch(pid) {
		case -1: // Fork error
			break;
		case 0: // Child process
			printf("Hello from child [%d - %d]\n", pid, n);
			break;
		default: // Parent process
			printf("Hello from parent [%d - %d]\n", pid, n);
			break;
	}
	return 0;
}
/*
OUTPUT:
Hello from parent [349 - 3]
Hello from child [0 - 3]
Hello from parent [351 - 3]
Hello from child [0 - 3]
Hello from parent [353 - 3]
Hello from child [0 - 3]
Hello from parent [355 - 3]
Hello from child [0 - 3]
Hello from parent [357 - 3]
Hello from child [0 - 3]
Hello from parent [359 - 3]
Hello from child [0 - 3]
Hello from parent [361 - 3]
Hello from child [0 - 3]
Hello from parent [363 - 3]
Hello from child [0 - 3]
Hello from parent [365 - 3]
Hello from child [0 - 3]
Hello from parent [367 - 3]
Hello from child [0 - 3]
Hello from parent [369 - 3]
Hello from child [0 - 3]

Explanation:
So, the PID of parent is inreasing because processes are executed one by one.
PID of the child process is zero just because fork() returns it for child's process.
*/
