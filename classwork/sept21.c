#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/arrfill.h"
#include "../includes/output.h"

int main()
{
    //int* ptr = (int*) malloc(100*sizeof(int));
    
    //fill(ptr, 100, 42);
    
    //printintarr(ptr, 100);
    //printf("Pointer after malloc: %p\n", (void*) ptr);

    //free(ptr);
    //printf("Pointer after free: %p\n", (void*) ptr);
    int A[] = { 1, 2, 3, 4, 5 };
    printf("%lu\n", A);
        
    char str[] = "0123456789";
    char* p = str;
    p++;
    printf("%s\n", str);
    printf("%s\n", p);
    printf("%c\n", *p);
    printf("%c\n", p[-1]);
    printf("%c\n", p[0]);

    return EXIT_SUCCESS;
}
