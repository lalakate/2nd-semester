#include "tree.h"

Node *min(Node *tree) {
    if (tree->left == NULL)
        return tree;
    return min(tree->left);
}

Node *max(Node *tree) {
    if (tree->right == NULL)
        return tree;
    return max(tree->right);
}

/*void print_tree(Node *tree) {
    if(tree == NULL){
        printf("\nTree is empty\n");
        return;
    }
    else {
        printf("%d\n", tree->key);
        print_tree(tree->left);
        print_tree(tree->right);
    }
}*/

Node *add_node(Node *tree, int x) {
    if (tree == NULL) {
        tree = (Node *) malloc(sizeof(Node));
        tree->key = x;
        tree->left = NULL;
        tree->right = NULL;
    } else if (x < tree->key)
        tree->left = add_node(tree->left, x);
    else
        tree->right = add_node(tree->right, x);
    return (tree);
}

Node *delete_node(Node *tree, int x) {
    if (tree == NULL)
        return tree;
    if (x < tree->key)
        tree->left = delete_node(tree->left, x);
    else if (x > tree->key)
        tree->right = delete_node(tree->right, x);
    else if ((tree->right != NULL) && (tree->left != NULL)) {
        tree->key = min(tree->right)->key;
        tree->right = delete_node(tree->right, tree->key);
    } else {
        if (tree->left != NULL)
            tree = tree->left;
        else if (tree->right != NULL)
            tree = tree->right;
        else
            tree = NULL;
    }
    return tree;
}

int max_num(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node *node) {
    if (node == NULL)
        return 0;
    else
        return 1 + max_num(height(node->left), height(node->right));
}

int balanced(struct Node *node) {
    int left, right;

    if (node == NULL)
        return 1;

    left = height(node->left);
    right = height(node->right);

    if (abs(left - right) <= 1 && balanced(node->left) && balanced(node->right))
        return 1;

    return 0;
}

int input_task(int number) {
    while (!scanf("%d", &number) || number > 6 || number < 1 || getchar() != '\n') {
        printf("Wrong input. Try again.\n");
        rewind(stdin);
    }
    return number;
}

int int_input() {
    int number;
    while (!scanf("%d", &number) || number > 100 || number < -100 || getchar() != '\n') {
        printf("Wrong input. Try again.\n");
        rewind(stdin);
    }
    return number;
}

void input_tree(Node **tree, int data) {
    if ((*tree) == NULL) {
        (*tree) = (Node *) malloc(sizeof(Node));
        (*tree)->key = data;
        (*tree)->left = NULL;
        (*tree)->right = NULL;
    } else {
        if ((*tree)->key > data)
            input_tree(&((*tree)->left), data);
        else
            input_tree(&((*tree)->right), data);
    }
}

void print_tree(Node *tree, int level) {
    if (tree) {
        print_tree(tree->left, level + 1);
        for (int i = 0; i < level; i++)
            printf("   ");
        printf("%i\n", tree->key);
        print_tree(tree->right, level + 1);
    }
}

int search(Node *tree, int data) {
    if (tree == NULL)
        return 0;
    if (tree->key == data)
        return 1;
    if (data < tree->key)
        return search(tree->left, data);
    else
        return search(tree->right, data);
}