#include <stdio.h>

// Recursive function to perform Bubble Sort
void bubbleSortRecursive(int arr[], int n) {
    // Base case: If array size is 1, return
    if (n == 1) {
        return;
    }

    // Perform one pass of bubble sort, pushing the largest element to the end
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            // Swap arr[i] and arr[i + 1]
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }

    // Recursive call for the remaining array
    bubbleSortRecursive(arr, n - 1);
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100], n;

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input the elements of the array
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform Bubble Sort using recursion
    bubbleSortRecursive(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}

/*
Enter the number of elements: 5
Enter 5 integers: 64 34 25 12 22
Sorted array: 12 22 25 34 64
*/