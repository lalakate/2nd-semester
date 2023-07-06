#include "tasks.h"

int main() {
    char *filename = "file.bin";

    task1(filename);
    while (1) {
        printf("Choose what do you wanna make:\n"
               "1 - Count the number of elements whose value is less than the specified one;\n"
               "2 - Delete all elements less than the specified one;\n"
               "3 - Sort all file elements in descending order.\n"
               "4 - Quit the program\n");

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
                task4(filename);
                break;
            case 4:
                exit(0);
        }
    }
}
