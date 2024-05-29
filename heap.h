typedef struct heap Heap;

Heap *heap_init();
void heap_destroy(Heap *heap);
int isEmpty(Heap *heap);
int size(Heap *heap);
int best(Heap *heap);
void insert(Heap *heap, void *element, int priority);
void *getMin(Heap *heap);
void *extractMin(Heap *heap);
void removeMin(Heap *heap);
