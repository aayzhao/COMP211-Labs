// Defines the array struct and helper functions for manipulating arrays
#ifndef ARRAYSTRUCT_H
#define ARRAYSTRUCT_H

#include <stdbool.h>

typedef struct array 
{
    char type;
    void* a;
    int size;
} array_t;

// commands for array_t will have some form of 't' to denote them

// fills array with a specified value. If given an int it will automatically demote the int to a long
void arrtfill(array_t *arr, // output: array to be filled 
              long val);    // input: value to fill array with

// returns index (0-indexed) of max value in given array_t struct
int arrtmax(array_t *arr);  // input: array to find max in

// returns index (0-indexed) of min value in given array_t struct
int arrtmin(array_t *arr);  // input: array to find min in

// returns a string for the type of array stored in an array_t struct
const char* arrtstr(array_t *arr);

// checks that a given char is a valid type
bool validt(array_t *arr);

// commands that can be called on specific arrays not wrapped in structs do not have an 'arrt' to denote them

// returns index of max value in a given int array
int arrmax(int *arr,        // input: array to search
           int size);       // input: size of array

// returns index of max value in a given long array
int larrmax(long *arr,      // input: array to search 
            int size);      // input: size of array

// returns index of min value in a given int array
int arrmin(int *arr,        // input: array to search
           int size);       // input: size of array

// returns index of min value in a given long array
int larrmin(long *arr,      // input: array to search
            int size);      // input: size of array

#endif
