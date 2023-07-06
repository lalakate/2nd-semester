#include "tree.h"

void task(Node *node) {
    if (balanced(node))
        printf("\nTree is balanced\n");
    else
        printf("\nTree is not balanced\n");
}