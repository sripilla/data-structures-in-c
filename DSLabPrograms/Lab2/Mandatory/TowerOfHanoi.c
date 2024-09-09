/*Simulate the working of Tower of Hanoi for n disks. Print the number of moves.*/
#include <stdio.h>

// Function to solve the Tower of Hanoi problem
// It moves 'n' disks from source rod to destination rod using auxiliary rod
void towerOfHanoi(int n, char source, char destination, char auxiliary, int *moveCount) {
    // Base case: If there's only one disk, move it directly
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", source, destination);
        (*moveCount)++; // Increment the move counter
        return;
    }

    // Move 'n-1' disks from source to auxiliary rod
    towerOfHanoi(n - 1, source, auxiliary, destination, moveCount);

    // Move the nth disk from source to destination rod
    printf("Move disk %d from rod %c to rod %c\n", n, source, destination);
    (*moveCount)++; // Increment the move counter

    // Move the 'n-1' disks from auxiliary rod to destination rod
    towerOfHanoi(n - 1, auxiliary, destination, source, moveCount);
}

int main() {
    int n; // Number of disks
    int moveCount = 0; // To count the number of moves

    // Input the number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Check if the number of disks is valid
    if (n <= 0) {
        printf("The number of disks should be a positive integer.\n");
        return 1; // Exit the program with an error code
    }

    // Call the Tower of Hanoi function
    printf("The steps to solve the Tower of Hanoi problem are:\n");
    towerOfHanoi(n, 'A', 'C', 'B', &moveCount);

    // Output the total number of moves
    printf("Total number of moves: %d\n", moveCount);

    return 0;
}

/*SAMPLE OUTPUT
INPUT: 
Enter the number of disks: 3

OUTPUT:
The steps to solve the Tower of Hanoi problem are:
Move disk 1 from rod A to rod C
Move disk 2 from rod A to rod B
Move disk 1 from rod C to rod B
Move disk 3 from rod A to rod C
Move disk 1 from rod B to rod A
Move disk 2 from rod B to rod C
Move disk 1 from rod A to rod C
Total number of moves: 7
*/

/* EXPLANATION 
Function towerOfHanoi:

   Parameters:
      n: Number of disks.
      source: The starting rod.
      destination: The target rod.
      auxiliary: The auxiliary rod used for intermediate moves.
      moveCount: A pointer to keep track of the number of moves.

  Base Case: If n is 1, move the disk directly from source to destination and increment the move count.
  Recursive Case:
      Move n-1 disks from source to auxiliary using destination as auxiliary.
      Move the nth disk from source to destination.
      Move the n-1 disks from auxiliary to destination using source as auxiliary.
      
main Function:

Prompts the user to input the number of disks.
Validates the input.
Calls towerOfHanoi with the appropriate parameters and displays the steps and total number of moves.*/
