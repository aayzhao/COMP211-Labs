#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/output.h"
#include "../includes/arrfill.h"
#include "../includes/arraystruct.h"

int main()
{
    /*
    int arr[5];
    int size = sizeof(arr) / sizeof(arr[0]);
    
    long larr[10];
    int size_l = sizeof(larr) / sizeof(larr[0]);
    
    array_t arr_int = { 'i', arr, size };
    array_t arr_struct = { 'l', larr, size_l };
    ((long*) arr_struct.a)[2] = 4;
    printf("test struct: ");
    printlongarr(arr_struct.a, arr_struct.size);

    printintarr(arr, size);
    printarrdet(arr, size);
    
    fill(arr, size, 4);
    printintarr(arr, size);
    fill(arr, size, 0);
    fillasc(arr, size, 0);
    printintarr(arr, size);
    filldesc(arr, size, size - 1);
    printintarr(arr,size);

    lfill(larr, size_l, 60);
    printlongarr(larr, size_l);
    printlarrdet(larr, size_l);
    
    arrtfill(&arr_struct, 81);    
    printlongarr(arr_struct.a, arr_struct.size);
    arrayfill(&arr_int, 67);
    printintarr(arr_int.a, arr_int.size);
    printintarr(arr, size);
    // printf("\nHello, world!\n");

    return EXIT_SUCCESS;
    */
    int arr[] = { 20, 1, 52, -1, -23, 2, 401, 5, 9, 102 };
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Min value in array:\t%d\n", arr[arrmin(arr, size)]);
    printf("Max value in array:\t%d\n", arr[arrmax(arr, size)]);
    printf("Size of array:\t\t%d\n", size);
    
    return EXIT_SUCCESS;
}
