/* write a program to read and display a 3*3 matrix using pointers */
#include <stdio.h>

// Function prototype for displaying the matrix
void display(int (*mat)[3]);

int main() {
    int i, j;
    int mat[3][3];  // Declare a 3x3 matrix

    // Prompt the user to enter the elements of the matrix
    printf("Enter the elements of the 3x3 matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    // Call the function to display the matrix
    display(mat);

    return 0;
}

// Function to display the matrix using pointers
void display(int (*mat)[3]) {
    int i, j;

    // Print a header for the matrix
    printf("\nThe elements of the matrix are:\n");

    // Loop through the matrix and print each element
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            // Access the matrix element using pointer arithmetic
            printf("%d\t", *(*(mat + i) + j));
        }
        printf("\n");  // Move to the next line after printing a row
    }
}

/*
INPUT 

Enter the elements of the 3x3 matrix:
Element [0][0]: 1
Element [0][1]: 2
Element [0][2]: 3
Element [1][0]: 4
Element [1][1]: 5
Element [1][2]: 6
Element [2][0]: 7
Element [2][1]: 8
Element [2][2]: 9


OUTPUT

The elements of the matrix are:
1	2	3	
4	5	6	
7	8	9	

*/