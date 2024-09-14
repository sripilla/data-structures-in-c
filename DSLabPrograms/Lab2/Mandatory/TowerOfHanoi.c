/*Simulate the working of Tower of Hanoi for n disks. Print the number of moves.*/
#include <stdio.h>

#include <stdio.h>

// Recursive function to solve the Tower of Hanoi puzzle
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    // Base case: if there's only one disk
    if (n == 1) {
        printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }
    // Move n-1 disks from 'from_rod' to 'aux_rod' using 'to_rod' as helper
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);

    // Move the nth disk from 'from_rod' to 'to_rod'
    printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);

    // Move the n-1 disks from 'aux_rod' to 'to_rod' using 'from_rod' as helper
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n = 3; // Number of disks

    printf("Tower of Hanoi for %d disks:\n", n);

    // Call the function to solve the Tower of Hanoi puzzle
    towerOfHanoi(n, 'A', 'C', 'B');  // A, B, and C are names of rods

    return 0;
}


/*SAMPLE OUTPUT
 Move disk 1 from rod A to rod C
 Move disk 2 from rod A to rod B
 Move disk 1 from rod C to rod B
 Move disk 3 from rod A to rod C
 Move disk 1 from rod B to rod A
 Move disk 2 from rod B to rod C
 Move disk 1 from rod A to rod C
*/

