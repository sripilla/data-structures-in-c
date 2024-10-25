/*Implement a queue with two stacks without transferring the elements of the second
stack back to stack one. (use stack1 as an input stack and stack2 as an output stack) */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the stacks

// Structure to represent a stack
struct Stack {
    int top;
    int items[MAX];
};

// Function to create a stack
void initStack(struct Stack* s) {
    s->top = -1; // Initialize top to -1 indicating an empty stack
}

// Function to check if the stack is full
int isFull(struct Stack* s) {
    return s->top == MAX - 1; // Check if the stack is full
}

// Function to check if the stack is empty
int isEmpty(struct Stack* s) {
    return s->top == -1; // Check if the stack is empty
}

// Function to push an element onto the stack
void push(struct Stack* s, int item) {
    if (isFull(s)) {
        printf("Stack Overflow. Cannot push %d onto the stack.\n", item);
        return;
    }
    s->items[++s->top] = item; // Increment top and add the item
    printf("Pushed %d onto the stack.\n", item);
}

// Function to pop an element from the stack
int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow. Cannot pop from the stack.\n");
        return -1; // Return -1 to indicate error
    }
    return s->items[s->top--]; // Return the top item and decrement top
}

// Function to get the top element of the stack without popping it
int peek(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot peek.\n");
        return -1; // Return -1 to indicate error
    }
    return s->items[s->top]; // Return the top item
}

// Structure to represent a queue using two stacks
struct QueueUsingStacks {
    struct Stack stack1; // Input stack
    struct Stack stack2; // Output stack
};

// Function to initialize the queue
void initQueue(struct QueueUsingStacks* q) {
    initStack(&q->stack1);
    initStack(&q->stack2);
}

// Function to enqueue an element into the queue
void enqueue(struct QueueUsingStacks* q, int item) {
    push(&q->stack1, item); // Push item onto the input stack
}

// Function to dequeue an element from the queue
int dequeue(struct QueueUsingStacks* q) {
    if (isEmpty(&q->stack2)) { // If output stack is empty, transfer elements
        while (!isEmpty(&q->stack1)) {
            push(&q->stack2, pop(&q->stack1)); // Move items to the output stack
        }
    }
    return pop(&q->stack2); // Pop the top item from the output stack
}

// Function to display the front element of the queue
int front(struct QueueUsingStacks* q) {
    if (isEmpty(&q->stack2)) { // If output stack is empty, transfer elements
        while (!isEmpty(&q->stack1)) {
            push(&q->stack2, pop(&q->stack1)); // Move items to the output stack
        }
    }
    return peek(&q->stack2); // Peek the top item from the output stack
}

// Main function to demonstrate the queue using two stacks
int main() {
    struct QueueUsingStacks queue;
    initQueue(&queue); // Initialize the queue

    // Enqueue elements
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Front element: %d\n", front(&queue)); // Display front element

    // Dequeue elements
    printf("Dequeued: %d\n", dequeue(&queue)); // Should return 10
    printf("Dequeued: %d\n", dequeue(&queue)); // Should return 20

    enqueue(&queue, 40);
    enqueue(&queue, 50);

    // Display front element again
    printf("Front element: %d\n", front(&queue)); // Should return 30

    // Dequeue remaining elements
    printf("Dequeued: %d\n", dequeue(&queue)); // Should return 30
    printf("Dequeued: %d\n", dequeue(&queue)); // Should return 40
    printf("Dequeued: %d\n", dequeue(&queue)); // Should return 50

    // Trying to dequeue from an empty queue
    printf("Dequeued: %d\n", dequeue(&queue)); // Should indicate empty queue

    return 0;
}

/* SAMPLE OUTPUT
Pushed 10 onto the stack.
Pushed 20 onto the stack.
Pushed 30 onto the stack.
Front element: 10
Dequeued: 10
Dequeued: 20
Pushed 40 onto the stack.
Pushed 50 onto the stack.
Front element: 30
Dequeued: 30
Dequeued: 40
Dequeued: 50
Stack Underflow. Cannot pop from the stack.
Dequeued: -1
*/