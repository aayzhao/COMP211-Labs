// Declarations for various algorthims, such as sorting algorithms
#ifndef ALGO_H
#define ALGO_H

// sorts a given array in place, in ascending order, starting from indices int from to int to, inclusive
void heapsort(int *arr,     // output: array to sort
              int from,     // input: index to start sorting from (inclusive)
              int to);      // input: index to sort to (inclusive)

// sorts a given long array in place, in ascending order, starting from indices int from to int to, inclusive
void lheapsort(long *arr,   // output: array to sort
               int from,    // input: index to start sorting from (inclusive)
               int to);     // input: index to sort to (inclusive)

#endif
