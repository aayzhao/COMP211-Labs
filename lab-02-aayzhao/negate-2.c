// PID: 730615143
// I pledge the COMP 211 honor code.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    printf("The negation of the 32-bit two's complement integer %s is: ", argv[argc - 1]);
    
    char* str = argv[argc - 1];
    char ch = str[0];
    int len = 0;

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
    for (int i = len - 1; i >= 0; i--)
    {
        if (str[i] == '0') 
        {
            str[i] = '1';
            break;
        }
        else str[i] = '0';
    }

    printf("%s.\n", str);
    return EXIT_SUCCESS;
}
