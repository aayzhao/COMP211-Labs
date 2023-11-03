#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/output.h"
#include "../includes/arraystruct.h"
#include "../includes/algo.h"
#include "../includes/binops.h"

void func(double x)
{
    x += 10.0;
    printf("x=%f\n", x);
}

int main()
{
    double* ptr = (double *) malloc( 8 );
    double x = 211.0;
    *ptr = x;
    while (x < 250.0) 
    {
        func(x);
        x += 10.0;
    }

    free(ptr);
    return EXIT_SUCCESS;    
}
