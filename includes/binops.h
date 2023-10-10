#ifndef BINOPS_H
#define BINOPS_H
// All functions use 2's complement representation for signed integers and longs

#define SIZE sizeof(int) * 8

// Returns pointer to a string that represents num
// in twos complement binary.
char* itob(int num, int size);

// Returns num after mask has been applied.
int mask_bits(int num, int mask);

// Returns num after bits have been set.
int set_bits(int num, int bits);

// Returns num after bits have been inversed.
int inverse_bits(int num, int bits);

// returns the bits in the number from startbit to
// end bit (including startbit and endbit);
int bit_select(int num, int startbit, int endbit);

// print out the base 2 representation of a signed integer
void printsib2(int b10);            // input: signed integer to be printed

// print out base 2 representation of an unsigned integer
void printuib2(unsigned int b10);   // input: unsigned integer

// TODO: UNIMPLEMENTED
// convert base 2 binary string into an int
int b2tob10(char* b2str);           // input: null-terminated string of the binary number

// TODO: UNIMPLEMENTED
// convert base 10 int to string of binary
void b10tob2(char* str,             // output: char buffer to put the string in. Must be a size of 33 or greater  
             int b10);              // input: base10 integer to be converted.

#endif
