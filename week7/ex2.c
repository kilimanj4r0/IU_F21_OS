#include "stdio.h"
#include <stdlib.h>

int main () {
    int N;
    printf("Enter the size of the array: ");
    scanf("%d", &N);
    int *arr = malloc(N * sizeof(int));
    printf("Array of %d elements has been allocated.\nArray: ", N);
    for (int i = 0; i < N; i++) {
        *(arr + i) = i;
        printf("%d ", *(arr + i));
    }
    if ( arr != NULL ) {
        free(arr);
        printf("\nMemory allocated for the array has been freed.\n");
    }
    return 0;
}