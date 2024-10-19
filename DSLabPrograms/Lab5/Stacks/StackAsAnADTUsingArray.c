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
        return -1; // Return -1 to indicate an error
    }
    return stack->arr[(stack->top)--]; // Return top element and decrement top
}

// Function to peek at the top element without removing it
int Peek(StackADT* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! Cannot peek.\n");
        return -1; // Return -1 to indicate an error
    }
    return stack->arr[stack->top]; // Return the top element
}

// Function to display the stack elements
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
    StackADT stack; // Declare a stack
    CreateS(&stack); // Initialize the stack

    // Perform stack operations
    Push(&stack, 10);
    Push(&stack, 20);
    Push(&stack, 30);

    Display(&stack); // Display the stack elements

    printf("Peek top element: %d\n", Peek(&stack)); // Peek the top element

    printf("Popped element: %d\n", Pop(&stack)); // Pop the top element
    Display(&stack); // Display the stack after popping

    return 0;
}

/*
CreateS: Initializes the stack by setting top = -1, indicating the stack is empty.
isEmpty: Returns true if the top is -1, meaning the stack is empty.
isFull: Returns true if top is MAX - 1, indicating the stack is full.
Push: Adds an element to the top of the stack after checking if there is space (isFull()).
Pop: Removes and returns the top element after checking if the stack is not empty (isEmpty()).
Peek: Returns the top element without removing it from the stack.
Display: Prints the current elements of the stack.
*/