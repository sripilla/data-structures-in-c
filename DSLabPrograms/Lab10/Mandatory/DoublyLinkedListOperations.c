/* Write a menu driven program to implement doubly linked list without header node
to insert into and delete from both the sides.*/

#include <stdio.h>
#include <stdlib.h>

// Define node structure for doubly linked list
struct Node {
    int data;               // Data to store the value
    struct Node* next;      // Pointer to next node
    struct Node* prev;      // Pointer to previous node
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for a new node
    newNode->data = data;       // Assign the data to the node
    newNode->next = NULL;       // Set the next pointer to NULL as it's the last node initially
    newNode->prev = NULL;       // Set the previous pointer to NULL
    return newNode;             // Return the new node
}

// Function to insert a node at the beginning (front) of the doubly linked list
void insertFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);  // Create a new node
    if (*head == NULL) {                      // If the list is empty
        *head = newNode;                       // The new node becomes the head
    } else {
        newNode->next = *head;                 // Link the new node to the current head
        (*head)->prev = newNode;               // Link the current head to the new node
        *head = newNode;                       // Update the head to the new node
    }
}

// Function to insert a node at the end (tail) of the doubly linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);  // Create a new node
    if (*head == NULL) {                      // If the list is empty
        *head = newNode;                       // The new node becomes the head
    } else {
        struct Node* temp = *head;             // Create a temporary pointer to traverse the list
        while (temp->next != NULL) {           // Traverse to the last node
            temp = temp->next;
        }
        temp->next = newNode;                  // Link the last node to the new node
        newNode->prev = temp;                  // Link the new node back to the last node
    }
}

// Function to delete a node from the beginning (front) of the doubly linked list
void deleteFront(struct Node** head) {
    if (*head == NULL) {                      // Check if the list is empty
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = *head;                 // Create a temporary pointer to hold the head node
    *head = (*head)->next;                     // Update the head to the next node
    if (*head != NULL) {
        (*head)->prev = NULL;                  // Set the previous pointer of the new head to NULL
    }
    free(temp);                                // Free the memory of the old head node
}

// Function to delete a node from the end (tail) of the doubly linked list
void deleteEnd(struct Node** head) {
    if (*head == NULL) {                      // Check if the list is empty
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = *head;                 // Create a temporary pointer to traverse the list
    while (temp->next != NULL) {               // Traverse to the last node
        temp = temp->next;
    }
    if (temp->prev != NULL) {                  // If the list has more than one node
        temp->prev->next = NULL;               // Set the previous node's next pointer to NULL
    } else {
        *head = NULL;                          // If the list has only one node, set head to NULL
    }
    free(temp);                                // Free the memory of the last node
}

// Function to display the doubly linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");        // Check if the list is empty
        return;
    }
    struct Node* temp = head;                  // Create a temporary pointer to traverse the list
    while (temp != NULL) {                     // Traverse the list
        printf("->%d", temp->data);            // Print the current node's data
        temp = temp->next;                     // Move to the next node
    }
    printf("\n");
}

// Function to free the memory of the entire list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;                     // Move to the next node
        free(temp);                            // Free the memory of the current node
    }
}

// Main function to drive the menu and perform operations on the doubly linked list
int main() {
    struct Node* head = NULL;  // Initialize the head of the list to NULL
    int choice, data;

    while (1) {
        // Display the menu
        printf("\nMenu:\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Delete from front\n");
        printf("4. Delete from end\n");
        printf("5. Display list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertFront(&head, data);  // Insert data at the front
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertEnd(&head, data);    // Insert data at the end
                break;
            case 3:
                deleteFront(&head);        // Delete node from the front
                break;
            case 4:
                deleteEnd(&head);          // Delete node from the end
                break;
            case 5:
                displayList(head);         // Display the current list
                break;
            case 6:
                freeList(head);            // Free the memory before exiting
                printf("Exiting...\n");
                exit(0);                    // Exit the program
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}


/* SAMPLE OUTPUT
Menu:
1. Insert at front
2. Insert at end
3. Delete from front
4. Delete from end
5. Display list
6. Exit
Enter your choice: 1
Enter data to insert at front: 10

Menu:
1. Insert at front
2. Insert at end
3. Delete from front
4. Delete from end
5. Display list
6. Exit
Enter your choice: 2
Enter data to insert at end: 20

Menu:
1. Insert at front
2. Insert at end
3. Delete from front
4. Delete from end
5. Display list
6. Exit
Enter your choice: 5
->10->20

Menu:
1. Insert at front
2. Insert at end
3. Delete from front
4. Delete from end
5. Display list
6. Exit
Enter your choice: 3

Menu:
1. Insert at front
2. Insert at end
3. Delete from front
4. Delete from end
5. Display list
6. Exit
Enter your choice: 5
->20
*/