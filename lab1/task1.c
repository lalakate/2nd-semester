#include "tasks.h"

void task1(char *filename) {

    FILE *f = fopen(filename, "wb");
    printf("Enter the amount of numbers: ");
    float fa;
    int i, n, *arr, a, r;
    while (1) {
        while (scanf("%f", &fa) != 1 || fa != (int) fa) {
            printf("Invalid input. Please, try again.\nEnter the amount of numbers: ");
            rewind(stdin);
        }
        char c = getchar();
        if (c != '\n' && c != '\t' && c != ' ') {
            printf("Incorrect input. Please, try again. \nEnter the amount of numbers: ");
            rewind(stdin);
        } else
            break;
    }
    n = fa;
    printf("1 - random numbers\n2 - custom numbers\n");
    while (1) {
        while (scanf("%f", &fa) != 1 || fa != (int) fa || (fa != 1 && fa != 2)) {
            printf("Invalid input. Please, try again.\n1 - random numbers\n2 - custom numbers\n");
            rewind(stdin);
        }
        char c = getchar();
        if (c != '\n' && c != '\t' && c != ' ') {
            printf("Incorrect input. Please, try again.\n1 - random numbers\n2 - custom numbers\n");
            rewind(stdin);
        } else
            break;
    }
    r = fa;
    if (r == 1) {
        for (i = 0; i < n; i++) {
            if (access_(filename)) {
                a = rand() % 100;
                fwrite(&a, sizeof(int), 1, f);
            } else
                return;
        }
    } else {
        printf("Enter the numbers: ");
        for (i = 0; i < n; i++) {
            while (1) {
                while (scanf("%f", &fa) != 1 || fa != (int) fa || fa <= 0) {
                    printf("Invalid input. Please, try again.\nEnter the numbers: \n");
                    rewind(stdin);
                }
                char c = getchar();
                if (c != '\n' && c != '\t' && c != ' ') {
                    printf("Incorrect input. Please, try again. \nEnter the numbers: \n");
                    rewind(stdin);
                } else
                    break;
            }
            a = fa;
            if (access_(filename))
                fwrite(&a, sizeof(int), 1, f);
            else
                return;
        }
    }
    if ((f = freopen(filename, "rb", f)) == NULL) {
        printf("File not found\n");
        return;
    }
    printf("File Contents: ");
    for (i = 0; i < n; i++) {
        fread(&a, sizeof(int), 1, f);
        printf("%i ", a);
    }
    printf("\n");
    fclose(f);
}