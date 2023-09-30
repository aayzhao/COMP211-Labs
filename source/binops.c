#include <stdio.h>
#include <stdlib.h>
#include "../includes/binops.h"

void printsib2(int b10)
{
    int seen = 0;
    int bit;
    int bits[32] = {0};

    for (bit = 0; bit < 32; bit++)
    {
        int mask = 1 << bit;
        int mask_n = b10 & mask;
        int res = mask_n >> bit;
        bits[bit] = res;
    }

    for (int i = 30; i >= 0; i--)
    {
        if (bits[i]) seen = 1;
        if (seen) printf("%d", bits[i]);
    }

    printf("\n");
}

void printuib2(unsigned int b10)
{
    int seen = 0;
    int bit;
    int bits[32] = {0};

    for (bit = 0; bit < 32; bit++)
    {
        int mask = 1 << bit;
        int mask_n = b10 & mask;
        int res = mask_n >> bit;
        bits[bit] = res;
    }

    for (int i = 30; i >= 0; i--)
    {
        if (bits[i]) seen = 1;
        if (seen) printf("%d", bits[i]);
    }

    printf("\n");
}
