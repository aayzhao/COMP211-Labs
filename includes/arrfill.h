// Functions for filling arrays are declared here
#ifndef ARRFILL_H
#define ARRFILL_H

// fills entire array starting from index 0, with numbers starting from specified value and ascending
void fillasc(int arr[],     // output: array to be filled
             int size,      // input: size of array
             int val);      // value to fill array from, inclusive 

// fills entire array starting from index 0, with numbers starting from specified value and descending
void filldesc(int arr[],    // output: array to be filled
              int size,     // input: size of array
              int val);     // input: value to fill array from, inclusive

// fills entire array with the specified value
void fill(int arr[],        // output: array to be filled
          int size,         // input: size of array
          int val);         // input: value to fill array with

// fills entire array of long integers with specified value
void lfill(long arr[],      // output: array to be filled
           int size,        // input: size of array
           long val);        // input: value to fill array with

#endif
