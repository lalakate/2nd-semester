#ifndef LAB7_TREE_H
#define LAB7_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;

Node *add_node(Node *, int);

void change();

void print_tree(Node *, int);

Node *delete_node(Node *, int);

Node *min(Node *);

Node *max(Node *);

int max_num(int, int);

int height(Node *);

int balanced(Node *);

void task(Node *);

int input_task(int);

int int_input();

int search(Node *, int);

void input_tree(Node **, int);

#endif //LAB7_TREE_H
