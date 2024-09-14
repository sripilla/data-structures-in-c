/* Write a function Reverse to reverse the elements of an integer array using pointer.
Access the elements of the array using dereference operator. Read the values from
the keyboard in main function. Display the result in the main function. */

#include <stdio.h>

// Function to reverse the elements of an array using pointers
void reverseArray(int *arr, int size) {
    int *start = arr;           // Pointer to the first element of the array
    int *end = arr + size - 1;   // Pointer to the last element of the array
    int temp;

    // Swap elements from start to end using pointers
    while (start < end) {
        temp = *start;       // Store the value at start
        *start = *end;       // Copy the value at end to start
        *end = temp;         // Copy the stored value to end

        // Move the pointers towards the center
        start++;
        end--;
    }
}

int main() {
    int size;

    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];  // Declare the array

    // Input the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Call the reverseArray function
    reverseArray(arr, size);

    // Display the reversed array
    printf("The reversed array is:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
