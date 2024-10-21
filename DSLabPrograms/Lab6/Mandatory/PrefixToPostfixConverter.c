/*To convert a prefix expression to postfix using stack */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100 // Maximum size of the stack

// Structure to represent the stack
struct Stack {
    int top; // Index of the top element in the stack
    char items[MAX][MAX]; // Array to hold stack elements (strings)
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
void push(struct Stack* s, char* item) {
    if (s->top < MAX - 1) { // Check if stack is not full
        strcpy(s->items[++s->top], item); // Increment top and copy item to stack
    } else {
        printf("Stack Overflow\n"); // Handle stack overflow
    }
}

// Function to pop an item from the stack
char* pop(struct Stack* s) {
    if (!isEmpty(s)) { // Check if stack is not empty
        return s->items[s->top--]; // Return top item and decrement top
    } else {
        printf("Stack Underflow\n"); // Handle stack underflow
        return NULL; // Return NULL for underflow
    }
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'); // Return 1 if character is an operator
}

// Function to convert prefix expression to postfix
void prefixToPostfix(char* prefix, char* postfix) {
    struct Stack* s = createStack(); // Create a new stack

    // Traverse the prefix expression from right to left
    for (int i = strlen(prefix) - 1; i >= 0; i--) {
        char ch = prefix[i]; // Get the current character

        // If the character is an operand (letter or digit)
        if (isalnum(ch)) {
            char temp[2] = {ch, '\0'}; // Create a temporary string for the operand
            push(s, temp); // Push the operand onto the stack
        }
        // If the character is an operator
        else if (isOperator(ch)) {
            // Pop the top two elements from the stack
            char* operand1 = pop(s); // First operand
            char* operand2 = pop(s); // Second operand

            // Create a new string for the resulting postfix expression
            char temp[MAX]; 
            sprintf(temp, "%s %s %c", operand1, operand2, ch); // Combine operands and operator
            push(s, temp); // Push the result back onto the stack
        }
    }

    // The final postfix expression will be the only item left in the stack
    strcpy(postfix, pop(s)); // Copy the result to the postfix variable
    free(s); // Free the stack memory
}

// Main function to test prefix to postfix conversion
int main() {
    char prefix[MAX]; // Array to hold the prefix expression
    char postfix[MAX]; // Array to hold the postfix expression

    // Get the prefix expression from the user
    printf("Enter a prefix expression: ");
    fgets(prefix, MAX, stdin); // Read the input expression
    prefix[strcspn(prefix, "\n")] = '\0'; // Remove the trailing newline character

    // Convert prefix to postfix
    prefixToPostfix(prefix, postfix);

    // Print the result
    printf("The postfix expression is: %s\n", postfix);

    return 0; // Return success
}

/*
INPUT: Enter a prefix expression: + A B
  
OUTPUT: The postfix expression is: A B +
*/