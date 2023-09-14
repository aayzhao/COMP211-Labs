// pointer comprehension stuff
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void fizzbuzz(int* x, int* y)
{
    *x = *x * *y;
}

int main() 
{
    int a = 30;
    int* b = &a;
    int c = 15;
//    int d[20] = {0};

//    size_t arr_size = sizeof(d) / sizeof(d[0]);

//    int* ptr = d;
//    for (unsigned long i = 0; i < arr_size; i++)
//    {
//        *ptr = i + 1;
//        printf("%d\n", *ptr);
//        ptr++;
//    }

    printf("\nPre-operations:\n");
    printf("a: %d\n", a);
    printf("b: %d\n", *b);
    printf("c: %d\n", c);

    a -= c;
    fizzbuzz(b, &c);

    printf("\nPost-operations:\n");
    printf("a: %d\nb: %d\nc: %d\n", a, *b, c);

    return EXIT_SUCCESS;
}
