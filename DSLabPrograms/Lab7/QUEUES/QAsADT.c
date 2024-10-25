// Abstract Data Type (ADT) for Queue

// Function to create a queue
Queue CreateQ(max_queue_size) ::= 
    create an empty queue whose maximum size is max_queue_size

// Function to check if the queue is full
Boolean IsFullQ(queue, max_queue_size) ::= 
    if (number of elements in queue == max_queue_size) 
        return TRUE 
    else 
        return FALSE

// Function to add an element to the queue
Queue AddQ(queue, item) ::= 
    if (IsFullQ(queue)) 
        queue_full 
    else 
        insert item at rear of queue and return queue

// Function to check if the queue is empty
Boolean IsEmptyQ(queue) ::= 
    if (queue == CreateQ(max_queue_size)) 
        return TRUE 
    else 
        return FALSE

// Function to delete an element from the queue
Element DeleteQ(queue) ::= 
    if (IsEmptyQ(queue)) 
        return 
    else 
        remove and return the item at front of queue
