#ifndef _HASHTABLE_H
#define _HASHTABLE_H

struct hash_item {
    struct hash_item* next;
    char* key;
    int value;
};

struct hash {
    struct hash_item* head;
    int size;
};

typedef struct hash Hash;

Hash* hash_create();

void hash_delete(Hash* h);

void hash_remove(Hash* h, char key[]);

void hash_set(Hash* h, char key[], int value);

int hash_value(Hash* h, char key[]);

#endif
