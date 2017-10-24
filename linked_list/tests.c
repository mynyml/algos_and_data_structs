#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "linked_list.h"

int main(void) {

    Node *head;
    Node *node;

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // test creation, initialization, freeing
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    head = list_create();
    assert(head->next == NULL);
    assert(head->data == 0);

    list_free(head);

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // test data member
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    head = list_create();
    head->data = 11;

    assert(head->data == 11);

    list_free(head);

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // test list_size()
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    head = list_create();

    size_t size = list_size(head);
    assert(size == 1);

    list_free(head);

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // test list_append()
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    head = list_create();
    head->data = 11;

    node = list_append(head, 22);

    assert(list_size(head) == 2);
    assert(node->data == 22);
    assert(head->data == 11); // ensure head isn't modified

    list_free(head);
    list_free(node);

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // test prepend()
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    head = list_create();
    head->data = 11;

    node = list_prepend(head, 33);

    assert(list_size(node) == 2);
    assert(node->data == 33);
    assert(head->data == 11);

    list_free(head);
    list_free(node);

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // test insert_after()
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    head = list_create();
    head->data = 11;

    list_append(head, 22);
    list_append(head, 33);

    assert(list_size(head) == 3);

    list_insert_after(head, 44, 1);

    assert(head->data                   == 11);
    assert(head->next->data             == 22);
    assert(head->next->next->data       == 44);
    assert(head->next->next->next->data == 33);

    list_free(head);


    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // test delete_at() in middle of list
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    head = list_create();
    head->data = 11;

    list_append(head, 22);
    list_append(head, 33);

    assert(list_size(head) == 3);

    node = list_delete_at(head, 1);

    assert(list_size(head)  == 2);
    assert(head->data       == 11);
    assert(head->next->data == 33);
    assert(node->data       == 22);

    list_free(head);
    list_free(node);

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // test delete_at() at head
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    head = list_create();
    head->data = 11;

    list_append(head, 22);
    list_append(head, 33);

    assert(list_size(head) == 3);

    Node *new_head = head->next;
    node = list_delete_at(head, 0);
    head = new_head;

    assert(list_size(head)  == 2);
    assert(head->data       == 22);
    assert(head->next->data == 33);

    list_free(head);
    list_free(node);

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // test delete_at() at tail
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    head = list_create();
    head->data = 11;

    list_append(head, 22);
    list_append(head, 33);

    assert(list_size(head) == 3);

    node = list_delete_at(head, 2);

    assert(list_size(head)  == 2);
    assert(head->data       == 11);
    assert(head->next->data == 22);

    list_free(head);
    list_free(node);

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    return EXIT_SUCCESS;
}

