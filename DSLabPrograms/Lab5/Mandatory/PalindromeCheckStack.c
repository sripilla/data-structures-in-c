/* Determine whether a given string is palindrome or not using stack.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100 // Maximum size of the stack

// Define a structure for STACK
typedef struct {
    char arr[MAX]; // Array to hold stack elements
    int top;       // Variable to keep track of the top element
} STACK;

// Function to initialize the stack
void initStack(STACK *s) {
    s->top = -1; // Initialize top to -1 indicating an empty stack
}

// Function to check if the stack is empty
int isEmpty(STACK *s) {
    return s->top == -1; // Stack is empty when top is -1
}

// Function to check if the stack is full
int isFull(STACK *s) {
    return s->top == MAX - 1; // Stack is full when top is at the last index
}

// Function to push an element onto the stack
void push(STACK *s, char data) {
    if (isFull(s)) { // Check for stack overflow
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = data; // Increment top and add the new element
}

// Function to pop an element from the stack
char pop(STACK *s) {
    if (isEmpty(s)) { // Check for stack underflow
        printf("Stack Underflow\n");
        return '\0'; // Return null character if stack is empty
    }
    return s->arr[s->top--]; // Get the top element and decrement top
}

// Function to check if a string is a palindrome using stack
int isPalindrome(const char *str) {
    STACK s;
    initStack(&s);

    int len = strlen(str);

    // Push all characters of the string onto the stack
    for (int i = 0; i < len; i++) {
        push(&s, str[i]);
    }

    // Compare the characters from the stack with the original string
    for (int i = 0; i < len; i++) {
        if (str[i] != pop(&s)) {
            return 0; // Not a palindrome
        }
    }

    return 1; // Is a palindrome
}

int main() {
    char str[MAX];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0';

    // Convert string to lowercase for case-insensitive comparison
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }

    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}

/*SAMPLE OUTPUT
INPUT:
Enter a string: madam

OUTPUT
The string 'madam' is a palindrome.
*/