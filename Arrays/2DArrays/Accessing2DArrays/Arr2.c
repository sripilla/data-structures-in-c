/* write a program to generate Pascal's triangle */

#include <stdio.h>

int main() {
    // Declare a 2D array to hold Pascal's triangle values
    int arr[7][7] = {0}; // Initialize all elements to 0
    int row = 2, col, i, j;

    // Initialize the first two rows of Pascal's triangle
    arr[0][0] = arr[1][0] = arr[1][1] = 1;

    // Generate the remaining rows of Pascal's triangle
    while(row < 7) {
        arr[row][0] = 1;  // First element of each row is always 1
        for(col = 1; col < row; col++) {
            // Each element is the sum of the two elements directly above it
            arr[row][col] = arr[row-1][col-1] + arr[row-1][col];
        }
        row++;
    }

    // Display Pascal's triangle
    for(i = 0; i < 7; i++) {
        printf("\n");  // New line for each row
        for(j = 0; j <= i; j++) {
            // Print each element with a tab for alignment
            printf("\t%d", arr[i][j]);
        }
    }

    return 0;  // End of program
}

/* SAMPLE OUTPUT

1
1       1
1       2       1
1       3       3       1
1       4       6       4       1
1       5      10       10      5       1
1       6      15       20      15      6       1

*/