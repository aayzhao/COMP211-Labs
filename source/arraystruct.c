// Defines the structs in arraystruct and helper functions.
// Dependent on arrayfill.h
#include <stdio.h>
#include <stdbool.h>
#include "../includes/algo.h"
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

int arrtmax(array_t *arr)
{
    int max_idx = 0;

    if (arr->type == 'i')
    {
        max_idx = arrmax( (int*)arr->a, arr->size);
    }
    else if (arr->type == 'l')
    {
        max_idx = larrmax( (long*)arr->a, arr->size);
    }
    else
    {
        printf("ERROR_INVALID_ARRAY_TYPE");
        return -1;
    }

    return max_idx;   
}

int arrtmin(array_t *arr)
{
    int min_idx = 0;
    if (arr->type == 'i')
    {
        min_idx = arrmin( (int*)arr->a, arr->size);
    }
    else if (arr->type == 'l')
    {
        min_idx = larrmin( (long*)arr->a, arr->size);
    }
    else 
    {
        printf("ERROR_INVALID_ARRAY_TYPE");
        return -1;
    }

    return min_idx;
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

int arrmax(int* arr, int size)
{
    int max_idx = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > arr[max_idx]) max_idx = i;
    }

    return max_idx;
}

int larrmax(long* arr, int size)
{
    int max_idx = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > arr[max_idx]) max_idx = i;
    }

    return max_idx;
}

int arrmin(int* arr, int size)
{
    int min_idx = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < arr[min_idx]) min_idx = i;
    }

    return min_idx;
}

int larrmin(long* arr, int size)
{
    int min_idx = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < arr[min_idx]) min_idx = i;
    }

    return min_idx;
}
