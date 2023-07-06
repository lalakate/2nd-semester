#include "tasks.h"

void task3(char *filename) {
    FILE *f = fopen(filename, "rb+");
    int i;
    printf("Enter the number: ");

    while (1) {
        int numread = scanf_s("%d", &i);
        char nextchar = getchar();
        if (numread == 1 && (nextchar == '\n' || nextchar == ' '))
            break;
        if (nextchar != '\n' && nextchar != ' ')
            flush();
        printf("Bad input. Try again.\n");
    }


    remove_numbers_less_than(filename, i);

    outputnumbers(size_of_f(filename), f);

    fclose(f);
}