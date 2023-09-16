// defines functions declared in output.h
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../includes/output.h"
void printintarr(int arr[], int size)
{
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return;
}

void printarrdet(int arr[], int size)
{
    printf("\nSize of array: %d\nArray Contents: { ", size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("}\n");
    
    return;
}

void printlongarr(long arr[], int size)
{
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%ld ", arr[i]);
    }
    printf("\n");

    return;
}

void printlarrdet(long arr[], int size)
{
    printf("\nSize of array: %d\nArray Contents: { ", size);
    for (int i = 0; i < size; i++)
    {
        printf("%ld ", arr[i]);
    }
    printf("}\n");

    return;
}

