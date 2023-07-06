#ifndef AB_6_QUEUE_H
#define AB_6_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int data;
    struct Queue *next;
} Queue;

void push(Queue **, Queue **, int);

void pop(Queue **);

void print_queue(Queue *);

void sort_in_ascendic_order(Queue *);

void sort_in_descendic_order(Queue *);

void task();

#endif //AB_6_QUEUE_H 