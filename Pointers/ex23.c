#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n); // &n to get the address of n

    // Allocate memory for n integers
    int *a = (int *)malloc(n * sizeof(int));

    // Check if memory allocation was successful
    if (a == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Initialize and display the elements of the array
    for (int i = 0; i < n; i++) {
        a[i] = i + 1; // Assigning some values to the array
        printf("%d ", a[i]);
    }

    // Free the allocated memory
    free(a);

    return 0;
}

/* 
Enter the number of elements in the array: 10
1 2 3 4 5 6 7 8 9 10 
*/