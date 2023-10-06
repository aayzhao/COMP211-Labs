// PID: 730615143
// I pledge the COMP 211 honor code.
#include <stdio.h>
#include <stdlib.h>

// declare constants
#define SHORT_MAX 32767
#define SHORT_MIN -32767 // short min value in 16 bits without two's complement is -32767 

// pull out 16 bits from given int num
void b10b2(int* bits, int num)
{   
    int k;
    int mask;
    int mask_n = 0;

    for (k = 0; k < 16; k++)
    {
        mask = 1 << k;
        mask_n = mask & num;
        bits[k] = mask_n >> k;
    }   
}

int main(int argc, char** argv)
{
    int num = atoi(argv[argc - 1]); // convert str into int
    if (num < 0) num = -num; // if num is negative, convert to positive
    int neg = argv[argc - 1][0] == '-'; // neg is true if first char of input is '-'

    printf("The signed 16-bit representation of %s%d is: ", neg ? "-" : "+", num);
    if (num > SHORT_MAX || num < SHORT_MIN) printf("not possible.\n"); // check that num fits into 16 bits
    else
    {
        int* bits = malloc(16 * sizeof(int)); // allocate int array for 16 integers
        b10b2(bits, num); // pull out 16 bits from num
        bits[15] = neg;
        
        // print out bits
        for (int i = 15; i >=0; i--)
        {
            printf("%d", bits[i]);
        }
        printf(".\n");
        free(bits); // free allocated memory on heap
    }

    return EXIT_SUCCESS;
}
