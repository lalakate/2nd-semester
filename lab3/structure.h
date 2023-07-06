#ifndef NEW_LAB3_STRUCTURE_H
#define NEW_LAB3_STRUCTURE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#pragma once

enum options {
    ADD = '1', PRINT, UPDATE, DELETE, SORT, STOCK, CHECK, QUIT
};

typedef struct {
    unsigned int id;
    char name[255];
    char type[255];
    unsigned int quantity;
    unsigned int day;
    unsigned int month;
    unsigned int year;
} Paintball;

void add_game(Paintball *, int);

void print_games(Paintball *, int);

void update_game(Paintball *, int);

void delete_game(Paintball *, int *);

void sort_by_parameter(Paintball *, int);

char *enterStr(char *);

char *giveMemory(int);


#endif //NEW_LAB3_STRUCTURE_H
