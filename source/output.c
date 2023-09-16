// defines functions declared in output.h
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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
    printf("\nArray Contents: { ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("}\n");
    
    return;
}
