// Defines the structs in arraystruct and helper functions.
// Dependent on arrayfill.h
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../includes/arrfill.h"
#include "../includes/arraystruct.h"

void arrayfill(array_t *arr, long val)
{
    if (arr->type == 'i')
    {
        int _val = (int) val;
        fill( (int*)arr->a, arr->size, _val);
    } 
    else if (arr->type == 'l')
    {
        lfill( (long*)arr->a, arr->size, val);
    }
    else 
    {
        printf("ERROR_INVALID_ARRAY_TYPE");
    }
}

const char* arrtstr(array_t *arr)
{
    if (arr->type == 'i')
    {
        return "int";
    }
    else if (arr->type == 'l')
    {
        return "long";
    }
    else 
    {
        return "invalid_type";
    }
}

bool validt(array_t *arr)
{
    if (arr->type == 'i')
    {
        return true;
    }
    else if (arr->type == 'l')
    {
        return true;
    }
    else 
    {
        return false;
    }
}
