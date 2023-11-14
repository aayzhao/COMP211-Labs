#include "bit_utils.h"

char* itob(int num, int size) {
    char* ret = (char*) malloc(size + 1);
    ret[size - 1] = '\0';

    bool is_neg = num < 0;

    // This finds the bit representation for the *absolute value* of num
    for (int i = size - 1; i >= 0; i--) {
        ret[i] = num % 2 == 0 ? '0' : '1';
        num /= 2;
    }

    // If negative, negate the bits found above
    if (is_neg) {
        // Invert digits
        for(int i = 0; i <= size - 1; i++)
            ret[i] = ret[i] == '0' ? '1' : '0';

        // Add one
        for (int i = size - 1; i >= 0; i--) {
            if(ret[i] == '0') {
                ret[i] = '1';
                break;
            } else {
                ret[i] = '0';
            }
        }
    }

    return ret;
}

int mask_bits(int num, int mask){
    return num & mask;
}

int set_bits(int num, int bits){
    return num | bits;
}

int inverse_bits(int num, int bits){
    return num ^ bits;
}

int bit_select(int num, int startbit, int endbit){
    startbit++;

    unsigned int ret = num << (SIZE - startbit);
    ret >>= (SIZE - startbit + endbit);

    return ret;
}

