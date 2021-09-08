#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INPUT_SIZE 128

int main() {
	char input[INPUT_SIZE];
	while (true) {
        	scanf("%s", input);
        	if (strcmp(input, "^Z") == 0) { // CTRL+Z to stop the shell
        		return 0;
        	}
        	system(input);
    	}
}
