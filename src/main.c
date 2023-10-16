#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdbool.h>
#include "stack.h"
#include "readline.h"



int main(int argc, char* argv[]) {

    char* input;
    Stack* stack;
    stack = (Stack*)malloc(sizeof(Stack) * MAX_SIZE);
    if(!stack) {
        fprintf(stderr, "Stack allocation failed \n");
        exit(1);
    }
    initialize_Stack(stack);
    while(input) {
        
    }
}
