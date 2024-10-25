#include <stdio.h>
#include <stdbool.h>

#define SIZE 5  // Maximum size of the circular queue

// Structure to represent a circular queue
struct CircularQueue {
    int items[SIZE];  // Array to hold the queue elements
    int front;        // Points to the front element
    int rear;         // Points to the rear element
};

// Initialize the circular queue
void initializeQueue(struct CircularQueue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
bool isFull(struct CircularQueue* q) {
    return (q->front == (q->rear + 1) % SIZE);
}

// Check if the queue is empty
bool isEmpty(struct CircularQueue* q) {
    return (q->front == -1);
}

// Enqueue operation to add an element to the queue
void enqueue(struct CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %d\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;  // Reset front if the queue was empty
    }
    q->rear = (q->rear + 1) % SIZE;  // Increment rear in a circular manner
    q->items[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Dequeue operation to remove and return the front element
int dequeue(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;  // Return -1 as an error code if the queue is empty
    }
    int value = q->items[q->front];
    if (q->front == q->rear) {
        // Queue becomes empty after removing the last element
        q->front = -1;
        q->rear = -1;
    } else {
        // Increment front in a circular manner
        q->front = (q->front + 1) % SIZE;
    }
    printf("Dequeued: %d\n", value);
    return value;
}

// Peek operation to return the front element without removing it
int peek(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Nothing to peek.\n");
        return -1;  // Return -1 as an error code if the queue is empty
    }
    return q->items[q->front];
}

// Display the elements in the queue
void displayQueue(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->items[i]);
        i = (i + 1) % SIZE;  // Move to the next element in circular manner
    }
    printf("%d\n", q->items[q->rear]);  // Print the last element
}

// Main function to test the Circular Queue implementation
int main() {
    struct CircularQueue q;
    initializeQueue(&q);

    // Perform enqueue operations
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    // Display the queue
    displayQueue(&q);

    // Try to enqueue when the queue is full
    enqueue(&q, 60);  // This should fail as the queue is full

    // Perform dequeue operations
    dequeue(&q);
    dequeue(&q);

    // Display the queue after dequeues
    displayQueue(&q);

    // Peek at the front element
    printf("Peeked element: %d\n", peek(&q));

    // Continue enqueue operations
    enqueue(&q, 60);
    enqueue(&q, 70);

    // Display the final state of the queue
    displayQueue(&q);

    return 0;
}
