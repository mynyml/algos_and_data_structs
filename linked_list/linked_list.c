
#include <stdlib.h>
#include <assert.h>

typedef struct Node {
    struct Node *next;
    int data;
} Node;

Node *list_create() {
    Node *head = malloc(sizeof head);
    head->next = NULL;
    head->data = 0;

    return head;
}

void list_free(Node *node) {
    free(node);
}

size_t list_size(const Node *head) {
    assert(head != NULL);
    size_t size = 1;

    while (head->next != NULL) {
        size++;
        head = head->next;
    }

    return size;
}

Node *list_append(Node *head, const int data) {
    assert(head != NULL);

    Node *curr = head;

    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = list_create();
    curr->next->data = data;

    return curr->next;
}

Node *list_prepend(Node *head, const int data) {
    assert(head != NULL);

    Node *new = list_create();
    new->data = data;
    new->next = head;

    return new;
}

Node *list_insert_after(Node *head, const int data, const size_t index) {
    assert(head != NULL);

    Node *curr = head;

    for (size_t i = 0; i < index; i++) {
        curr = curr->next;
    }

    Node *new = list_create();
    new->data = data;

    new->next  = curr->next;
    curr->next = new;

    return new;
}

Node *list_delete_at(Node *head, const size_t index) {
    assert(head != NULL);

    Node *curr = head;
    Node *prev = NULL;

    for (size_t i = 0; i < index; i++) {
        prev = curr;
        curr = curr->next;
    }

    if (prev != NULL) {
        prev->next = curr->next;
    }

    return curr;
}

