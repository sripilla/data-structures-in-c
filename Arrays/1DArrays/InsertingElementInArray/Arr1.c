/* Write a program to insert a number at a given location in an array */

#include <stdio.h>

int main() {
  // Declare variables: n for the number of elements, i for looping, num for the new number, pos for the position
  // Declare an array of size 10 to hold the elements
    int n, i, num, pos;          
    int arr[10];                 

    // Prompt the user to enter the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n); // Read the number of elements

    // Loop to read the elements into the array
    for(i = 0; i < n; i++) {
        // Prompt for the i-th element (1-based index for clarity)
        printf("Enter element %d: ", i + 1);  
        scanf("%d", &arr[i]);     // Store the user input in the array
    }

    // Prompt the user to enter the number to be inserted and its position
    printf("Enter the number to be inserted: ");
    scanf("%d", &num);   // Read the new number
    printf("Enter the position at which the number has to be inserted: ");
    scanf("%d", &pos);   // Read the position

    // Shift elements to the right to make space for the new element
    for(i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];  // Move each element one position to the right
    }

    // Insert the new number at the specified position
    // Insert the number (1-based index for user clarity)
    arr[pos - 1] = num;            
    n++;  // Increment the size of the array

    // Display the array after insertion
    printf("The array after insertion of %d is: ", num);
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);     // Print each element
    }

    return 0;  // Return 0 to indicate successful execution
}

/* ********************* SAMPLE OUTPUT *********************

    Enter the number of elements in the array: 5
    Enter element 1: 12
    Enter element 2: 45
    Enter element 3: 67
    Enter element 4: 34
    Enter element 5: 23
    Enter the number to be inserted: 25
    Enter the position at which the number has to be inserted: 2
    The array after insertion of 25 is: 12 25 45 67 34 23 

*/
    
