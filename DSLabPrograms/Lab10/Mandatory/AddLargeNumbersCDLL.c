/*Add two long positive integers represented using circular doubly linked list with
header node */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for the Circular Doubly Linked List node
struct Node {
    int data;               // Data to store the digit
    struct Node* next;      // Pointer to the next node
    struct Node* prev;      // Pointer to the previous node
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory
    newNode->data = data;          // Set the node data
    newNode->next = newNode;       // Circular: Points to itself initially
    newNode->prev = newNode;       // Circular: Points to itself initially
    return newNode;                // Return the new node
}

// Function to insert a node at the end of the circular doubly linked list
void insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data); // Create a new node
    struct Node* last = head->prev;          // Last node is before the head node

    // Update the pointers to add the new node to the circular list
    last->next = newNode;       // Last node's next points to the new node
    newNode->prev = last;       // New node's previous points to the last node
    newNode->next = head;       // New node's next points to the head (circular)
    head->prev = newNode;       // Head's previous points to the new node
}

// Function to display the circular doubly linked list
void displayList(struct Node* head) {
    struct Node* temp = head->next;  // Start from the first node
    if (temp == head) {
        printf("The list is empty.\n");
        return;
    }
    while (temp != head) {           // Traverse till we reach the head again
        printf("%d ", temp->data);   // Print the data
        temp = temp->next;           // Move to the next node
    }
    printf("\n");
}

// Function to add two circular doubly linked lists representing large numbers
struct Node* addTwoLists(struct Node* list1, struct Node* list2) {
    struct Node* resultHead = createNode(0);  // Create a header node for the result list
    struct Node* resultTail = resultHead;     // Pointer to keep track of the result list's tail
    struct Node* temp1 = list1->next;         // Start from the first node of list1
    struct Node* temp2 = list2->next;         // Start from the first node of list2
    int carry = 0;                            // Initialize carry to 0

    // Loop until both lists are exhausted and no carry remains
    while (temp1 != list1 || temp2 != list2 || carry) {
        int sum = carry;  // Start with carry value

        // Add the digit from list1 if available
        if (temp1 != list1) {
            sum += temp1->data;
            temp1 = temp1->next;  // Move to the next node in list1
        }

        // Add the digit from list2 if available
        if (temp2 != list2) {
            sum += temp2->data;
            temp2 = temp2->next;  // Move to the next node in list2
        }

        // Update carry for the next iteration
        carry = sum / 10;

        // Insert the result digit into the result list
        insertEnd(resultHead, sum % 10);
    }

    return resultHead;  // Return the header node of the result list
}

// Function to free the memory of the entire circular doubly linked list
void freeList(struct Node* head) {
    struct Node* temp = head->next;
    while (temp != head) {
        struct Node* toDelete = temp;
        temp = temp->next;
        free(toDelete);
    }
    free(head);  // Free the header node
}

// Main function to drive the program
int main() {
    struct Node* list1 = createNode(0);  // Create header node for the first number
    struct Node* list2 = createNode(0);  // Create header node for the second number
    struct Node* result = NULL;          // Pointer to store the result list

    // Input the first large number
    printf("Enter the first number (digits in reverse order): ");
    int digit;
    while (scanf("%d", &digit) == 1) {
        if (digit < 0) break;  // Negative input terminates the input
        insertEnd(list1, digit);  // Insert each digit into list1
    }

    // Input the second large number
    printf("Enter the second number (digits in reverse order): ");
    while (scanf("%d", &digit) == 1) {
        if (digit < 0) break;  // Negative input terminates the input
        insertEnd(list2, digit);  // Insert each digit into list2
    }

    // Display the two input numbers
    printf("\nFirst number: ");
    displayList(list1);
    printf("Second number: ");
    displayList(list2);

    // Add the two numbers represented by the lists
    result = addTwoLists(list1, list2);

    // Display the result of the addition
    printf("Sum: ");
    displayList(result);

    // Free the memory used by the lists
    freeList(list1);
    freeList(list2);
    freeList(result);

    return 0;
}

/*SAMPLE OUTPUT
Enter the first number (digits in reverse order): 5 4 3 2 -1
Enter the second number (digits in reverse order): 9 8 7 6 -1

First number: 5 4 3 2
Second number: 9 8 7 6
Sum: 4 3 1 9 1

*/
