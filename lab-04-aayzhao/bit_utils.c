// PID: 730615143
// I pledge the COMP 211 honor code.

#include "bit_utils.h"

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
