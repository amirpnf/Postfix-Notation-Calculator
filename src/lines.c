#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "lines.h"

int options(char* input) {
    if(input) {
        if(strcmp(input, "p\0") == 0) {
            return PRINT;
        }
        if(strcmp(input, "a\0") == 0) {
            return ALL;
        }
        if(strcmp(input, "r\0") == 0) {
            return REVERSE;
        }
        if(strcmp(input, "q\0") == 0) {
            return QUIT;
        }
        if(strcmp(input, "c\0") == 0) {
            return CLEAR;
        }
    }    
    return FINISH;
}


void line_parser(char* input) {
    char* token = strtok(input, " ");
    while(token != NULL) {
        // REQUIRED RESPONSE
        token = strtok(NULL, " ");
    }
}

