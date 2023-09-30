// PID: 730615143
// I pledge the COMP 211 honor code.
#include <stdio.h>
#include <stdlib.h>

// declare constants
const int SHORT_MAX = 32767;
const int SHORT_MIN = -32768;

// put 16 bits from num into a given int array
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
    int num = atoi(argv[argc - 1]); // convert str representation into int
    if (num < 0) num = -num; // turn num into a positive if negative
    int neg = argv[argc - 1][0] == '-'; // neg is true if the first character of input is '-'

    printf("The two's complement 16-bit representation of %s%d is: ", neg ? "-" : "+", num);
    if (num > SHORT_MAX || num < SHORT_MIN) printf("not possible.\n"); // check if num fits in 16 bits
    else
    {
        int* bits = malloc(16 * sizeof(int)); // allocate int array for 16 integers
        b10b2(bits, neg ? -num : num); // pull out 16 bits from num

        // print out bits
        for (int i = 15; i >=0; i--)
        {
            printf("%d", bits[i]);
        }
        printf(".\n");
        free(bits); // free allocated heap memory
    }

    return EXIT_SUCCESS;
}
