/* Write a program to delete a number from a given location in an array */

#include <stdio.h>

int main() {
  // Declare variables: arr[] for the array, n for number of elements, i for looping, pos for position to delete

    int arr[10], n, i, pos;      
  // Prompt the user to enter the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);   // Read the number of elements

    // Loop to read the elements into the array
    for(i = 0; i < n; i++) {
        printf("arr[%d] = ", i);  // Prompt for the i-th element
        scanf("%d", &arr[i]);    // Store the element in the array
    }

    // Prompt the user to enter the position of the number to be deleted
    printf("Enter the position from which the number has to be deleted: ");
    scanf("%d", &pos);   // Read the position

    // Shift elements to the left to remove the element at the specified position
    for(i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];     // Shift each element to the left
    }

    n--;       // Decrement the size of the array

    // Display the array after deletion
    printf("The array after deletion is: ");
    for(i = 0; i < n; i++) {
        printf("\narr[%d] = %d", i, arr[i]);  // Print each element
    }

    return 0;  // Return 0 to indicate successful execution
}

/* SAMPLE OUTPUT 
Enter the number of elements in the array: 5
arr[0] = 10
arr[1] = 20
arr[2] = 30
arr[3] = 40
arr[4] = 50
Enter the position from which the number has to be deleted: 3
The array after deletion is:
arr[0] = 10
arr[1] = 20
arr[2] = 40
arr[3] = 50

*/