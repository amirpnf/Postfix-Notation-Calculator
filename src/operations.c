#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdbool.h>
#include "operations.h"
#include <math.h>

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

bool division(Stack* stack) {
    if(stack->size < 2) {
        fprintf(stderr, "Not Enough values for division \n");
        return false;
    }
    if(stack->data[stack->top] == 0) {
        fprintf(stderr, "Division by zero ! \n");
        return false;
    }
    int quotient = stack->data[stack->top - 1] / stack->data[stack->top];
    pop(stack);
    pop(stack);
    push(stack, quotient);
    return true;
}

bool remainderr(Stack* stack) {
    if(stack->size < 2) {
        fprintf(stderr, "Not Enough values for remainder \n");
        return false;
    }
    if(stack->data[stack->top] == 0) {
        fprintf(stderr, "Not possible \n");
        return false;
    }
    int remainder = stack->data[stack->top - 1] % stack->data[stack->top];
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