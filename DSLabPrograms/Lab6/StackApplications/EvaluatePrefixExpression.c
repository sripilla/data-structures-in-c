#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure
typedef struct {
    int top;
    int items[MAX];
} Stack;

// Function to initialize the stack
void initStack(Stack* s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Function to push an item onto the stack
void push(Stack* s, int item) {
    if (s->top < MAX - 1) {
        s->items[++s->top] = item;
    }
}

// Function to pop an item from the stack
int pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->items[s->top--];
    }
    return 0; // Return 0 if the stack is empty
}

// Function to evaluate the prefix expression
int evaluatePrefix(char* expr) {
    Stack s;
    initStack(&s);

    // Get the length of the expression
    int length = strlen(expr);

    // Traverse the expression from right to left
    for (int i = length - 1; i >= 0; i--) {
        char token = expr[i];

        // If the token is a whitespace, skip it
        if (isspace(token)) {
            continue;
        }

        // If the token is a number (operand)
        if (isdigit(token)) {
            // Convert char to int and push onto the stack
            push(&s, token - '0');
        } else { // The token is an operator
            // Pop two operands from the stack
            int operand1 = pop(&s);
            int operand2 = pop(&s);
            int result;

            // Perform the operation
            switch (token) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator: %c\n", token);
                    return 0;
            }

            // Push the result back onto the stack
            push(&s, result);
        }
    }

    // The final result will be on the top of the stack
    return pop(&s);
}

int main() {
    char expr[MAX];

    printf("Enter a prefix expression: ");
    fgets(expr, MAX, stdin);

    // Evaluate the prefix expression
    int result = evaluatePrefix(expr);

    printf("Result: %d\n", result);

    return 0;
}

/* For the prefix expression + 3 * 5 4, the output would be Result: 23 since the evaluation is done as follows:

Multiply 5 and 4, resulting in 20.
Add 3 to 20, resulting in 23.*/
