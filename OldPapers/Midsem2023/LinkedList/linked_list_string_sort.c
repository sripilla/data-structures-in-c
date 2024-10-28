/* Write a program to sort a linked list using selection sort in ascending order. While creating the list add in the front only. Data that a linked list contains is a string.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data[100];         // String data
    struct Node* next;
};

// Function to create a new node with a given string
struct Node* create_node(char* str) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    strcpy(new_node->data, str);
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the front of the linked list
void insert_front(struct Node** head, char* str) {
    struct Node* new_node = create_node(str);
    new_node->next = *head;
    *head = new_node;
}

// Function to sort the linked list using selection sort
void selection_sort(struct Node* head) {
    struct Node* temp1 = head;
    while (temp1 != NULL) {
        struct Node* min = temp1;
        struct Node* temp2 = temp1->next;

        // Find the node with the smallest data in the unsorted part
        while (temp2 != NULL) {
            if (strcmp(temp2->data, min->data) < 0) {
                min = temp2;
            }
            temp2 = temp2->next;
        }

        // Swap data of the current node with the minimum node found
        if (min != temp1) {
            char temp[100];
            strcpy(temp, temp1->data);
            strcpy(temp1->data, min->data);
            strcpy(min->data, temp);
        }

        temp1 = temp1->next;
    }
}

// Function to display the linked list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Adding nodes to the front of the list
    insert_front(&head, "banana");
    insert_front(&head, "apple");
    insert_front(&head, "orange");
    insert_front(&head, "grape");
    insert_front(&head, "kiwi");

    printf("Original list:\n");
    display(head);

    // Sorting the list
    selection_sort(head);

    printf("\nSorted list:\n");
    display(head);

    return 0;
}

/*SAMPLE OUTPUT
Original list:
kiwi -> grape -> orange -> apple -> banana -> NULL

Sorted list:
apple -> banana -> grape -> kiwi -> orange -> NULL
*/