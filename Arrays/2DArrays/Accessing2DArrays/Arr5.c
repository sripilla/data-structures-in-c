/*Write a program to read and display a 3*3 matrix */

#include <stdio.h>

int main() {
    int mat[3][3];  // Declare a 3x3 matrix
    int i, j;       // Loop variables

    // Input: Read the elements of the 3x3 matrix
    printf("Enter the elements of the matrix (3x3):\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("Element at position [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &mat[i][j]);  // Input each element of the matrix
        }
    }

    // Output: Display the elements of the matrix
    printf("\nThe elements of the matrix are:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d\t", mat[i][j]);  // Print each element with tab spacing
        }
        printf("\n");  // Move to the next line after each row
    }

    return 0;  // End of the program
}


/* SAMPLE OUTPUT
Enter the elements of the matrix (3x3):
Element at position [1][1]: 1
Element at position [1][2]: 2
Element at position [1][3]: 3
Element at position [2][1]: 4
Element at position [2][2]: 5
Element at position [2][3]: 6
Element at position [3][1]: 7
Element at position [3][2]: 8
Element at position [3][3]: 9

The elements of the matrix are:
1	2	3	
4	5	6	
7	8	9	

*/