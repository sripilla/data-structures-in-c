#include <stdio.h>

int main() {
    int rows, cols, i, j;

    // Input the number of rows and columns for the matrices
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Declare two matrices and one for the result (difference)
    int mat1[10][10], mat2[10][10], diff[10][10];

    // Input the elements of the first matrix
    printf("\nEnter the elements of the first matrix:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("mat1[%d][%d] = ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }

    // Input the elements of the second matrix
    printf("\nEnter the elements of the second matrix:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("mat2[%d][%d] = ", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }

    // Calculate the difference of the matrices
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            diff[i][j] = mat1[i][j] - mat2[i][j];
        }
    }

    // Display the difference matrix
    printf("\nThe difference of the two matrices is:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%d\t", diff[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/* SAMPLE OUTPUT
Enter the number of rows and columns: 2 2

Enter the elements of the first matrix:
mat1[0][0] = 5
mat1[0][1] = 7
mat1[1][0] = 3
mat1[1][1] = 9

Enter the elements of the second matrix:
mat2[0][0] = 2
mat2[0][1] = 1
mat2[1][0] = 4
mat2[1][1] = 6

The difference of the two matrices is:
3       6
-1      3

*/