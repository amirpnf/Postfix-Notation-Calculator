#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 64

typedef struct stack {
    int* data;
    int top;
    int size;
} Stack;

typedef enum {
    ADDITION,
    SUBTRACTION,
    TIMES,
    DIVIDED_BY,
    REMAINDER,
    FACTORIAL,
    POWER,
} OPERATION;

typedef enum {
    QUIT,
    PRINT,
    CLEAR,
    ALL,
    REVERSE,
    NONE,
    FINISH,
} Response;

int options(char* input) {
    if(input) {
        if(strcmp(input, "p\0") == 0) {
            return PRINT;
        }
        if(strcmp(input, "a\0") == 0) {
            return ALL;
        }
        if(strcmp(input, "r\0") == 0) {
            return REVERSE;
        }
        if(strcmp(input, "q\0") == 0) {
            return QUIT;
        }
        if(strcmp(input, "c\0") == 0) {
            return CLEAR;
        }
    }    
    return FINISH;
}

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
        printf("%d ", stack.data[stack.size - i - 1]);
    }
    printf("\n");
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

bool division(Stack* stack) {
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

bool remainderr(Stack* stack) {
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

int main(int argc, char* argv[]) {

    /*char* input;
    Stack* stack;
    stack = (Stack*)malloc(sizeof(Stack) * MAX_SIZE);
    if(!stack) {
        fprintf(stderr, "Stack allocation failed \n");
        exit(1);
    }
    input = (char*)malloc(sizeof(char) * 64);
    if(!input) {
        fprintf(stderr, "input allocation failed \n");
        exit(-1);
    }
    initialize_Stack(stack);
    while(input) {
        input = readline(">  ");
    }*/
    Stack* stack;
    stack->data = (int*)malloc(sizeof(int) * MAX_SIZE);
    if(!(stack->data)) {
        fprintf(stderr, "Stack Allocation failed \n");
        exit(-1);
    }
    char* input = (char*)malloc(sizeof(char) * 64);
    if(!input) {
        fprintf(stderr, "input allocation failed \n");
        exit(-1);
    }
    initialize_Stack(stack);
    while (input)
    {
        input = readline(">  ");
        if(options(input) == NONE && operations(input) == NONE) {
            // REQUIRED ANSWER
        }
    }
    
    free(stack->data);
    stack = NULL;
    return 0;
}