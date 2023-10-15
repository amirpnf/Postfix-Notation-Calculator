#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/readline.h>
#include <stdbool.h>

#define MAX_SIZE 64

typedef struct stack {
    int data[MAX_SIZE];
    int top;
    int size;
} Stack;

void initialize_Stack(Stack* stack) {
    stack->top = -1;
}

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
        return 0;
    }
}

bool isNumerical(char* str) {
    if(str == NULL || *str == '\0') {
        return false;
    }

    int i = 0;
    if(str[0] == '_') {
        if(str[1] == '\0')
            return false;
        i = 1;    
    }

    for(; str[i] != '\0'; i++) {
        if(str[i] < '0' || str[i] > '9')
            return false;
    } 
    return true;
}

int main(int argc, char* argv[]) {

    char* input;
    Stack* stack;
    stack = (Stack*)malloc(sizeof(Stack) * MAX_SIZE);
    if(!stack) {
        fprintf(stderr, "stack allocation failed \n");
        exit(1);
    }
    
    while(1) {
        input = readline("> ");
        if(!input)
            break;
        if(strlen(input) == 0) {
            free(input);
            continue;
        }    
        char* token = strtok(input, " ");
        while(token) {
            if(isNumerical(token)) {
                push(stack, atoi(token));
            }
            else {
                switch (token[0])
                {
                case 'p':
                    print_Top(*stack);
                    break;
                
                case 'q':
                    exit(0);
                }
            }
        }
    }
    
    return 0;
    
}