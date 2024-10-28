#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Function to create a new node
struct node* create_node(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the end for setup
struct node* insert_at_end(struct node* head, int data) {
    struct node* newNode = create_node(data);
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

// Function to delete a node at the beginning
struct node* delete_at_beginning(struct node* head) {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return head;
    }
    struct node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete a node at the end
struct node* delete_at_end(struct node* head) {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return head;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

// Function to delete a node at a specific position
struct node* delete_at_position(struct node* head, int position) {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return head;
    }
    if (position == 1) {
        struct node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct node* temp = head;
    for (int i = 1; i < position - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    // If position is out of range
    if (temp->next == NULL) {
        printf("Position out of range.\n");
        return head;
    }

    struct node* delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
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

    // Adding nodes to the list for demonstration
    head = insert_at_end(head, 10);
    head = insert_at_end(head, 20);
    head = insert_at_end(head, 30);
    head = insert_at_end(head, 40);
    head = insert_at_end(head, 50);

    printf("Initial list:\n");
    display_list(head);

    // Deleting the first node
    printf("\nDeleting the first node:\n");
    head = delete_at_beginning(head);
    display_list(head);

    // Deleting the last node
    printf("\nDeleting the last node:\n");
    head = delete_at_end(head);
    display_list(head);

    // Deleting a node at position 2
    printf("\nDeleting node at position 2:\n");
    head = delete_at_position(head, 2);
    display_list(head);

    return 0;
}


/* SAMPLE OUTPUT
Initial list:
10 -> 20 -> 30 -> 40 -> 50 -> NULL

Deleting the first node:
20 -> 30 -> 40 -> 50 -> NULL

Deleting the last node:
20 -> 30 -> 40 -> NULL

Deleting node at position 2:
20 -> 40 -> NULL
*/