#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdbool.h>
#include "stack.h"
#include "lines.h"


int main(int argc, char* argv[]) {

    Stack* stack = (Stack*)malloc(sizeof(stack));
    char* input = (char*)malloc(sizeof(char) * 64);
    if(!input || !stack) {
        fprintf(stderr, "input or stack allocation failed \n");
        exit(-1);
    }

    input = readline(">  ");
    while(input != NULL) {
        cases(stack, input);
        input = readline(">  ");
    }
    free_stack(stack);
    free(input);
    return 0;
}
