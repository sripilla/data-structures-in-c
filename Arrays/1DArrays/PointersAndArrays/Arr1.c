/* Write a program to display an array of given numbers */

#include <stdio.h>

int main() {
    // Initialize an array of integers
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Declare two pointer variables
    int *ptr1, *ptr2;

    // Initialize ptr1 to point to the first element of the array
    ptr1 = arr;

    // Initialize ptr2 to point to the last element of the array
    // arr[8] refers to the 9th element (value 9)
    ptr2 = &arr[8]; 

    // Loop through the array using ptr1, and print values until ptr1 reaches ptr2
    while (ptr1 <= ptr2) {
        printf("%d\n", *ptr1); // Dereference ptr1 to get the value it points to
        ptr1++;                // Move ptr1 to the next element in the array
    }

    return 0; // Return 0 to indicate successful execution
}


/* SAMPLE OUTPUT
1
2
3
4
5
6
7
8
9

*/