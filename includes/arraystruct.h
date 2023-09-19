#ifndef ARRAYSTRUCT_H
#define ARRAYSTRUCT_H

#include <stdbool.h>

struct array 
{
    char type;
    void* a;
    int size;
};
typedef struct array array_t;

void arrayfill(array_t *arr, long val);
const char* arrtstr(array_t *arr);
bool validt(array_t *arr);

#endif
