#include <stdio.h>
#include <stdlib.h>
#include "../includes/arrfill.h"

void fillasc(int arr[],     // output: array 
             int size,      // input: array size
             int val)       // input: value to fill from
{
    int _val = val;
    for (int i = 0; i < size; i++)
    {
        arr[i] = _val++;
    }

    return;
}

void filldesc(int arr[],    // output: array 
              int size,     // input: array size
              int val)      // input: value to fill from
{
    int _val = val;
    for (int i = 0; i < size; i++)
    {
        arr[i] = _val--;
    }

    return;
}

void fill(int arr[],        // output: array
          int size,         // input: array size
          int val)          // input: value to fill array with
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = val;
    }
}
