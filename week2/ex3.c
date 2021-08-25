#include <stdio.h>

void printTriangle(int);
void printSpaces(int);

int main(int argc, char *argv[]) {
    int n;
    sscanf(argv[1], "%d", &n);
    printTriangle(n);
    printf("\n");
    return 0;
}

void printTriangle(int n) {
    int max_spaces = 2*n;

    for (int i = 1; i <= n; i++) {
        printSpaces(max_spaces - 2*i);
        for (int j = 0; j < 2*i - 1; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printSpaces(int n) {
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
}
