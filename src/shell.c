// gcc shell.c ./lib/linenoise.c -o shell

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./lib/linenoise.h"

#define PROMPT "$ "
#define HISTORY_LENGTH 1024
#define MAX_ARGS 1024
#define TOKEN_SEPS " \t"

int s_read(char *input, char **args) {
    int i = 0;
    char *token = strtok(input, TOKEN_SEPS); // whitespace and tab are token separators
    while (token != NULL && i < (MAX_ARGS - 1)) {
        args[i++] = token;
        token = strtok(NULL, TOKEN_SEPS);
    }
    args[i] = NULL;
    return i;
}

int main(void) {
    if (!linenoiseHistorySetMaxLen(HISTORY_LENGTH)) {
        fprintf(stderr, "Could not set linenoise history");
        exit(1);
    }

    char *line;
    char *args[MAX_ARGS];
    while((line = linenoise(PROMPT)) != NULL) {
        int args_read = s_read(line, args);
        
        fprintf(stdout, "Read %d args\n", args_read);
        for (int i = 0; i < args_read; i++) {
            fprintf(stdout, "arg[%d] = %s\n", i, args[i]);
        }

        //skip empty lines 
        if (args_read == 0) {
            linenoiseFree(line);
            continue;
        }

        linenoiseHistoryAdd(line);
        linenoiseFree(line);
    }
    return 0;
}