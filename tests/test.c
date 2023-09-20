#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/output.h"
#include "../includes/arrfill.h"
#include "../includes/arraystruct.h"
#include "../includes/algo.h"

int main()
{
    int arr[] = { 20, 1, 52, -1, -23, 2, 401, 5, 9, 102 };
    int size = sizeof(arr) / sizeof(arr[0]);
    
    //printf("Min value in array:\t%d\n", arr[arrmin(arr, size)]);
    //printf("Max value in array:\t%d\n", arr[arrmax(arr, size)]);
    //printf("Size of array:\t\t%d\n", size);
    
    heapsort(arr, 0, size - 1);
    printf("Sorted array:");
    printintarr(arr, size);
    
    long larr[] = { 20, 1, 52, -1, -1000, 3, 13, 204, 509192, -21, -21, -21 };
    int lsize = sizeof(larr) / sizeof(larr[0]);

    printlongarr(larr, lsize);
    lheapsort(larr, 0, lsize - 1);
    printlongarr(larr, lsize);
    
    printf("%d\n", lbinsearch(larr, 0, 11, -21));
    printf("%d\n", binsearch(arr, 0, 9, 3));

    printf("Contains -21:\t%s\n", lbinsearch(larr, 0, 11, -21) != -1 ? "true" : "false");
    printf("Contains 3:\t%s\n", binsearch(arr, 0, 9, 3) != -1 ? "true" : "false");

    return EXIT_SUCCESS;
}
