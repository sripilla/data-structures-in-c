/* To implement selection sort using recursion */

#include <stdio.h>

// Function to recursively perform selection sort
void selectionSortRecursive(int arr[], int n, int index) {
    // Base case: If the array is sorted (index reaches n-1), return
    if (index >= n - 1) {
        return;
    }

    // Find the index of the minimum element in the unsorted portion of the array
    int minIndex = index;
    for (int i = index + 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    // Swap the found minimum element with the first element of the unsorted portion
    if (minIndex != index) {
        int temp = arr[index];
        arr[index] = arr[minIndex];
        arr[minIndex] = temp;
    }

    // Recursively call the function for the next index
    selectionSortRecursive(arr, n, index + 1);
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};  // Example array
    int n = sizeof(arr) / sizeof(arr[0]);  // Number of elements in the array

    printf("Original array:\n");
    printArray(arr, n);  // Print the original array

    // Perform selection sort using recursion
    selectionSortRecursive(arr, n, 0);

    printf("Sorted array:\n");
    printArray(arr, n);  // Print the sorted array

    return 0;
}

/* SAMPLE OUTPUT 
Original array:
64 25 12 22 11 
Sorted array:
11 12 22 25 64 
*/

/*EXPLANATION
1. Function Definition - selectionSortRecursive:

  Parameters:
      arr[]: The array to be sorted.
      n: The total number of elements in the array.
      index: The current index being processed (starting from 0).
  Base Case: If index is greater than or equal to n - 1, the array is already sorted, so the function returns.
  Finding Minimum: The function finds the minimum element in the unsorted portion of the array (from index to n - 1).
  Swapping: It then swaps the minimum element with the element at the current index.
  Recursive Call: The function is called recursively with the next index (index + 1).

2. Function Definition - printArray:

    Prints the elements of the array to the console.
3. main Function:

    Defines an example array and calculates its size.
    Prints the original array.
    Calls selectionSortRecursive to sort the array.
    Prints the sorted array.*/