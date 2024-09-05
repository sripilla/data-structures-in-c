/* Write a program to transpose a 3 * 3 matrix */

#include <stdio.h>

int main() {
    int mat[3][3];              // Declare the original matrix
    int transposed_mat[3][3];   // Declare the transposed matrix
    int i, j;                   // Loop variables

    // Input: Reading the elements of the 3x3 matrix
    printf("Enter elements in a matrix of size 3x3:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("Element at position [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &mat[i][j]);  // Input each element
        }
    }

    // Display the original matrix
    printf("\nThe original matrix is:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d\t", mat[i][j]);  // Print each element with tab spacing
        }
        printf("\n");  // Move to the next line after each row
    }

    // Transpose logic: Swap rows with columns
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            transposed_mat[i][j] = mat[j][i];  // Transpose the matrix
        }
    }

    // Display the transposed matrix
    printf("\nThe transposed matrix is:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d\t", transposed_mat[i][j]);  // Print each element with tab spacing
        }
        printf("\n");  // Move to the next line after each row
    }

    return 0;  // End of the program
}

/* SAMPLE OUTPUT
Enter elements in a matrix of size 3x3:
Element at position [1][1]: 1
Element at position [1][2]: 2
Element at position [1][3]: 3
Element at position [2][1]: 4
Element at position [2][2]: 5
Element at position [2][3]: 6
Element at position [3][1]: 7
Element at position [3][2]: 8
Element at position [3][3]: 9

The original matrix is:
1	2	3	
4	5	6	
7	8	9	

The transposed matrix is:
1	4	7	
2	5	8	
3	6	9

*/