// Defines the structs in arraystruct and helper functions.
// Dependent on arrayfill.h
#include <stdio.h>
#include <stdbool.h>
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

int arrtmax(array_t *arr)
{
    int max_idx = 0;

    if (arr->type == 'i')
    {
        int* _a = (int*)arr->a;
        for (int i = 1; i < arr->size; i++)
        {
            if (_a[max_idx] < _a[i]) max_idx = i;
        }
    }
    else if (arr->type == 'l')
    {
        long* _a = (long*)arr->a;
        for (int i = 1; i < arr->size; i++)
        {
            if (_a[max_idx] < _a[i]) max_idx = i;
        }
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
        int* _a = (int*)arr->a;
        for (int i = 1; i < arr->size; i++)
        {
            if (_a[i] < _a[min_idx]) min_idx = i;
        }
    }
    else if (arr->type == 'l')
    {
        long* _a = (long*)arr->a;
        for (int i = 1; i < arr->size; i++)
        {
            if (_a[i] < _a[min_idx]) min_idx = i;
        }
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

