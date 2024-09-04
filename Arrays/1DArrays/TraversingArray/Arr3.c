/* Write a program to print the position of the smallest number of n numbers using arrays */
#include <stdio.h>

int main() {
// Declare variables: n for the number of elements, i for looping
// Declare an array of size 20 to hold the elements
// Declare variables: small to store the smallest element, pos to store its position
    int n, i;
    int arr[20]; 
    int small, pos;          

// Prompt the user to enter the number of elements
// Read the number of elements from the user
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);          

// Loop to read each element into the array
    for(i = 0; i < n; i++) {
// Prompt for the i-th element (starting from 1 for user clarity)
// Store the user input in the array
        printf("Enter element %d: ", i + 1);  
        scanf("%d", &arr[i]);  
    }

// Initialize the smallest element and its position
    small = arr[0];  // Assume the first element is the smallest
    pos = 0;         // The position of the smallest element is 0 (0-based index)

    // Loop to find the smallest element and its position
    for(i = 1; i < n; i++) {  // Start from the second element (index 1)
        if(arr[i] < small) {  // If the current element is smaller than the smallest found so far
            small = arr[i];   // Update the smallest element
            pos = i;          // Update the position of the smallest element
        }
    }

    // Display the smallest element and its position
    printf("The smallest element is %d and its position is %d\n", small, pos + 1); // Adding 1 to position to show 1-based index

    return 0;  // Return 0 to indicate successful execution
}

/* ************************ SAMPLE OUTPUT *********************
  Enter the number of elements in the array: 3
  Enter element 1: 23
  Enter element 2: 56
  Enter element 3: 78
  The smallest element is 23 and its position is 1
*/
