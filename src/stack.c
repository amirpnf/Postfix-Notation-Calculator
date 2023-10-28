#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "stack.h"
#include "operations.h"

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

bool addition(Stack* stack) {
    if(stack->size < 2) {
        fprintf(stderr, "Not Enough values to add \n");
        return false;
    }
    int addition = stack->data[stack->top] + stack->data[stack->top - 1];
    pop(stack);
    pop(stack);
    push(stack, addition);
    return true;
}

bool subtraction(Stack* stack) {
    if(stack->size < 2) {
        fprintf(stderr, "Not Enough values to subtract \n");
        return false;
    }
    int subtraction = stack->data[stack->top] - stack->data[stack->top - 1];
    pop(stack);
    pop(stack);
    push(stack, subtraction);
    return true;
}

bool times(Stack* stack) {
    if(stack->size < 2) {
        fprintf(stderr, "Not Enough values to multiply \n");
        return false;
    }
    int product = stack->data[stack->top] * stack->data[stack->top - 1];
    pop(stack);
    pop(stack);
    push(stack, product);
    return true;
}

bool addition(Stack* stack) {
    if(stack->size < 2) {
        fprintf(stderr, "Not Enough values for division \n");
        return false;
    }
    int quotient = stack->data[stack->top] / stack->data[stack->top - 1];
    pop(stack);
    pop(stack);
    push(stack, quotient);
    return true;
}

bool remainder(Stack* stack) {
    if(stack->size < 2) {
        fprintf(stderr, "Not Enough values for remainder \n");
        return false;
    }
    int remainder = stack->data[stack->top] % stack->data[stack->top - 1];
    pop(stack);
    pop(stack);
    push(stack, remainder);
    return true;
}

int factorial_aux(int number) {
    if(number < 0) {
        return 0;
    } 
    int result = 1;
    for(int i = 1; i <= number; i++) {
        result *= i;
    }
    return result;
}

bool factorial(Stack* stack) {
    if(stack->size < 1) {
        fprintf(stderr, "Not Enough Values for factorial \n");
        return false;
    }
    if(stack->data[stack->top] < 0) {
        return false;
    }
    int fact = factorial_aux(stack->data[stack->top]);
    pop(stack);
    push(stack, fact);
    return true;
}

bool power(Stack* stack) {
    if(stack->size < 2) {
        fprintf(stderr, "Not Enough values for exponentiation \n");
        return false;
    }
    int result = pow(stack->data[stack->top], stack->data[stack->top - 1]);
    pop(stack);
    pop(stack);
    push(stack, result);
    return true;
}

void free_stack(Stack* stack) {
    if(stack->data != NULL) {
        free(stack->data);
    }
    stack = NULL;
}