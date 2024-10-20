#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100 // Maximum size for the stack

char stack[MAX][MAX]; // Stack to store operands and intermediate results
int top = -1;         // Top pointer for stack

// Function to push a string onto the stack
void push(char *str) {
    if (top < MAX - 1) {
        top++;
        strcpy(stack[top], str); // Copy the string to the top of the stack
    }
}

// Function to pop a string from the stack
char *pop() {
    if (top >= 0) {
        return stack[top--]; // Return the top string and decrease the top index
    }
    return NULL;
}

// Function to check if the character is an operand (letter or digit)
int isOperand(char ch) {
    return (isalnum(ch)); // Return true if the character is a letter or digit
}

// Function to convert Prefix expression to Postfix
void prefixToPostfix(char prefix[]) {
    int length = strlen(prefix); // Get the length of the prefix expression

    // Traverse the prefix expression from right to left
    for (int i = length - 1; i >= 0; i--) {
        // If the character is an operand, push it onto the stack
        if (isOperand(prefix[i])) {
            char operand[2]; // Store the single character operand as a string
            operand[0] = prefix[i];
            operand[1] = '\0'; // Null-terminate the string
            push(operand); // Push the operand string onto the stack
        }
        // If the character is an operator
        else {
            // Pop two operands from the stack
            char operand1[MAX], operand2[MAX];
            strcpy(operand1, pop());
            strcpy(operand2, pop());

            // Concatenate the operands and operator in the form "operand1 operand2 operator"
            char result[MAX];
            strcpy(result, operand1);
            strcat(result, operand2);
            strncat(result, &prefix[i], 1); // Add the operator

            // Push the resultant string back onto the stack
            push(result);
        }
    }

    // The final result is the only string left in the stack, which is the postfix expression
    printf("Postfix Expression: %s\n", pop());
}

int main() {
    char prefix[MAX];

    // Input: Prefix expression
    printf("Enter a Prefix expression: ");
    scanf("%s", prefix);

    // Convert to Postfix
    prefixToPostfix(prefix);

    return 0;
}

/* Example Input and Output

Enter a Prefix expression: *+AB-CD
Postfix Expression: AB+CD-*
*/