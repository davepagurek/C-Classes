#include <stdio.h>
#include "vector.h";


int main(void) {
    struct vector *v = vector_create();
    printf("%d\n", vector_value(v, 0));

    int i;
    for (i=0; i<10; i++) {
        vector_push(v, i);
    }
    printf("%d\n", vector_value(v, 7));
    vector_set(v, 30, 1);
    printf("%d\n", vector_value(v, 30));
    printf("%d\n", vector_value(v, 28));
    vector_delete(v);
    return 0;
}


