#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/output.h"
#include "../includes/arrfill.h"
#include "../includes/arraystruct.h"
#include "../includes/algo.h"

int inc(int x)
{
    int y = 0;
    y += x;
    return y;
}

int main()
{
    int* ptr = (int*) malloc(100*sizeof(int));
    printf("%p\n", ptr);
    int a = 20;
    free(ptr);
    ptr = NULL;
    
    printf("%d\n", *&a);
    printf("null pointer: %s\n", ptr == NULL ? "true" : "false");
    printf("%p\n", ptr);
    
    printf("y val: %d\n", inc(10)); // 10
    printf("y val: %d\n", inc(30)); // 40
    return EXIT_SUCCESS;
}
