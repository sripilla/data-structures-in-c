#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>   // For isdigit()
#include <string.h>  // For strlen()

#define MAX 100      // Maximum size for the stack

// Stack to hold operators
char stack[MAX];
int top = -1;

// Function to push an element onto the stack
void push(char item) {
    if (top >= MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        stack[++top] = item;
    }
}

// Function to pop an element from the stack
char pop() {
    if (top < 0) {
        printf("Stack Underflow!\n");
        return -1;
    } else {
        return stack[top--];
    }
}

// Function to check if a character is an operator
int is_operator(char symbol) {
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '%' || symbol == '^');
}

// Function to check the precedence of operators
int precedence(char symbol) {
    switch (symbol) {
        case '^':
            return 3;  // Exponentiation has the highest precedence
        case '*':
        case '/':
        case '%':
            return 2;  // Multiplication, division, and modulus have medium precedence
        case '+':
        case '-':
            return 1;  // Addition and subtraction have the lowest precedence
        default:
            return 0;  // Parentheses or unknown characters
    }
}

// Function to convert an infix expression to postfix expression
void infix_to_postfix(char infix[], char postfix[]) {
    int i, j = 0;
    char item, temp;

    // Scan the infix expression from left to right
    for (i = 0; i < strlen(infix); i++) {
        item = infix[i];

        // If the character is an operand (digit or letter), add it to postfix
        if (isalnum(item)) {
            postfix[j++] = item;
        }
        // If left parenthesis, push it to stack
        else if (item == '(') {
            push(item);
        }
        // If right parenthesis, pop until matching left parenthesis is found
        else if (item == ')') {
            while ((temp = pop()) != '(') {
                postfix[j++] = temp;
            }
        }
        // If the character is an operator
        else if (is_operator(item)) {
            while (top != -1 && precedence(stack[top]) >= precedence(item)) {
                postfix[j++] = pop();
            }
            push(item);  // Push the current operator to the stack
        }
    }

    // Pop all the remaining operators in the stack
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';  // Null-terminate the postfix expression
}

// Main function to test the conversion
int main() {
    char infix[MAX], postfix[MAX];

    // Input the infix expression from the user
    printf("Enter infix expression: ");
    scanf("%s", infix);

    // Call the function to convert infix to postfix
    infix_to_postfix(infix, postfix);

    // Display the resulting postfix expression
    printf("Postfix expression: %s\n", postfix);

    return 0;
}

/* 
INPUT
(A+B)*(C-D)

OUTPUT
Postfix expression: AB+CD-*

*/