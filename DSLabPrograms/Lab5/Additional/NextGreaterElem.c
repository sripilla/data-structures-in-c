/* 
Given an array, print the Next Greater Element (NGE) for every element using stack.
The Next Greater Element for an element x is the first greater element on the right
side of x in array. Elements for which no greater element exist, consider next greater
element as -1. For the input array [13, 7, 6, 12}, the next greater elementsfor each
element are as follows.
Element NGE
13   → -1
7    → 12
6    → 12
12   → -1
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the stack

// Stack structure
typedef struct {
    int arr[MAX]; // Array to hold stack elements
    int top;      // Variable to keep track of the top element
} Stack;

// Function to initialize the stack
void initStack(Stack* s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Function to push an element onto the stack
void push(Stack* s, int data) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = data;
}

// Function to pop an element from the stack
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1; // Return -1 for underflow condition
    }
    return s->arr[s->top--];
}

// Function to get the top element of the stack without popping
int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->arr[s->top];
}

// Function to print the Next Greater Element (NGE) for each element in the array
void printNextGreaterElement(int arr[], int n) {
    Stack s;
    initStack(&s);
    int nge[n]; // Array to store Next Greater Elements

    // Initialize all NGE values to -1
    for (int i = 0; i < n; i++) {
        nge[i] = -1;
    }

    // Traverse the array
    for (int i = 0; i < n; i++) {
        // While stack is not empty and the current element is greater than the element
        // corresponding to the index stored at the top of the stack
        while (!isEmpty(&s) && arr[i] > arr[peek(&s)]) {
            nge[pop(&s)] = arr[i];
        }
        // Push the current index onto the stack
        push(&s, i);
    }

    // Print the NGE for each element
    printf("Element NGE\n");
    for (int i = 0; i < n; i++) {
        printf("%d → %d\n", arr[i], nge[i]);
    }
}

int main() {
    int arr[] = {13, 7, 6, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    printNextGreaterElement(arr, n);

    return 0;
}

/* SAMPLE OUTPUT
Element   NGE
13    →   -1
7     →   12
6     →   12
12    →   -1
*/