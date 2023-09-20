#include <stdio.h>
#include <stdlib.h>
#include "../includes/algo.h"

void bubbledown(int* arr, int idx, int to);
void lbubbledown(long* arr, int idx, int to);
void dequeue(int* arr, int from, int to);
void ldequeue(long* arr, int from, int to);

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
