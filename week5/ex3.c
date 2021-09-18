#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 8192
#define COUNT_PRINT_STEP 64

int buffer_size;

void* producer(void*);
void* consumer(void*);

int main() {
  buffer_size = 0;

  pthread_t producer_thread;
  pthread_t consumer_thread;
  pthread_create(&producer_thread, NULL, &producer, NULL);
  pthread_create(&consumer_thread, NULL, &consumer, NULL);

  pthread_join(producer_thread, NULL);

  pthread_exit(NULL);
  exit(0);
}

void* producer(void* arg) { // producer's thread func
  int count = 0;

  while(1) {
    while (buffer_size == MAX_BUFFER_SIZE); // block the funciton execution waiting for the buffer being full

    if (count % COUNT_PRINT_STEP == 0) { // every COUNT_PRINT_STEP imaginary items print the size of the buffer and items
      printf("[Producer] buffer size: %d\titems: %d\n", buffer_size, count);
    }

    if (count < MAX_BUFFER_SIZE) { // producer creates a new imaginary items filling the buffer
      buffer_size++;
      count++;
    }
  }
}


void* consumer(void* arg) { // consumer's thread func
  int count = 0;

  while(1) {
    while (buffer_size == 0); // block funciton execution waiting for the buffer being empty

    if (count % COUNT_PRINT_STEP == 0) { // every COUNT_PRINT_STEP imaginary items print the size of the buffer and items
      printf("[Consumer] buffer size: %d\titems: %d\n", buffer_size, count);
    }

    if (count < MAX_BUFFER_SIZE) { // consumer consumes the imaginary items emptying the buffer
      buffer_size--;
      count++;
    }
  }
}