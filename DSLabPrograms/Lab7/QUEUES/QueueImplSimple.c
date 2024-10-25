#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the queue

int queue[MAX]; // Array to store queue elements
int front = -1, rear = -1; // Front and rear pointers

// Function prototypes
void enqueue(int value);
int dequeue();
int peek();
void printQueue();
int isFull();
int isEmpty();

// Function to add an element to the queue
void enqueue(int value) {
    // Check if the queue is full
    if (isFull()) {
        printf("Queue is full\n");
        exit(1); // Exit if the queue is full
    }
    // Initialize front if it's the first element being added
    if (front == -1) 
        front = 0;
    rear++; // Move the rear pointer forward
    queue[rear] = value; // Add the new value to the queue
}

// Function to remove and return the front element from the queue
int dequeue() {
    int value; // Variable to hold the dequeued value
    // Check if the queue is empty
    if (isEmpty()) {
        printf("Queue is empty\n");
        exit(1); // Exit if the queue is empty
    }
    value = queue[front]; // Get the front value
    front++; // Move the front pointer forward
    return value; // Return the dequeued value
}

// Function to check if the queue is full
int isFull() {
    return rear == MAX - 1; // Returns 1 (true) if full
}

// Function to check if the queue is empty
int isEmpty() {
    return front == -1 || front > rear; // Returns 1 (true) if empty
}

// Function to get the front element without removing it
int peek() {
    // Check if the queue is empty
    if (isEmpty()) {
        printf("Queue is empty\n");
        exit(1); // Exit if the queue is empty
    }
    return queue[front]; // Return the front value
}

// Function to print all elements in the queue
void printQueue() {
    int i;
    // Check if the queue is empty
    if (isEmpty()) {
        printf("Queue underflow\n");
        exit(1); // Exit if the queue is empty
    }
    // Print elements from front to rear
    for (i = front; i <= rear; i++)
        printf("%d ", queue[i]); 
    printf("\n"); // Newline after printing all elements
}

int main() {
    int choice, value; // Value variable for user input
    while (1) {
        // Display menu options
        printf("\n1. Insert\n2. Delete\n3. Peek\n4. Print\n5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // User choice input
        switch (choice) {
            case 1: 
                printf("Enter the element to be added to the queue: ");
                scanf("%d", &value); // User input for the queue element
                enqueue(value); // Add element to the queue
                printf("Element %d added to queue\n", value);
                break;
            case 2:
                value = dequeue(); // Remove and get front element
                printf("Element %d deleted from queue\n", value);
                break;
            case 3:
                printf("Front element is %d\n", peek()); // Show front element
                break;
            case 4:  
                printf("Queue elements are: ");
                printQueue(); // Print all queue elements
                break;
            case 5:
                exit(0); // Exit the program
            default:
                printf("Wrong choice\n"); // Handle invalid choices
        }
    }
}
