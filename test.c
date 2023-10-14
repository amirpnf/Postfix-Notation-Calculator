#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/readline.h>

#define MAX_SIZE 64

typedef struct stack {
    int data[MAX_SIZE];
    int top;
    int size;
} Stack;

void print_Top(Stack stack) {
    if(stack.size > 0) {
        printf("%d \n", stack.data[stack.top]);
    } else {
        fprintf(stderr, "There's nothing in the stack \n");
    }
}

void push(Stack* stack, int number) {
    if(stack->size < MAX_SIZE) {
        stack->data[++(stack->top)] = number;
    } else {
        fprintf(stderr, "The stack is full \n");
    }
}

int pop(Stack* stack) {
    if(stack->top >= 0) {
        return stack->data[(stack->top)--];
    } else {
        fprintf(stderr, "There's nothing in the stack \n");
    }
}

int main(int argc, char* argv[]) {

    char* array = (char*)malloc(sizeof(char) * MAX_SIZE);
    if(!array) {
        fprintf("Memory allocation failed");
        exit(1);
    }

    rl_initialize();
    char* command = (char*)malloc(sizeof(char) * 128);
    while(1) {
        char* command = readline("Enter something : ");
        printf("%s \n", command);
    }
    free(command);
    return 0;
}