#include "structure.h"
#include "functions.h"

int main() {
    List *games = NULL;
    int size = 0;
    FILE *fp = fopen("file.log", "a+");
    log_record(Start, games, fp);
    while (1) {
        printf("\nWhat do you wanna do?\n"
               "1. Add game \n"
               "2. Print all games\n"
               "3. Update information about game\n"
               "4. Delete game\n"
               "5. Sort games\n"
               "6. Find game\n"
               "7. Exit program\n");

        char choose;
        while (!scanf("%c", &choose) || choose > '7' || choose < '1' || getchar() != '\n') {
            printf("Wrong input. Try again.\n");
            rewind(stdin);
        }

        if (choose == add) {
            add_game(&games, &size);
            printf("New game has been added!\n");
            log_record(Add, games, fp);
        } else if (choose == print) {
            printf("\n_________________________________\n");
            print_games(games);
            log_record(Print, games, fp);
        } else if (choose == update) {
            update_game(games);
            log_record(Update, games, fp);
        } else if (choose == delete) {
            delete_game(&games, &size);
            log_record(Delete, games, fp);
        } else if (choose == sort) {
            sort_by_parameter(games);
            log_record(Sort, games, fp);
        } else if (choose == find) {
            find_game(games);
            log_record(Find, games, fp);
        } else {
            log_record(Exit, games, fp);
            exit(0);
        }
    }
}
