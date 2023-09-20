// Declarations for various algorthims, such as sorting and search algorithms
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

// searches a given array for target. Assumes that the array is sorted in ascending order
// Starts the search from index lower to index upper, inclusive. Returns index if target is found,
// otherwise -1.
int binsearch(int *arr,     // input: array to search through
              int lower,    // input: lower bound index of search area
              int upper,    // input: upper bound index of search area
              int target);  // input: int to search for

// searches a given long array for target. Assumes that the array is sorted in ascending order.
// Returns index if found, -1 otherwise.
int lbinsearch(long *arr,   // input: array to search through
               int lower,   // input: lower bound index of search area
               int upper,   // input: upper bound index of search area
               long target);// input: long to search for

// checks if given array is sorted. Returns 1 if true, 0 if false
int csorted(int *arr,       // input: array to check if it's sorted
            int size);      // input: size of array

// checks if given long array is sorted. Returns 1 if true, 0 if false
int lcsorted(long *arr,     // input: array to check if it's sorted
             int size);     // input: size of array

#endif
