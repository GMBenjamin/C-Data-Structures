#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

typedef struct heap {
    int size;
    void **ob;
    int *pri;
} Heap;

Heap *heap_init() {
    Heap *h = malloc(sizeof(Heap));
    (*h).size = 0;
    (*h).ob = NULL;
    (*h).pri = NULL;
}

void heap_destroy(Heap *heap) {
    free((*heap).pri);
    free((*heap).ob);
    free(heap);
}

int isEmpty(Heap *heap) {
    return !(*heap).size;
}

int size(Heap *heap) {
    return (*heap).size;
}

int best(Heap *heap) {
    if ((*heap).size == 0) {
        perror("Empty Queue\n");
        exit(1);
    }
    return (*heap).pri[0];
}

void insert(Heap *heap, void *element, int priority) {
    if ((*heap).size == 0) {
        (*heap).size += 1;
        (*heap).ob = realloc((*heap).ob,
            sizeof(void*)*(*heap).size);
        (*heap).pri = realloc((*heap).pri,
            sizeof(int)*(*heap).size);
        (*heap).ob[0] = element;
        (*heap).pri[0] = priority;
    }
    else {
        int pos = 0;
        for (int i = 0; i < (*heap).size; i++) {
            if (priority > (*heap).pri[i])
                pos += 1;
            else
                break;
        }
        (*heap).size += 1;
        (*heap).ob = realloc((*heap).ob,
            sizeof(void*)*(*heap).size);
        (*heap).pri = realloc((*heap).pri,
            sizeof(int)*(*heap).size);
        for (int i = (*heap).size - 1; i > pos; i--) {
            (*heap).ob[i] = (*heap).ob[i-1];
            (*heap).pri[i] = (*heap).pri[i-1];
        }
        (*heap).ob[pos] = element;
        (*heap).pri[pos] = priority;
    }
}

void *getMin(Heap *heap) {
    if ((*heap).size == 0) {
        perror("Empty Queue\n");
        exit(1);
    }
    return (*heap).ob[0];
}

void *extractMin(Heap *heap) {
    if ((*heap).size == 0) {
        perror("Empty Queue\n");
        exit(1);
    }
    void *ans = (*heap).ob[0];
    for (int i = 0; i < (*heap).size - 1; i++) {
        (*heap).pri[i] = (*heap).pri[i+1];
        (*heap).ob[i] = (*heap).ob[i+1];
    }
    (*heap).size -= 1;
    (*heap).ob = realloc((*heap).ob,
        sizeof(void*)*(*heap).size);
    (*heap).pri = realloc((*heap).pri,
        sizeof(int)*(*heap).size);
    return ans;
}

void removeMin(Heap *heap) {
    if ((*heap).size == 0) {
        perror("Empty Queue\n");
        exit(1);
    }
    for (int i = 0; i < (*heap).size - 1; i++) {
        (*heap).pri[i] = (*heap).pri[i+1];
        (*heap).ob[i] = (*heap).ob[i+1];
    }
    (*heap).size -= 1;
    (*heap).ob = realloc((*heap).ob,
        sizeof(void*)*(*heap).size);
    (*heap).pri = realloc((*heap).pri,
        sizeof(int)*(*heap).size);
}

