#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int a = 10;
    int b = 20;
    for ( ; a < b ; a++)
    {
        b--;
    }
    printf( "(%d,%d)\n", a, b);

    return 0;
}
