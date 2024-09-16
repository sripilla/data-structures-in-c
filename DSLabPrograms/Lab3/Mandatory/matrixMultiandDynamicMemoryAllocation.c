/*Implement a C program to read, display and to find the product of two matrices using
functions with suitable parameters. Note that the matrices should be created using
dynamic memory allocation functions and the elements are accessed using array
dereferencing.*/

#include <stdio.h>
#include <stdlib.h>

// Function to dynamically allocate a matrix
int** allocateMatrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to read matrix elements
void readMatrix(int **matrix, int rows, int cols) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int **matrix, int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply two matrices
void multiplyMatrices(int **A, int Arows, int Acols, int **B, int Brows, int Bcols, int **result) {
    if (Acols != Brows) {
        printf("Matrix dimensions do not match for multiplication.\n");
        return;
    }

    // Initialize result matrix to 0
    for (int i = 0; i < Arows; i++) {
        for (int j = 0; j < Bcols; j++) {
            result[i][j] = 0;
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < Arows; i++) {
        for (int j = 0; j < Bcols; j++) {
            for (int k = 0; k < Acols; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to free the allocated matrix memory
void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int Arows, Acols, Brows, Bcols;

    // Read dimensions for Matrix A
    printf("Enter number of rows and columns for Matrix A: ");
    scanf("%d %d", &Arows, &Acols);

    // Allocate memory for Matrix A
    int **A = allocateMatrix(Arows, Acols);
    readMatrix(A, Arows, Acols);

    // Read dimensions for Matrix B
    printf("Enter number of rows and columns for Matrix B: ");
    scanf("%d %d", &Brows, &Bcols);

    // Allocate memory for Matrix B
    int **B = allocateMatrix(Brows, Bcols);
    readMatrix(B, Brows, Bcols);

    // Check if multiplication is possible
    if (Acols != Brows) {
        printf("Matrix dimensions do not match for multiplication.\n");
        freeMatrix(A, Arows);
        freeMatrix(B, Brows);
        return 1;
    }

    // Allocate memory for Result Matrix
    int **result = allocateMatrix(Arows, Bcols);

    // Multiply matrices
    multiplyMatrices(A, Arows, Acols, B, Brows, Bcols, result);

    // Display matrices
    printf("Matrix A:\n");
    displayMatrix(A, Arows, Acols);

    printf("Matrix B:\n");
    displayMatrix(B, Brows, Bcols);

    printf("Product of Matrix A and Matrix B:\n");
    displayMatrix(result, Arows, Bcols);

    // Free allocated memory
    freeMatrix(A, Arows);
    freeMatrix(B, Brows);
    freeMatrix(result, Arows);

    return 0;
}
/* Enter number of rows and columns for Matrix A: 2 3
Enter the elements of the matrix:
Element [0][0]: 1
Element [0][1]: 2
Element [0][2]: 3
Element [1][0]: 4
Element [1][1]: 5
Element [1][2]: 6

Enter number of rows and columns for Matrix B: 3 2
Enter the elements of the matrix:
Element [0][0]: 7
Element [0][1]: 8
Element [1][0]: 9
Element [1][1]: 10
Element [2][0]: 11
Element [2][1]: 12

Matrix A:
1 2 3 
4 5 6 
Matrix B:
7 8 
9 10 
11 12 
Product of Matrix A and Matrix B:
58 64 
139 154 
*/