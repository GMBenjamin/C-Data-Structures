#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

typedef struct queue {
    int size;
    void *head;
    struct queue *next;
} Queue;

Queue *queue_init() {
    Queue *q = malloc(sizeof(Queue));
    (*q).size = 0;
    (*q).head = NULL;
    (*q).next = NULL;
    return q;
}

void queue_destroy(Queue *queue) {
    free((*queue).next);
    free(queue);
}

int isEmpty(Queue *queue) {
    return !(*queue).size;
}

int size(Queue *queue) {
    return (*queue).size;
}

void push(Queue *queue, void *element) {
    (*queue).size += 1;
    if ((*queue).head == NULL)
        (*queue).head = element;
    else if ((*queue).next == NULL) {
        (*queue).next = queue_init();
        push((*queue).next, element);
    }
    else
        push((*queue).next, element);
}

void *front(Queue *queue) {
    if ((*queue).head == NULL || (*queue).size == 0) {
        perror("Empty Queue\n");
        exit(1);
    }
    return (*queue).head;
}

void *pop(Queue *queue) {
    if ((*queue).head == NULL || (*queue).size == 0) {
        perror("Empty Queue\n");
        exit(1);
    }
    else if ((*queue).size == 1) {
        (*queue).size = 0;
        void *ans = (*queue).head;
        (*queue).head = NULL;
        return ans;
    }
    void *ans = (*queue).head;
    (*queue).size -= 1;
    (*queue).head = (*((*queue).next)).head;
    Queue *n = (*queue).next;
    (*queue).next = (*((*queue).next)).next;
    free(n);
    return ans;
}

