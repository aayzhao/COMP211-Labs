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
    push(heap, 10);
    push(heap, -1);
    push(heap, 212);
    push(heap, -29);
    push(heap, 123);
    push(heap, 59);
    push(heap, 0);
    push(heap, 12);
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
