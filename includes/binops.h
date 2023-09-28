#ifndef BINOPS_H
#define BINOPS_H

// print out the base 2 representation of a signed integer
void printsib2(int b10);            // input: signed integer to be printed

// print out base 2 representation of an unsigned integer
void printuib2(unsigned int b10);   // input: unsigned integer

int b2tob10(char* b2str);           // input: null-terminated string of the binary number

void b10tob2(char* str,             // output: char buffer to put the string in. Must be a size of 33 or greater  
             int b10);              // input: base10 integer to be converted.

#endif
