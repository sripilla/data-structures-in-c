/*Perform UNION and INTERSECTION set operations on singly linked lists with
and without header node. */

#include <stdio.h>
#include <stdlib.h>

// Node structure
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

// Insert a node at the end of the linked list
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

// Display elements of the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Check if an element is present in the list
int isPresent(struct Node* head, int data) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data)
            return 1;
        temp = temp->next;
    }
    return 0;
}

// UNION operation
struct Node* unionList(struct Node* head1, struct Node* head2) {
    struct Node* result = NULL;
    struct Node* temp = head1;

    // Copy all elements of list1 to result
    while (temp != NULL) {
        insertEnd(&result, temp->data);
        temp = temp->next;
    }

    // Insert only unique elements from list2
    temp = head2;
    while (temp != NULL) {
        if (!isPresent(result, temp->data))
            insertEnd(&result, temp->data);
        temp = temp->next;
    }
    return result;
}

// INTERSECTION operation
struct Node* intersectionList(struct Node* head1, struct Node* head2) {
    struct Node* result = NULL;
    struct Node* temp = head1;

    // Insert elements present in both lists
    while (temp != NULL) {
        if (isPresent(head2, temp->data))
            insertEnd(&result, temp->data);
        temp = temp->next;
    }
    return result;
}

// Free memory of linked list
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
    struct Node *head1 = NULL, *head2 = NULL;
    struct Node *unionResult = NULL, *intersectionResult = NULL;

    // Insert elements in first linked list (set)
    insertEnd(&head1, 1);
    insertEnd(&head1, 2);
    insertEnd(&head1, 3);
    insertEnd(&head1, 4);

    // Insert elements in second linked list (set)
    insertEnd(&head2, 3);
    insertEnd(&head2, 4);
    insertEnd(&head2, 5);
    insertEnd(&head2, 6);

    printf("List 1: ");
    displayList(head1);

    printf("List 2: ");
    displayList(head2);

    // Perform UNION
    unionResult = unionList(head1, head2);
    printf("\nUnion of List 1 and List 2: ");
    displayList(unionResult);

    // Perform INTERSECTION
    intersectionResult = intersectionList(head1, head2);
    printf("Intersection of List 1 and List 2: ");
    displayList(intersectionResult);

    // Free allocated memory
    freeList(head1);
    freeList(head2);
    freeList(unionResult);
    freeList(intersectionResult);

    return 0;
}

/* SAMPLE OUTPUT
List 1: 1 -> 2 -> 3 -> 4 -> NULL
List 2: 3 -> 4 -> 5 -> 6 -> NULL

Union of List 1 and List 2: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
Intersection of List 1 and List 2: 3 -> 4 -> NULL
*/