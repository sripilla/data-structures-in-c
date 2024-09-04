/* Write an program to find the second largest of n numbers using an array */
#include <stdio.h>

int main() {
// Declare variables: n for the number of elements, i for looping
// Declare an array of size 20 to hold the elements
// Declare variables to store the largest and second largest elements
    int n, i;                     
    int arr[20];                   
    int large, second_large;       

  // Prompt the user to enter the number of elements
  // Read the number of elements from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);               

  // Prompt the user to enter the elements of the array
  // Store each element in the array
    printf("Enter the elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);      
    }

    // Initialize the largest and second largest elements
    large = arr[0];                // Assume the first element is the largest
    second_large = arr[0];         // Initially set second largest to the same value

    // Loop to find the largest element
    for(i = 1; i < n; i++) {
        if(arr[i] > large) {
            large = arr[i];        // Update the largest element if a bigger one is found
        }
    }

    // Loop to find the second largest element
    for(i = 0; i < n; i++) {
        if(arr[i] != large && arr[i] > second_large) {
            second_large = arr[i]; // Update the second largest element
        }
    }

    // Display the elements of the array
    printf("The numbers you entered are: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);     // Print each element
    }

    // Display the largest and second largest elements
    printf("\nThe largest element is %d", large);
    printf("\nThe second largest element is %d", second_large);

    return 0;  // Return 0 to indicate successful execution
}

/********************* SAMPLE OUTPUT ****************
  Enter the number of elements: 5
  Enter the elements: 10 20 15 5 30
  The numbers you entered are: 10 20 15 5 30 
  The largest element is 30
  The second largest element is 20
*/
  
