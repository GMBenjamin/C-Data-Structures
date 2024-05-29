typedef struct queue Queue;

Queue *queue_init();
void queue_destroy(Queue *queue);
int isEmpty(Queue *queue);
int size(Queue *queue);
void push(Queue *queue, void *element);
void *front(Queue *queue);
void *pop(Queue *queue);
