/* Reverse a doubly linked list containing words in the data field. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define node structure for a doubly linked list
struct Node {
    char data[100];  // Data field to store a word (string)
    struct Node* next;  // Pointer to the next node in the list
    struct Node* prev;  // Pointer to the previous node in the list
};

// Function to create a new node with given data (word)
struct Node* createNode(char data[]) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Copy the word (data) into the new node's data field
    strcpy(newNode->data, data);

    // Initialize the next and prev pointers to NULL
    newNode->next = NULL;
    newNode->prev = NULL;

    // Return the newly created node
    return newNode;
}

// Function to insert a new node at the end of the doubly linked list
void insertEnd(struct Node** head, char data[]) {
    // Create a new node with the given data (word)
    struct Node* newNode = createNode(data);

    // If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = newNode;
    } else {
        // If the list is not empty, traverse to the last node
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Insert the new node at the end
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to display the doubly linked list
void displayList(struct Node* head) {
    // Traverse the list and print each node's data
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%s ", temp->data);  // Print the word stored in the node
        temp = temp->next;  // Move to the next node
    }
    printf("\n");  // Print a newline after displaying the list
}

// Function to reverse the doubly linked list
void reverseList(struct Node** head) {
    struct Node* temp = NULL;
    struct Node* current = *head;

    // Traverse the list and reverse the next and prev pointers of each node
    while (current != NULL) {
        // Swap the next and prev pointers for the current node
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to the previous node (which is now the next node after swap)
        current = current->prev;
    }

    // If the list is not empty, update the head to point to the last node
    if (temp != NULL) {
        *head = temp->prev;
    }
}

// Function to free the memory of the doubly linked list
void freeList(struct Node* head) {
    struct Node* temp;
    // Traverse the list and free each node's memory
    while (head != NULL) {
        temp = head;
        head = head->next;  // Move to the next node
        free(temp);  // Free the current node
    }
}

// Main function to test the program
int main() {
    struct Node* head = NULL;  // Initialize an empty list

    // Insert words (data) into the doubly linked list
    insertEnd(&head, "Hello");
    insertEnd(&head, "world");
    insertEnd(&head, "this");
    insertEnd(&head, "is");
    insertEnd(&head, "a");
    insertEnd(&head, "test");

    // Display the original list
    printf("Original List: ");
    displayList(head);

    // Reverse the list
    reverseList(&head);

    // Display the reversed list
    printf("Reversed List: ");
    displayList(head);

    // Free the memory allocated for the list
    freeList(head);

    return 0;
}

/* SAMPLE OUTPUT
Original List: Hello world this is a test 
Reversed List: test a is this world Hello 
*/