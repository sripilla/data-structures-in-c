/* Write a program to fill a square matrix with 
Zeros (0) on the diagonals.
Ones (1) in the upper right triangle.
Negative ones (-1) in the lower left triangle. */

#include <stdio.h>

int main() {
    int n;

    // Ask user for the size of the matrix
    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);

    // Declare the matrix
    int matrix[n][n];

    // Fill the matrix according to the given pattern
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                // Diagonal elements are 0
                matrix[i][j] = 0;
            } else if (i < j) {
                // Upper right triangle elements are 1
                matrix[i][j] = 1;
            } else {
                // Lower left triangle elements are -1
                matrix[i][j] = -1;
            }
        }
    }

    // Print the matrix
    printf("Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/* SAMPLE OUTPUT

Matrix:
 0  1  1 1 
-1  0  1 1 
-1 -1  0 1 
-1 -1 -1 0 

*/