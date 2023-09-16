#include <stdio.h>
#include <stdlib.h>
#include "../includes/arrfill.h"

void fillasc(int arr[], int size, int val)
{
    int _val = val;
    for (int i = 0; i < size; i++)
    {
        arr[i] = _val++;
    }

    return;
}

void filldesc(int arr[], int size, int val)
{
    int _val = val;
    for (int i = 0; i < size; i++)
    {
        arr[i] = _val--;
    }

    return;
}

void fill(int arr[], int size, int val)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = val;
    }
}

void lfill(long arr[], int size, long val)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = val;
    }
}
