// PID: 730615143
// I pledge the COMP 211 honor code.
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main()
{
    char c; // character var to store input
    int col = 0; // counter to track which column we are printing to
    int line = 0; // counter to track which line we are copying
    
    int trunc[100] = {0}; // array to hold offending line numbers
    int idx = 0; // counter to track index of trunc to write to
    trunc[0] = -1;

    while ((c = getchar()) != EOF) { // checks to see if End Of File is reached
        col++;
        
        if (c == '\n') // check for new line
        {
            col = 0;
            line++;
        }
        else if (col == 51) // check if 51st column is reached
        {
            putchar('\n');
            col = 1; // reset to 1 as we print char on NL
            // add line num to array if not already
            if (idx == 0 || trunc[idx - 1] != line) 
            {
                trunc[idx++] = line;
            }
        }

        putchar(c);
    }
    //print out details
    printf("\nTotal lines over 50 chars: %d\n", idx);
    printf("Offending lines: ");
    for (int i = 0; i < idx; i++)
    {
        printf("%d, ", trunc[i]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}
