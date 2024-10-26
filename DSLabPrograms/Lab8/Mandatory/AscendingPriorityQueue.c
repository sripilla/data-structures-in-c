/*Implement an ascending priority queue.
Note: An ascending priority queue is a collection of items into which items can be inserted arbitrarily and from which only the smallest item can be removed. If apq is an ascending priority queue, the operation

pqinsert(apq,x) inserts element x into apq and 
pqmindelete(apq) removes the minimum element from apq and returns its value. */

#include <stdio.h>
#include <limits.h> // For INT_MAX

#define MAX 100

// Structure for an ascending priority queue
struct PriorityQueue {
    int items[MAX]; // Array to store the elements
    int size;       // Number of elements in the queue
};

// Function to initialize the priority queue
void initQueue(struct PriorityQueue* pq) {
    pq->size = 0; // Initially, the queue is empty
}

// Function to insert an element into the priority queue
void pqinsert(struct PriorityQueue* pq, int x) {
    if (pq->size == MAX) {
        printf("Priority Queue is full. Cannot insert %d\n", x);
        return;
    }
    pq->items[pq->size] = x; // Insert the element at the end
    pq->size++;
    printf("Inserted %d into the priority queue.\n", x);
}

// Function to remove and return the minimum element from the priority queue
int pqmindelete(struct PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty.\n");
        return INT_MAX; // Return a large value indicating the queue is empty
    }

    // Find the minimum element and its index
    int minIdx = 0;
    for (int i = 1; i < pq->size; i++) {
        if (pq->items[i] < pq->items[minIdx]) {
            minIdx = i;
        }
    }

    int minValue = pq->items[minIdx];

    // Remove the minimum element by shifting the elements
    for (int i = minIdx; i < pq->size - 1; i++) {
        pq->items[i] = pq->items[i + 1];
    }

    pq->size--; // Reduce the size of the queue
    return minValue;
}

// Function to display the current elements in the priority queue
void displayQueue(struct PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("Priority Queue elements: ");
    for (int i = 0; i < pq->size; i++) {
        printf("%d ", pq->items[i]);
    }
    printf("\n");
}

// Main function to demonstrate the priority queue operations
int main() {
    struct PriorityQueue apq;
    initQueue(&apq); // Initialize the priority queue

    // Insert elements into the ascending priority queue
    pqinsert(&apq, 15);
    pqinsert(&apq, 5);
    pqinsert(&apq, 30);
    pqinsert(&apq, 10);
    pqinsert(&apq, 20);

    // Display the current state of the priority queue
    displayQueue(&apq);

    // Delete the minimum element
    printf("Minimum element removed: %d\n", pqmindelete(&apq));
    displayQueue(&apq);

    printf("Minimum element removed: %d\n", pqmindelete(&apq));
    displayQueue(&apq);

    return 0;
}

/*SAMPLE OUTPUT
Inserted 15 into the priority queue.
Inserted 5 into the priority queue.
Inserted 30 into the priority queue.
Inserted 10 into the priority queue.
Inserted 20 into the priority queue.
Priority Queue elements: 15 5 30 10 20 
Minimum element removed: 5
Priority Queue elements: 15 30 10 20 
Minimum element removed: 10
Priority Queue elements: 15 30 20 
*/