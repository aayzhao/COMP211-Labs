#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    size_t len;
    char *str[1024];
} string;

int main ()
{
    char str[1024];

    fgets(str, 1024, stdin);
//    ret = memchr(str, '\n', strlen(str));
    string s = {strlen(str), {str}};

    size_t size = s.len;

    printf("\nSize of input string: %lu\n", size);
//    printf("Input string: %s\n", s.str);

    

    return EXIT_SUCCESS;
}
