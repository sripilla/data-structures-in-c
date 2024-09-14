/* Write a function Smallest to find the smallest element in an array using pointer.
    Create a dynamically allocated array and read the values from keyboard in main.
    Display the result in the main function.*/
#include <stdio.h>
#include <stdlib.h>  // For malloc and free

// Function to find the smallest element in the array using pointers
int Smallest(int *arr, int size) {
    int *ptr = arr;        // Pointer to the start of the array
    int smallest = *ptr;   // Assume the first element is the smallest

    // Traverse the array using pointers to find the smallest element
    for (int i = 1; i < size; i++) {
        if (*(ptr + i) < smallest) {  // Dereference the pointer to compare values
            smallest = *(ptr + i);    // Update the smallest value if found
        }
    }

    return smallest;
}

int main() {
    int size;

    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;  // Exit if memory allocation fails
    }

    // Input the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Call the Smallest function
    int smallest = Smallest(arr, size);

    // Display the smallest element
    printf("The smallest element in the array is: %d\n", smallest);

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}
