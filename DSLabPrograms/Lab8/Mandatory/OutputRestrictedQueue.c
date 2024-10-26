/* Implement a queue of strings using an output restricted deque (no deleteRight).
Note: An output-restricted deque is one where insertion can be made at both ends, but deletion can be made from one end only, where as An input-restricted deque isone where deletion can be made from both ends, but insertion can be made at one end only.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5 // Maximum number of elements in the queue
#define STR_LEN 100 // Maximum length of the string

// Define the structure for the Output Restricted Deque
struct Deque {
    char items[MAX][STR_LEN]; // Array to store strings
    int front, rear;          // Front and rear indices
};

// Function to initialize the deque
void initDeque(struct Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
}

// Check if deque is full
int isFull(struct Deque *dq) {
    return ((dq->front == 0 && dq->rear == MAX - 1) || (dq->front == dq->rear + 1));
}

// Check if deque is empty
int isEmpty(struct Deque *dq) {
    return (dq->front == -1);
}

// Insert an element at the rear
void insertRight(struct Deque *dq, char str[]) {
    if (isFull(dq)) {
        printf("Queue is full. Cannot insert %s at the rear.\n", str);
        return;
    }

    // If the deque is empty
    if (dq->front == -1) {
        dq->front = 0;
        dq->rear = 0;
    }
    // If rear is at the last position of the deque, wrap around
    else if (dq->rear == MAX - 1) {
        dq->rear = 0;
    }
    // Otherwise, increment rear
    else {
        dq->rear++;
    }
    strcpy(dq->items[dq->rear], str);
    printf("Inserted %s at the rear.\n", str);
}

// Insert an element at the front
void insertLeft(struct Deque *dq, char str[]) {
    if (isFull(dq)) {
        printf("Queue is full. Cannot insert %s at the front.\n", str);
        return;
    }

    // If the deque is empty
    if (dq->front == -1) {
        dq->front = 0;
        dq->rear = 0;
    }
    // If front is at the first position, wrap around to the last position
    else if (dq->front == 0) {
        dq->front = MAX - 1;
    }
    // Otherwise, decrement front
    else {
        dq->front--;
    }
    strcpy(dq->items[dq->front], str);
    printf("Inserted %s at the front.\n", str);
}

// Delete an element from the front
void deleteLeft(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Queue is empty. Cannot delete from the front.\n");
        return;
    }

    printf("Deleted %s from the front.\n", dq->items[dq->front]);

    // If the deque has only one element
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    }
    // If front is at the last position, wrap around to the first


/* SAMPLE OUTPUT
Inserted apple at the rear.
Inserted banana at the rear.
Inserted cherry at the front.
Inserted date at the rear.
Inserted elderberry at the front.
Current elements in the queue: 
elderberry cherry apple banana date 
Deleted elderberry from the front.
Current elements in the queue: 
cherry apple banana date 
Deleted cherry from the front.
Current elements in the queue: 
apple banana date 
*/