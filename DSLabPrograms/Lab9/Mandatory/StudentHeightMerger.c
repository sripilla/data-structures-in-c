/*  The students of 2 classes (A and B) are standing in 2 separate lines in ascending order
of their height. The principle asks the students to combine and join a single line. Write
a function merge to combine the lines into a single line in ascending order of their
height using the singly linked list. For example class A: 5->10->15. Class B: 2->3-
>20 resultant line: 2->3->5->10->15->20. Input first line contains 2 integer N1 and
N2 as number of students of class A and B respectively. Second line contains N1
integers (heights of the students of class A in ascending order) third line contains N2
integers (heights of students of class B in ascending order). Output Display Line of
Class A. Display line of class B. Display the joint class file.
Sample Input:
5 4
1 3 4 7 8
2 5 6 9
Sample Output
Class A
->1->3->4->7->8
Class B
->2->5->6->9
Joint Class
->1->2->3->4->5->6->7->8->9
Provide suitable name for the program
	  
Provide appropriate comments and sample output */

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

// Display linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("->%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Merge two sorted linked lists into a single sorted linked list
struct Node* merge(struct Node* headA, struct Node* headB) {
    struct Node* result = NULL;  // Resulting merged list
    struct Node** lastPtrRef = &result;  // Pointer to the last node of result

    // Traverse both lists and add the smaller element to the result list
    while (headA != NULL && headB != NULL) {
        if (headA->data <= headB->data) {
            *lastPtrRef = headA;
            headA = headA->next;
        } else {
            *lastPtrRef = headB;
            headB = headB->next;
        }
        lastPtrRef = &((*lastPtrRef)->next);
    }

    // Attach remaining nodes of list A or list B
    *lastPtrRef = (headA != NULL) ? headA : headB;

    return result;
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
    struct Node *classA = NULL, *classB = NULL, *mergedClass = NULL;
    int n1, n2, i, height;

    // Input number of students in Class A and Class B
    printf("Enter the number of students in Class A and Class B: ");
    scanf("%d %d", &n1, &n2);

    // Input heights for Class A
    printf("Enter heights for Class A in ascending order:\n");
    for (i = 0; i < n1; i++) {
        scanf("%d", &height);
        insertEnd(&classA, height);
    }

    // Input heights for Class B
    printf("Enter heights for Class B in ascending order:\n");
    for (i = 0; i < n2; i++) {
        scanf("%d", &height);
        insertEnd(&classB, height);
    }

    // Display Class A
    printf("\nClass A\n");
    displayList(classA);

    // Display Class B
    printf("Class B\n");
    displayList(classB);

    // Merge the two classes into a single list
    mergedClass = merge(classA, classB);

    // Display the merged class
    printf("Joint Class\n");
    displayList(mergedClass);

    // Free memory
    freeList(mergedClass);

    return 0;
}

/* SAMPLE OUTPUT
Enter the number of students in Class A and Class B: 5 4
Enter heights for Class A in ascending order:
1 3 4 7 8
Enter heights for Class B in ascending order:
2 5 6 9

Class A
->1->3->4->7->8
Class B
->2->5->6->9
Joint Class
->1->2->3->4->5->6->7->8->9
*/