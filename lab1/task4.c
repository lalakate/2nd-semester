#include "tasks.h"

void task4(char *filename) {
    FILE *f = fopen(filename, "rb+");
    sort(f, size_of_f(filename));
    outputnumbers(size_of_f(filename), f);
}

