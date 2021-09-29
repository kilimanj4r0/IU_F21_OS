#include <stdio.h>
#include <stdlib.h> // 1: to use malloc()

int main() {
    char **s;
    char foo[] = "Hello World";
    s = malloc(sizeof(char*)); // 2: s was declared but not initialized, so before initialization we need to allocate memory
    *s = foo; // s initialization
    printf("s is %s\n", s);
    s[0] = foo;
    printf("s[0] is %s\n", s[0]);
    return 0;
}