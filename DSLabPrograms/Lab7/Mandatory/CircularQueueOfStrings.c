/*Implement a circular queue of Strings using structures. Include functions insertcq,
deletecq and displaycq.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5 // Maximum number of elements in the circular queue
#define STRING_LENGTH 100 // Maximum length of each string

// Structure to represent a circular queue
struct CircularQueue {
    char data[MAX][STRING_LENGTH]; // Array to hold the strings
    int front; // Index of the front element
    int rear; // Index of the rear element
};

// Function to initialize the circular queue
void initQueue(struct CircularQueue* cq) {
    cq->front = -1;
    cq->rear = -1;
}

// Function to check if the queue is full
int isFull(struct CircularQueue* cq) {
    return (cq->rear + 1) % MAX == cq->front;
}

// Function to check if the queue is empty
int isEmpty(struct CircularQueue* cq) {
    return cq->front == -1;
}

// Function to insert a string into the circular queue
void insertcq(struct CircularQueue* cq, char* str) {
    if (isFull(cq)) {
        printf("Queue is full. Cannot insert '%s'.\n", str);
        return;
    }
    if (isEmpty(cq)) {
        cq->front = 0; // Set front to 0 if inserting the first element
    }
    cq->rear = (cq->rear + 1) % MAX; // Move rear forward circularly
    strcpy(cq->data[cq->rear], str); // Copy the string to the queue
    printf("Inserted '%s' into the queue.\n", str);
}

// Function to delete a string from the circular queue
void deletecq(struct CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty. Cannot delete.\n");
        return;
    }
    printf("Deleted '%s' from the queue.\n", cq->data[cq->front]);
    if (cq->front == cq->rear) { // If the queue has only one element
        cq->front = -1;
        cq->rear = -1;
    } else {
        cq->front = (cq->front + 1) % MAX; // Move front forward circularly
    }
}

// Function to display the circular queue
void displaycq(struct CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Circular Queue contents:\n");
    int i = cq->front;
    while (1) {
        printf("%s ", cq->data[i]);
        if (i == cq->rear) break; // Stop when we've reached the rear
        i = (i + 1) % MAX; // Move forward circularly
    }
    printf("\n");
}

// Main function to demonstrate the circular queue
int main() {
    struct CircularQueue cq;
    initQueue(&cq);

    // Inserting strings into the circular queue
    insertcq(&cq, "Hello");
    insertcq(&cq, "World");
    insertcq(&cq, "Circular");
    insertcq(&cq, "Queue");
    insertcq(&cq, "Example");

    // Displaying the contents of the queue
    displaycq(&cq);

    // Trying to insert another string
    insertcq(&cq, "Overflow");

    // Deleting a string from the queue
    deletecq(&cq);

    // Displaying the contents of the queue after deletion
    displaycq(&cq);

    // Continuing to delete until the queue is empty
    deletecq(&cq);
    deletecq(&cq);
    deletecq(&cq);
    deletecq(&cq);

    // Displaying the queue when empty
    displaycq(&cq);

    return 0;
}


/* SAMPLE OUTPUT

Inserted 'Hello' into the queue.
Inserted 'World' into the queue.
Inserted 'Circular' into the queue.
Inserted 'Queue' into the queue.
Inserted 'Example' into the queue.
Circular Queue contents:
Hello World Circular Queue Example 
Queue is full. Cannot insert 'Overflow'.
Deleted 'Hello' from the queue.
Circular Queue contents:
World Circular Queue Example 
Queue is empty. Cannot delete.
Deleted 'World' from the queue.
Deleted 'Circular' from the queue.
Deleted 'Queue' from the queue.
Deleted 'Example' from the queue.
Queue is empty.
Queue is empty.


*/
