# Estructuras de datos elementales en C

En este proyecto se presenta una implementación básica de las estructuras de datos más populares utilizando **C**. Dentro del repositorio se cuenta con la implementación de:

- **Listas** (List)
- **Colas** (Queue)
- **Pilas** (Stack)
- **Colas de prioridad** (Heap)

### Lista

En esta implementación, una lista (tipo List) es un arreglo de objetos de largo variable autogestionado. Para ello, la lista ocupa memoria dinámica que se modifica al realizar operaciones sobre la lista. Por otro lado, estas listas almacenan punteros a los objetos que se desean almacenar, por lo que "podrían ser de cualquier tipo".

Para crear una lista es necesario llamar a la función:
```C
List *list_init();
```
La cual inicializa una lista vacía.

Una vez desocupada la lista, se puede liberar la memoria llamando a la función:
```C
void list_destroy(List *list);
```

Estas listas incluyen las siguientes operaciones:

##### isEmpty
```C
int isEmpty(List *list);
```
Esta función indica si la lista está vacía.

##### size
```C
int size(List *list);
```
Esta función retorna la cantidad de elementos en la lista.

##### append
```C
void append(List *list, void *element);
```
Esta función añade un nuevo elemento al final de la lista.

##### insert
```C
void insert(List *list, void *element, int pos);
```
Esta función agrega un nuevo elemento a la lista en la posición *pos*.

##### replace
```C
void replace(List *list, void *element, int pos);
```
Esta función reemplaza el elemento de la lista en la posición *pos* por uno nuevo.

##### get
```C
void *get(List *list, int pos);
```
Esta función muestra el elemento ubicado en la posición *pos*.

##### pop
```C
void *pop(List *list, int pos);
```
Esta función extrae el elemento ubicado en la posición *pos*, es decir, lo saca de la lista y lo retorna.

##### removeFrom
```C
void removeFrom(List *list, int pos);
```
Esta función remueve el elemento ubicado en la posición *pos*.

### Cola
La cola es una estructura de datos que sigue la regla **FIFO**, por lo que el primer elemento que se almacena es el primero en salir. En esta implementación, las colas son de tipo Queue y almacenan punteros a objetos.

Para crear una cola se debe llamar a la función:
```C
Queue *queue_init();
```
Lo que devuelve el puntero a una cola vacía.

Cuando la cola ya no se encuentra en uso, se puede liberar la memoria que ocupa con la función:
```C
void queue_destroy(Queue *queue);
```

Para esta implementación, las colas incluyen sus operaciones elementales, las cuales se presentan a continuación:

##### isEmpty
```C
int isEmpty(Queue *queue);
```
Esta función indica si la cola está vacía.

##### size
```C
int size(Queue *queue);
```
Esta función retorna la cantidad de elementos en la cola.

##### push
```C
void push(Queue *queue, void *element);
```
Esta función inserta un elemento en la cola.

##### front
```C
void *front(Queue *queue);
```
Esta función muestra el primer elemento de la cola.

##### pop
```C
void *pop(Queue *queue);
```
Esta función extrae el primer elemento, es decir, lo saca de la cola y lo retorna.

### Pila
A diferencia de las colas, las pilas siguen la regla **LIFO**, por lo que el último elemento en ser almacenado será el primero en salir. En esta implementación, las pilas tienen tipo Stack y almacenan punteros a objetos.

Para crear una pila se debe llamar a la función:
```C
Stack *stack_init();
```
Esta retorna el puntero a una pila vacía.

Cuando se desee liberar la memoria que ocupa la pila, se debe llamar a la función:
```C
void stack_destroy(Stack *stack);
```

Las pilas cuentan con las siguientes operaciones:

##### isEmpty
```C
int isEmpty(Stack *stack);
```
Esta función indica si la pila está vacía.

##### size
```C
int size(Stack *stack);
```
Esta función retorna la cantidad de elementos en la pila.

##### push
```C
void push(Stack *stack, void *element);
```
Esta función inserta un elemento en la pila.

##### peek
```C
void *peek(Stack *stack);
```
Esta función muestra el último elemento ingresado a la pila.

##### pop
```C
void *pop(Stack *stack);
```
Esta función extrae el último elemento que ingresó a la pila, es decir, se remueve de la pila y se retorna.

### Cola de prioridad
Una cola de prioridad es una estructura en donde los datos se almacenan en un orden o prioridad. Los elementos con mejor prioridad son los primeros en salir, mientras que los elementos con peor prioridadse van quedando al final. En esta implementación, la cola de prioridad es de tipo Heap y almacenan punteros a objetos con una prioridad represenatada por un número entero, en donde menor es mejor.

Para crear una cola de prioridad, o heap, se debe llamar a la función:
```C
Heap *heap_init();
```
Lo que entrega un puntero a un heap vacío.

Cuando se desee liberar la memoria ocupada, se debe llamar a la función:
```C
void heap_destroy(Heap *heap);
```

La estructura Heap cuenta con las siguientes operaciones:

##### isEmpty
```C
int isEmpty(Heap *heap);
```
Esta función indica si el heap está vacío.

##### size
```C
int size(Heap *heap);
```
Esta función indica la cantidad de elementos en el heap.

##### best
```C
int best(Heap *heap);
```
Retorna el valor de la mejor prioridad en el heap.

##### insert
```C
void insert(Heap *heap, void *element, int priority);
```
Esta función inserta en el heap un elemento con un prioridad determinada.

##### getMin
```C
void *getMin(Heap *heap);
```
Esta función muestra el elemento con mejor prioridad en el heap.

##### extractMin
```C
void *extractMin(Heap *heap);
```
Esta función extrae el elemento que posee la mejor prioridad en el heap.

##### removeMin
```C
void *removeMin(Heap *heap);
```
Esta función remueve el elemento con mejor prioridad del heap.
