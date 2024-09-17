/*Write a C program to implement multiple stacks (say n stacks) in a single array.
Implement ADD(i. X) and DELETE(i) to add X and delete an element from stack i,
1<= i <= n. */

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACKS 10  // Maximum number of stacks
#define MAX_SIZE 100   // Maximum size of the array

// Define a structure for multiple stacks
typedef struct {
    int top[MAX_STACKS];  // Array to keep track of the top index of each stack
    int arr[MAX_SIZE];    // Single array to store all elements of all stacks
    int size;             // Size of each stack
} MultiStack;

// Initialize the multi-stack
void initMultiStack(MultiStack *ms, int size) {
    ms->size = size;
    for (int i = 0; i < MAX_STACKS; i++) {
        ms->top[i] = -1;  // Initialize all stacks as empty
    }
}

// Check if stack i is full
int isFull(MultiStack *ms, int i) {
    return ms->top[i] == ms->size - 1;
}

// Check if stack i is empty
int isEmpty(MultiStack *ms, int i) {
    return ms->top[i] == -1;
}

// Add element X to stack i
void add(MultiStack *ms, int i, int X) {
    if (i < 1 || i > MAX_STACKS) {
        printf("Invalid stack index\n");
        return;
    }

    if (isFull(ms, i - 1)) {
        printf("Stack %d is full\n", i);
        return;
    }

    int index = (i - 1) * ms->size + (++ms->top[i - 1]);
    ms->arr[index] = X;
    printf("Added %d to stack %d\n", X, i);
}

// Delete element from stack i
void delete(MultiStack *ms, int i) {
    if (i < 1 || i > MAX_STACKS) {
        printf("Invalid stack index\n");
        return;
    }

    if (isEmpty(ms, i - 1)) {
        printf("Stack %d is empty\n", i);
        return;
    }

    int index = (i - 1) * ms->size + ms->top[i - 1]--;
    printf("Deleted %d from stack %d\n", ms->arr[index], i);
}

// Display all elements of stack i
void display(MultiStack *ms, int i) {
    if (i < 1 || i > MAX_STACKS) {
        printf("Invalid stack index\n");
        return;
    }

    if (isEmpty(ms, i - 1)) {
        printf("Stack %d is empty\n", i);
        return;
    }

    printf("Stack %d elements: ", i);
    for (int j = 0; j <= ms->top[i - 1]; j++) {
        printf("%d ", ms->arr[(i - 1) * ms->size + j]);
    }
    printf("\n");
}

int main() {
    MultiStack ms;
    int stackSize, choice, stackIndex, value;

    printf("Enter the size of each stack: ");
    scanf("%d", &stackSize);
    initMultiStack(&ms, stackSize);

    while (1) {
        printf("\n1. Add\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter stack index (1 to %d): ", MAX_STACKS);
                scanf("%d", &stackIndex);
                printf("Enter value to add: ");
                scanf("%d", &value);
                add(&ms, stackIndex, value);
                break;
            case 2:
                printf("Enter stack index (1 to %d): ", MAX_STACKS);
                scanf("%d", &stackIndex);
                delete(&ms, stackIndex);
                break;
            case 3:
                printf("Enter stack index (1 to %d): ", MAX_STACKS);
                scanf("%d", &stackIndex);
                display(&ms, stackIndex);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}


/*SAMPLE OUTPUT
Enter the size of each stack: 3

1. Add
2. Delete
3. Display
4. Exit
Enter your choice: 1
Enter stack index (1 to 10): 1
Enter value to add: 10
Added 10 to stack 1

1. Add
2. Delete
3. Display
4. Exit
Enter your choice: 1
Enter stack index (1 to 10): 1
Enter value to add: 20
Added 20 to stack 1

1. Add
2. Delete
3. Display
4. Exit
Enter your choice: 1
Enter stack index (1 to 10): 1
Enter value to add: 30
Added 30 to stack 1

1. Add
2. Delete
3. Display
4. Exit
Enter your choice: 3
Enter stack index (1 to 10): 1
Stack 1 elements: 10 20 30 

1. Add
2. Delete
3. Display
4. Exit
Enter your choice: 2
Enter stack index (1 to 10): 1
Deleted 30 from stack 1

1. Add
2. Delete
3. Display
4. Exit
Enter your choice: 3
Enter stack index (1 to 10): 1
Stack 1 elements: 10 20 

1. Add
2. Delete
3. Display
4. Exit
Enter your choice: 4
*/