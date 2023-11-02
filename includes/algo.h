// Declarations for various algorthims, such as sorting and search algorithms. Also contains declarations
// for the heap struct, hashset struct, and associated helper functions.
#ifndef ALGO_H
#define ALGO_H

////////////////////////////////////////////////////////
//
// HASHSET STRUCT, HASH FUNCTION, AND HELPER FUNCTION DECLARATIONS
//
////////////////////////////////////////////////////////

// Hashset structs should only be modified using the given methods
// in this header file. Bypassing methods can result in undefined
// behavior. Guarantees O (1) average runtime for add, remove, contains

#define HASHING_CONST32 0x45d9f3b
#define INV_HASHING_CONST32 0x119de1f3
#define DEFAULT_L_FACTOR 0.75
#define DEFAULT_SIZE 16
#define SUCCESS_VAL 1
#define FAIL_VAL 0

// linked list implementation for hash set
typedef struct bucket_node {
    int val;
    struct bucket_node* prev;
    struct bucket_node* next;
} bucket_node_t;

// bucket node functions;
// SHOULD NOT BE TOUCHED BY USER
bucket_node_t* create_bucket_node();
void destroy_bucket_node(bucket_node_t* node);
bucket_node_t* remove_node(bucket_node_t* node, int val);
bucket_node_t* add_node(bucket_node_t* node, int val, int* changed);

typedef struct hash_set {
    bucket_node_t* *arr;
    int cap;
    int size;    
} hashset_t;

// create heap_t with given size and return a pointer to it.
hashset_t* create_hashset();

// destroy a given hashset
void destroy_hashset(hashset_t* set); // pointer to hashset

// HashSet helper functions return FAIL_VAL(if failed, 0 by default), 
// SUCCESS_VAL(1 by default) if successful

// attempts to add a number to hashset, returns SUCCESS_VAL if success
// FAIL_VAL otherwise
int hashset_add(hashset_t* set,     // hashset pointer
                int val);           // value to be added

// Checks if the set contains the specified number
// returns SUCCESS_VAL if true, FAIL_VAL if false
int hashset_contains(hashset_t* set,// hashset pointer 
                     int val);      // value to check if contained

// attempts to remove a value, if present. Returns SUCCESS_VAL if 
// successful, FAIL_VAL otherwise
int hashset_remove(hashset_t* set,  // hashset pointer
                   int val);        // value to remove

// returns SUCCESS_VAL if hashset is empty, FAIL_VAL otherwise
int hashset_is_empty(hashset_t* set);   // hashset pointer

////////////////////////////////////////////////////////
//
// HEAP STRUCT AND HELPER FUNCTION DECLARATIONS
//
////////////////////////////////////////////////////////

// Heaps should only be modified using the given methods
// in this header file
// Modification bypassing methods can result in
// undefined behavior
// max heap by default. Handles ints. Guarantees O (log n) runtime for pop, push
typedef struct heap {
    int *arr;               // array backing the heap
    int cap;                // capacity of the heap
    int size;               // number of elements in heap
} heap_t;

// heapify the array inside heap_t if not already in heap form.
void heapify(heap_t *heap); // output: heap struct

// push given element into array, return 1 (true) if successful, 0 (false) if not
int push(heap_t *heap,      // input: heap struct 
         int elem);         // input: element to push

// pop head of the heap, return 0 if heap is empty
int pop(heap_t *heap);      // input: heap struct

// return head of heap without popping it.
int peek(heap_t* heap);     // input: heap struct

// return 1 (true) if heap is empty, else 0 (false)
int heap_empty(heap_t* heap); // input: heap struct

// create heap_t with given size and return a pointer to it.
heap_t* create_heap(int size);  // size of heap

// destroy and deallocate give heap struct pointer
void destroy_heap(heap_t* heap);// pointer to heap

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

// returns the number of appearances of a given element in int array.
int counti(int *arr,        // input: array to count
          int size,         // input: size of array
          int elem);        // input: element to count

// returns numbers of appearances of a given element in long array.
int countl(long *arr,       // input: array to count
           int size,        // input: size of array
           long elem);      // input: element to count

// returns max element in a given array
int arr_max(int *arr,       // input: array to search
            int size);      // input: size of array 

// returns min element in a given array
int arr_min(int *arr,       // input: array to search
            int size);      // input: size of array

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

// fills entire long array starting from index 0, with numbers starting from specified value and ascending
void lfillasc(long arr[],   // output: array to be filled
              int size,     // input: size of array
              long val);    // input: value to fill array from, inclusive

// fills entire long array starting from index 0, with numbers starting from specified value and descending
void lfilldesc(long arr[],  // output: array to be filled
               int size,    // input: size of array
               long val);   // input: value to fill array from, inclusive

// fills entire array of long integers with specified value
void lfill(long arr[],      // output: array to be filled
           int size,        // input: size of array
           long val);       // input: value to fill array with

#endif
