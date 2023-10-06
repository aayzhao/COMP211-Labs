#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/output.h"
#include "../includes/arraystruct.h"
#include "../includes/algo.h"
#include "../includes/binops.h"

int main()
{
    short x = 0x0037;
    short y = 0x009B;    
    
    short z = x & y;
    printf("%d\n", z);
    
    short a = -32768;
    short b = a + (a + 1);
    printf("%d\n", b);

    return EXIT_SUCCESS;
    
}
