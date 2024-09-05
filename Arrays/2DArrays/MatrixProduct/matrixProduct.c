/* Program to Multiply Two Matrices
write a program to multiply two m * n matrices */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, k;
    int rows1, cols1, rows2, cols2;
    int mat1[10][10], mat2[10][10], res[10][10];

    // Input dimensions for the first matrix
    printf("Enter the number of rows and columns for matrix 1: ");
    scanf("%d %d", &rows1, &cols1);

    // Input dimensions for the second matrix
    printf("Enter the number of rows and columns for matrix 2: ");
    scanf("%d %d", &rows2, &cols2);

    // Check if multiplication is possible
    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible. The number of columns in the first matrix must be equal to the number of rows in the second matrix.\n");
        return 1; // Exit with an error code
    }

    // Input elements for the first matrix
    printf("Enter the elements of matrix 1:\n");
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    // Input elements for the second matrix
    printf("Enter the elements of matrix 2:\n");
    for (i = 0; i < rows2; i++) {
        for (j = 0; j < cols2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    // Initialize the result matrix to 0
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            res[i][j] = 0;
        }
    }

    // Multiply the two matrices
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            for (k = 0; k < cols1; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    // Display the resultant matrix
    printf("The resultant matrix is:\n");
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            printf("%d\t", res[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/* SAMPLE OUTPUT
Enter the number of rows and columns for matrix 1: 
2 3
Enter the number of rows and columns for matrix 2: 
3 2
Enter the elements of matrix 1:
1 2 3
4 5 6
Enter the elements of matrix 2:
7 8
9 10
11 12
The resultant matrix is:
58    64
139   154

*/