/* Write a program to find the mean of n numbers using arrays. */

#include <stdio.h>

int main() {

    // Declare variables: n for the number of elements, i for looping, sum to store the sum of elements
    int n, i, sum = 0;       
    int arr[20];  // Declare an array of size 20 to hold the elements
    float mean = 0.0;  // Declare a variable to store the mean, initialized to 0.0

    // Prompt the user to enter the number of elements
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);   // Read the number of elements from the user

    // Loop to read each element into the array
    for(i = 0; i < n; i++) {
// Prompt for the i-th element (starting from 1 for user clarity)
        printf("Enter element %d: ", i + 1); 
        scanf("%d", &arr[i]);  // Store the user input in the array
    }

    // Loop to calculate the sum of the array elements
    for(i = 0; i < n; i++) {
        sum += arr[i];  // Add each element to the sum
    }

    // Calculate the mean of the elements
    mean = (float)sum / n;  // Typecast sum to float for accurate division

    // Display the sum and mean of the array elements
    printf("The sum of the array elements = %d\n", sum);
    printf("The mean of the array elements = %.2f\n", mean);  
    // Print the mean with 2 decimal places

    return 0;  // Return 0 to indicate successful execution
}

/************************* SAMPLE OUTPUT *******************
    Enter the number of elements in the array: 5
    Enter element 1: 12
    Enter element 2: 23
    Enter element 3: 45
    Enter element 4: 21
    Enter element 5: 56
    The sum of the array elements = 146
    The mean of the array elements = 29.20
    */
