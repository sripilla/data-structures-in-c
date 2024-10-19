#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;

// Function prototypes
void push(char *str);
char* pop();
int isEmpty();
void reverse(char *str);
void postfixToPrefix(char *postfix, char *prefix);

int main() {
    char postfix[MAX];
    char prefix[MAX];

    printf("Enter the postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);
    postfix[strcspn(postfix, "\n")] = '\0'; // Remove the newline character

    postfixToPrefix(postfix, prefix);
    printf("The equivalent prefix expression is: %s\n", prefix);

    return 0;
}

// Push a string onto the stack
void push(char *str) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    top++;
    strcpy(stack[top], str);
}

// Pop a string from the stack
char* pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

// Check if the stack is empty
int isEmpty() {
    return top == -1;
}

// Reverse a string in place
void reverse(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

// Convert postfix expression to prefix expression
void postfixToPrefix(char *postfix, char *prefix) {
    char symbol;
    char operand1[MAX], operand2[MAX], temp[MAX];

    // Reverse the postfix expression to process it from right to left
    reverse(postfix);

    for (int i = 0; i < strlen(postfix); i++) {
        symbol = postfix[i];

        if (symbol == ' ') continue; // Ignore spaces

        if (symbol >= '0' && symbol <= '9') {
            // Operand: push it onto the stack
            char operand[2] = {symbol, '\0'};
            push(operand);
        } else if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^') {
            // Operator: pop two operands and create a new string
            char *op1 = pop();
            char *op2 = pop();
            snprintf(temp, sizeof(temp), "%c%s%s", symbol, op2, op1);
            push(temp);
        }
    }

    // The remaining string on the stack is the prefix expression
    strcpy(prefix, pop());

    // Reverse the result to get the correct prefix expression
    reverse(prefix);
}
