#include "tasks.h"

void task2(char *filename) {
    FILE *f = fopen(filename, "rb");
    if ((f = freopen(filename, "rb", f)) == NULL) {
        printf("File not found\n");
        exit(0);
    }
    int counter = 0, num, val;
    printf("Enter the number: ");
    while (1) {
        int numread = scanf_s("%d", &num);
        char nextchar = getchar();
        if (numread == 1 && (nextchar == '\n' || nextchar == ' '))
            break;
        if (nextchar != '\n' && nextchar != ' ')
            flush();
        printf("Bad input. Try again.\n");
    }

    while (!feof(f)) {
        fread(&val, sizeof(int), 1, f);
        if (val < num)
            counter++;
    }

    printf("The amount of numbers that less than %d = %d\n", num, counter);

    fclose(f);
}