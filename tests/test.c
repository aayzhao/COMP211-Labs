#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/output.h"
#include "../includes/arrfill.h"
#include "../includes/arraystruct.h"

int main()
{
    int arr[] = { 20, 1, 52, -1, -23, 2, 401, 5, 9, 102 };
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Min value in array:\t%d\n", arr[arrmin(arr, size)]);
    printf("Max value in array:\t%d\n", arr[arrmax(arr, size)]);
    printf("Size of array:\t\t%d\n", size);
    
    return EXIT_SUCCESS;
}
