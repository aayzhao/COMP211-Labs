#include <stdlib.h>
#include <stdio.h>
#include "../includes/algo.h"
#include "../includes/arraystruct.h"
#include "../includes/output.h"
#include "../includes/binops.h"

int main(int argc, char** argv)
{
    hashset_t* set = create_hashset();
    hashset_add(set, 0);
    hashset_add(set, -47);
    hashset_add(set, 81);
    hashset_add(set, 10);
    hashset_add(set, 9);
    hashset_add(set, 1000);
    hashset_add(set, 692);
    hashset_add(set, 99112);
    hashset_add(set, 291);
    hashset_add(set, 2299222);
    hashset_add(set, 1);
    hashset_add(set, -12);
    hashset_add(set, -2);
    hashset_add(set, 13);
    hashset_add(set, 29);
    hashset_add(set, 53);
    hashset_add(set, 59);
    hashset_add(set, 101);
    hashset_add(set, 3301);
    hashset_add(set, 52);
    hashset_add(set, -53);
    hashset_add(set, 3);
    hashset_add(set, 5);
    hashset_add(set, -5);
    hashset_add(set, -13);

    printf("Contains 10: %s\n", hashset_contains(set, 10) ? "true" : "false");
    printf("Contains 9: %s\n", hashset_contains(set, 9) ? "true" : "false"); 
    printf("Contains -12: %s\n", hashset_contains(set, -12) ? "true" : "false");
    printf("Contains 0: %s\n",  hashset_contains(set, 0) ? "true" : "false");
    printf("Contains 53: %s\n", hashset_contains(set, 53) ? "true" : "false");
    printf("Contains 103: %s\n", hashset_contains(set, 103) ? "true" : "false");
    printf("Contains -53: %s\n", hashset_contains(set, -53) ? "true" : "false");

    printhashset(set);

    return EXIT_SUCCESS;
}
