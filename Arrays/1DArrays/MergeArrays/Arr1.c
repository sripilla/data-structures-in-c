/* Write a program to merge two sorted arrays */

#include <stdio.h>

int main() {
  // Declare arrays: arr1[] and arr2[] for input, arr3[] for merged output
    int arr1[10], arr2[10], arr3[20];  
  // Declare variables: n1 and n2 for sizes of arr1 and arr2, m for total size, index for tracking arr3
    int i, n1, n2, m, index = 0;  

    // Read the number of elements in the first array
    printf("Enter the number of elements in array1: ");
    scanf("%d", &n1);

    // Loop to read the elements of the first array
    printf("Enter the elements of array1:\n");
    for(i = 0; i < n1; i++) {
        printf("arr1[%d] = ", i);  // Prompt for the i-th element
        scanf("%d", &arr1[i]);  // Store the element in arr1
    }

    // Read the number of elements in the second array
    printf("\nEnter the number of elements in array2: ");
    scanf("%d", &n2);

    // Loop to read the elements of the second array
    printf("Enter the elements of array2:\n");
    for(i = 0; i < n2; i++) {
        printf("arr2[%d] = ", i);  // Prompt for the i-th element
        scanf("%d", &arr2[i]);  // Store the element in arr2
    }

    // Merge arr1 into arr3
    for(i = 0; i < n1; i++) {
        arr3[index] = arr1[i];  // Copy each element of arr1 to arr3
        index++;
    }

    // Merge arr2 into arr3
    for(i = 0; i < n2; i++) {
        arr3[index] = arr2[i];  // Copy each element of arr2 to arr3
        index++;
    }

    m = n1 + n2;  // Total number of elements in the merged array

    // Display the merged array
    printf("\nThe merged array is:\n");
    for(i = 0; i < m; i++) {
        printf("arr3[%d] = %d\n", i, arr3[i]);  // Print each element of arr3
    }

    return 0;  // Return 0 to indicate successful execution
}

/* SAMPLE OUTPUT
Enter the number of elements in array1: 3
Enter the elements of array1:
arr1[0] = 1
arr1[1] = 3
arr1[2] = 5

Enter the number of elements in array2: 3
Enter the elements of array2:
arr2[0] = 2
arr2[1] = 4
arr2[2] = 6

The merged array is:
arr3[0] = 1
arr3[1] = 3
arr3[2] = 5
arr3[3] = 2
arr3[4] = 4
arr3[5] = 6

*/
