/* write a program to read an array of N numbers and then find the smallest number */

#include <stdio.h>

// Function prototypes
void read_array(int arr[], int n);
int find_smallest(int arr[], int n);

int main() {
  // Define array `num` and variables `n` for size, `smallest` for storing the smallest number
    int num[10], n, smallest;  

    // Read the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Function to read the array elements
    read_array(num, n);

    // Function to find the smallest number in the array
    smallest = find_smallest(num, n);

    // Print the smallest number
    printf("\nThe smallest number in the array is: %d", smallest);

    return 0;  // Return 0 to indicate successful execution
}

// Function to read the array elements from the user
void read_array(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("arr[%d] = ", i);  // Prompt for the i-th element
        scanf("%d", &arr[i]);  // Store the element in the array
    }
}

// Function to find the smallest number in the array
int find_smallest(int arr[], int n) {
    int i, small;
    small = arr[0];  // Initialize `small` with the first element of the array

    // Loop to compare each element with `small`
    for (i = 1; i < n; i++) {
        if (arr[i] < small) {
            small = arr[i];  // Update `small` if a smaller element is found
        }
    }
    return small;  // Return the smallest element
}

/* SAMPLE OUTPUT
Enter the size of the array: 5
arr[0] = 10
arr[1] = 2
arr[2] = 35
arr[3] = 4
arr[4] = 1

The smallest number in the array is: 1

*/
