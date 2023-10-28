#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "stack.h"

void initialize_Stack(Stack* stack) {
    stack->top = -1;
    stack->size = 0;
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
        stack->size++;
    } else {
        fprintf(stderr, "The stack is full \n");
    }
}

int pop(Stack* stack) {
      if(stack->top >= 0) {
        stack->size--;
        return stack->data[(stack->top)--];
    
    } else {
        fprintf(stderr, "There's nothing in the stack \n");
        return 0;
    }
}

bool is_number(char* str) {
    if(*str == '_') {
        str++;
    }
    while(*str) {
        if(*str < '0' || *str > '9') {
            return false;
        }
        str++;
    }
    return true;
}

void print_stack(Stack stack) {
    if(stack.top == -1) {
        fprintf(stderr, "Your stack is empty \n");
        return;
    }
    for(int i = stack.top; i >= 0; i--) {
        printf("%d ", stack.data[stack.size - i - 1]);
    }
    printf("\n");
}

void clear_stack(Stack* stack) {
    if(stack->top == -1) {
        fprintf(stderr, "Stack already empty \n");
        return;
    }
    while(stack->size != 0) {
        pop(stack);
    }
}

void reverse_stack(Stack* stack) {
    if(stack->size < 2) {
        fprintf(stderr, "Not enough elements in stack \n");
        return;
    }
    int tmp = stack->data[stack->top];
    stack->data[stack->top] = stack->data[stack->top - 1];
    stack->data[stack->top - 1] = tmp;
}

void free_stack(Stack* stack) {
    if(stack->data != NULL) {
        free(stack->data);
    }
    free(stack);
    stack = NULL;
}