#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "list.h"

int main(void) {

    struct list *list = NULL;

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // test creation, initialization, freeing
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    list = list_create();

    assert(list->length == 0);

    list_free(list);

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // test prepending
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    list = list_create();

    list_add_head(list, "aaa");
    list_add_head(list, "bbb");
    list_add_head(list, "ccc");

    assert(list->length                 == 3);
    assert(list->head->data             == "ccc");
    assert(list->head->next->data       == "bbb");
    assert(list->head->next->next->data == "aaa");

    list_free(list);

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // test appending
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    list = list_create();

    list_add_tail(list, "aaa");
    list_add_tail(list, "bbb");
    list_add_tail(list, "ccc");

    assert(list->length                 == 3);
    assert(list->head->data             == "aaa");
    assert(list->head->next->data       == "bbb");
    assert(list->head->next->next->data == "ccc");

    list_free(list);

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // test adding at any index
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    list = list_create();

    list_add(list, 0, "aaa");
    list_add(list, 1, "bbb");
    list_add(list, 1, "ccc");

    assert(list->length                 == 3);
    assert(list->head->data             == "aaa");
    assert(list->head->next->data       == "ccc");
    assert(list->head->next->next->data == "bbb");

    list_free(list);

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // test deleting head
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    list = list_create();

    list_add_tail(list, "aaa");
    list_add_tail(list, "bbb");
    list_add_tail(list, "ccc");

    list_del_head(list);

    assert(list->length           == 2);
    assert(list->head->data       == "bbb");
    assert(list->head->next->data == "ccc");

    list_del_head(list);

    assert(list->length     == 1);
    assert(list->head->data == "ccc");

    list_del_head(list);

    assert(list->length == 0);
    assert(list->head   == NULL);

    list_free(list);

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // test deleting tail
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    list = list_create();

    list_add_tail(list, "aaa");
    list_add_tail(list, "bbb");
    list_add_tail(list, "ccc");

    list_del_tail(list);

    assert(list->length           == 2);
    assert(list->head->data       == "aaa");
    assert(list->head->next->data == "bbb");

    list_del_tail(list);

    assert(list->length     == 1);
    assert(list->head->data == "aaa");

    list_del_tail(list);

    assert(list->length == 0);
    assert(list->head   == NULL);

    list_free(list);

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // test deleting at any index
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    list = list_create();

    list_add_tail(list, "aaa");
    list_add_tail(list, "bbb");
    list_add_tail(list, "ccc");

    list_del(list, 1);

    assert(list->length           == 2);
    assert(list->head->data       == "aaa");
    assert(list->head->next->data == "ccc");

    list_del(list, 1);

    assert(list->length     == 1);
    assert(list->head->data == "aaa");

    list_del(list, 0);

    assert(list->length == 0);
    assert(list->head   == NULL);

    list_free(list);
}

