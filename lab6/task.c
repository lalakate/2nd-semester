#include "queue.h"

void task() {
    Queue *head1, *head2, *new_head, *tail1, *tail2, *new_tail;

    head1 = NULL;
    head2 = NULL;
    new_head = NULL;
    tail1 = NULL;
    tail2 = NULL;
    new_tail = NULL;

    while (1) {
        printf("\nWhat do you wanna do?\n"
               "1 - push element to the first queue\n"
               "2 - push element to the second queue\n"
               "3 - print queues\n"
               "4 - make new sorted queue\n"
               "5 - print new queue\n"
               "6 - exit program\n");

        int action;
        while (!scanf("%d", &action) || action > 6 || action < 1 || getchar() != '\n') {
            printf("Wrong input. Try again.\n");
            rewind(stdin);
        }

        int element;

        switch (action) {
            case 1:
                printf("\nEnter the element you wanna push to the first stack: ");

                while (!scanf("%d", &element) || element > 1000000 || element < -10000000 || getchar() != '\n') {
                    printf("Wrong input. Try again.\n");
                    rewind(stdin);
                }

                push(&head1, &tail1, element);
                break;
            case 2:
                printf("\nEnter the element you wanna push to the second stack: ");

                while (!scanf("%d", &element) || element > 1000000 || element < -10000000 || getchar() != '\n') {
                    printf("Wrong input. Try again.\n");
                    rewind(stdin);
                }

                push(&head2, &tail2, element);
                break;
            case 3:
                sort_in_ascendic_order(head1);
                sort_in_descendic_order(head2);
                printf("\nThe first queue: ");
                print_queue(head1);
                printf("\nThe second queue: ");
                print_queue(head2);
                printf("\n");
                break;
            case 4:
                while (head1 != NULL) {
                    push(&new_head, &new_tail, head1->data);
                    pop(&head1);
                }
                while (head2 != NULL) {
                    push(&new_head, &new_tail, head2->data);
                    pop(&head2);
                }

                sort_in_ascendic_order(new_head);
                printf("New queue was created successfully!\n");
                break;
            case 5:
                printf("\nNew queue: ");
                print_queue(new_head);
                break;
            case 6:
                exit(0);
        }
    }
}
