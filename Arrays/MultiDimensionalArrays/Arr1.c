#include <stdio.h>

int main() {
    // Declare a 3D array of size 2x2x2
    int array[2][2][2];
    int i, j, k;

    // Prompt the user to enter the elements of the matrix
    printf("Enter the elements of the 2x2x2 matrix:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 2; k++) {
                printf("Element [%d][%d][%d]: ", i, j, k);
                scanf("%d", &array[i][j][k]);
            }
        }
    }

    // Print the elements of the matrix
    printf("\nThe elements of the 2x2x2 matrix are:\n");
    for (i = 0; i < 2; i++) {
        printf("Layer %d:\n", i);
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 2; k++) {
                printf("%d\t", array[i][j][k]);
            }
            printf("\n");  // New line after each row
        }
        printf("\n");  // New line after each layer
    }

    return 0;
}

/* SAMPLE OUTPUT

INPUT

Enter the elements of the 2x2x2 matrix:
Element [0][0][0]: 1
Element [0][0][1]: 2
Element [0][1][0]: 3
Element [0][1][1]: 4
Element [1][0][0]: 5
Element [1][0][1]: 6
Element [1][1][0]: 7
Element [1][1][1]: 8


OUTPUT

The elements of the 2x2x2 matrix are:
Layer 0:
1	2	
3	4	

Layer 1:
5	6	
7	8	

*/