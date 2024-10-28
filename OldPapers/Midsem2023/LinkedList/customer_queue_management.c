/*Consider a scenario of the billing counter of an XYZ company. There are two types of
customers, i.e. premium(P) and loyal customers (L). As per the company policy, the
premium customers are added to the front of the waiting line. If there are K premium
customers at the front of the waiting line, all premium customers are moved to another line
(Premium line). The loyal customers are moved to the front of the line as per their order.
Due to the arrival and departure of customers, the waiting line will grow and shrink at any
point of time. Always loyal customers are added to the end of the waiting line (original line).
The customers leave the system as soon as they get the bill. Implement the scenario using
an efficient data structure.

Ex: Premium  customer p   Loyal customer L
    K = 3

After adding 2 Premium customers and 4 Loyal customers

P-> P -> L -> L -> L -> L

The waiting line is shown below after three successive deletions

L->L->L

Add 3 Premium customers

P-> P -> P -> L -> L -> L

After the insertion

Original line: P-> P -> P

Premium line:  L -> L -> L

Structure declaration 0.5M
memory allocation 0.5M
q=(struct cust*)malloc(sizeof(struct cust));
INSERT FUNCTION
Inserting to original queue -1M
Inserting to Premium queue-1M */

/*So overall, this program uses:

singly linked list implementation for the queues

A priority queue for the Original queue, with a linked list structure, and
A FIFO queue for the Premium queue, also with a linked list structure. */

#include <stdio.h>
#include <stdlib.h>

struct Customer {
    char type;              // 'P' for Premium, 'L' for Loyal
    struct Customer* next;
};

// Queue structure for both Original and Premium lines
struct Queue {
    struct Customer* front;
    struct Customer* rear;
};

// Function to initialize a queue
struct Queue* create_queue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to create a new customer
struct Customer* create_customer(char type) {
    struct Customer* newCust = (struct Customer*)malloc(sizeof(struct Customer));
    newCust->type = type;
    newCust->next = NULL;
    return newCust;
}

// Insert a Premium customer at the front of the queue
void insert_premium(struct Queue* q, char type) {
    struct Customer* newCust = create_customer(type);
    if (q->front == NULL) {
        q->front = q->rear = newCust;
    } else {
        newCust->next = q->front;
        q->front = newCust;
    }
}

// Insert a Loyal customer at the rear of the queue
void insert_loyal(struct Queue* q, char type) {
    struct Customer* newCust = create_customer(type);
    if (q->rear == NULL) {
        q->front = q->rear = newCust;
    } else {
        q->rear->next = newCust;
        q->rear = newCust;
    }
}

// Function to transfer premium customers to Premium line if there are K or more
void transfer_premium_customers(struct Queue* original, struct Queue* premium, int K) {
    int count = 0;
    struct Customer* temp = original->front;

    // Count premium customers at the front of the Original line
    while (temp != NULL && temp->type == 'P') {
        count++;
        temp = temp->next;
    }

    // If there are K or more premium customers, transfer them
    if (count >= K) {
        while (count > 0 && original->front != NULL && original->front->type == 'P') {
            struct Customer* moveCust = original->front;
            original->front = original->front->next;
            moveCust->next = NULL;
            if (premium->rear == NULL) {
                premium->front = premium->rear = moveCust;
            } else {
                premium->rear->next = moveCust;
                premium->rear = moveCust;
            }
            count--;
        }
        if (original->front == NULL) {
            original->rear = NULL;
        }
    }
}

// Function to delete a customer from the front of the queue
void delete_customer(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Customer* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
}

// Function to display the queue
void display_queue(struct Queue* q) {
    struct Customer* temp = q->front;
    while (temp != NULL) {
        printf("%c -> ", temp->type);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int K = 3;  // Threshold for transferring Premium customers
    struct Queue* originalQueue = create_queue();
    struct Queue* premiumQueue = create_queue();

    // Adding 2 Premium customers and 4 Loyal customers
    insert_premium(originalQueue, 'P');
    insert_premium(originalQueue, 'P');
    insert_loyal(originalQueue, 'L');
    insert_loyal(originalQueue, 'L');
    insert_loyal(originalQueue, 'L');
    insert_loyal(originalQueue, 'L');

    printf("Original queue after adding customers:\n");
    display_queue(originalQueue);

    // Three successive deletions
    printf("\nOriginal queue after three deletions:\n");
    delete_customer(originalQueue);
    delete_customer(originalQueue);
    delete_customer(originalQueue);
    display_queue(originalQueue);

    // Add 3 more Premium customers
    insert_premium(originalQueue, 'P');
    insert_premium(originalQueue, 'P');
    insert_premium(originalQueue, 'P');

    printf("\nOriginal queue after adding 3 Premium customers:\n");
    display_queue(originalQueue);

    // Transfer Premium customers if count >= K
    transfer_premium_customers(originalQueue, premiumQueue, K);

    printf("\nOriginal line after transferring Premium customers:\n");
    display_queue(originalQueue);
    printf("Premium line:\n");
    display_queue(premiumQueue);

    return 0;
}


/* SAMPLE OUTPUT
Original queue after adding customers:
P -> P -> L -> L -> L -> L -> NULL

Original queue after three deletions:
L -> L -> L -> NULL

Original queue after adding 3 Premium customers:
P -> P -> P -> L -> L -> L -> NULL

Original line after transferring Premium customers:
L -> L -> L -> NULL
Premium line:
P -> P -> P -> NULL
*/