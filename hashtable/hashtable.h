#ifndef _HASHTABLE_H
#define _HASHTABLE_H

struct hash_item {
    struct hash_item* next;
    char* key;
    int value;
};

typedef struct hash_item Hash;

Hash* hash_create();

void hash_delete(Hash* head);

void hash_remove(Hash* head, char key[]);

void hash_set(Hash* head, char key[], int value);

int hash_value(Hash* head, char key[]);

#endif
