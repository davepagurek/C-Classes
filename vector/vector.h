#ifndef _VECTOR_H
#define _VECTOR_H

struct vector {
    int* values;
    int length;
    int max;
};

struct vector* vector_create();

void vector_push(struct vector *v, int n);

int vector_value(struct vector *v, int n);

void vector_delete(struct vector *v);

void vector_set(struct vector *v, int n, int val);

#endif // _VECTOR_H
