#ifndef __STACK_C__
#define __STACK_C__

#define MAX_SIZE 64

typedef struct stack {
    int data[MAX_SIZE];
    int top;
    int size;
} Stack;

/**
 * @brief initializes your stack, sets the index of the top at -1
 * 
 * @param stack 
 */
void initialize_Stack(Stack* stack);

/**
 * @brief prints the top of your stack 
 * 
 * @param stack
 */
void print_Top(Stack stack);


/**
 * @brief pushes a number on top of your stack
 * 
 * @param stack
 * @param number
 */
void push(Stack* stack, int number);

/**
 * @brief pops the top element of your stack and returns it
 * 
 * @param stack 
 * @return int
 */
int pop(Stack* stack);

/**
 * @brief checks if a string contains only numerical characters
 * 
 * @param str 
 * @return true 
 * @return false 
 */
bool isNumerical(char* str);

void print_stack(Stack stack);

#endif

