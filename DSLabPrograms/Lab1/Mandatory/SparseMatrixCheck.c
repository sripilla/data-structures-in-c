/* Check whether the given matrix is sparse matrix or not using functions.  */

#include <stdio.h>

// Function to count the number of zero elements in the matrix
int countZeros(int matrix[][10], int rows, int cols) {
    int zeroCount = 0;

    // Loop through the matrix to count zeros
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                zeroCount++;
            }
        }
    }

    return zeroCount;
}

// Function to check if the matrix is sparse or not
int isSparse(int matrix[][10], int rows, int cols) {
    // Get the total number of elements in the matrix
    int totalElements = rows * cols;

    // Count the number of zero elements
    int zeroCount = countZeros(matrix, rows, cols);

    // If zeros are more than half of the total elements, it is sparse
    if (zeroCount > (totalElements / 2)) {
        return 1; // Sparse matrix
    } else {
        return 0; // Not sparse
    }
}

// Main function to test the program
int main() {
    int rows, cols;
    int matrix[10][10]; // Assuming a maximum size of 10x10 for simplicity

    // Input the number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Input the elements of the matrix
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check if the matrix is sparse
    if (isSparse(matrix, rows, cols)) {
        printf("The matrix is sparse.\n");
    } else {
        printf("The matrix is not sparse.\n");
    }

    return 0;
}

/* SAMPLE OUTPUT
Enter the number of rows: 3
Enter the number of columns: 3
Enter the elements of the matrix:
0 0 1
0 0 0
1 0 0
The matrix is sparse.


Note: In the above example, the matrix contains 5 zero elements out of a total of 9 elements. Since the number of zeros is greater than half the total elements (9 / 2 = 4.5), the matrix is considered sparse.
*/


/* EXPLANATION

countZeros(): This function counts the number of zero elements in the matrix by looping through all elements.

isSparse(): This function determines if the matrix is sparse by comparing the number of zeros to half of the total elements.

Main Function:

Inputs the matrix dimensions and elements from the user.
Calls the isSparse() function to determine if the matrix is sparse.
Prints whether the matrix is sparse or not.*/

/* What is sparse matrix?

A sparse matrix is a matrix in which most of the elements are zero. In other words, it is a matrix with a large number of zero entries compared to the non-zero entries. For a matrix to be considered sparse, the number of zero elements must be greater than half of the total number of elements in the matrix.
Example of Sparse Matrix:
0  0  1
0  0  0
1  0  0
Total elements: 9 (3x3)
Zero elements: 6
Since the number of zeros (6) is more than half of the total elements (9 / 2 = 4.5), this matrix is considered sparse.

Example of Non-Sparse Matrix:

1  2  3
0  4  5
6  7  8

Total elements: 9
Zero elements: 1
Since the number of zeros (1) is less than half of the total elements, this matrix is not sparse.
*/