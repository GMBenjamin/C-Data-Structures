typedef struct stack Stack;

Stack *stack_init();
void stack_destroy(Stack *stack);
int isEmpty(Stack *stack);
int size(Stack *stack);
void push(Stack *stack, void *element);
void *peek(Stack *stack);
void *pop(Stack *stack);
