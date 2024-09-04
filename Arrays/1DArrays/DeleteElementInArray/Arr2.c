/* write a program to delete a number from an array that is already sorted in ascending order */

#include <stdio.h>

int main() {
  // Declare variables: arr[] for the array, n for number of elements, num for the number to delete
    int arr[10], i, j, n, num;  

  // Prompt the user to enter the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);  // Read the number of elements

    // Loop to read the elements into the array
    for(i = 0; i < n; i++) {
        printf("arr[%d] = ", i);  // Prompt for the i-th element
        scanf("%d", &arr[i]);    // Store the element in the array
    }

    // Prompt the user to enter the number to be deleted
    printf("Enter the number to be deleted: ");
    scanf("%d", &num);  // Read the number to be deleted

    // Loop to find the element to delete
    for(i = 0; i < n; i++) {
        if(arr[i] == num) {  // If the current element matches the number to be deleted
            // Shift elements to the left to remove the found element
            for(j = i; j < n - 1; j++) {
                arr[j] = arr[j + 1];  // Shift each element to the left
            }
            n--;  // Decrement the size of the array
            i--;  // Adjust index to recheck the current position after shifting
        }
    }

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
 Enter the number to be deleted: 30
 The array after deletion is:
 arr[0] = 10
 arr[1] = 20
 arr[2] = 40
 arr[3] = 50

*/