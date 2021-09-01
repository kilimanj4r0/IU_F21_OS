#include <stdio.h>

#define ARRAY_SIZE 10

void bubble_sort(int *);

int main(){
	int i, array[ARRAY_SIZE];
	printf("Enter %d integers:\n", ARRAY_SIZE);
	for (i = 0; i < ARRAY_SIZE; i++)
		scanf("%d", &array[i]);

	bubble_sort(array);

	printf("Array after sorting:\n");
	for (i = 0; i < ARRAY_SIZE; i++)
		printf("%d ", array[i]);
	printf("\n");
	return 0;
}

void bubble_sort(int * array) {
	for (int i = 0; i < ARRAY_SIZE - 1; i++) {
		for (int j = 0; j < ARRAY_SIZE - i - 1; j++) {
			if (*(array + j) > *(array + j + 1)) {
				int t = *(array + j);
				*(array + j) = *(array + j + 1);
				*(array + j + 1) = t;
			}
		}
	}
}
