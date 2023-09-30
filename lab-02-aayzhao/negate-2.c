// PID: 730615143
// I pledge the COMP 211 honor code.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    printf("The negation of the 32-bit two's complement integer %s is: ", argv[argc - 1]);
    
    char* str = argv[argc - 1];
    int len = 0; // counter for length of str
    
    // negate all bits
    while (str[len] != '\0')
    {
        if (str[len] == '0')
        {
            str[len] = '1';
        }
        else if (str[len] == '1')
        {
            str[len] = '0';
        }
        len++;
    }
    // add 1 to the string representation
    for (int i = len - 1; i >= 0; i--)
    {
        if (str[i] == '0') 
        {
            str[i] = '1';
            break;
        }
        else str[i] = '0';
    }

    printf("%s.\n", str); // print out string
    return EXIT_SUCCESS;
}
