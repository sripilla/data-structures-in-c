public interface CircularQueueADT {
    // Method to add an element to the queue (enqueue operation)
    void enqueue(int element);

    // Method to remove and return the front element from the queue (dequeue operation)
    int dequeue();

    // Method to return the front element without removing it (peek operation)
    int peek();

    // Method to check if the queue is full
    boolean isFull();

    // Method to check if the queue is empty
    boolean isEmpty();

    // Method to display the queue elements
    void displayQueue();
}
