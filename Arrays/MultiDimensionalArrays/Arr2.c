/* POINTERS AND 3D Arrays
Write a program which illustrates the use of a pointer to a three-dimensional array.
*/

#include <stdio.h>

int main() {
    int i, j, k;
    int arr[2][2][2];          // Declare a 3D array
    int (*parr)[2][2] = arr;   // Pointer to a 2D array of size 2x2

    // Prompt the user to enter the elements of the 3D array
    printf("Enter the elements of the 3D array:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 2; k++) {
                printf("Element [%d][%d][%d]: ", i, j, k);
                scanf("%d", &arr[i][j][k]);
            }
        }
    }

    // Print the elements of the 3D array using pointers
    printf("\nThe elements of the 3D array are:\n");
    for (i = 0; i < 2; i++) {
        printf("Layer %d:\n", i);
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 2; k++) {
                // Access the element using pointers
                printf("%d\t", *(*(*(parr + i) + j) + k));
            }
            printf("\n");  // New line after each row
        }
        printf("\n");  // New line after each layer
    }

    return 0;
}

/* SAMPLE OUTPUT
INPUT
Enter the elements of the 3D array:
Element [0][0][0]: 1
Element [0][0][1]: 2
Element [0][1][0]: 3
Element [0][1][1]: 4
Element [1][0][0]: 5
Element [1][0][1]: 6
Element [1][1][0]: 7
Element [1][1][1]: 8

OUTPUT
The elements of the 3D array are:
Layer 0:
1	2	
3	4	

Layer 1:
5	6	
7	8	

*/