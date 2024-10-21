/* Convert an infix expression to prefix.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100 // Maximum size of the stack

// Structure to represent the stack
struct Stack {
    int top; // Index of the top element in the stack
    char items[MAX]; // Array to hold stack elements
};

// Function to create a stack
struct Stack* createStack() {
    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack)); // Allocate memory for the stack
    s->top = -1; // Initialize the top of the stack as -1 (indicating empty stack)
    return s; // Return the created stack
}

// Function to check if the stack is empty
int isEmpty(struct Stack* s) {
    return s->top == -1; // Return 1 if stack is empty, else return 0
}

// Function to push an item onto the stack
void push(struct Stack* s, char item) {
    if (s->top < MAX - 1) { // Check if stack is not full
        s->items[++s->top] = item; // Increment top and add item to stack
    } else {
        printf("Stack Overflow\n"); // Handle stack overflow
    }
}

// Function to pop an item from the stack
char pop(struct Stack* s) {
    if (!isEmpty(s)) { // Check if stack is not empty
        return s->items[s->top--]; // Return top item and decrement top
    } else {
        printf("Stack Underflow\n"); // Handle stack underflow
        return '\0'; // Return null character for underflow
    }
}

// Function to return the precedence of operators
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1; // Lowest precedence
        case '*':
        case '/':
            return 2; // Higher precedence
        case '^':
            return 3; // Highest precedence
        default:
            return 0; // Unknown operator
    }
}

// Function to reverse a string
void reverse(char* exp) {
    int n = strlen(exp); // Get the length of the expression
    for (int i = 0; i < n / 2; i++) {
        // Swap characters from start and end
        char temp = exp[i];
        exp[i] = exp[n - i - 1];
        exp[n - i - 1] = temp;
    }
}

// Function to convert infix expression to prefix
void infixToPrefix(char* infix, char* prefix) {
    struct Stack* s = createStack(); // Create a new stack
    int k = 0; // Index for prefix expression

    // Reverse the infix expression
    reverse(infix);

    // Process the reversed infix expression
    for (int i = 0; i < strlen(infix); i++) {
        char ch = infix[i]; // Get the current character

        // If the character is an operand, add it to the prefix expression
        if (isalnum(ch)) {
            prefix[k++] = ch; // Add operand to prefix
        }
        // If the character is a closing parenthesis
        else if (ch == ')') {
            push(s, ch); // Push it onto the stack
        }
        // If the character is an opening parenthesis
        else if (ch == '(') {
            // Pop from the stack until a closing parenthesis is found
            while (!isEmpty(s) && s->items[s->top] != ')') {
                prefix[k++] = pop(s); // Add operators to prefix
            }
            pop(s); // Pop the closing parenthesis
        }
        // If the character is an operator
        else {
            // Pop operators from the stack to the prefix expression based on precedence
            while (!isEmpty(s) && precedence(s->items[s->top]) > precedence(ch)) {
                prefix[k++] = pop(s); // Add higher precedence operators to prefix
            }
            push(s, ch); // Push the current operator onto the stack
        }
    }

    // Pop all remaining operators in the stack
    while (!isEmpty(s)) {
        prefix[k++] = pop(s); // Add remaining operators to prefix
    }

    prefix[k] = '\0'; // Null-terminate the prefix expression
    reverse(prefix); // Reverse the prefix expression to get the correct order
    free(s); // Free the stack memory
}

// Main function to test infix to prefix conversion
int main() {
    char infix[MAX]; // Array to hold the infix expression
    char prefix[MAX]; // Array to hold the prefix expression

    // Get the infix expression from the user
    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin); // Read the input expression
    infix[strcspn(infix, "\n")] = '\0'; // Remove the trailing newline character

    // Convert infix to prefix
    infixToPrefix(infix, prefix);

    // Print the result
    printf("The prefix expression is: %s\n", prefix);

    return 0; // Return success
}


/*
INPUT:  Enter an infix expression: (A + B) * C

OUTPUT: The prefix expression is: *+ABC
*/