/* 
Given an array of distinct elements. The task is to find triplets in an array whose sum is zero. Take the array as input. (Triplets Game) 
Sample Input 0 -1 2 -3 1 
Sample output 0 -1 1 
              2 -3 1  
*/

#include <stdio.h>

// Function to find triplets in the array whose sum is zero
void findTriplets(int arr[], int n) {
    int found = 0;

    // Loop to fix the first element of the triplet
    for (int i = 0; i < n - 2; i++) {

        // Loop to fix the second element of the triplet
        for (int j = i + 1; j < n - 1; j++) {

            // Loop to fix the third element of the triplet
            for (int k = j + 1; k < n; k++) {

                // Check if the sum of the three elements is zero
                if (arr[i] + arr[j] + arr[k] == 0) {
                    printf("%d %d %d\n", arr[i], arr[j], arr[k]);
                    found = 1;
                }
            }
        }
    }

    // If no triplet is found, print this message
    if (found == 0) {
        printf("No triplets found that sum to zero\n");
    }
}

// Main function
int main() {
    int n;

    // Taking the number of elements in the array as input
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Taking the array elements as input
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call the function to find triplets with sum zero
    findTriplets(arr, n);

    return 0;
}

/*        SAMPLE INPUT AND OUTPUT 

INPUT:
Enter the number of elements in the array: 5
Enter 5 elements: 0 -1 2 -3 1

OUTPUT:
0 -1 1
2 -3 1
*/

/* EXPLANATION

1. Input: The program first asks the user for the number of elements in the array and then takes the array elements as input.

2. findTriplets Function:

           This function iterates through all possible combinations of three elements in the array.
           For each combination, it checks if their sum equals zero.
           If a triplet is found, it is printed; otherwise, a message is printed if no such triplet exists.
           
3. Nested Loops: The three nested loops are used to select three elements at a time, ensuring that all triplets are considered.

4. Edge Case: If no triplets are found, the program prints "No triplets found that sum to zero."
*/