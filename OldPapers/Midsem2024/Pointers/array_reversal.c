/* Develop a C function that accepts a pointer to an array and the size of the array, and
reverses the elements of the array in place. Use pointer arithmetic and the
dereferencing operator to access and modify array elements. */

#include <stdio.h>

// Function to reverse the elements of the array in place
void reverseArray(int* arr, int size) {
    // Use pointer arithmetic to reverse the array
    int* start = arr;          // Pointer to the start of the array
    int* end = arr + size - 1; // Pointer to the end of the array

    while (start < end) {
        // Swap the elements
        int temp = *start;     // Store the start element
        *start = *end;         // Assign end element to start
        *end = temp;           // Assign temp (original start) to end

        // Move the pointers towards the center
        start++;
        end--;
    }
}

// Function to display the elements of the array
void displayArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i)); // Using pointer arithmetic
    }
    printf("\n");
}

int main() {
    // Sample array
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    printf("Original array: ");
    displayArray(arr, size);

    // Reverse the array
    reverseArray(arr, size);

    printf("Reversed array: ");
    displayArray(arr, size);

    return 0;
}

/*SAMPLE OUTPUT
Original array: 1 2 3 4 5 
Reversed array: 5 4 3 2 1 
*/