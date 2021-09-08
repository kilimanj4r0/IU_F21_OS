#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define INPUT_SIZE 128

int main(int argc, char * argv[]) {
        char input[INPUT_SIZE];

	char *newargv[] = { argv[1], "Hello", "World", NULL };
	char *newenviron[] = { NULL };

	execve(argv[1], newargv, newenviron);
	perror("execve");

        while (true) {
                scanf("%s", input);
                if (strcmp(input, "^Z") == 0) { // CTRL+Z to stop the shell
                        return 0;
                }
                system(input);
        }
}
