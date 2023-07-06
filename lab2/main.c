#include "functions.h"

int main() {
    char *filename = "file.txt";

    task1(filename);

    while (1) {
        printf("\nChoose what do you wanna make:\n"
               "1 - Determine how many times the number specified by the keyboard occurs in the file;\n"
               "2 - Perform a cyclic shift of the numbers in the file by k positions (set from\n"
               "the keyboard) to the right;\n"
               "3 - Quit the program\n");

        int task;
        while (1) {
            int numread = scanf_s("%d", &task);
            char nextchar = getchar();
            if (numread == 1 && (nextchar == '\n' || nextchar == ' '))
                break;
            if (nextchar != '\n' && nextchar != ' ')
                flush();
            printf("Bad input. Try again.\n");
        }

        switch (task) {
            case 1:
                task2(filename);
                break;
            case 2:
                task3(filename);
                break;
            case 3:
                exit(0);
        }
    }
}
