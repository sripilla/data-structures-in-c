/*Implement a C program to read, display and to find the product of two matrices using functions with suitable parameters. Check for the compatibility of the input matrices before multiplication*/
#include <stdio.h>

// Function to read a matrix
void readMatrix(int matrix[10][10], int rows, int cols) {
    printf("Enter elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[10][10], int rows, int cols) {
    printf("Matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply two matrices
void multiplyMatrices(int mat1[10][10], int mat2[10][10], int result[10][10], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

// Main function
int main() {
    int mat1[10][10], mat2[10][10], result[10][10];
    int r1, c1, r2, c2;

    // Input matrix dimensions
    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &r2, &c2);

    // Check if multiplication is possible
    if (c1 != r2) {
        printf("Matrix multiplication not possible: Columns of first matrix must equal rows of second matrix.\n");
        return 0;
    }

    // Read matrices
    readMatrix(mat1, r1, c1);
    readMatrix(mat2, r2, c2);

    // Multiply matrices
    multiplyMatrices(mat1, mat2, result, r1, c1, c2);

    // Display matrices and result
    printf("First Matrix:\n");
    displayMatrix(mat1, r1, c1);

    printf("Second Matrix:\n");
    displayMatrix(mat2, r2, c2);

    printf("Product of the two matrices:\n");
    displayMatrix(result, r1, c2);

    return 0;
}

/*SAMPLE OUTPUT
Enter rows and columns for first matrix: 2 3
Enter rows and columns for second matrix: 3 2
Enter elements of the matrix (2 x 3):
Element [1][1]: 1
Element [1][2]: 2
Element [1][3]: 3
Element [2][1]: 4
Element [2][2]: 5
Element [2][3]: 6
Enter elements of the matrix (3 x 2):
Element [1][1]: 7
Element [1][2]: 8
Element [2][1]: 9
Element [2][2]: 10
Element [3][1]: 11
Element [3][2]: 12

First Matrix:
1    2    3
4    5    6

Second Matrix:
7    8
9   10
11  12

Product of the two matrices:
58   64
139  154

*/

/* EXPLANATION
Matrix Reading: The readMatrix() function reads the matrix elements from the user and stores them in a 2D array.

Matrix Display: The displayMatrix() function prints the matrix elements in a structured format.

Matrix Multiplication: The multiplyMatrices() function multiplies two matrices only if they are compatible for multiplication. The number of columns in the first matrix must equal the number of rows in the second matrix. Each element of the product matrix is computed by multiplying corresponding rows and columns of the two matrices.

Main Logic:

The program prompts the user for matrix dimensions.
It checks if matrix multiplication is possible.

*/