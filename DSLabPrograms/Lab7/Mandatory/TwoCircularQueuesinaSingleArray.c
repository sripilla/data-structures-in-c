/* Implement two circular queues of integers in a single array where first queue will run
from 0 to N/2 and second queue will run from N/2+1 to N-1 where N is the size of
the array.*/

#include <stdio.h>
#include <stdlib.h>

#define N 10  // Total size of the array

// Circular Queue Structure
typedef struct {
    int items[N];
    int front1, rear1;  // For the first queue
    int front2, rear2;  // For the second queue
} TwoCircularQueues;

// Function to initialize the two circular queues
void initQueues(TwoCircularQueues* q) {
    q->front1 = q->rear1 = -1;  // Initialize first queue
    q->front2 = q->rear2 = N / 2;  // Initialize second queue
}

// Function to check if the first queue is full
int isFullQueue1(TwoCircularQueues* q) {
    return (q->rear1 + 1) % (N / 2 + 1) == q->front1;
}

// Function to check if the second queue is full
int isFullQueue2(TwoCircularQueues* q) {
    return (q->rear2 + 1) % (N - N / 2) == q->front2;
}

// Function to check if the first queue is empty
int isEmptyQueue1(TwoCircularQueues* q) {
    return q->front1 == -1;
}

// Function to check if the second queue is empty
int isEmptyQueue2(TwoCircularQueues* q) {
    return q->front2 == N / 2;
}

// Function to enqueue an element in the first queue
void enqueueQueue1(TwoCircularQueues* q, int value) {
    if (isFullQueue1(q)) {
        printf("Queue 1 is full. Cannot enqueue %d\n", value);
        return;
    }
    if (isEmptyQueue1(q)) {
        q->front1 = 0;  // Set front for the first queue
    }
    q->rear1 = (q->rear1 + 1) % (N / 2 + 1);  // Circular increment
    q->items[q->rear1] = value;
    printf("Enqueued to Queue 1: %d\n", value);
}

// Function to enqueue an element in the second queue
void enqueueQueue2(TwoCircularQueues* q, int value) {
    if (isFullQueue2(q)) {
        printf("Queue 2 is full. Cannot enqueue %d\n", value);
        return;
    }
    if (isEmptyQueue2(q)) {
        q->front2 = N / 2 + 1;  // Set front for the second queue
    }
    q->rear2 = (q->rear2 + 1) % (N - N / 2);  // Circular increment
    q->items[q->rear2] = value;
    printf("Enqueued to Queue 2: %d\n", value);
}

// Function to dequeue an element from the first queue
int dequeueQueue1(TwoCircularQueues* q) {
    if (isEmptyQueue1(q)) {
        printf("Queue 1 is empty. Cannot dequeue\n");
        return -1;  // Return -1 to indicate that the queue is empty
    }
    int value = q->items[q->front1];
    if (q->front1 == q->rear1) {
        // Queue has only one element, reset the queue
        q->front1 = q->rear1 = -1;
    } else {
        q->front1 = (q->front1 + 1) % (N / 2 + 1);  // Circular increment
    }
    printf("Dequeued from Queue 1: %d\n", value);
    return value;
}

// Function to dequeue an element from the second queue
int dequeueQueue2(TwoCircularQueues* q) {
    if (isEmptyQueue2(q)) {
        printf("Queue 2 is empty. Cannot dequeue\n");
        return -1;  // Return -1 to indicate that the queue is empty
    }
    int value = q->items[q->front2];
    if (q->front2 == q->rear2) {
        // Queue has only one element, reset the queue
        q->front2 = N / 2;
        q->rear2 = N / 2;
    } else {
        q->front2 = (q->front2 + 1) % (N - N / 2);  // Circular increment
    }
    printf("Dequeued from Queue 2: %d\n", value);
    return value;
}

// Function to display the contents of the first queue
void displayQueue1(TwoCircularQueues* q) {
    if (isEmptyQueue1(q)) {
        printf("Queue 1 is empty\n");
        return;
    }
    printf("Queue 1 contents: ");
    int i = q->front1;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear1) {
            break;
        }
        i = (i + 1) % (N / 2 + 1);
    }
    printf("\n");
}

// Function to display the contents of the second queue
void displayQueue2(TwoCircularQueues* q) {
    if (isEmptyQueue2(q)) {
        printf("Queue 2 is empty\n");
        return;
    }
    printf("Queue 2 contents: ");
    int i = q->front2;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear2) {
            break;
        }
        i = (i + 1) % (N - N / 2);
    }
    printf("\n");
}

// Main function to demonstrate the two circular queues
int main() {
    TwoCircularQueues q;
    initQueues(&q);

    // Test the first queue
    enqueueQueue1(&q, 10);
    enqueueQueue1(&q, 20);
    displayQueue1(&q);

    dequeueQueue1(&q);
    displayQueue1(&q);

    enqueueQueue1(&q, 30);
    enqueueQueue1(&q, 40);
    displayQueue1(&q);

    // Test the second queue
    enqueueQueue2(&q, 50);
    enqueueQueue2(&q, 60);
    displayQueue2(&q);

    dequeueQueue2(&q);
    displayQueue2(&q);

    enqueueQueue2(&q, 70);
    enqueueQueue2(&q, 80);
    displayQueue2(&q);

    return 0;
}


/* SAMPLE OUTPUT 
Enqueued to Queue 1: 10
Enqueued to Queue 1: 20
Queue 1 contents: 10 20 
Dequeued from Queue 1: 10
Queue 1 contents: 20 
Enqueued to Queue 1: 30
Enqueued to Queue 1: 40
Queue 1 contents: 20 30 40 
Enqueued to Queue 2: 50
Enqueued to Queue 2: 60
Queue 2 contents: 50 60 
Dequeued from Queue 2: 50
Queue 2 contents: 60 
Enqueued to Queue 2: 70
Enqueued to Queue 2: 80
Queue 2 contents: 60 70 80 
*/