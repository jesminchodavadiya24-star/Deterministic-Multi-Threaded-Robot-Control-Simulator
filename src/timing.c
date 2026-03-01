#include <stdio.h>
#include "timing.h"

void print_execution_time(struct timespec start, struct timespec end) {
    long seconds = end.tv_sec - start.tv_sec;
    long nanoseconds = end.tv_nsec - start.tv_nsec;
    double elapsed = seconds + nanoseconds * 1e-9;

    printf("Execution Time: %.6f seconds\n", elapsed);
}
