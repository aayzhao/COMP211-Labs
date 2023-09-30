#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../includes/algo.h"

void bubbledown(int* arr, int idx, int to);
void lbubbledown(long* arr, int idx, int to);
void dequeue(int* arr, int from, int to);
void ldequeue(long* arr, int from, int to);
void bubbleup(int* arr, int idx);

heap_t* create_heap(int cap)
{
    heap_t* heap = malloc(sizeof(heap_t));
    heap->cap = cap;
    heap->arr = malloc(sizeof(int) * cap);
    heap->size = 0;
    
    return heap;
}

void destroy_heap(heap_t* heap)
{
    if (heap == NULL) return;
    free(heap->arr);
    free(heap);
    heap = NULL;
}

void heapify(heap_t* heap)
{
    int* arr = heap->arr;
    int i = heap->size;    
    
    if (i % 2 == 0) i = (i - 2) / 2;
    else i = (i - 1) / 2;

    for ( ; i >= 0; i--)
    {
        bubbledown(arr, i, heap->size);
    }
}

int push(heap_t* heap, int elem)
{
    int size = heap->size;
    int* arr = heap->arr;
    if (size == heap->cap) return 0;

    arr[size] = elem;
    
    bubbleup(arr, size);
    heap->size++;
    return 1;
}

int pop(heap_t* heap)
{
    if (heap->size == 0) return 0;
    int* arr = heap->arr;
    int head = arr[0];
    
    heap->size--;
    arr[0] = arr[heap->size];
    arr[heap->size + 1] = 0;
    
    bubbledown(arr, 0, heap->size);

    return head;
}

int peek(heap_t* heap)
{
    if (heap->size == 0) return 0;
    else return heap->arr[0];
}

void heapsort(int* arr, int from, int to)
{
    int i = to;
    
    //heapify array section (min heap)
    if (i % 2 == 0) i = (i - 2) / 2;
    else i = (i - 1) / 2;
    
    for ( ; i >= from; i--)
    {
        bubbledown(arr, i, to);
    }

    // dequeue all elements in the pseudo heap
    while (to >= from)
    {
        dequeue(arr, from, to--);
    }
}

void lheapsort(long* arr, int from, int to)
{
    int i = to;
    
    //heapify array section (min heap)
    if (i % 2 == 0) i = (i - 2) / 2;
    else i = (i - 1) / 2;
    
    for ( ; i >= from; i--)
    {
        lbubbledown(arr, i, to);
    }
    
    //dequeue
    while (to >= from)
    {
        ldequeue(arr, from, to--);
    }
}

void bubbledown(int* arr, int idx, int to)
{
    int i = idx;
    int target;
    int left = idx * 2 + 1;
    int right = idx * 2 + 2;
    if (left <= to && right <= to) {
        if (arr[left] > arr[right]) target = left;
        else target = right;
        if (arr[target] > arr[idx]) i = target;
    }
    else if (left <= to) {
        target = left;
        if (arr[target] > arr[idx]) i = target;
    }
    else if (right <= to) {
        target = right;
        if (arr[target] > arr[idx]) i = target;
    }
    
    if (i != idx)
    {
        int temp = arr[idx];
        arr[idx] = arr[i];
        arr[i] = temp;
        bubbledown(arr, i, to);
    }
}

void bubbleup(int* arr, int idx)
{
    if (idx == 0) return;
    int parent = (idx - 1) / 2;
    
    if (arr[idx] > arr[parent]) 
    {
        int temp = arr[idx];
        arr[idx] = arr[parent];
        arr[parent] = temp; 
        bubbleup(arr, parent);    
    }
}

void lbubbledown(long* arr, int idx, int to)
{
    int i = idx;
    int target;
    int left = idx * 2 + 1;
    int right = idx * 2 + 2;
    if (left <= to && right <= to) {
        if (arr[left] > arr[right]) target = left;
        else target = right;
        if (arr[target] > arr[idx]) i = target;
    }
    else if (left <= to) {
        target = left;
        if (arr[target] > arr[idx]) i = target;
    }
    else if (right <= to) {
        target = right;
        if (arr[target] > arr[idx]) i = target;
    }
    
    if (i != idx)
    {
        int temp = arr[idx];
        arr[idx] = arr[i];
        arr[i] = temp;
        lbubbledown(arr, i, to);
    }
}

void dequeue(int* arr, int from, int to)
{
    if (to <= from) return;

    int temp = arr[to];
    arr[to] = arr[from];
    arr[from] = temp;

    bubbledown(arr, from, --to);
}

void ldequeue(long* arr, int from, int to)
{
    if (to <= from) return;

    int temp = arr[to];
    arr[to] = arr[from];
    arr[from] = temp;

    lbubbledown(arr, from, --to);
}

int csorted(int* arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < arr[i - 1]) return 0;
    }
    return 1;
}

int lcsorted(long* arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < arr[i - 1]) return 0;
    }
    return 1;
}

int binsearch(int* arr, int lower, int upper, int target)
{
    int mid = -1;
    upper++;
    while (lower < upper)
    {
        mid = (lower + upper) / 2;
        if (arr[mid] < target)
        {
            lower = mid + 1;
        }
        else if (arr[mid] > target)
        {
            upper = mid;
        }
        else 
        {
            return mid;
        }
    }

    return -1;
}

int lbinsearch(long* arr, int lower, int upper, long target)
{
    int mid = -1;
    upper++;
    while (lower < upper)
    {
        mid = (lower + upper) / 2;
        if (arr[mid] < target)
        {
            lower = mid + 1;
        }
        else if (arr[mid] > target)
        {
            upper = mid;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int counti(int *arr, int size, int elem)
{
    int count = 0;
    for (int i = 0; i < size; i++) if (elem == arr[i]) count++;
    return count;
}

int countl(long *arr, int size, long elem)
{
    int count = 0;
    for (int i = 0; i < size; i++) if (elem == arr[i]) count++;
    return count;
}

int arr_max(int *arr, int size)
{
    int max = INT_MIN;
    for (int i = 0; i < size; i++) if (arr[i] > max) max = arr[i];
    return max;
}

int arr_min(int *arr, int size)
{
    int min = INT_MAX;
    for (int i = 0; i < size; i++) if (arr[i] < min) min = arr[i];
    return min;
}
