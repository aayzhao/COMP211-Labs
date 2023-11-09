#include <stdio.h>
#include <stdlib.h>

int leet (int a) {

    int b = a & 0x0000FFFF;
    return b | 0x13370000;

}

int foo (int a, int b) {
    int c = a << (4*4);
    int d = b >> (4 * 3);

    c = c & 0xFFF00000;
    d = d & 0x000FFFF0;
    d = d | 0x00000009;

    return c + d;
}

int main()
{
    int a = 0xc001ca75;
    int b = 0xcafec0c0;
    int c = leet(b);
    int d = foo(a,b);

    printf("%X\n", c);
    printf("%X\n", d);
    return EXIT_SUCCESS;
}
