// PID: 730615143
// I pledge the COMP 211 honor code.
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main()
{
    
    char c; // tracks current char

    while ((c = getchar()) != EOF) // check if End Of File is reached
    {
        if (64 < c && c < 91) c += 32; // if 64 < c < 91, c is an uppercase char
        putchar(c);
    } 

    
    return EXIT_SUCCESS;
}
