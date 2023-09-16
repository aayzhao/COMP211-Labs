#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/output.h"

int main()
{
    int arr[5];
    int size = sizeof(arr) / sizeof(arr[0]);

    printintarr(arr, size);
    printarrdet(arr, size);
    
    

    printf("\nHello, world!\n");

    return EXIT_SUCCESS;
}
