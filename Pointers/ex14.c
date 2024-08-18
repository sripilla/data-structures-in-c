#include<stdio.h>
void SumOfElements(int A[]) 
{
    printf("SOE - Size of A = %d, Size of A[0] = %d\n", (int)sizeof(A), (int)sizeof(A[0]));
}

int main()
{
    int A[] = {4, 5, 6, 7, 8};
    printf("MAIN - Size of A = %d, Size of A[0] = %d\n", (int)sizeof(A), (int)sizeof(A[0]));

    SumOfElements(A);
    return 0;
}

/* SAMPLE OUTPUT
MAIN - Size of A = 20, Size of A[0] = 4
SOE - Size of A = 8, Size of A[0] = 4

 In main:

     sizeof(A) gives 20 (because A is an array of 5 ints, and each int 
     is 4 bytes).
     sizeof(A[0]) gives 4 (the size of one int).
In SumOfElements:

      sizeof(A) gives 8 (because A is now a pointer to an int, and the 
      size of a pointer on a 64-bit system is 8 bytes).
      sizeof(A[0]) still gives 4 (because A[0] is still an int).

1. The size of a pointer on a 64-bit system is 8 bytes, regardless of what the pointer points to
2. When you pass an array to a function, it decays into a pointer, so sizeof(A) inside the function will return the size of the pointer, not the array.
*/

