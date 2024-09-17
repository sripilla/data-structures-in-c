#include <stdio.h>
#include <stdlib.h>

#define MAX 4 // Maximum size of the stack

int stack_arr[MAX]; // Array to hold stack elements
int top = -1;       // Variable to keep track of the top element of the stack

// Function to check if the stack is full
int isFull() {
    return top == MAX - 1; // Stack is full when top is at the last index
}

// Function to check if the stack is empty
int isEmpty() {
    return top == -1; // Stack is empty when top is -1
}

// Function to push an element onto the stack
void push(int data) {
    if (isFull()) { // Check for stack overflow
        printf("Stack Overflow\n");
        return;
    }
    stack_arr[++top] = data; // Increment top and add the new element
}

// Function to pop an element from the stack
int pop() {
    if (isEmpty()) { // Check for stack underflow
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack_arr[top--]; // Return the top element and decrement top
}

// Function to get the top element of the stack without removing it
int peek() {
    if (isEmpty()) { // Check for stack underflow
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack_arr[top]; // Return the top element
}

// Function to print all elements of the stack
void printStack() {
    if (isEmpty()) { // Check if the stack is empty
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= top; i++) { // Iterate through the stack
        printf("%d ", stack_arr[i]);
    }
    printf("\n");
}

int main() {
    int choice, data; // Variables to hold user input

    while (1) {
        // Display menu options
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Print the top element\n");
        printf("4. Print all the elements of the stack\n");
        printf("5. Quit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Push an element onto the stack
                printf("Enter the element to be pushed: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2: // Pop an element from the stack
                data = pop();
                printf("Deleted element from the stack is %d\n", data);
                break;
            case 3: // Print the top element of the stack
                printf("The topmost element of the stack is %d\n", peek());
                break;
            case 4: // Print all elements of the stack
                printStack();
                break;
            case 5: // Exit the program
                exit(0);
            default: // Handle invalid choices
                printf("Wrong choice\n");
        }
    }

    return 0;
}

