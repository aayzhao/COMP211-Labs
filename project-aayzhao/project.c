// ----------------------------------------------
//
#include "shell.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -----------------------------------
// Main function
int main(int argc, char** argv) {
    int cmd_cnt = 0;
    char shell_cmd[101] = "\0";         // maximum length of command 100 characters + 1 for '\0'
    command_t command;

    while(true){
        printf("(%d)$ ", cmd_cnt++);                  // print the prompt
        fgets(shell_cmd, 100, stdin);               // read command
        shell_cmd[strcspn(shell_cmd, "\n")] = 0;      // remove newline
        parse(shell_cmd, &command);                 // create the command_t structure

        // Execute command
        if (command.argc > 0 ) {
            if (execute( &command ) == ERROR) {
                fprintf(stderr, "%s command failed\n", shell_cmd);
            }
        }

        cleanup(&command);                            // unallocate memory
    }

    return 0;

} // end main function
