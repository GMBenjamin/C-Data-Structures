#include <stdlib.h>
#include <stdio.h>
#include "list.h"

typedef struct list {
    int size;
    void **ob;
} List;

List *list_init() {
    List *l = malloc(sizeof(List));
    (*l).size = 0;
    (*l).ob = NULL;
    return l;
}

void list_destroy(List *list) {
    (*list).size = 0;
    free((*list).ob);
    free(list); 
}

int isEmpty(List *list) {
    return !(*list).size;
}

int size(List *list) {
    return (*list).size;
}

void *get(List *list, int pos) {
    if ((*list).size == 0) {
        perror("Empty List\n");
        exit(1);
    }
    else if (pos < (*list).size && pos >= 0)
        return (*list).ob[pos];
    else {
        perror("Index value out of range\n");
        exit(2);
    }
}

void *pop(List *list, int pos) {
    if ((*list).size == 0) {
        perror("Empty List\n");
        exit(1);
    }
    else if (pos < (*list).size && pos >= 0) {
        void *ans = (*list).ob[pos];
        if ((*list).size == 1) {
            (*list).size -= 1;
            free((*list).ob);
            (*list).ob = NULL;
        }
        else {
            for (int i = pos; i < (*list).size - 1; i++)
                (*list).ob[i] = (*list).ob[i+1];
            (*list).size -= 1;
            (*list).ob = realloc((*list).ob,
                sizeof(void*)*(*list).size);
        }
        return ans;
    }
    else {
        perror("Index value out of range\n");
        exit(2);
    }
}

void append(List *list, void *element) {
    (*list).size += 1;
    (*list).ob = realloc((*list).ob,
        sizeof(void*)*(*list).size);
    (*list).ob[(*list).size-1] = element;
}

void insert(List *list,void *element, int pos) {
    if (pos > (*list).size || pos < 0) {
        perror("Index value out of range\n");
        exit(1);
    }
    (*list).size += 1;
    (*list).ob = realloc((*list).ob,
        sizeof(void*)*(*list).size);
    for (int i = (*list).size - 1; i > pos; i--)
        (*list).ob[i] = (*list).ob[i-1];
    (*list).ob[pos] = element;
}

void replace(List *list, void *element, int pos) {
    if ((*list).size == 0) {
        perror("Empty List\n");
        exit(1);
    }
    else if (pos >= (*list).size || pos < 0) {
        perror("Index value out of range\n");
        exit(2);
    }
    (*list).ob[pos] = element;
}

void removeFrom(List *list, int pos) {
    if ((*list).size == 0) {
        perror("Empty List\n");
        exit(1);
    }
    else if ((*list).size == 1) {
        (*list).size = 0;
        free((*list).ob);
        (*list).ob = NULL;
    }
    else {
        for (int i = pos; i < (*list).size - 1; i++)
            (*list).ob[i] = (*list).ob[i+1];
        (*list).size -= 1;
        (*list).ob = realloc((*list).ob,
            sizeof(void*)*(*list).size);
    }
}

