#include <stdlib.h>
#include <stdio.h>

struct list_node {
    struct list_node *prev, *next;
    char *data;
};

static struct list_node *list_node_create(char *data) {
    struct list_node *node = malloc(sizeof node);

    node->prev = node;
    node->next = node;
    node->data = data;

    return node;
}

static void list_node_free(struct list_node *node) {
    free(node);
}

static void list_node_insert(struct list_node *node, struct list_node *prev, struct list_node *next) {
    node->next = next;
    node->prev = prev;
    next->prev = node;
    prev->next = node;
}

static void list_node_remove(struct list_node *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

struct list {
    struct list_node *head;
    size_t length;
};

struct list *list_create() {
    struct list *list = malloc(sizeof list);

    list->head   = NULL;
    list->length = 0;

    return list;
}

// TODO free all nodes
void list_free(struct list* list)  {
    list_node_free(list->head);
    free(list);
}

void list_add_head(struct list *list, char *data) {
    struct list_node *node = list_node_create(data);

    if (list->head != NULL) {
        list_node_insert(node, list->head->prev, list->head);
    }
    list->head = node;
    list->length++;
}

void list_add_tail(struct list *list, char *data) {
    struct list_node *node = list_node_create(data);

    if (list->head == NULL) {
        list->head = node;
    } else {
        list_node_insert(node, list->head->prev, list->head);
    }
    list->length++;
}

void list_add(struct list *list, size_t index, char *data) {
    if (index == 0) {
        list_add_head(list, data);
    }
    else if (index >= list->length) {
        list_add_tail(list, data);
    }
    else {
        struct list_node *curr = list->head;
        struct list_node *node = list_node_create(data);

        // stop at item before sought index
        for (size_t i = 1; i < index; i++) {
            curr = curr->next;
        }
        list_node_insert(node, curr, curr->next);

        list->length++;
    }
}

void list_del_head(struct list *list) {
    if (list->length == 1) {
        list_node_free(list->head);
        list->head = NULL;
    }
    else {
        struct list_node *new_head = list->head->next;

        list_node_remove(list->head);
        list_node_free(list->head);

        list->head = new_head;
    }
    list->length--;
}

void list_del_tail(struct list *list) {
    if (list->length == 1) {
        list_node_free(list->head);
        list->head = NULL;
    }
    else {
        struct list_node *node = list->head->prev;

        list_node_remove(list->head->prev);
        list_node_free(node);
    }
    list->length--;
}

void list_del(struct list *list, size_t index) {
    if (index == 0) {
        list_del_head(list);
    }
    else if (index >= list->length) {
        list_del_tail(list);
    }
    else {
        struct list_node *curr = list->head;

        for (size_t i = 0; i < index; i++) {
            curr = curr->next;
        }
        list_node_remove(curr);
        list_node_free(curr);

        list->length--;
    }
}
