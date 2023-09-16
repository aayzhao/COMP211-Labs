#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int length;
    int width;
    int height;
} box;

int p = 211;
void foo()
{
    p += 100;
}

void bar()
{
    foo();
}

int main()
{
    int array[10];
    array[9] = '\0';

    // printf("%d\n", arr[9]);
    
    // char movie[] = "finding nemo";
    // char mystery[100];
    // strcpy(mystery, movie);
    // printf("%d\n", strlen(movie));
    // printf("%d\n", sizeof(movie) / sizeof(movie[0]));
    // printf("%d\n", strlen(mystery));
    // printf("%d\n", sizeof(mystery) / sizeof(mystery[0]));
    
    int i = 2;
    int arr[7] = {9, 8, 7, 6, 5, 4, 3};

    arr[++i] = 0;
    printf("\nLine 7 execution: ");
    for (int j = 0; j < 7; j++)
    {
        printf("%d ", arr[j]);
    }

    arr[3] = 1;
    printf("\nLine 8 execution: ");
    for (int j = 0; j < 7; j++)
    {
        printf("%d ", arr[j]);
    }
    
    arr[i] = i + 3;
    arr[i += 3] = -3;

    printf("\nLine 10 execution: ");
    for (int j = 0; j < 7; j++) 
    {
        printf("%d ", arr[j]);
    }
    printf("\n"); 
    
    char password[] = "S3cr3t!";

    password[0] = 't';
    password[2] = 's';
    password[3] = 't';
    password[4] = '\0';
    
    printf("%s\n", password);
    
    box myBox = {1, 1, 0};
    myBox.height = 2;
    printf("%d\n", myBox.length * myBox.width * myBox.height);
    

    bar();
    printf("%d\n", p);   
    return EXIT_SUCCESS;
}
