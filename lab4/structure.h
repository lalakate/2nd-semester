#ifndef LAB4_STRUCTURE_H
#define LAB4_STRUCTURE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

#pragma once

enum options {
    add = '1', print, update, delete, sort, find
};

typedef struct {
    unsigned int day;
    unsigned int month;
    unsigned year;
} Date;

typedef struct {
    unsigned int id;
    char name[255];
    unsigned int quantity;
    Date date_of_last_check;
    int type;
    union {
        struct {
            unsigned int rate_of_fire;
            unsigned int weight;
        } Type1;
        struct {
            char appointment[255];
            unsigned int cost;
        } Type2;
    } Types;

} Paintball;

typedef struct List {
    Paintball game;
    struct List *next;
} List;

void add_game(List **, int *);

void print_games(List *);

void update_game(List *);

void delete_game(List **, int *);

void sort_by_parameter(List *);

void find_game(List *);

#endif //LAB4_STRUCTURE_H