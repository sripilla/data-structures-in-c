/*Given a queue of integers, write a program to reverse the queue, using only the following operations:
i. enqueue(x): Add an item x to rear of queue.
ii. dequeue() : Remove an item from front of queue.
iii. empty() : Checks if a queue is empty or not. */
#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the queue

// Define the structure for the queue
struct Queue {
    int items[MAX];
    int front, rear;
};

// Function to initialize the queue
void initQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
int empty(struct Queue *q) {
    return (q->front == -1);
}

// Check if the queue is full
int full(struct Queue *q) {
    return (q->rear == MAX - 1);
}

// Enqueue operation: add an element to the rear
void enqueue(struct Queue *q, int x) {
    if (full(q)) {
        printf("Queue is full. Cannot enqueue more elements.\n");
        return;
    }

    if (empty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = x;
}

// Dequeue operation: remove an element from the front
int dequeue(struct Queue *q) {
    if (empty(q)) {
        printf("Queue is empty. Cannot dequeue any elements.\n");
        return -1;
    }

    int item = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1; // Reset queue if it's empty
    } else {
        q->front++;
    }

    return item;
}

// Function to print the elements of the queue
void displayQueue(struct Queue *q) {
    if (empty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

// Function to reverse the queue using a stack
void reverseQueue(struct Queue *q) {
    int stack[MAX]; // Use an array as a stack
    int top = -1;   // Top of the stack

    // Dequeue all elements from the queue and push them onto the stack
    while (!empty(q)) {
        int item = dequeue(q);
        stack[++top] = item;
    }

    // Pop all elements from the stack and enqueue them back into the queue
    while (top != -1) {
        enqueue(q, stack[top--]);
    }
}

// Main function to test the queue reversal
int main() {
    struct Queue q;
    initQueue(&q);

    int n, x;

    printf("Enter the number of elements in the queue: ");
    scanf("%d", &n);

    printf("Enter %d elements to enqueue into the queue: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(&q, x);
    }

    printf("\nOriginal ");
    displayQueue(&q);

    // Reverse the queue
    reverseQueue(&q);

    printf("\nReversed ");
    displayQueue(&q);

    return 0;
}

/* SAMPLE OUTPUT
Enter the number of elements in the queue: 5
Enter 5 elements to enqueue into the queue: 
1 2 3 4 5

Original Queue: 1 2 3 4 5 

Reversed Queue: 5 4 3 2 1
*/