/* Write a program to modify the contents of an array using a pointer to an array */

#include <stdio.h>

int main() {
    // Initialize the array with 5 elements
    int arr[] = {1, 2, 3, 4, 5};

    // Declare a pointer variable and assign it to the third element (index 2) of the array
    int *ptr;
    int i;
    ptr = &arr[2];  // ptr points to arr[2] (the value 3)

    // Modify values in the array using pointer arithmetic
    *ptr = -1;        // Change arr[2] to -1
    *(ptr + 1) = 0;   // Change arr[3] (next element) to 0
    *(ptr - 2) = 1;   // Change arr[0] (previous element by 2 positions) to 1

    // Print the modified array
    printf("\nArray is: ");
    for (i = 0; i < 5; i++) {
        printf(" %d", *(arr + i));  // Access array elements using pointer arithmetic
    }

    return 0;  // Successful program execution
}


/* SAMPLE OUTPUT 
 Array is: 1 1 -1 0 5
*/