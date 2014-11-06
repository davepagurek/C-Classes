#include "hashtable.h"

int main() {
    Hash* table = hash_create();
    hash_set(table, "test", 22);
    hash_set(table, "deleted", 1);
    hash_remove(table, "deleted");

    printf("deleted: %d\n", hash_value(table, "deleted"));
    printf("test: %d\n", hash_value(table, "test"));

    hash_delete(table);

    printf("test: %d\n", hash_value(table, "test"));

    return 0;
}

