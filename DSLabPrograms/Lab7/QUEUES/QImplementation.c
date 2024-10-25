// Queue Array Implementation

#define MAX_QUEUE_SIZE 100

typedef struct {
    int key;
    /* other fields */
} element;

element queue[MAX_QUEUE_SIZE];
int rear = -1;
int front = -1;

// Function to create an empty queue with a given size
void CreateQ(int max_queue_size) {
    front = 0;
    rear = -1;
    // Queue initialization logic can go here, depending on needs.
    // max_queue_size would generally be used as a limit for queue expansion.
}

// Function to check if the queue is full
int isFull() {
    return rear == MAX_QUEUE_SIZE - 1;
}

// Function to insert an item into the queue
void insertQ(element item) {
    if (rear == MAX_QUEUE_SIZE - 1) {
        printf("QUEUE OVERFLOW\n");
        return;
    }
    rear = rear + 1;
    queue[rear] = item;
}

// Function to check if the queue is empty
int isEmpty() {
    return front > rear;
}

// Function to delete an item from the queue
int deleteQ() {
    if (front > rear)
        return -1;  // Queue is empty
    return queue[front++];
}

// Function to display the contents of the queue
void display() {
    int i;
    if (front > rear) {
        printf("Q is empty\n");
        return;
    }

    printf("Contents of the Q:\n");
    for (i = front; i <= rear; i++) {
        printf("%d\n", queue[i]);
    }
}

// ADD TO A QUEUE: Alternate approach (assuming front = -1 and rear = -1)
void addq(int *rear, element item) {
    if (*rear == MAX_QUEUE_SIZE - 1) {
        printf("QUEUE FULL\n");
        return;
    }
    queue[++*rear] = item;
}

// DELETE FROM A QUEUE: Alternate approach
element deleteq(int *front, int rear) {
    if (*front == rear)
        return -1;  // Queue is empty
    return queue[++*front];
}
