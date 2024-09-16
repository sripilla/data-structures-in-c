/* Write a C program to
a) Demonstrate passing pointers to a function.
b) Demonstrate Returning pointer from a function.
c) c) Using pointer to pointer.*/

#include <stdio.h>
#include <stdlib.h>

// Function to demonstrate passing pointers to a function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to demonstrate returning a pointer from a function
int* createArray(int size) {
    // Dynamically allocate an array of the given size
    int *array = (int *)malloc(size * sizeof(int));

    // Check if memory allocation was successful
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    // Initialize array elements
    for (int i = 0; i < size; i++) {
        array[i] = i + 1;
    }

    return array;
}

// Function to demonstrate using a pointer to pointer
void updateValue(int **ptrToPtr) {
    // Modify the value of the integer pointed to by ptrToPtr
    **ptrToPtr = 50;
}

int main() {
    // Part a: Passing pointers to a function
    int x = 10, y = 20;
    printf("Before swap: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After swap: x = %d, y = %d\n", x, y);

    // Part b: Returning a pointer from a function
    int size = 5;
    int *arr = createArray(size);
    if (arr != NULL) {
        printf("Array elements: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        free(arr); // Free the allocated memory
    }

    // Part c: Using pointer to pointer
    int value = 10;
    int *ptr = &value;
    int **ptrToPtr = &ptr;
    printf("Value before update: %d\n", value);
    updateValue(ptrToPtr);
    printf("Value after update: %d\n", value);

    return 0;
}

/* 
Before swap: x = 10, y = 20
After swap: x = 20, y = 10
Array elements: 1 2 3 4 5 
Value before update: 10
Value after update: 50
*/