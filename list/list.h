#include <stdlib.h>

struct list_node {
    struct list_node *prev, *next;
    char *data;
};

struct list {
    struct list_node *head;
    size_t length;
};

struct list *list_create();
struct list *list_free(struct list *);

void list_add_head(struct list *, char *data);
void list_add_tail(struct list *, char *data);
void list_add(struct list *, size_t index, char *data);

void list_del_head(struct list *);
void list_del_tail(struct list *);
void list_del(struct list *, size_t index);

char *list_get(struct list *, size_t index);

