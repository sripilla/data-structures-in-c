/* Write a program to read and display n numbers using an array*/

#include <stdio.h>

int main() {

  // Declare variables: n for the number of elements, i for looping
    int n, i;               
    int arr[20];// Declare an array of size 20 to hold the elements

    // Prompt the user to enter the number of elements
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n); // Read the number of elements from the user

    // Loop to read each element into the array
    for(i = 0; i < n; i++) {
      // Prompt for the i-th element (starting from 1 for user clarity)
        printf("Enter element %d: ", i + 1);  
        scanf("%d", &arr[i]);  // Store the user input in the array
    }

    // Display the elements stored in the array
    printf("The elements of the array are: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);  // Print each element followed by a space
    }

    return 0;  // Return 0 to indicate successful execution
}


/*        SAMPLE OUTPUT

Enter the number of elements in the array: 5
Enter element 1: 1
Enter element 2: 2
Enter element 3: 3
Enter element 4: 4
Enter element 5: 5
The elements of the array are: 1 2 3 4 5 
*/