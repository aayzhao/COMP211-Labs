#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct {
    int num;
    char word[20];
    bool boolean;
} mytype_t;

int main()
{
    mytype_t my_struct = {20, "Hello, World", true};

    printf("Struct num: %d\nStruct word: %s\nStruct bool: %s\n", my_struct.num, my_struct.word, my_struct.boolean ? "true" : "false");
    
    return EXIT_SUCCESS;
}
