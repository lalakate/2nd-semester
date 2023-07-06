#ifndef NEW_LAB3_FUNCTIONS_H
#define NEW_LAB3_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

#pragma once

void save(Paintball *p, int size);

void load(Paintball **p, int *size);

void load_previously_entered_data(Paintball **p, int *size);

int sort_condition(Paintball bubble, Paintball pj, char choose);

void insertion_sort(Paintball *p, int size, char choose);

int stock_availability(char *, Paintball);

void task1(Paintball *, int);

#endif //NEW_LAB3_FUNCTIONS_H
