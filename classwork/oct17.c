#include "../includes/algo.h"
#include "../includes/binops.h"
#include "../includes/output.h"
#include "../includes/arraystruct.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char** argv)
{
    printf("arguments passed: %d\n", argc);
    for (int i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }

    heap_t* heap = create_heap(10);
    if (heap == NULL) return EXIT_FAILURE;
    push(heap, 300);
    printf("%d\n", peek(heap));
    push(heap, -4012);
    push(heap, 2103);
    push(heap, 23);
    push(heap, 4);

    printintarr(heap->arr, heap->cap);
    printintarr(heap->arr, heap->size);
    printf("top pop: %d\n", pop(heap));    
    printintarr(heap->arr, heap->size);

    destroy_heap(heap);
}


