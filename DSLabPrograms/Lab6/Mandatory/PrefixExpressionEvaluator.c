/* Evaluate a given prefix expression using stack. */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100 // Maximum size of the stack

// Structure to represent the stack
struct Stack {
    int top; // Index of the top element in the stack
    int items[MAX]; // Array to hold stack elements
};

// Function to create a stack
struct Stack* createStack() {
    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack)); // Allocate memory for stack
    s->top = -1; // Initialize the top of the stack as -1 (indicating empty stack)
    return s; // Return the created stack
}

// Function to check if the stack is empty
int isEmpty(struct Stack* s) {
    return s->top == -1; // Return 1 if stack is empty, else return 0
}

// Function to push an item onto the stack
void push(struct Stack* s, int item) {
    if (s->top < MAX - 1) { // Check if stack is not full
        s->items[++s->top] = item; // Increment top and add item to stack
    } else {
        printf("Stack Overflow\n"); // Handle stack overflow
    }
}

// Function to pop an item from the stack
int pop(struct Stack* s) {
    if (!isEmpty(s)) { // Check if stack is not empty
        return s->items[s->top--]; // Return top item and decrement top
    } else {
        printf("Stack Underflow\n"); // Handle stack underflow
        return -1; // Return -1 for underflow
    }
}

// Function to evaluate the prefix expression
int evaluatePrefix(char* expression) {
    struct Stack* s = createStack(); // Create a new stack
    int i;

    // Traverse the expression from right to left
    for (i = strlen(expression) - 1; i >= 0; i--) {
        char ch = expression[i]; // Get the current character

        // If the character is an operand (0-9)
        if (isdigit(ch)) {
            // Convert character to integer and push it onto the stack
            push(s, ch - '0'); // Subtract '0' to get the integer value
        }
        // If the character is an operator (+, -, *, /)
        else {
            // Pop the top two elements from the stack
            int operand1 = pop(s);
            int operand2 = pop(s);
            int result;

            // Perform the operation based on the operator
            switch (ch) {
                case '+':
                    result = operand1 + operand2; // Addition
                    break;
                case '-':
                    result = operand1 - operand2; // Subtraction
                    break;
                case '*':
                    result = operand1 * operand2; // Multiplication
                    break;
                case '/':
                    result = operand1 / operand2; // Division
                    break;
                default:
                    printf("Invalid operator: %c\n", ch); // Handle invalid operator
                    free(s); // Free stack memory before returning
                    return -1;
            }

            // Push the result of the operation back onto the stack
            push(s, result);
        }
    }

    // The final result will be the only item left in the stack
    int finalResult = pop(s); // Pop the final result
    free(s); // Free the stack memory
    return finalResult; // Return the final result
}

// Main function to test the prefix evaluation
int main() {
    char expression[MAX]; // Array to hold the prefix expression

    // Get the prefix expression from the user
    printf("Enter a prefix expression: ");
    fgets(expression, MAX, stdin); // Read the input expression

    // Evaluate the prefix expression
    int result = evaluatePrefix(expression);

    // Print the result
    printf("The result of the prefix expression is: %d\n", result);

    return 0; // Return success
}

/*
INPUT:   + 9 * 2 3
OUTPUT:   The result of the prefix expression is: 15



Explanation of the Code:
Header Files:
Includes standard libraries for input/output and memory management.
Stack Structure:
Defines a Stack structure with a top index and an array for storing items.
Stack Functions:
createStack: Allocates memory for a stack and initializes it.
isEmpty: Checks if the stack is empty.
push: Adds an item to the stack.
pop: Removes and returns the top item from the stack.
Evaluation Function:
evaluatePrefix: Evaluates the prefix expression by traversing it from right to left and using the stack to perform operations.
Main Function:
Prompts the user for a prefix expression, evaluates it, and prints the result.
This commented code should help users understand the logic and flow of the program just by reading the comments! */