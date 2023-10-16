#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

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

void print_stack(Stack stack) {
    if(stack.top == -1) {
        fprintf(stderr, "Your stack is empty \n");
        return;
    }
    for(int i = stack.top; i >= 0; i--) {
        printf("%d \n", stack.data[i]);
    }
}