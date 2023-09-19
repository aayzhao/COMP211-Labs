#ifndef ARRAYSTRUCT_H
#define ARRAYSTRUCT_H

#include <stdbool.h>

typedef struct array 
{
    char type;
    void* a;
    int size;
} array_t;

void arrayfill(array_t *arr, long val);
const char* arrtstr(array_t *arr);
bool validt(array_t *arr);

#endif
