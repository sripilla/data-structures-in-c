#include<stdio.h>
/* Array as function arguments
arrays are passed by reference by default*/
#include <stdio.h>

int SumOfElements(int A[], int size) {
    int i, sum = 0;
    for(i = 0; i < size; i++) {
        sum += A[i];
    }
    return sum;  // Return the calculated sum
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    int size = sizeof(A) / sizeof(A[0]);
    int total = SumOfElements(A, size);
    printf("Sum of array elements = %d\n", total);
    return 0;
}

/* OUTPUT
Sum of array elements = 15
*/