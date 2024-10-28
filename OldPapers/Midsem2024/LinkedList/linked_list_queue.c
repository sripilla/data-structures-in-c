/* Linked lists find applications in the implementation of queues using dynamic
memory allocation. To insert an item into the queue, we allocate memory for the
new node, store data in it, and add the node at the rear end of the existing queue. To
delete an item from the queue, the node at the front of the queue is removed.
Assume the typical function calls for enqueue() and dequeue() as enqueue(&rear,
&front, N); and dequeue(&front, &rear);, where N is the element to be added. The
structure definition of the node is as given.
// Self- referential structure
typedef struct node *queue; struct node{ int data; Nodeptr next; };
Develop the functions to implement linked implementation of enqueue() and
dequeue() operations.*/

#include <stdio.h>
#include <stdlib.h>

// Self-referential structure for the queue node
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function prototypes
void enqueue(Node** rear, Node** front, int N);
int dequeue(Node** front, Node** rear);
void display(Node* front);

int main() {
    Node* front = NULL;
    Node* rear = NULL;

    // Testing the queue operations
    enqueue(&rear, &front, 10);
    enqueue(&rear, &front, 20);
    enqueue(&rear, &front, 30);

    printf("Queue after enqueue operations: ");
    display(front);

    printf("Dequeued: %d\n", dequeue(&front, &rear));
    printf("Dequeued: %d\n", dequeue(&front, &rear));

    printf("Queue after dequeue operations: ");
    display(front);

    return 0;
}

// Function to add an item to the queue
void enqueue(Node** rear, Node** front, int N) {
    // Allocate memory for new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = N;
    newNode->next = NULL;

    // If queue is empty, set both front and rear to the new node
    if (*rear == NULL) {
        *front = *rear = newNode;
        return;
    }

    // Add the new node at the end of the queue and update the rear pointer
    (*rear)->next = newNode;
    *rear = newNode;
}

// Function to remove an item from the queue
int dequeue(Node** front, Node** rear) {
    // If the queue is empty, return -1
    if (*front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }

    // Store the node to be dequeued and update front pointer
    Node* temp = *front;
    int dequeuedData = temp->data;
    *front = (*front)->next;

    // If the queue becomes empty after the dequeue operation, update rear
    if (*front == NULL) {
        *rear = NULL;
    }

    // Free the memory of the dequeued node
    free(temp);
    return dequeuedData;
}

// Function to display the queue elements
void display(Node* front) {
    Node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* SAMPLE OUTPUT
Queue after enqueue operations: 10 20 30 
Dequeued: 10
Dequeued: 20
Queue after dequeue operations: 30 
*/