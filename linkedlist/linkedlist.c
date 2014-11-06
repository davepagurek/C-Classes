#include "linkedlist.h"

List* list_create() {
    List *l = malloc(sizeof(*l));

    l->head = 0;
    l->length = 0;

    return l;
};

void list_delete(List *l) {
    struct list_item* h = l->head;
    while (h) {
        struct list_item* n = h->next;
        free(h);
        h = n;
    }
    l->head = 0;
    l->length = 0;
}

void list_remove(List *l, int n) {
    if (l->length<=n) return;
    if (n==0 && l->head) {
        struct list_item* target = l->head;
        l->head = l->head->next;
        free(target);
        l->length--;
    } else {
        struct list_item* h;
        int i=1;
        for (h = l->head, i=1; h->next && i<n; i++) {
            h = h->next;
        }
        if (h->next && i==n) {
            struct list_item* target = h->next;
            h->next = target->next;
            free(target);
            l->length--;
        }
    }
}

void list_set(List *l, int n, int value) {
    if (l->length<=n) return;
    if (n==0 && l->head) {
        l->head->value = value;
    }
    struct list_item* h;
    int i=1;
    for (h = l->head->next, i=1; h && i<n; i++) {
        h = h->next;
    }
    if (h && i==n) {
        h->value = value;
    }
}

void list_push(List *l, int value) {
    struct list_item *i = malloc(sizeof *i);
    i->next = 0;
    i->value = value;
    if (l->length==0) {
        l->head = i;
        l->length++;
    } else {
        struct list_item* h;
        for (h = l->head; h->next; h = h->next) { }
        if (h) {
            h->next = i;
            l->length++;
        } else {
            free(i);
        }
    }
}

int list_value(List *l, int n) {
    if (l->length<=n) return 0;
    if (n==0 && l->head) {
        return l->head->value;
    }
    struct list_item* h;
    int i=1;
    for (h = l->head->next, i=1; h && i<n; i++) {
        h = h->next;
    }
    if (h && i==n) {
        return h->value;
    }
    return 0;
}

