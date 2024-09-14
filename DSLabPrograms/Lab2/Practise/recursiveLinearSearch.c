#include <stdio.h>

// Recursive function for linear search
int recursiveLinearSearch(int arr[], int size, int target, int index) {
    // Base case: if index is out of bounds, the target is not found
    if (index >= size) {
        return -1; // Element not found
    }

    // Check if the current element matches the target
    if (arr[index] == target) {
        return index; // Element found at the current index
    }

    // Recursive call to search in the next index
    return recursiveLinearSearch(arr, size, target, index + 1);
}

int main() {
    int arr[100], n, target, result;

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input the elements of the array
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the target element to search
    printf("Enter the target element to search: ");
    scanf("%d", &target);

    // Perform Recursive Linear Search
    result = recursiveLinearSearch(arr, n, target, 0);

    // Print the result
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}


/*Enter the number of elements: 5
Enter 5 integers: 12 34 25 64 22
Enter the target element to search: 25
Element 25 found at index 2.
 */