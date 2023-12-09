#include <stdio.h>
#include <stdlib.h>
#include "../includes/algo.h"
#include "../includes/arraystruct.h"
#include "../includes/binops.h"
#include "../includes/output.h"
int a[300];

int main(int argc, char** argv)
{
    float f1 = 1.5;
    float f2 = 3.4;
    float f3 = 5.125;
    printfloat(f1); 
    printfloat(f2);
    printfloat(f3);

    f1 *= -1;
    printfloat(f1);
    
    printf("%d", argc);
    printf("%s", argv[0]);
}
