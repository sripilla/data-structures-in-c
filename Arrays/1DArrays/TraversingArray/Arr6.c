/* Write a program to find whether the array of integers contains a duplicate number */

#include <stdio.h>

int main() {
    int n, i, j;                     // Declare variables: n for the number of elements, i and j for looping
    int array[20];                   // Declare an array of size 20 to hold the elements
    int flag = 0;                    // Flag to indicate if a duplicate is found

    // Prompt the user to enter the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);                 // Read the size of the array

    // Loop to read each element into the array
    for(i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);  // Prompt for the i-th element (1-based index for clarity)
        scanf("%d", &array[i]);       // Store the user input in the array
    }

    // Loop to check for duplicate elements
    for(i = 0; i < n - 1; i++) {      // Loop through each element
        for(j = i + 1; j < n; j++) {  // Compare with each subsequent element
            if(array[i] == array[j]) {  // If a duplicate is found
                flag = 1;             // Set the flag to 1
                printf("Duplicate number found at positions %d and %d\n", i + 1, j + 1);  // Print positions (1-based index)
            }
        }
    }

    // If no duplicates are found
    if(flag == 0) {
        printf("No duplicate numbers found.\n");
    }

    return 0;  // Return 0 to indicate successful execution
}

/* **************** SAMPLE OUTPUT ******************
  Enter the size of the array: 5
  Enter element 1: 10
  Enter element 2: 20
  Enter element 3: 30
  Enter element 4: 20
  Enter element 5: 50
  Duplicate number found at positions 2 and 4
*/