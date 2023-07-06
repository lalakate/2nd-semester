#include "functions.h"

void task3(char *filename) {

    FILE *f = fopen(filename, "rt");

    int val, n = num_of_elements(filename);

    printf("%d", n);

    if (f != NULL) {
        int *arr = (int *) calloc(n, sizeof(int));

        for (int i = 0; i < n; i++) {
            fread(&val, sizeof(int), 1, f);
            arr[i] = val;
        }

        cyclic_shift(arr, n);

        fclose(f);

        f = fopen(filename, "w");

        for (int i = 0; i < n; i++) {
            val = arr[i];
            fwrite(&val, sizeof(int), 1, f);
        }

        printf("\n");
        freopen(filename, "r", f);
        for (int i = 0; i < n; i++) {
            fread(&val, sizeof(int), 1, f);
            printf("%d ", val);
        }
        printf("\n");

        fclose(f);

        free(arr);
    } else
        printf("\nFile is not found\n");
}

