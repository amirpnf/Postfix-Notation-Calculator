#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdbool.h>
#include "stack.h"
#include "lines.h"


int main(int argc, char* argv[]) {

    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(sizeof(int) * MAX_SIZE);
    if (stack->data == NULL)
    {
        fprintf(stderr, "Stack allocation failed \n");
        exit(-1);
    }
    initialize_Stack(stack);
    char* input;
    input = (char*)malloc(64);
    if (!input)
    {
        fprintf(stderr, "String allocation failed \n");
        exit(-1);
    }
    input = readline(">  ");
    while(input != NULL) {
        cases(stack, input);
        input = readline(">  ");
    }
    free_stack(stack);
    return 0;
}    
