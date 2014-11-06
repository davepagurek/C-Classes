#include "hashtable.h"

struct hash_item* hash_create() {
    struct hash_item *head = malloc(sizeof *head);

    head->key = "";
    head->value = 0;
    head->next = 0;

    return head;
};

void hash_delete(Hash* head) {
    Hash* h = head->next;
    while (h) {
        Hash* n = h->next;
        free(h);
        h = n;
    }
    head->key = "";
    head->value = 0;
    head->next = 0;
}

void hash_remove(Hash* head, char key[]) {
    Hash* h = head;
    if (h) {
        if (strcmp(h->key, key)==0) {
            if (h->next) {
                Hash* target = h;
                h = h->next;
                free(target);
            } else {
                h->key = "";
                h->value = 0;
            }
        } else if (h->next) {
            while (h->next && strcmp(h->next->key, key) != 0) {
                h = h->next;
            }
            if (h->next && strcmp(h->next->key, key)==0) {
                Hash* target = h->next;
                h->next = target->next;
                free(target);
            }
        }
    }
}

void hash_set(Hash* head, char key[], int value) {
    Hash* h = head;
    if (h) {
        if (strcmp(h->key, key)==0) {
            h->value = value;
        } else if (h->next) {
            while (h->next && strcmp(h->next->key, key) != 0) {
                h = h->next;
            }
            if (h->next && strcmp(h->next->key, key)==0) {
                h->next->value = value;
            } else {
                h->next = malloc(sizeof(*(head->next)));
                h->next->next = 0;
                h->next->key = key;
                h->next->value = value;
            }
        } else {
            h->next = malloc(sizeof(*(head->next)));
            h->next->next = 0;
            h->next->key = key;
            h->next->value = value;
        }
    }
}

int hash_value(Hash* head, char key[]) {
    Hash* h = head;
    while (h && strcmp(h->key, key)!=0) {
        h = h->next;
    }
    if (h) return h->value;
    return 0;
}
