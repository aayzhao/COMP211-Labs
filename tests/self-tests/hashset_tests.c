// hashset_t testing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/output.h"
#include "../includes/arraystruct.h"
#include "../includes/algo.h"
#include "../includes/binops.h"
#include <time.h>

int main()
{
    hashset_t* set = create_hashset();

    printhashset(set);
    
    srand(time(NULL));
    printf("\nAdding up to 100 elements to hashset...\n");
    for (int i = 1; i < 131; i++) {
        int r = rand();
        int idx = hash_func(r) % set->cap;
        printf("Adding %d at bucket %d\n", r, idx);
        hashset_add(set, r);
    }
    
    printhashset(set);
    
    printf("\nAdding 1-256, then checking we can find all of them\n");

    for (int i = 1; i < 257; i++) 
    {
        hashset_add(set, i);
    }

    printf("\nElements added.\n");
    printhashset(set);
    printf("\nChecking 1-256 are in the set...\n");
    
    int flag = 1;
    for (int i = 1; i < 257; i++)
    {
        printf("Checking for %d\n", i);
        if (!hashset_contains(set, i)) 
        {
            printf("%d not found!\n", i);
            flag = 0;
        }
        else printf("Found %d\n", i);
    }

    if (flag) printf("All elements found\n");
    else printf("Element retrieval error\n");
    //return EXIT_SUCCESS; 
    
    destroy_hashset(set);
    
//    return EXIT_SUCCESS;
    set = create_hashset();
    printf("allocated new set successfully\n");
    
//    return EXIT_SUCCESS;
    for (int i = 1; i < 257; i++) 
    {
        printf("Adding element %d\n", i);
        if (i == 39) printhashset(set);
        hashset_add(set, i);
    }
    printhashset(set);
    for (int i = 1024; i < 1024 + 128; i++) hashset_add(set, i);
    printhashset(set);
    for (int i = 1; i < 257; i++)
    {
        printf("Checking for %d\n", i);
        if (!hashset_remove(set, i)) 
        {
            printf("%d not found!i\n", i);
            flag = 0;
        }
    }
    for (int i = 1024; i < 1024 + 128; i++) hashset_remove(set, i);
    printhashset(set);

    return EXIT_SUCCESS;
}
