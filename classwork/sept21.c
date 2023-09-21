#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/arrfill.h"
#include "../includes/output.h"

int main()
{
    int* ptr = (int*) malloc(100*sizeof(int));
    
    fill(ptr, 100, 42);
    
    printintarr(ptr, 100);
    printf("Pointer after malloc: %p\n", (void*) ptr);

    free(ptr);
    printf("Pointer after free: %p\n", (void*) ptr);

    return EXIT_SUCCESS;
}
