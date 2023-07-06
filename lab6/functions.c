#include "queue.h"

void push(Queue **head, Queue **tail, int element) {
    Queue *temp;
    temp = (Queue *) malloc(sizeof(Queue));
    temp->data = element;
    temp->next = NULL;
    if (*head == NULL) {
        *head = temp;
        *tail = temp;
    } else {
        (*tail)->next = temp;
        *tail = temp;
    }
}

void pop(Queue **head) {
    Queue *temp;
    if (*head == NULL) printf("Queue is empty\n");
    else {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void print_queue(Queue *head) {
    if (head == NULL) printf("Queue is empty\n");
    else {
        while (head != NULL) {
            printf("%d ", head->data);
            head = head->next;
        }
    }
}

void sort_in_ascendic_order(Queue *head) {
    Queue *temp;
    int temp2;
    while (head != NULL) {
        temp = head;
        while (temp != NULL) {
            if (temp->data < head->data) {
                temp2 = temp->data;
                temp->data = head->data;
                head->data = temp2;
            }
            temp = temp->next;
        }
        head = head->next;
    }
}

void sort_in_descendic_order(Queue *head) {
    Queue *temp;
    int temp2;
    while (head != NULL) {
        temp = head;
        while (temp != NULL) {
            if (temp->data > head->data) {
                temp2 = temp->data;
                temp->data = head->data;
                head->data = temp2;
            }
            temp = temp->next;
        }
        head = head->next;
    }
}