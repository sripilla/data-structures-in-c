/*Implement a queue using singly linked list without header node. */
class Node {
    int data;
    Node next;

    // Constructor to initialize node
    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class Queue {
    private Node front, rear;

    // Constructor to initialize empty queue
    public Queue() {
        this.front = this.rear = null;
    }

    // Method to add element at the rear (enqueue)
    public void enqueue(int data) {
        Node newNode = new Node(data);

        // If queue is empty, then front and rear both will be the new node
        if (rear == null) {
            front = rear = newNode;
            System.out.println("Enqueued: " + data);
            return;
        }

        // Add the new node at the end of the queue and update the rear pointer
        rear.next = newNode;
        rear = newNode;
        System.out.println("Enqueued: " + data);
    }

    // Method to remove element from the front (dequeue)
    public int dequeue() {
        // Check if queue is empty
        if (front == null) {
            System.out.println("Queue is empty!");
            return -1;
        }

        // Move the front pointer to the next node
        int data = front.data;
        front = front.next;

        // If front becomes null, then rear must also be null (queue becomes empty)
        if (front == null) {
            rear = null;
        }

        System.out.println("Dequeued: " + data);
        return data;
    }

    // Method to get the front element of the queue
    public int peek() {
        if (front == null) {
            System.out.println("Queue is empty!");
            return -1;
        }
        return front.data;
    }

    // Method to check if the queue is empty
    public boolean isEmpty() {
        return front == null;
    }
}

// Test the Queue implementation
public class QueueUsingLinkedList {
    public static void main(String[] args) {
        Queue queue = new Queue();

        // Enqueue elements
        queue.enqueue(10);
        queue.enqueue(20);
        queue.enqueue(30);

        // Display front element
        System.out.println("Front element is: " + queue.peek());

        // Dequeue elements
        queue.dequeue();
        queue.dequeue();

        // Check if queue is empty
        System.out.println("Queue is empty: " + queue.isEmpty());

        // Dequeue another element
        queue.dequeue();

        // Attempt to dequeue from empty queue
        queue.dequeue();
    }
}

/*SAMPLE OUTPUT
Enqueued: 10
Enqueued: 20
Enqueued: 30
Front element is: 10
Dequeued: 10
Dequeued: 20
Queue is empty: false
Dequeued: 30
Queue is empty: true
Queue is empty!
*/