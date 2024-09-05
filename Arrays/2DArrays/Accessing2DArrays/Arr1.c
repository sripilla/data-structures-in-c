/* write a program to print the elements of a 2D array */

#include <stdio.h>

int main() {
    // Declare and initialize a 2x2 matrix (2D array)
    int a[2][2] = { {12, 34}, {56, 78} };

    // Variables for loop counters
    int i, j;

    // Loop through the rows
    for(i = 0; i < 2; i++) {
        printf("\n");  // Move to the next line after each row

        // Loop through the columns
        for(j = 0; j < 2; j++) {
            // Print each element with a tab space for proper formatting
            printf("%d\t", a[i][j]);
        }
    }

    return 0;  // Successful execution
}

/* SAMPLE OUTPUT
12    34    
56    78

*/