#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdbool.h>
#include "operations.h"

int operations(char* input){
    if(input) {
        if(strcmp(input, "+\0") == 0) {
            // ADDITION
        }
        if(strcmp(input, "-\0") == 0) {
            // SUBTRACTION
        }
        if(strcmp(input, "*\0") == 0) {
            // TIMES
        }
        if(strcmp(input, "/\0") == 0) {
            // DIVISION
        }
        if(strcmp(input, "!\0") == 0) {
            // FACTORIAL
        }
        if(strcmp(input, "^\0") == 0) {
            // TO THE POWER OF...
        }
        if(strcmp(input, "%%\0") == 0) {
            // REMAINDER
        }
    }
    // DEFAULT ACTION
}