#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    size_t memsize = 10 * 1024 * 1024; // 10 MB in bytes
    struct rusage usage;
    int RUSAGE_SELF;
    
    for (int i = 0; i < 5; i++) {
        void* p = malloc(memsize); // Allocating the 10 MB memory
        memset(p, 0, memsize); // Set the memory with 0
        getrusage(RUSAGE_SELF, &usage);
        // Printing some values of memory usage struct
        printf("System CPU time used: %ld %ld\n", usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
        printf("Max resident set size: %ld\n", usage.ru_maxrss);
        printf("Integral shared memory size: %ld\n", usage.ru_ixrss);
        printf("Integral unshared data size: %ld\n", usage.ru_idrss);
        printf("Integral unshared stack size: %ld\n", usage.ru_isrss);
        printf("---//---\n");
        sleep(1); // Pause for 1 second
    }
    
    return 0;
}