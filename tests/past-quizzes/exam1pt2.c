#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/output.h"
#include "../includes/arrfill.h"
#include "../includes/arraystruct.h"
#include "../includes/algo.h"
/*
int mystery(char* s) {
    char* t;
    for (t = s; *t != '\0'; t++);
    return t-s;
}

int foo(double x)
{
    if (x == 5) {
        int output = 100;
    } else {
        int output = -100;
    }

    return output;
}
*/
typedef struct {
    int count;
    int* numbers;
} sizedList;

int main(int argc, char **argv)
{
    int* i;
    int size = sizeof(i);
    printf("%d\n", size);
    /*
    int* arr = malloc( 6 * sizeof(int));
    int output = 1;    
    arr[0] = 9;
    arr[1] = 8;
    arr[2] = 7;
    arr[3] = 6;
    arr[4] = 5;
    arr[5] = 4;

    int x = 3;
    int* p = &arr[2];

    arr[0] = 0; printintarr(arr, 6);
    *p = 1; printintarr(arr, 6);
    p--;
    p[x] = 2;
    arr[p[x]] = 3; printintarr(arr, 6);

    free(arr);

    char string0[]  = "COMP Joke:";
    char string1[] = "What is a C programmer's favorite kind of dog?";
    
    int mysteryInt = mystery(string0);

    printf("%d\n", mysteryInt);
    char* int2 = string0;
    int2++;
    int res = int2 - string0;
    printf("%d\n", res);
    */
    sizedList myList;
    sizedList* myPointer = &myList;
    myList.count = 6;
    
    int* arr = malloc(myList.count * sizeof(int));
    arr[1] = 10;

    myList.numbers = arr;

    printf("1. %s\n", argv[1]);
    printf("2. %s\n", argv[2]);
    printf("3. %i\n", argc);

    free(arr);
    return EXIT_SUCCESS;



}
