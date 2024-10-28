#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Function to create a new node with given data
struct node* create_node(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the beginning of the list
struct node* insert_at_beginning(struct node* head, int data) {
    struct node* newNode = create_node(data);
    newNode->next = head;
    return newNode;  // New node becomes the new head
}

// Function to insert at the end of the list
struct node* insert_at_end(struct node* head, int data) {
    struct node* newNode = create_node(data);

    // If the list is empty, the new node becomes the head
    if (head == NULL) {
        return newNode;
    }

    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to insert at a specific position in the list
struct node* insert_at_position(struct node* head, int data, int position) {
    struct node* newNode = create_node(data);

    // Insert at the beginning if position is 1
    if (position == 1) {
        newNode->next = head;
        return newNode;
    }

    struct node* temp = head;
    // Traverse to the node just before the target position
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // If position is out of range
    if (temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return head;
    }

    // Link the new node at the specified position
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Function to display the linked list
void display_list(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct node* head = NULL;

    // Insert nodes using different methods
    printf("Inserting 10 at the beginning:\n");
    head = insert_at_beginning(head, 10);
    display_list(head);

    printf("\nInserting 20 at the end:\n");
    head = insert_at_end(head, 20);
    display_list(head);

    printf("\nInserting 30 at the beginning:\n");
    head = insert_at_beginning(head, 30);
    display_list(head);

    printf("\nInserting 40 at position 2:\n");
    head = insert_at_position(head, 40, 2);
    display_list(head);

    printf("\nInserting 50 at the end:\n");
    head = insert_at_end(head, 50);
    display_list(head);

    return 0;
}

/* SAMPLE OUTPUT
Inserting 10 at the beginning:
10 -> NULL

Inserting 20 at the end:
10 -> 20 -> NULL

Inserting 30 at the beginning:
30 -> 10 -> 20 -> NULL

Inserting 40 at position 2:
30 -> 40 -> 10 -> 20 -> NULL

Inserting 50 at the end:
30 -> 40 -> 10 -> 20 -> 50 -> NULL
*/