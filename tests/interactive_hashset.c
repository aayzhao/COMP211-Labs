// hashset_t testing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/output.h"
#include "../includes/arraystruct.h"
#include "../includes/algo.h"
#include "../includes/binops.h"

void hashcontents(hashset_t* set)
{
    printf("HashSet contents:\n");
    for (int i = 0; i < set->cap; i++)
    {
        if (set->arr[i] != NULL)
        {
            bucket_node_t* it = set->arr[i];
            while (it != NULL) 
            {
                printf("%d ", it->val);
                it = it->next;
            }
        }
    }
    printf("\n");
}

int main()
{
    hashset_t* set = create_hashset();
    int input = -1;
    int flag = 1;
    int res = 0;
    while (flag)
    {
        printf("\nSelect option:\n1. Add Number\n");
        printf("2. Remove Number\n");
        printf("3. Check For Number\n");
        printf("4. Print Hash Set Contents\n");
        printf("5. Print Hash Set Details and Buckets\n");
        printf("6. Exit\n");
        printf("Type option number to select. 0 or 6 to quit\n\n");
        scanf("%d", &input);
    
        switch (input)
        {
            case 0:
                flag = 0;
                break;
            case 1: 
                printf("Input number: ");
                scanf("%d", &input);
                res = hashset_add(set, input);
                if (res == SUCCESS_VAL) printf("\nAdded %d to set\n", input);
                else printf("\nFailed to add %d to set\n", input); 
                break;
            case 2:
                printf("Input number: ");
                scanf("%d", &input);
                res = hashset_remove(set, input);
                if (res == SUCCESS_VAL) printf("\nRemoved %d from set\n", input);
                else printf("\nFailed to remove %d from set\n", input);
                break;
            case 3:
                printf("Input number: ");
                scanf("%d", &input);
                if (hashset_contains(set, input)) printf("Set contains %d\n", input);
                else printf("Set does not contain %d\n", input);
                break;
            case 4:
                hashcontents(set);
                break;
            case 5:
                printhashset(set);
                break;
            case 6:
                flag = 0;
                break;
            default:
                printf("Invalid Option.\n");
        }
    
    }
    printf("\nExiting...\n");
    destroy_hashset(set);

    return EXIT_SUCCESS;
}
