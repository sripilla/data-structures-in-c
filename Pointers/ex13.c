#include<stdio.h>

/* Array as function arguments
arrays are passed by reference by default*/
int SumOfElements(int A[]) 
{
  int i, sum = 0;
  int size = sizeof(A) / sizeof(A[0]);
   printf("SOE - Size of A = %d, Size of A[0] = %d\n", (int)sizeof(A), (int)sizeof(A[0]));

  for(i = 0; i < size; i++)
  {
    sum += A[i];
  }
  return sum;
}

int main()
{
  int A[] = {4,5,6,7,8};
  int size = sizeof(A) / sizeof(A[0]);

  int total = SumOfElements(A);
  printf("Sum of array elements = %d\n", total);

   printf("MAIN - Size of A = %d, Size of A[0] = %d\n", (int)sizeof(A), (int)sizeof(A[0]));

  return 0;
}


/* SAMPLE OUTPUT
SOE - Size of A = 8, Size of A[0] = 4
Sum of array elements = 9
MAIN - Size of A = 20, Size of A[0] = 4
*/