/*Given an array arr with n elements and a number k, k<n. The task is to delete k
elements which are smaller than next element (i.e., we delete arr[i] if arr[i] <
arr[i+1]) or become smaller than next because next element is deleted. 
Example:
Input: arr[] = {20, 10, 25, 30, 40}, k = 2
Output: 25 30 40.  Explanation: First we delete 10 because it follows arr[i] < arr[i+1]. 
Then we delete 20 because 25 is moved next to it and it also starts following the condition. */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack structure
typedef struct {
    int arr[MAX];
    int top;
} Stack;

// Initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Push an element onto the stack
void push(Stack *s, int data) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = data;
}

// Pop an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1; // Return -1 or any error value
    }
    return s->arr[s->top--];
}

// Peek the top element of the stack
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1; // Return -1 or any error value
    }
    return s->arr[s->top];
}

// Delete k elements that are smaller than the next element
void deleteSmallerElements(int arr[], int *n, int k) {
    Stack s;
    initStack(&s);

    // Push all elements to the stack
    for (int i = 0; i < *n; i++) {
        push(&s, arr[i]);
    }

    // Temporary array to hold elements
    int temp[MAX];
    int tempIndex = 0;

    // Pop elements from stack and use conditions to manage the deletions
    for (int delCount = 0; delCount < k; delCount++) {
        int prev = -1;
        while (!isEmpty(&s)) {
            int current = pop(&s);
            if (prev == -1 || current >= prev) {
                temp[tempIndex++] = current;
            }
            prev = current;
        }
        // Restore elements back to the stack, excluding the deleted one
        for (int i = tempIndex - 1; i >= 0; i--) {
            push(&s, temp[i]);
        }
        tempIndex = 0;
    }

    // Collect remaining elements from stack to the original array
    while (!isEmpty(&s)) {
        temp[tempIndex++] = pop(&s);
    }

    // Reverse the order of elements in temp to match original order
    for (int i = 0; i < tempIndex / 2; i++) {
        int tempValue = temp[i];
        temp[i] = temp[tempIndex - i - 1];
        temp[tempIndex - i - 1] = tempValue;
    }

    // Copy elements back to the original array
    for (int i = 0; i < tempIndex; i++) {
        arr[i] = temp[i];
    }
    *n = tempIndex; // Update the size of the array
}

int main() {
    int arr[] = {20, 10, 25, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    deleteSmallerElements(arr, &n, k);

    printf("Array after deleting %d elements: ", k);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


/* SAMPLE OUTPUT

Enter number of elements in array: 5
Enter the elements of the array: 20 10 25 30 40
Enter the value of k: 2


Modified array after deletion: 25 30 40
*/