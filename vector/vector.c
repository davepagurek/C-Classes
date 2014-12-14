#include <stdlib.h>;
#include "vector.h";

struct vector* vector_create() {
    struct vector* v = malloc(sizeof *v);

    v->max = 5;
    v->length = 0;
    v->values = (int*)calloc(5, sizeof(int));

    return v;
};

void vector_push(struct vector *v, int n) {
    if (v->length >= v->max) {
        v->max *= 2;
        v->values = realloc(v->values, sizeof(int)*v->max);
    }
    v->length++;
    v->values[v->length-1] = n;
}

int vector_value(struct vector *v, int n) {
    if (n>v->length-1) {
        return 0;
    }
    return v->values[n];
}

void vector_delete(struct vector *v) {
    free(v->values);
    free(v);
}

void vector_set(struct vector *v, int n, int val) {
    while (n >= v->length-1) {
        vector_push(v, 0);
    }
    v->values[n]=val;
}
