#include <stdio.h>
#include <stdlib.h>

int* func(int x);

int x = 10;

int main() {
    int* arr = func(x);
    for (int i = 0; i < x; i++)
        printf("%d\n", arr[i]);

    return EXIT_SUCCESS;
}
