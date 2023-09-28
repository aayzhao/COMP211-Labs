#include <stdio.h>
#include <stdlib.h>
#include "../includes/binops.h"

void printsib2(int b10)
{
    int seen = 0;
    int negative = 0;
    if (b10 < 0) 
    {
        b10 *= -1;
        negative = 1;
    }
    int bit;
    int bits[32] = {0};

    for (bit = 0; bit < 32; bit++)
    {
        int mask = 1 << bit;
        int mask_n = b10 & mask;
        int res = mask_n >> bit;
        bits[bit] = res;
    }

    if (negative) printf("-");
    for (int i = 30; i >= 0; i--)
    {
        if (bits[i]) seen = 1;
        if (seen) printf("%d", bits[i]);
    }

    printf("\n");
}
