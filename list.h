typedef struct list List;

List *list_init();
void list_destroy(List *list);
int isEmpty(List *list);
int size(List *list);
void *get(List *list, int pos);
void *pop(List *list, int pos);
void append(List *list, void *element);
void insert(List *list, void *element, int pos);
void replace(List *list, void *element, int pos);
void removeFrom(List *list, int pos);
