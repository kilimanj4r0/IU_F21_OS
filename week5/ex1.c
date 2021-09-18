#include "stdio.h"
#include <stdint.h>
#include <stdlib.h>
#include <pthread.h>

#define N 128

pthread_t thread_ids[N];

void* threadFunc(int index) {
	printf("Running Thread[%i]", index);
	pthread_exit(NULL);
}


int main() {
	for(int i = 0; i < N; i++) {
		int rtn_val;
		if ( rtn_val = pthread_create(&thread_ids[i], NULL, threadFunc, i) ) {
            printf("\nSomething went wrong while thread creation [%i]\n", rtn_val);
            exit(1);
		} else {
			printf("\nThread[%i] was created successfully [%i]\n", i, rtn_val);
			pthread_join(thread_ids[i], NULL); // Allow us to process threads sequentially
		}
	}
	pthread_exit(NULL);
	return 0;
}
