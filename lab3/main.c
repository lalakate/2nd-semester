#include "structure.h"
#include "functions.h"

int main() {
    int size = 0;
    Paintball *paintball = malloc(size * sizeof(Paintball));

    //load_previously_entered_data(&paintball, &size);

    while (1) {
        printf("\nWhat do you wanna do?\n"
               "1. Add game \n"
               "2. Print all games\n"
               "3. Update information about game\n"
               "4. Delete game\n"
               "5. Sort games\n"
               "6. Check stock availability\n"
               "7. Quit\n");

        char choose;
        while (!scanf("%c", &choose) || choose > '7' || choose < '1' || getchar() != '\n') {
            printf("Wrong input. Try again.\n");
            rewind(stdin);
        }

        if (choose == ADD) {
            realloc(paintball, (++size) * sizeof(Paintball));
            add_game(paintball, size);
            printf("New game has been added!\n");
        } else if (choose == PRINT) {
            if (size == 0) printf("List of games is clear \n");
//            printf(" ________________________________________________________________________\n");
//            printf("|    ID    |  Game name  |  Game type  | Quantity |  Date of last check  |\n");
//            printf(" ________________________________________________________________________\n");
            printf("\n_________________________________\n");
            for (int i = 0; i < size; i++) print_games(paintball, i);
        } else if (choose == UPDATE) update_game(paintball, size);
        else if (choose == DELETE) delete_game(paintball, &size);
        else if (choose == SORT) sort_by_parameter(paintball, size);
        else if (choose == STOCK) task1(paintball, size);
        else exit(0);
        /*{
            save(paintball, size);
            if(size != 0) free(paintball);
            exit(0);
        }*/
    }
}
