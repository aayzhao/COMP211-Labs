#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/algo.h"
#include "../includes/arraystruct.h"
#include "../includes/output.h"
#include "../includes/binops.h"

int main(int argc, char** argv)
{
    short x = 0xFFFC;
    x = x >> 1;
    printf("%d\n", x);

    short y = 0x8000;
    printf("%d\n", y);
    y = y >> 1;
    printf("%d\n", y);

    short z = 0x4000;
    printf("%d\n", z);
    
    short u = z << 1;
    printf("%d\n", u);
    
    double dbl = 0.0;
    int cont = 0;
    printf("%lu\n%lu\n", sizeof(dbl), sizeof(cont));

    return EXIT_SUCCESS;
} 
