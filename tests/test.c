#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/output.h"
#include "../includes/arrfill.h"

int main()
{
    int arr[5];
    int size = sizeof(arr) / sizeof(arr[0]);
    
    long larr[10];
    int size_l = sizeof(larr) / sizeof(larr[0]);

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

    // printf("\nHello, world!\n");

    return EXIT_SUCCESS;
}
