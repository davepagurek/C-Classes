#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

struct list_item {
    struct list_item* next;
    int value;
};

struct list {
    struct list_item* head;
    int length;
};

typedef struct list List;

List* list_create();

void list_delete(List *l);

void list_remove(List *l, int n);

void list_push(List *l, int value);

int list_value(List *l, int n);

#endif // _LINKEDLIST_H
