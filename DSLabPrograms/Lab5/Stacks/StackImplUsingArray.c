#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // For boolean data type

// Define the maximum capacity of the stack
#define MAX 100

// Stack structure definition
typedef struct {
    int arr[MAX]; // Array to store stack elements
    int top;      // Index of the top element
} StackADT;

// Function to create and initialize the stack
void CreateS(StackADT* stack) {
    stack->top = -1; // Initialize top to -1, indicating an empty stack
}

// Function to check if the stack is empty
bool isEmpty(StackADT* stack) {
    return stack->top == -1; // Returns true if the stack is empty
}

// Function to check if the stack is full
bool isFull(StackADT* stack) {
    return stack->top == MAX - 1; // Returns true if the stack is full
}

// Function to push an element onto the stack
void Push(StackADT* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    stack->arr[++(stack->top)] = value; // Increment top and push the value
    printf("Pushed %d onto the stack\n", value);
}

// Function to pop the top element from the stack
int Pop(StackADT* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop\n");
        return -1; // Error code for underflow
    }
    return stack->arr[(stack->top)--]; // Return top element and decrement top
}

// Function to peek the top element without removing it
int Peek(StackADT* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! Cannot peek.\n");
        return -1; // Error code for empty stack
    }
    return stack->arr[stack->top]; // Return the top element
}

// Function to display the elements of the stack
void Display(StackADT* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

// Main function to demonstrate stack operations
int main() {
    StackADT stack;        // Create stack object
    CreateS(&stack);       // Initialize stack

    // Perform stack operations
    Push(&stack, 10);      // Push element 10
    Push(&stack, 20);      // Push element 20
    Push(&stack, 30);      // Push element 30

    Display(&stack);       // Display current stack elements

    printf("Peek top element: %d\n", Peek(&stack)); // Peek top element

    printf("Popped element: %d\n", Pop(&stack));    // Pop the top element
    Display(&stack);       // Display current stack after pop

    return 0;
}

/* 
CreateS: Initializes the stack by setting top to -1, indicating that the stack is empty.

isEmpty:Checks if the stack is empty by verifying if top == -1.

isFull:Checks if the stack is full by verifying if top == MAX - 1.

Push:Adds an element to the top of the stack. If the stack is full, it returns an error message.

Pop:Removes and returns the top element from the stack. If the stack is empty, it returns an error message for underflow.

Peek:Returns the top element without removing it. If the stack is empty, it returns an error message.

Display:Prints the elements of the stack from bottom to top.
*/