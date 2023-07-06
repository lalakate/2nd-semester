#include "structure.h"
#include "functions.h"

void add_game(Paintball *paintball, int size) {
    paintball[size - 1].id = time(NULL);

    printf("\nEnter name of the game: ");
    fgets(paintball[size - 1].name, 255, stdin);
    rewind(stdin);

    printf("\nEnter type of the game: ");
    fgets(paintball[size - 1].type, 255, stdin);
    rewind(stdin);

    printf("\nEnter quantity of games: ");
    while (!scanf("%d", &paintball[size - 1].quantity) || paintball[size - 1].quantity < 0 || getchar() != '\n') {
        printf("Wrong input. Try again.\n");
        rewind(stdin);
    }

    printf("\nEnter date of last check: \n");

    printf("    day: ");
    while (!scanf("%d", &paintball[size - 1].day) || paintball[size - 1].day < 0 || paintball[size - 1].day > 31 ||
           getchar() != '\n') {
        printf("Wrong input. Try again.\n");
        rewind(stdin);
    }

    printf("    month: ");
    while (!scanf("%d", &paintball[size - 1].month) || paintball[size - 1].month < 0 ||
           paintball[size - 1].month > 12 || getchar() != '\n') {
        printf("Wrong input. Try again.\n");
        rewind(stdin);
    }

    printf("    year: ");
    while (!scanf("%d", &paintball[size - 1].year) || paintball[size - 1].year < 0 || getchar() != '\n') {
        printf("Wrong input. Try again.\n");
        rewind(stdin);
    }
}

void print_games(Paintball *paintball, int i) {
//    printf("|%d|%13s|%13s|%6d     |      %d.%d.%d      | \n", paintball[i].id, paintball[i].name, paintball[i].type,
//           paintball[i].quantity, paintball[i].day, paintball[i].month, paintball[i].year);
//    printf(" ________________________________________________________________________\n");

    printf("1. id: %d\n"
           "2. name: %s\n"
           "3. type: %s\n"
           "4. quantity: %d\n"
           "5. date of last check: %d.%d.%d\n"
           "_________________________________\n", paintball[i].id, paintball[i].name, paintball[i].type,
           paintball[i].quantity, paintball[i].day, paintball[i].month, paintball[i].year);
}

void update_game(Paintball *paintball, int size) {
    unsigned int id;
    printf("\nEnter id of the game you wanna edit: ");

    while (!scanf("%d", &id) || id < 0 || getchar() != '\n') {
        printf("Wrong input. Try again.\n");
        rewind(stdin);
    }

    if (size == 0) printf("\nThere is no one game with id.%d\n", id);

    for (int i = 0; i < size; i++) {
        if (id == paintball[i].id) {
            add_game(paintball, i + 1);
            printf("\nAll info about this game has been updated!\n");
            break;
        } else printf("\nThere is no one game with id.%d\n", id);
    }
}

void delete_game(Paintball *paintball, int *size) {
    unsigned int id;
    int delete_num = -1;
    printf("\nEnter id of the game you wanna delete: ");
    while (!scanf("%d", &id) || getchar() != '\n') {
        printf("Wrong input. Try again.\n");
        rewind(stdin);
    }

    for (int i = 0; i < (*size); i++) if (id == paintball[i].id) delete_num = i;

    if (delete_num == -1) printf("\nThere is no one game with id.%d\n", id);
    else {
        for (int i = delete_num; i < (*size) - 1; i++)
            paintball[i] = paintball[i + 1];

        (*size)--;
        realloc(paintball, (*size) * sizeof(Paintball));
        printf("\nThe game has been deleted successfully!\n");
        fflush(stdin);
    }
}

void sort_by_parameter(Paintball *paintball, int size) {
    if (size < 2) printf("\nToo few games. Please try again\n");
    else {
        printf("\nEnter number of the parameter by which you wanna sort games:\n"
               "1. id\n"
               "2. name\n"
               "3. type\n"
               "4. quantity\n"
               "5. date of the last check\n");
        char choose;
        while (!scanf("%c", &choose) || choose < '1' || choose > '5' || getchar() != '\n') {
            printf("Wrong input. Try again.\n");
            rewind(stdin);
        }
        insertion_sort(paintball, size, choose);

        printf("\nSorting was successful!\n");
    }
}
