#include <stdio.h>
#include <stdlib.h>
#include "../includes/binops.h"

char* itob(int num, int size)
{   
    char* bstr = malloc(sizeof(char) * (size + 1)); // allocate memory on heap for char buffer
    bstr[size] = '\0'; // set last char to null char

    for (int k = 0; k < size; k++)
    {   
        // shift num by k bits to left, mask last bit, then check
        // if the last bit is 1
        bstr[size - 1 - k] = ((num >> k) & 1) == 1 ? '1' : '0';
    }   

    return bstr;
}

char* ftob(float num, int size)
{   
    char* bstr = malloc(sizeof(char) * (size + 1)); // allocate memory on heap for char buffer
    bstr[size] = '\0'; // set last char to null char

    for (int k = 0; k < size; k++)
    {   
        // shift num by k bits to left, mask last bit, then check
        // if the last bit is 1
        bstr[size - 1 - k] = (( *(int *) &num >> k) & 1) == 1 ? '1' : '0';
    }   

    return bstr;
}

int mask_bits(int num, int mask)
{
    return num & mask; // bitwise AND will mask
}

int set_bits(int num, int bits)
{
    return num | bits; // bitwise OR will set
}

int inverse_bits(int num, int bits)
{
    return num ^ bits; // bitwise XOR inverts
}

int bit_select(int num, int msb, int lsb)
{
    unsigned int ui = (unsigned int) num; // create an unsigned integer to work with

    // shift to left, then shift back to get rid of the bits before our
    // most significant bit (so shift until the MSB itself, i.e. msb - 1)
    ui = ui << (SIZE - msb - 1);
    ui = ui >> (SIZE - msb - 1);
    
    // shift to right, getting rid of bits before least significant bit
    ui = ui >> lsb;

    return (int) ui;
}

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

void printfloat(float f) 
{
    char* str = ftob(f, FLOAT_SIZE);
    printf("Float:\t\t%f\n", f);
    printf("Binary:\t\t%s\n", str);
    printf("Sign:\t\t%c\n", str[0]);
    printf("Exponent:\t");

    for (int i = 1; i < 9; i++)
        putchar(str[i]);

    printf("\n");

    printf("Mantissa:\t%s\n\n", &str[9]);
    
    free(str);    
}


