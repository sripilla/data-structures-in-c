/* Write a program to insert a number in an array that is already sorted in ascending order  */

#include <stdio.h>

int main() {
  // Declare variables: a[] for the array, n for number of elements, i and j for looping, num for the new number
    int a[10], n, i, j, num;     

    // Prompt the user to enter the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);     // Read the number of elements

    // Loop to read the elements into the array
    for(i = 0; i < n; i++) {
        printf("arr[%d] = ", i);  // Prompt for the i-th element
        scanf("%d", &a[i]);      // Store the element in the array
    }

    // Prompt the user to enter the number to be inserted
    printf("Enter the number to be inserted: ");
    scanf("%d", &num);    // Read the new number

    // Find the correct position to insert the new number
    for(i = 0; i < n; i++) {
        if(a[i] > num) {    // If the current element is greater than the new number
            break;    // Break the loop to insert at the current position
        }
    }

    // Shift elements to the right to make space for the new element
    for(j = n; j > i; j--) {
        a[j] = a[j - 1];  // Shift each element to the right
    }

    // Insert the new number at the found position
    a[i] = num;   // Insert the number at position i
    n++;         // Increment the size of the array

    // Display the array after insertion
    printf("The array after insertion of %d is: ", num);
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);     // Print each element
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
Enter the number to be inserted: 25
The array after insertion of 25 is: 10 20 25 30 40 50 */



