/* Write a program to to store the address of three individual arrays in the 
array of pointer */

#include <stdio.h>

int main() {
    // Initializing three arrays with some values
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {0, 2, 4, 6, 8};
    int arr3[] = {1, 3, 5, 7, 9};

    // Array of pointers to point to the three arrays
    int *parr[3] = {arr1, arr2, arr3}; 

    // Loop to display the address and the first element of each array
    for (int i = 0; i < 3; i++) {
        printf("Address of arr%d is %p and the first element is %d\n", i + 1, parr[i], *parr[i]);
    }

    return 0; // Return 0 to indicate successful execution
}

/* SAMPLE OUTPUT
Address of arr1 is 0x7ffeed9c46f0 and the first element is 1
Address of arr2 is 0x7ffeed9c4704 and the first element is 0
Address of arr3 is 0x7ffeed9c4718 and the first element is 1

*/