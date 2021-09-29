#include <stdio.h>
#include <stdlib.h>

void *mrealloc(int *ptr, int size) {
    if (ptr == NULL) { // Allocation
        return malloc(size);
    } else if (size == 0) { // Free
        free(ptr);
        return NULL;
    } else { // Reallocation
        int *new_arr = malloc(size);
        if (new_arr != NULL) {
            for (int i = 0; i < size; i++) {
                *(new_arr + i) = *(ptr + i);
            }
        }
        free(ptr);
        return new_arr;
    }
}

int main() {
    int init_size = 7;
    int new_size = 17;

    int *arr = malloc(sizeof(int) * init_size);
    printf("Initial array: ");
    for (int i = 0; i < init_size; ++i){
        *(arr + i) = i;
        printf("%d ", *(arr + i));
    }
    // Changing the size of the array to the new one
    arr = mrealloc(arr, sizeof(int) * new_size);
    printf("\nArray after mrealloc: ");
    for (int i = 0; i < new_size; ++i) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
    return 0;
}