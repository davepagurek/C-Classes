#include "hashtable.h"

Hash* hash_create() {
    Hash *hash = malloc(sizeof *hash);

    hash->head = 0;
    hash->size = 0;

    return hash;
};

void hash_delete(Hash* hash) {
    struct hash_item* h = hash->head;
    while (h) {
        struct hash_item* n = h->next;
        free(h);
        h = n;
    }
    hash->head = 0;
    hash->size = 0;
}

void hash_remove(Hash* hash, char key[]) {
    if (hash->size<=0) return;
    struct hash_item* h = hash->head;
    if (h) {
        if (strcmp(h->key, key)==0) {
            struct hash_item* target = h;
            h = h->next;
            free(target);
            hash->size--;
        } else if (h->next) {
            while (h->next && strcmp(h->next->key, key) != 0) {
                h = h->next;
            }
            if (h->next && strcmp(h->next->key, key)==0) {
                struct hash_item* target = h->next;
                h->next = target->next;
                free(target);
                hash->size--;
            }
        }
    }
}

void hash_set(Hash* hash, char key[], int value) {
    struct hash_item* h = hash->head;
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
                h->next = malloc(sizeof(*(h->next)));
                h->next->next = 0;
                h->next->key = key;
                h->next->value = value;
                hash->size++;
            }
        } else {
            h->next = malloc(sizeof(*(h->next)));
            h->next->next = 0;
            h->next->key = key;
            h->next->value = value;
            hash->size++;
        }
    } else {
        hash->head = malloc(sizeof(*(hash->head)));
        hash->head->next = 0;
        hash->head->key = key;
        hash->head->value = value;
        hash->size++;
    }
}

int hash_value(Hash* hash, char key[]) {
    struct hash_item* h = hash->head;
    while (h && strcmp(h->key, key)!=0) {
        h = h->next;
    }
    if (h) return h->value;
    return 0;
}
