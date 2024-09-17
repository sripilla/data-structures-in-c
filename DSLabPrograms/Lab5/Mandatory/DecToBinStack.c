/* Convert a given decimal number to binary using stack. */

#include <stdio.h>
#include <stdlib.h>

#define MAX 32  // Maximum size of the stack to hold binary digits

// Define a structure for STACK
typedef struct {
    int arr[MAX]; // Array to hold stack elements
    int top;      // Variable to keep track of the top element
} STACK;

// Function to initialize the stack
void initStack(STACK *s) {
    s->top = -1; // Initialize the stack top
}

// Function to check if the stack is empty
int isEmpty(STACK *s) {
    return s->top == -1;
}

// Function to check if the stack is full
int isFull(STACK *s) {
    return s->top == MAX - 1;
}

// Function to push an element onto the stack
void push(STACK *s, int data) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = data;
}

// Function to pop an element from the stack
int pop(STACK *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}

// Function to convert decimal to binary using stack
void decimalToBinary(int decimal) {
    STACK s;
    initStack(&s);

    // Handle the special case when decimal is 0
    if (decimal == 0) {
        printf("Binary: 0\n");
        return;
    }

    // Push binary digits onto the stack
    while (decimal > 0) {
        int remainder = decimal % 2;
        push(&s, remainder);
        decimal /= 2;
    }

    // Pop elements to display the binary number
    printf("Binary: ");
    while (!isEmpty(&s)) {
        printf("%d", pop(&s));
    }
    printf("\n");
}

int main() {
    int decimal;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    decimalToBinary(decimal);

    return 0;
}

/* SAMPLE OUTPUT 
Enter a decimal number: 10
Binary: 1010
*/