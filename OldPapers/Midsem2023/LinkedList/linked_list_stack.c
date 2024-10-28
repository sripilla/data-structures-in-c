/*Stacks can be implemented using linked lists with the help of dynamic memory
allocation functions. Develop push() and pop() functions to implement a stack using linked
list. The typical function calls would be push(&top, item) and item = pop (&top);. Assume
the following initial declarations.

typedef struct node *Nodeptr;
struct node{
int data;
Nodeptr next;
}; */

#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node *Nodeptr;
struct node {
    int data;
    Nodeptr next;
};

// Function to check if memory allocation was successful
#define IS_FULL(temp) ((temp) == NULL)
#define IS_EMPTY(top) ((top) == NULL)

// Push function to add an element to the top of the stack
void push(Nodeptr *top, int item) {
    Nodeptr temp = (Nodeptr) malloc(sizeof(struct node));
    if (IS_FULL(temp)) {
        printf("The memory is full\n");
        exit(1);
    }
    temp->data = item;
    temp->next = *top;
    *top = temp;
    printf("Pushed %d onto the stack\n", item);
}

// Pop function to remove an element from the top of the stack
int pop(Nodeptr *top) {
    if (IS_EMPTY(*top)) {
        printf("The stack is empty\n");
        exit(1);
    }
    Nodeptr temp = *top;
    int item = temp->data;
    *top = temp->next;
    free(temp);
    return item;
}

// Display function to show all elements in the stack
void display(Nodeptr top) {
    if (IS_EMPTY(top)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements:\n");
    Nodeptr temp = top;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    Nodeptr top = NULL;  // Initialize the stack as empty

    // Sample stack operations
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);

    display(top);

    printf("Popped item: %d\n", pop(&top));
    printf("Popped item: %d\n", pop(&top));

    display(top);

    return 0;
}

/* SAMPLE PROGRAM 
Pushed 10 onto the stack
Pushed 20 onto the stack
Pushed 30 onto the stack
Stack elements:
30 -> 20 -> 10 -> NULL
Popped item: 30
Popped item: 20
Stack elements:
10 -> NULL
*/