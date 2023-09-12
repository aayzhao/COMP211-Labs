#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int x;
    int y;
} pair_t;

int main()
{
    pair_t op = {0, 0};
    
    printf("Enter x: \n");
    scanf("%d", &op.x);
    printf("Enter y: \n");
    scanf("%d", &op.y);    

    //putchar(op.x + '0');
    printf("\nOrdered Pair: (%d,%d)\n", op.x, op.y);

    return EXIT_SUCCESS;
}
