#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

typedef struct stack {
    int size;
    void **ob;
} Stack;

Stack *stack_init() {
    Stack *s = malloc(sizeof(Stack));
    (*s).size = 0;
    (*s).ob = NULL;
    return s;
}

void stack_destroy(Stack *stack) {
    free((*stack).ob);
    free(stack);
}

int isEmpty(Stack *stack) {
    return !(*stack).size;
}

int size(Stack *stack) {
    return (*stack).size;
}

void push(Stack *stack, void *element) {
    (*stack).size += 1;
    (*stack).ob = realloc((*stack).ob,
        sizeof(void*)*(*stack).size);
    (*stack).ob[(*stack).size - 1] = element;
}

void *peek(Stack *stack) {
    if ((*stack).size == 0) {
        perror("Empty Stack\n");
        exit(1);
    }
    return (*stack).ob[(*stack).size - 1];
}

void *pop(Stack *stack) {
    if ((*stack).size == 0) {
        perror("Empty Stack\n");
        exit(1);
    }
    void *ans = (*stack).ob[(*stack).size - 1];
    (*stack).size -= 1;
    (*stack).ob = realloc((*stack).ob,
        sizeof(void*)*(*stack).size);
    return ans;
}

