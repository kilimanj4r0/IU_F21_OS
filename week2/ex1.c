#include "stdio.h"
#include <limits.h>
#include <float.h>

int main() {
    int i = INT_MAX;
    float f = FLT_MAX;
    double d = DBL_MAX;
    printf("Integer = %d\n", i);
    printf("Float = %f\n", f);
    printf("Double = %f\n", d);
    printf("Sizeof Integer = %lu\n", sizeof(i));
    printf("Sizeof Float = %lu\n", sizeof(f));
    printf("Sizeof Double = %lu\n", sizeof(d));
    return 0;
}
