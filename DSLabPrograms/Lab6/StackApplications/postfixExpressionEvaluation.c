#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100 /* Define the maximum size of the stack */
#define MAX_EXPR_SIZE 100  /* Define the maximum size of the expression */

/* Define an enum for operators and operands to represent the precedence of each symbol */
typedef enum {
    lparen, rparen, plus, minus, times, divide, mod, eos, operand
} precedence;

/* Declare a global stack array to store operands during evaluation */
int stack[MAX_STACK_SIZE];
/* Declare a global expression array to store the postfix expression */
char expr[MAX_EXPR_SIZE];

/* Function to push a value onto the stack */
void push(int *top, int value) {
    /* Check if the stack is not full, then add value to stack */
    if (*top < MAX_STACK_SIZE - 1) {
        stack[++(*top)] = value;
    } else {
        printf("Stack Overflow!\n");  /* Error if stack is full */
    }
}

/* Function to pop a value from the stack */
int pop(int *top) {
    /* Check if the stack is not empty, then remove and return the top value */
    if (*top >= 0) {
        return stack[(*top)--];  /* Decrement the top and return the value */
    } else {
        printf("Stack Underflow!\n");  /* Error if stack is empty */
        exit(1);  /* Exit if there's an underflow error */
    }
}

/* Function to get the next token from the postfix expression */
precedence get_token(char *symbol, int *n) {
    /* Retrieve the next character from the expression */
    *symbol = expr[(*n)++];
    /* Return the corresponding token for the character (operator or operand) */
    switch (*symbol) {
        case '(': return lparen;   /* Left parenthesis */
        case ')': return rparen;   /* Right parenthesis */
        case '+': return plus;     /* Addition operator */
        case '-': return minus;    /* Subtraction operator */
        case '/': return divide;   /* Division operator */
        case '*': return times;    /* Multiplication operator */
        case '%': return mod;      /* Modulus operator */
        case '\0': return eos;     /* End of string (end of expression) */
        default: return operand;   /* Assume it's a single-digit operand */
    }
}

/* Function to evaluate the postfix expression */
int eval(void) {
    precedence token;  /* Variable to store the token type */
    char symbol;       /* Variable to store the current character symbol */
    int op1, op2;      /* Operands to perform the operation on */
    int n = 0;         /* Counter to scan through the expression */
    int top = -1;      /* Initialize the top of the stack to -1 (empty stack) */

    /* Get the first token from the expression */
    token = get_token(&symbol, &n);

    /* Loop through the entire expression until end of string (eos) */
    while (token != eos) {
        /* If the token is an operand, push its integer value onto the stack */
        if (token == operand) {
            push(&top, symbol - '0');  /* Convert character '0'-'9' to integer */
        } else {
            /* If the token is an operator, pop the top two operands from the stack */
            op2 = pop(&top);  /* Pop the second operand */
            op1 = pop(&top);  /* Pop the first operand */

            /* Perform the appropriate operation based on the token */
            switch (token) {
                case plus:   push(&top, op1 + op2); break;  /* Addition */
                case minus:  push(&top, op1 - op2); break;  /* Subtraction */
                case times:  push(&top, op1 * op2); break;  /* Multiplication */
                case divide: push(&top, op1 / op2); break;  /* Division */
                case mod:    push(&top, op1 % op2); break;  /* Modulus */
            }
        }
        /* Get the next token from the expression */
        token = get_token(&symbol, &n);
    }

    /* After processing the entire expression, the result will be the only value left on the stack */
    return pop(&top);  /* Return the final result */
}

int main() {
    /* Ask the user to input a valid postfix expression */
    printf("Enter a valid postfix expression: ");
    /* Read the postfix expression into the global expr array */
    scanf("%s", expr);

    /* Call the eval function to evaluate the expression and store the result */
    int result = eval();
    /* Output the final result of the expression */
    printf("Result of the postfix expression is: %d\n", result);

    return 0;
}

/*
SAMPLE i/p and o/p:
Enter a valid postfix expression: 23*54*+
Result of the postfix expression is: 26

In this example:

The postfix expression 23*54*+ is evaluated as 2*3 + 5*4 = 6 + 20 = 26.


Breakdown with Comments:
Global Variables:

stack[]: Stores operands for evaluation.
expr[]: Stores the input postfix expression.
push() Function:

Pushes values (operands or intermediate results) onto the stack.
Checks for stack overflow (exceeds MAX_STACK_SIZE).
pop() Function:

Pops values from the stack (used to retrieve operands for operations).
Checks for stack underflow (empty stack).
get_token() Function:

Reads the next character from the expression.
Converts the character into a corresponding operator or operand.
eval() Function:

The core evaluation function:
Scans the postfix expression from left to right.
If an operand is encountered, it is pushed onto the stack.
If an operator is encountered, it pops two operands from the stack, performs the operation, and pushes the result back.
Continues until the end of the expression.
Main Function:

Takes a postfix expression as input from the user.
Calls eval() to evaluate the expression and outputs the result.
*/