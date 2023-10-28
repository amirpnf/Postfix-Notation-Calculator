#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "lines.h"
#include "operations.h"
#include "stack.h"

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
