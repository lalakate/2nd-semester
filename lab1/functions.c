#include "tasks.h"

int access_(char *filename) {
    if (fopen(filename, "rb") == NULL) {
        printf("The file not found\n");
        return 0;
    }
    return 1;
}

void flush() {
    while (getchar() != '\n')
        continue;
}

void sort(FILE *f, int size) {
    int buf, flg;
    int num_i, num_j;
    for (int gap = size / 2; gap > 0; gap /= 2)
        do {
            flg = 0;
            for (int i = 0, j = gap; j < size; i++, j++) {
                fseek(f, i * (int) sizeof(int), SEEK_SET);
                fread(&num_i, (int) sizeof(int), 1, f);
                fseek(f, j * (int) sizeof(int), SEEK_SET);
                fread(&num_j, (int) sizeof(int), 1, f);
                if (num_i < num_j) {
                    buf = num_j;
                    num_j = num_i;
                    num_i = buf;
                    fseek(f, i * (int) sizeof(int), SEEK_SET);
                    fwrite(&num_i, (int) sizeof(int), 1, f);
                    fseek(f, j * (int) sizeof(int), SEEK_SET);
                    fwrite(&num_j, (int) sizeof(int), 1, f);
                    flg = 1;
                }
            }
        } while (flg != 0);
}

int size_of_f(char *filename) {
    FILE *f = fopen(filename, "rb");
    int counter = 0, val;

    while (!feof(f)) {
        fread(&val, sizeof(int), 1, f);
        counter++;
    }

    return counter;
}

void outputnumbers(int quantity, FILE *fp) {
    int x;
    rewind(fp);
    for (int i = 0; i < quantity; i++) {
        fread(&x, sizeof(int), 1, fp);
        printf("%d ", x);
    }
    printf("\n");
}

void remove_numbers_less_than(const char *filename, int threshold) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    FILE *temp = tmpfile();
    if (!temp) {
        perror("Failed to create temporary file");
        fclose(file);
        return;
    }

    int value;
    while (fread(&value, sizeof(int), 1, file) == 1) {
        if (value >= threshold) {
            fwrite(&value, sizeof(int), 1, temp);
        }
    }

    fclose(file);

    file = fopen(filename, "wb");
    if (!file) {
        perror("Failed to open file for writing");
        fclose(temp);
        return;
    }

    rewind(temp);
    while (fread(&value, sizeof(int), 1, temp) == 1) {
        fwrite(&value, sizeof(int), 1, file);
    }

    fclose(file);
    fclose(temp);
}
