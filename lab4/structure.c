#include "structure.h"
#include "functions.h"

void add_game(List **games, int *size) {
    int quantity, day, month, year, rate, weight, cost;
    char s[255];
    int n;
    List *temp = (List *) malloc(sizeof(List));
    (*size)++;
    temp->game.id = time(NULL);
    printf("Enter name of the game: ");
    rewind(stdin);
    gets(s);
    strcpy(temp->game.name, s);

    printf("Enter the quantity of games: ");
    while (!scanf("%d", &quantity) || quantity < 0 || getchar() != '\n') {
        printf("Wrong input. Try again.\n");
        rewind(stdin);
    }
    temp->game.quantity = quantity;

    printf("\nEnter date of last check: \n");

    printf("    day: ");
    while (!scanf("%d", &day) || day < 0 || day > 31 ||
           getchar() != '\n') {
        printf("Wrong input. Try again.\n");
        rewind(stdin);
    }

    temp->game.date_of_last_check.day = day;

    printf("    month: ");
    while (!scanf("%d", &month) || month < 0 ||
           month > 12 || getchar() != '\n') {
        printf("Wrong input. Try again.\n");
        rewind(stdin);
    }

    temp->game.date_of_last_check.month = month;

    printf("    year: ");
    while (!scanf("%d", &year) || year < 0 || getchar() != '\n') {
        printf("Wrong input. Try again.\n");
        rewind(stdin);
    }

    temp->game.date_of_last_check.year = year;

    printf("\nChoose the type of information about weapon:\n"
           "1 - rate of fire, weight\n"
           "2 - appointment, cost\n");
    while (!scanf("%d", &n) || n < 0 ||
           n > 2 || getchar() != '\n') {
        printf("Wrong input. Try again.\n");
        rewind(stdin);
    }
    if (n == 1) {
        temp->game.type = 1;
        printf("\nEnter the rate of fire: ");
        while (!scanf("%d", &rate) || rate < 0 || getchar() != '\n') {
            printf("Wrong input. Try again.\n");
            rewind(stdin);
        }
        temp->game.Types.Type1.rate_of_fire = rate;

        printf("\nEnter weight: ");
        while (!scanf("%d", &weight) || weight < 0 || getchar() != '\n') {
            printf("Wrong input. Try again.\n");
            rewind(stdin);
        }
        temp->game.Types.Type1.weight = weight;
    } else {
        temp->game.type = 2;
        printf("\nEnter appointment: ");
        rewind(stdin);
        gets(s);
        strcpy(temp->game.Types.Type2.appointment, s);

        printf("\nEnter cost: ");
        while (!scanf("%d", &cost) || cost < 0 || getchar() != '\n') {
            printf("Wrong input. Try again.\n");
            rewind(stdin);
        }
        temp->game.Types.Type2.cost = cost;
    }
    if ((*games) == NULL) {
        temp->next = (*games);
        (*games) = temp;
    } else {
        List *last = get_last(*games);
        temp->next = NULL;
        last->next = temp;
    }
}


void print_games(List *games) {
    if (games == NULL) {
        printf("\nThere are no games\n");
        return;
    }
    while (games != NULL) {
        printf("id: %d\n"
               "name: %s\n"
               "quantity: %d\n"
               "date of last check: %d.%d.%d\n", games->game.id, games->game.name,
               games->game.quantity, games->game.date_of_last_check.day, games->game.date_of_last_check.month,
               games->game.date_of_last_check.year);
        if (games->game.type == 1) {
            printf("rate of fire: %d\n"
                   "weight: %d\n", games->game.Types.Type1.rate_of_fire, games->game.Types.Type1.weight);
        } else if (games->game.type == 2) {
            printf("appointment: %s\n"
                   "cost: %d\n", games->game.Types.Type2.appointment, games->game.Types.Type2.cost);
        }
        printf("_________________________________\n");
        games = games->next;
    }
}


void update_game(List *games) {
    int n, n2, day, month, year, quantity, rate, weight, cost;
    char s[255];
    List *game;
    printf("\nEnter number of the game you wanna edit: ");
    scanf("%i", &n);
    n--;
    for (int i = 0; i < n; i++) {
        games = games->next;
    }
    game = games;

    if (game->game.type == 1) {
        printf("\nSelect the parameter to change\n"
               "1 - name of the game\n"
               "2 - quantity\n"
               "3 - date of last check\n"
               "4 - rate of fire\n"
               "5 - weight\n");
        while (!scanf("%d", &n2) || n2 < 0 || getchar() != '\n') {
            printf("Wrong input. Try again.\n");
            rewind(stdin);
        }
        switch (n2) {
            case 1:
                printf("\nEnter name of game: ");
                rewind(stdin);
                gets(s);
                strcpy(game->game.name, s);
                break;

            case 2:
                printf("\nEnter quantity: ");
                while (!scanf("%d", &quantity) || quantity < 0 || getchar() != '\n') {
                    printf("Wrong input. Try again.\n");
                    rewind(stdin);
                }
                game->game.quantity = quantity;
                break;

            case 3:
                printf("\nEnter date of last check: \n");

                printf("    day: ");
                while (!scanf("%d", &day) || day < 0 || day > 31 ||
                       getchar() != '\n') {
                    printf("Wrong input. Try again.\n");
                    rewind(stdin);
                }

                game->game.date_of_last_check.day = day;

                printf("    month: ");
                while (!scanf("%d", &month) || month < 0 ||
                       month > 12 || getchar() != '\n') {
                    printf("Wrong input. Try again.\n");
                    rewind(stdin);
                }

                game->game.date_of_last_check.month = month;

                printf("    year: ");
                while (!scanf("%d", &year) || year < 0 || getchar() != '\n') {
                    printf("Wrong input. Try again.\n");
                    rewind(stdin);
                }

                game->game.date_of_last_check.year = year;
                break;

            case 4:
                printf("\nEnter the rate of fire: ");
                while (!scanf("%d", &rate) || rate < 0 || getchar() != '\n') {
                    printf("Wrong input. Try again.\n");
                    rewind(stdin);
                }
                game->game.Types.Type1.rate_of_fire = rate;
                break;

            case 5:
                printf("\nEnter weight: ");
                while (!scanf("%d", &weight) || weight < 0 || getchar() != '\n') {
                    printf("Wrong input. Try again.\n");
                    rewind(stdin);
                }
                game->game.Types.Type1.weight = weight;
                break;

        }
    } else {
        printf("\nSelect the parameter to change\n"
               "1 - name of the game\n"
               "2 - quantity\n"
               "3 - date of last check\n"
               "4 - appointment\n"
               "5 - cost\n");
        while (!scanf("%d", &n2) || n2 < 0 || getchar() != '\n') {
            printf("Wrong input. Try again.\n");
            rewind(stdin);
        }
        switch (n2) {
            case 1:
                printf("\nEnter name of game: ");
                rewind(stdin);
                gets(s);
                strcpy(game->game.name, s);
                break;
            case 2:
                printf("\nEnter quantity: ");
                while (!scanf("%d", &quantity) || quantity < 0 || getchar() != '\n') {
                    printf("Wrong input. Try again.\n");
                    rewind(stdin);
                }
                game->game.quantity = quantity;
                break;
            case 3:
                printf("\nEnter date of last check: \n");

                printf("    day: ");
                while (!scanf("%d", &day) || day < 0 || day > 31 ||
                       getchar() != '\n') {
                    printf("Wrong input. Try again.\n");
                    rewind(stdin);
                }

                game->game.date_of_last_check.day = day;

                printf("    month: ");
                while (!scanf("%d", &month) || month < 0 ||
                       month > 12 || getchar() != '\n') {
                    printf("Wrong input. Try again.\n");
                    rewind(stdin);
                }

                game->game.date_of_last_check.month = month;

                printf("    year: ");
                while (!scanf("%d", &year) || year < 0 || getchar() != '\n') {
                    printf("Wrong input. Try again.\n");
                    rewind(stdin);
                }

                game->game.date_of_last_check.year = year;
                break;

            case 4:
                printf("\nEnter appointment: ");
                rewind(stdin);
                gets(s);
                strcpy(game->game.Types.Type2.appointment, s);
                break;

            case 5:
                printf("\nEnter cost: ");
                while (!scanf("%d", &cost) || cost < 0 || getchar() != '\n') {
                    printf("Wrong input. Try again.\n");
                    rewind(stdin);
                }
                game->game.Types.Type2.cost = cost;
                break;
        }
    }
}

void delete_game(List **games, int *size) {
    int n;
    if ((*games) == NULL) {
        printf("\nThere are no games\n");
        return;
    }
    printf("\nEnter the number of the game you wanna delete: ");
    while (!scanf("%d", &n) || n < 0 || getchar() != '\n') {
        printf("Wrong input. Try again.\n");
        rewind(stdin);
    }
    if (n > (*size))
        printf("\nThere is no product with this number\n");
    else {
        (*size)--;
        n--;
        if (n == 0) {
            List *elem = (*games);
            (*games) = (*games)->next;
            free(elem);
        } else {
            List *prev = find_n((*games), n - 1);
            List *elem = prev->next;
            prev->next = elem->next;
            free(elem);
        }
    }
}

void find_game(List *games) {
    char appointment[255];
    int choice, rate, weight, cost, fl = 0;

    printf("\nEnter the parameter by which you wanna search:"
           "\n1 - rate of fire"
           "\n2 - weight"
           "\n3 - appointment"
           "\n4 - cost\n");

    while (!scanf("%d", &choice) || choice < 1 || choice > 4 || getchar() != '\n') {
        printf("Wrong input. Try again.\n");
        rewind(stdin);
    }

    if (choice == 1) {
        printf("\nEnter rate of fire: ");
        rewind(stdin);
        while (!scanf("%d", &rate) || rate < 0 || getchar() != '\n') {
            printf("Wrong input. Try again.\n");
            rewind(stdin);
        }
        while (games) {
            if (games->game.type == 1 && games->game.Types.Type1.rate_of_fire == rate) {
                List *next = games->next;
                games->next = NULL;
                print_games(games);
                games->next = next;
                fl = 1;
            }
            games = games->next;
        }
        if (!fl)
            printf("\nThere are no games with this rate\n");
    } else if (choice == 2) {
        printf("\nEnter weight: ");
        rewind(stdin);
        while (!scanf("%d", &weight) || weight < 0 || getchar() != '\n') {
            printf("Wrong input. Try again.\n");
            rewind(stdin);
        }
        while (games) {
            if (games->game.type == 1 && games->game.Types.Type1.weight == weight) {
                List *next = games->next;
                games->next = NULL;
                print_games(games);
                games->next = next;
                fl = 1;
            }
            games = games->next;
        }
        if (!fl)
            printf("\nThere are no games with this weight\n");
    } else if (choice == 3) {
        printf("\nEnter appointment: ");
        rewind(stdin);
        gets(appointment);
        while (games) {
            if (games->game.type == 2 && strstr(games->game.Types.Type2.appointment, appointment)) {
                List *next = games->next;
                games->next = NULL;
                print_games(games);
                games->next = next;
                fl = 1;
            }
            games = games->next;
        }
        if (!fl)
            printf("\nThere are no games with this appointment\n");
    } else if (choice == 4) {
        printf("\nEnter cost: ");
        rewind(stdin);
        while (!scanf("%d", &cost) || cost < 0 || getchar() != '\n') {
            printf("Wrong input. Try again.\n");
            rewind(stdin);
        }
        while (games) {
            if (games->game.type == 2 && games->game.Types.Type2.cost == cost) {
                List *next = games->next;
                games->next = NULL;
                print_games(games);
                games->next = next;
                fl = 1;
            }
            games = games->next;
        }
        if (!fl)
            printf("\nThere are no games with this cost\n");
    }
}

void sort_by_parameter(List *games) {
    int choice;
    printf("\nEnter the parameter by which you wanna sort: "
           "\n1 - rate of fire"
           "\n2 - weight"
           "\n3 - appointment"
           "\n4 - cost\n");
    while (!scanf("%d", &choice) || choice < 0 || getchar() != '\n') {
        printf("Wrong input. Try again.\n");
        rewind(stdin);
    }
    switch (choice) {
        case 1:
            sort_by_rate(games);
            break;
        case 2:
            sort_by_weight(games);
            break;
        case 3:
            sort_by_appointment(games);
            break;
        case 4:
            sort_by_cost(games);
            break;
    }
    printf("\nSorted games: ");
    print_games(games);
}