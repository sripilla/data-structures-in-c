/*Write a C program to print an array in forward direction by adding one to pointer and in backward direction by subtracting one from pointer. */

#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Pointer to the start of the array
    int *ptr = arr;

    // Printing the array in forward direction
    printf("Array in forward direction: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    // Pointer to the end of the array
    ptr = arr + n - 1;

    // Printing the array in backward direction
    printf("Array in backward direction: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(ptr - i));
    }
    printf("\n");

    return 0;
}


/*SAMPLE OUTPUT
Enter the number of elements in the array: 5
Enter 5 elements: 1 2 3 4 5
Array in forward direction: 1 2 3 4 5 
Array in backward direction: 5 4 3 2 1 
*/