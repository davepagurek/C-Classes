#include <stdio.h>
#include "linkedlist.h"

int main() {
    List *l = list_create();
    list_push(l, 3);

    printf("%d\n", list_value(l, 0));

    list_remove(l, 0);

    list_push(l, 67);
    list_push(l, 88);

    printf("%d\n", list_value(l, 0));
    printf("%d\n", list_value(l, 1));

    list_delete(l);
    printf("%d\n", l->length);

    return 0;
}
