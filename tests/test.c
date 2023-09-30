#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/output.h"
#include "../includes/arrfill.h"
#include "../includes/arraystruct.h"
#include "../includes/algo.h"
#include "../includes/binops.h"

int main()
{
    heap_t* heap = create_heap(10);

    push(heap, 5);
    printintarr(heap->arr, heap->size);
 
    push(heap, 10);
    printintarr(heap->arr, heap->size);
 
    push(heap, -1);
    printintarr(heap->arr, heap->size);

    push(heap, 212);
    printintarr(heap->arr, heap->size);
 
    push(heap, -29);
    printintarr(heap->arr, heap->size);
 
    push(heap, 123);
    printintarr(heap->arr, heap->size);
 
    push(heap, 59);
    printintarr(heap->arr, heap->size);
 
    push(heap, 0);
    printintarr(heap->arr, heap->size);
    
    push(heap, 12);
    printintarr(heap->arr, heap->size);
    
    push(heap, 89);
    printintarr(heap->arr, heap->size);
    
    while (heap->size > 0)
    {
        printf("%d ", pop(heap));
    }

    printf("\n");

    destroy_heap(heap);
    return EXIT_SUCCESS;
}
