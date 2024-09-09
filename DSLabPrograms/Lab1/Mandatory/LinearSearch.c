/*
Implement an iterative Lsearch(....) function to search for an element in an 1D array 
of type integer using linear search technique. 
*/
#include <stdio.h>

// Function to perform linear search in an integer array
int Lsearch(int arr[], int size, int element) {
    // Iterate through each element in the array
    for (int i = 0; i < size; i++) {
        // If the current element matches the target element
        if (arr[i] == element) {
            // Return the index where the element is found
            return i;
        }
    }
    // If element is not found, return -1
    return -1;
}

int main() {
    int n, searchElement, result;

    // Asking user for the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Taking input for array elements from the user
    printf("Enter %d elements of the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Asking user for the element to be searched
    printf("Enter the element to search for: ");
    scanf("%d", &searchElement);

    // Calling the linear search function
    result = Lsearch(arr, n, searchElement);

    // Displaying result based on the search outcome
    if (result != -1) {
        printf("Element %d found at index %d.\n", searchElement, result);
    } else {
        printf("Element %d not found in the array.\n", searchElement);
    }

    return 0;
}

/* SAMPLE OUTPUT 
Enter the size of the array: 5
Enter 5 elements of the array:
10 22 35 48 56
Enter the element to search for: 35
Element 35 found at index 2.
*/

/* EXPLANATION 
Lsearch Function: This function takes an array arr[], its size, and the element to search. It iterates through the array, comparing each element with the target. If a match is found, it returns the index. Otherwise, it returns -1 to indicate that the element was not found.
Main Function: The user is prompted to input the size and elements of the array. Then, the element to search is entered, and the Lsearch function is called to check if the element exists in the array.
*/