/* You're given the pointer to the head node of a sorted singly linked list, where the data
in the nodes is in ascending order. Delete as few nodes as possible so that the list does
not contain any value more than once (deleting duplicates). The given head pointer
may be null indicating that the list is empty.*/

#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert node at the end of the linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Remove duplicates from sorted linked list
void removeDuplicates(struct Node* head) {
    struct Node* current = head;

    // Traverse the list
    while (current != NULL && current->next != NULL) {
        // Check if current node data equals the next node data
        if (current->data == current->next->data) {
            struct Node* temp = current->next; // Store duplicate node
            current->next = current->next->next; // Remove duplicate
            free(temp); // Free memory of duplicate node
        } else {
            current = current->next; // Move to the next node
        }
    }
}

// Display linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("->%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Free linked list memory
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// MAIN FUNCTION
int main() {
    struct Node* head = NULL;
    int n, i, data;

    // Input the number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Input nodes in sorted order
    printf("Enter the nodes in ascending order:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        insertEnd(&head, data);
    }

    // Display original list
    printf("\nOriginal List:\n");
    displayList(head);

    // Remove duplicates
    removeDuplicates(head);

    // Display list after removing duplicates
    printf("List after removing duplicates:\n");
    displayList(head);

    // Free memory
    freeList(head);

    return 0;
}

/* SAMPLE OUTPUT
Enter the number of nodes: 8
Enter the nodes in ascending order:
1 2 2 3 4 4 4 5

Original List:
->1->2->2->3->4->4->4->5
List after removing duplicates:
->1->2->3->4->5
*/