/*  Program to Input Two Matrices and Calculate Their Sum

write a program to input two m * n matrices and then calculate the sum of their corresponding elements and store it in a third m * n matrix 
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j;
    int rows1, cols1, rows2, cols2;
    int mat1[10][10], mat2[10][10], mat_sum[10][10];

    // Input dimensions for the first matrix
    printf("Enter the number of rows and columns for matrix 1: ");
    scanf("%d %d", &rows1, &cols1);

    // Input dimensions for the second matrix
    printf("Enter the number of rows and columns for matrix 2: ");
    scanf("%d %d", &rows2, &cols2);

    // Check if dimensions match for addition
    if (rows1 != rows2 || cols1 != cols2) {
        printf("The matrices cannot be added as their dimensions do not match.\n");
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

    // Calculate the sum of the two matrices
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols1; j++) {
            mat_sum[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    // Display the resultant matrix
    printf("\nThe elements of the resultant matrix are:\n");
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols1; j++) {
            printf("%d ", mat_sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/* SAMPLE OUTPUT

Enter the number of rows and columns for matrix 1: 
2 3
Enter the number of rows and columns for matrix 2: 
2 3
Enter the elements of matrix 1:
1 2 3
4 5 6
Enter the elements of matrix 2:
7 8 9
10 11 12

The elements of the resultant matrix are:
8 10 12 
14 16 18 

*/