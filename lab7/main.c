#include "tree.h"

int main() {
    Node *tree = NULL;
    printf("\nEnter the size of tree: ");
    int n = int_input();
    for (int i = 0; i < n; i++) {
        int a = int_input();
        input_tree(&tree, a);
    }
    printf("\nOriginal tree:\n");
    print_tree(tree, 0);
    while (1) {
        printf("\n\nWhat do you wanna do?"
               "\n1 - Add node"
               "\n2 - Delete node"
               "\n3 - Print the tree"
               "\n4 - Check tree balance"
               "\n5 - Search minimal node"
               "\n6 - Search maximal node"
               "\n7 - Exit program\n\n");

        int choice;
        while (!scanf("%d", &choice) || choice > 7 || choice < 1 || getchar() != '\n') {
            printf("Wrong input. Try again.\n");
            rewind(stdin);
        }

        if (choice == 1) {
            printf("\nEnter number: ");
            int node = int_input();
            add_node(tree, node);
        } else if (choice == 2) {
            printf("\nEnter number: ");
            int node = int_input();
            delete_node(tree, node);
        } else if (choice == 3) {
            printf("\nOriginal tree:\n");
            print_tree(tree, 0);
        } else if (choice == 4)
            task(tree);
        else if (choice == 5)
            printf("Minimal node: %d", min(tree)->key);
        else if (choice == 6)
            printf("Maximal node: %d", max(tree)->key);
        else if (choice == 7)
            exit(0);

    }
}
