/*Write a ‘C’ program to:
1) Implement a menu driven program to define a stack of characters. Include push, pop and display functions. 
Also include functions for checking error conditions such as underflow and overflow (ref. figure 1) by defining isEmpty and isFull functions.
Use these function in push, pop and display functions appropriately. Use type defined structure to define a STACK containing a character array and an integer top. Do not use global variables. */

#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of the stack

// Define a structure for STACK
typedef struct {
    char arr[MAX]; // Array to hold stack elements
    int top;       // Variable to keep track of the top element
} STACK;

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
    printf("Pushed '%c' onto the stack\n", data);
}

// Function to pop an element from the stack
char pop(STACK *s) {
    if (isEmpty(s)) { // Check for stack underflow
        printf("Stack Underflow\n");
        return '\0'; // Return null character if stack is empty
    }
    char data = s->arr[s->top--]; // Get the top element and decrement top
    return data;
}

// Function to display all elements of the stack
void display(STACK *s) {
    if (isEmpty(s)) { // Check if the stack is empty
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= s->top; i++) { // Iterate through the stack
        printf("%c ", s->arr[i]);
    }
    printf("\n");
}

int main() {
    STACK s;
    s.top = -1; // Initialize the stack top

    int choice;
    char data;

    while (1) {
        // Display menu options
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Push an element onto the stack
                printf("Enter the character to be pushed: ");
                scanf(" %c", &data); // Note the space before %c to consume any leftover newline
                push(&s, data);
                break;
            case 2: // Pop an element from the stack
                data = pop(&s);
                if (data != '\0') {
                    printf("Popped '%c' from the stack\n", data);
                }
                break;
            case 3: // Display all elements of the stack
                display(&s);
                break;
            case 4: // Exit the program
                exit(0);
            default: // Handle invalid choices
                printf("Invalid choice\n");
        }
    }

    return 0;
}
