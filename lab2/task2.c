#include "functions.h"

void task2(char* filename) {

    FILE* f = fopen(filename, "rt");

    if (f != NULL) {
        int counter = 0, num, val;

        printf("\nEnter number: ");

        while (scanf_s("%d", &num) < 1 || getchar() != '\n' || num > 100000) {
            printf("\nIncorrect input. Please, try again.\n");
            rewind(stdin);
        }

        for(int i = 0; i < num_of_elements(filename); i++){
            fread(&val, sizeof(int), 1, f);
            if(val == num)
                counter++;
        }

        printf("\nThe amount of numbers that are equally %d = %d\n", num, counter);

        fclose(f);

        }
    else
        printf("\nFile is not found\n");

}
