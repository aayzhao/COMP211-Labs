#include "bit_utils.h"

void debug(int num, int bits, int (*fun)(int, int));
void debug_bitsel(int n, int start, int end);

int main(){
    // test your functions here!

    debug_bitsel(0xE7E7, 3, 0);
    debug_bitsel(0xFFFF, 6, 4);
    return EXIT_SUCCESS;
}

// Function to debug mask_bits, set_bits and inverse_bits.
// Params:  num - number to pass to function
//          bits- bits to apply to num (mask, set, or inverse)
//          fun - name of function to test
// i.e. to test the masking 0xa5 with 0x0f, do:
//      debug(0xa5, 0x0f, mask_bits)
void debug(int num, int bits, int (*fun)(int, int)){
    printf("For integer \t\t0x%x =\t%s\n", num, itob(num, SIZE));
    printf("Applying bits \t\t0x%x = \t%s:\n", bits, itob(bits, SIZE));
    int new_num = fun(num, bits);
    printf("Function returns:  \t0x%x = \t%s\n\n", new_num, itob(new_num, SIZE));
}

// Function to call bit_select and print debug information.
// Params:  n   - number to pass to function
//          start - startbit parameter to pass to bit_select
//          end   - endbit parameter to pass to bit_select
// i.e. calling debug_bitsel(0x0f, 3, 4) is the same as calling bit_select(0x0f, 3, 4)
//      and printing additional debug information.
void debug_bitsel(int n, int start, int end){
    int i = bit_select(n, start, end);
    printf("For int \t\t0x%x = \t%s:\n", n, itob(n, SIZE));
    printf("Keeping bits %i to %i: \t0x%x =  \t%s\n\n", start, end, i, itob(i, SIZE));
}

