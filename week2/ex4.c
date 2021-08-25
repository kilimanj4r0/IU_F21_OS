#include <stdio.h>

void swap(int*, int*);

int main(int argc, char *argv[]) {
    int n1, n2;
    sscanf(argv[1], "%d", &n1);
    sscanf(argv[2], "%d", &n2);
    printf("Numbers before swap:%d %d\n", n1, n2);
    swap(&n1, &n2);
    printf("Numbers after swap:%d %d\n", n1, n2);
    return 0;
}

void swap(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

