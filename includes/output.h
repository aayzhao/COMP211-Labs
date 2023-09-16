// Contains declarations for functions that print different types of variables to console for debugging
#ifndef OUTPUT_H
#define OUTPUT_H

// prints the specified int array, starting from index 0 to size - 1 inclusive
void printintarr(int arr[],     // input: array to be printed 
                 int size);     // input: size of array

// prints the specified array with extra formatting and details
void printarrdet(int arr[],     // input: array to be printed 
                 int size);     // input: size of array

// prints the specified long array, starting from index 0 to size - 1 inclusive
void printlongarr(long arr[],   // input: array to be printed
                  int size);    // input: size of array

// prints the specified long array with extra formatting and details
void printlarrdet(long arr[],   // input: array to be printed
                  int size);    // input: size of array

#endif
