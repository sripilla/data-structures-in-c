/* Consider the following structure definition.
struct list1
{
int data;
struct list1 *next;
};
Write the C functions to implement the following operations on the singly linked
list of integers with header node.
Insert: To insert a node into the list in sorted order. The parameters of this function
are a pointer to the header node and an integer to be inserted.
RemoveDuplicate: To remove the duplicate element from the list. The parameter
of this function is a pointer to the header node.*/

// Structure Definition:
#include <stdio.h>
#include <stdlib.h>

// Define the structure for the list node
struct list1 {
    int data;
    struct list1 *next;
};

// Function to Insert a Node in Sorted Order:

// Function to insert a node into the list in sorted order
void insert(struct list1 *head, int value) {
    // Create a new node
    struct list1 *newNode = (struct list1 *)malloc(sizeof(struct list1));
    newNode->data = value;
    newNode->next = NULL;

    // Start from the header node
    struct list1 *current = head;

    // Find the correct position to insert the new node
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    // Insert the new node
    newNode->next = current->next;
    current->next = newNode;

    printf("Inserted %d into the list.\n", value);
}

// Function to Remove Duplicates:
// Function to remove duplicate elements from the list
void removeDuplicate(struct list1 *head) {
    struct list1 *current = head->next;  // Skip header node

    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            // Duplicate found, remove the next node
            struct list1 *duplicateNode = current->next;
            current->next = current->next->next;
            free(duplicateNode);
            printf("Removed duplicate node with value %d.\n", current->data);
        } else {
            // Move to the next node if no duplicate
            current = current->next;
        }
    }
}

// Helper Functions:
   //Print List: A utility function to print the elements of the list.
   //Create List: A function to initialize a list with a header node
// Function to create and initialize a linked list with a header node
struct list1* createList() {
    struct list1 *header = (struct list1 *)malloc(sizeof(struct list1));
    header->data = -1; // Header node has no valid data
    header->next = NULL;
    return header;
}

// Function to print the list
void printList(struct list1 *head) {
    struct list1 *current = head->next; // Skip header node
    printf("List elements: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Main Function:
int main() {
    // Create an empty list with a header node
    struct list1 *head = createList();

    // Insert elements in sorted order
    insert(head, 10);
    insert(head, 20);
    insert(head, 15);
    insert(head, 20);  // Insert duplicate element
    insert(head, 30);
    insert(head, 25);

    printf("Before removing duplicates:\n");
    printList(head);

    // Remove duplicates from the list
    removeDuplicate(head);

    printf("After removing duplicates:\n");
    printList(head);

    return 0;
}

/* SAMPLE OUTPUT
Inserted 10 into the list.
Inserted 20 into the list.
Inserted 15 into the list.
Inserted 20 into the list.
Inserted 30 into the list.
Inserted 25 into the list.
Before removing duplicates:
List elements: 10 -> 15 -> 20 -> 20 -> 25 -> 30 -> NULL
Removed duplicate node with value 20.
After removing duplicates:
List elements: 10 -> 15 -> 20 -> 25 -> 30 -> NULL
*/