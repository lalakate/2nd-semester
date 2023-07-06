#include "functions.h"

List *get_last(List *head) {
    if (head == NULL)
        return NULL;
    while (head->next)
        head = head->next;
    return head;
}

List *find_n(List *head, int n) {
    for (int i = 0; i < n; i++)
        head = head->next;
    return head;
}

int size(List *games) {
    int counter = 0;
    while (games != NULL) {
        counter++;
        games = games->next;
    }
    return counter;
}

void sort_by_rate(List *games) {
    List *head = games, *temp = (List *) malloc(sizeof(List));
    while (head != NULL) {
        games = head;
        while (games != NULL) {
            if (head->game.type == 1 && games->game.type == 1) {
                if (head->game.Types.Type1.rate_of_fire > games->game.Types.Type1.rate_of_fire) {
                    temp->game = head->game;
                    head->game = games->game;
                    games->game = temp->game;
                }
            }
            games = games->next;
        }
        head = head->next;
    }
}

void sort_by_weight(List *games) {
    List *head = games, *temp = (List *) malloc(sizeof(List));
    while (head != NULL) {
        games = head;
        while (games != NULL) {
            if (head->game.type == 1 && games->game.type == 1) {
                if (head->game.Types.Type1.weight > games->game.Types.Type1.weight) {
                    temp->game = head->game;
                    head->game = games->game;
                    games->game = temp->game;
                }
            }
            games = games->next;
        }
        head = head->next;
    }
}

void sort_by_appointment(List *games) {
    List *head = games, *temp = (List *) malloc(sizeof(List));
    while (head != NULL) {
        games = head;
        while (games != NULL) {
            if (head->game.type == 2 && games->game.type == 2) {
                if (strcmp(head->game.Types.Type2.appointment, games->game.Types.Type2.appointment) >= 1) {
                    temp->game = head->game;
                    head->game = games->game;
                    games->game = temp->game;
                }
            }
            games = games->next;
        }
        head = head->next;
    }
}

void sort_by_cost(List *games) {
    List *head = games, *temp = (List *) malloc(sizeof(List));
    while (head != NULL) {
        games = head;
        while (games != NULL) {
            if (head->game.type == 2 && games->game.type == 2) {
                if (head->game.Types.Type2.cost > games->game.Types.Type2.cost) {
                    temp->game = head->game;
                    head->game = games->game;
                    games->game = temp->game;
                }
            }
            games = games->next;
        }
        head = head->next;
    }
}

void log_record(int event, List *games, FILE *fp) {
    fopen("file.log", "a+");
    if (fp == NULL) {
        printf("\nFile is not found");
        exit(0);
    }

    SYSTEMTIME st;
    GetLocalTime(&st);

    switch (event) {
        case Start: {
            fprintf(fp, "[Record of %02d.%02d.%04d]\n", st.wDay, st.wMonth, st.wYear);
            fprintf(fp, "[%02i.%02i.%02i] -- Start of execution\n", st.wHour, st.wMinute, st.wSecond);
            break;
        }
        case Add: {
            fprintf(fp, "[%i.%i.%i] -- Add list element [id-%d]\n", st.wHour, st.wMinute, st.wSecond, games->game.id);
            break;
        }
        case Update: {
            fprintf(fp, "[%i.%i.%i] -- Update list element [id-%d]\n", st.wHour, st.wMinute, st.wSecond,
                    games->game.id);
            break;
        }
        case Delete: {
            fprintf(fp, "[%i.%i.%i] -- Delete list element [id-%d]\n", st.wHour, st.wMinute, st.wSecond,
                    games->game.id);
            break;
        }
        case Print: {
            fprintf(fp, "[%i.%i.%i] -- Print list \n", st.wHour, st.wMinute, st.wSecond);
            break;
        }
        case Sort: {
            fprintf(fp, "[%i.%i.%i] -- Sort list \n", st.wHour, st.wMinute, st.wSecond);
            break;
        }
        case Find: {
            fprintf(fp, "[%i.%i.%i] -- Search element of list \n", st.wHour, st.wMinute, st.wSecond);
            break;
        }
        case Exit: {
            fprintf(fp, "[%i.%i.%i] -- Exit  \n", st.wHour, st.wMinute, st.wSecond);
            break;
        }
        default:
            break;
    }
    fclose(fp);
}
