#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAX_LIMIT 256

int main() {
    printf("Enter a string to be reversed:\n");
    char s[MAX_LIMIT];
    fgets(s, MAX_LIMIT, stdin);
    for (int i = strlen(s) - 1; i >= 0; i--)
        putchar(s[i]);
    printf("\n");
    return 0;
}

