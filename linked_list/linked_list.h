#include <stdlib.h>

typedef struct Node {
    struct Node *next;
    int data;
} Node;

Node*  list_create();
void   list_free(Node*);
size_t list_size(Node*);
Node*  list_append(Node*, int);
Node*  list_prepend(Node*, int);
Node*  list_insert_after(Node*, int, size_t);
Node*  list_delete_head(Node*);
Node*  list_delete_tail(Node*);
Node*  list_delete_at(Node*, size_t);

