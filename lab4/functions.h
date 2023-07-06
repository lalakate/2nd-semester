#ifndef LAB4_FUNCTIONS_H
#define LAB4_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

#pragma once

enum log_conditions {
    Start = 1, Add, Print, Update, Delete, Sort, Find, Exit
};

List *get_last(List *);

List *find_n(List *, int);

void sort_by_rate(List *);

void sort_by_weight(List *);

void sort_by_appointment(List *);

void sort_by_cost(List *);

void log_record(int, List *, FILE *);

#endif //LAB4_FUNCTIONS_H
