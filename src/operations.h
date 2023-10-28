#ifndef __OPERATIONS_H__
#define __OPERATIONS_H__
#include "stack.h"

/**
 * @brief adds the last two elements in a stack
 * 
 * @param stack
 */
bool addition(Stack* stack);

/**
 * @brief subtracts the last two elements in a stack
 * 
 * @param stack 
 * @return true 
 * @return false 
 */
bool subtraction(Stack* stack);

/**
 * @brief multiplies the last two elements in a stack
 * 
 * @param stack 
 * @return true 
 * @return false 
 */
bool times(Stack* stack);

/**
 * @brief does the division for the last two elements in a stack
 * 
 * @param stack 
 * @return true 
 * @return false 
 */
bool division(Stack* stack);

/**
 * @brief does the remainder operation for the last two elements in a stack
 * 
 * @param stack 
 * @return true 
 * @return false 
 */
bool remainderr(Stack* stack);

/**
 * @brief calculates the factorial of a positive non-zero integer using an iterative method
 * 
 * @param number 
 * @return int 
 */
int factorial_aux(int number);

/**
 * @brief factorial of the peak element in a stack
 * 
 * @param stack 
 * @return true 
 * @return false 
 */
bool factorial(Stack* stack);

/**
 * @brief The peak element to the power of the second element
 * 
 * @param stack 
 * @return true 
 * @return false 
 */
bool power(Stack* stack);



#endif