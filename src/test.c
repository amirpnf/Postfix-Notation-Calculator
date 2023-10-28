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
    NONE_O,
} Operation;

typedef enum {
    QUIT,
    PRINT,
    CLEAR,
    ALL,
    REVERSE,
    NONE_R,
    FINISH,
} Response;

bool addition(Stack* stack);
bool subtraction(Stack* stack);
bool times(Stack* stack);
bool division(Stack* stack);
bool remainderr(Stack* stack);
int factorial_aux(int number);
bool factorial(Stack* stack);
bool power(Stack* stack);
bool is_number(char* str);
void push(Stack* stack, int number);
void clear_stack(Stack* stack);
void reverse_stack(Stack* stack);
void print_stack(Stack stack);
void print_Top(Stack stack);
// -------------------------

void cases(Stack* stack, char* input) {
    char* token = strtok(input, " ");
    while(token != NULL) {
        if(is_number(token)) {
            push(stack, atoi(token));
        } 
        if(strlen(token) == 1) {
            switch (token[0])
            {
            case '+':
                addition(stack);
                break;
            case '-':
                subtraction(stack);
                break;
            case '*':
                times(stack);
                break;
            case '/':
                division(stack);
                break;
            case '%':
                remainderr(stack);
                break;
            case '^':
                power(stack);
                break;
            case '!':
                factorial(stack);
                break;    
            case 'a':
                print_stack(*stack);
                break;                        
            case 'c':
                clear_stack(stack);
                break;
            case 'p':
                print_Top(*stack);
                break;
            case 'q':
                exit(0);
                break;
            case 'r':
                reverse_stack(stack);
                break;              
            }
        }    
    token = strtok(NULL, " ");    
    }
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
    stack->data[stack->top] = stack->data[stack->top + 1];
    stack->data[stack->top + 1] = tmp;
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
    if(stack->data[stack->top + 1] == 0) {
        fprintf(stderr, "division by zero \n");
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
    free(stack->data);
    free(stack);
    stack = NULL;
    return 0;
}    