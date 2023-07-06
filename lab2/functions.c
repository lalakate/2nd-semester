#include "functions.h"

void cyclic_shift(int *arr, int n) {

    int k;

    printf("\nEnter k: ");

    while (scanf_s("%d", &k) < 1 || getchar() != '\n' || k < 1) {
        printf("\nIncorrect input. Please, try again: ");
        rewind(stdin);
    }

    int temp;

    if (k > n)
        k = k % n;

    while (k != 0) {
        temp = arr[n - 1];
        for (int i = n - 1; i > 0; i--)
            arr[i] = arr[i - 1];
        arr[0] = temp;
        k--;
    }
}

void flush() {
    while (getchar() != '\n')
        continue;
}

int access_(char *filename) {
    if (fopen(filename, "rt") == NULL) {
        printf("The file not found\n");
        return 0;
    }
    return 1;
}

int num_of_elements(char *filename) {
    FILE *f = fopen(filename, "rt");

    int counter = 0, val;

    while (!feof(f)) {
        fread(&val, sizeof(int), 1, f);
        counter++;
    }
    return counter - 1;
}