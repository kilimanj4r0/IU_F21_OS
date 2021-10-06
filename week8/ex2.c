#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    size_t memsize = 10 * 1024 * 1024; // 10 MB in bytes
    while (1) {
        void* p = malloc(memsize); // Allocating the 10 MB memory
        memset(p, 0, memsize); // Set the memory with 0
        sleep(1); // Pause for 1 second
    }
    return 0;
}