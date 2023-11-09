#include <stdio.h>
#include <stdlib.h>

int main() {
    short a = -3;
    int b = (int) a;
    unsigned short c = (unsigned short) a;
    unsigned short d = (unsigned int) c;

    printf("%hX\n", a);
    printf("%X\n", b);
    printf("%hX\n", c);
    printf("%X\n", d);

    return EXIT_SUCCESS;

}
