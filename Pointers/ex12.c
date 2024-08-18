#include<stdio.h>
/* Array as function arguments
arrays are passed by reference by default*/
int SumOfElements(int a[], int size) 
{
  int i, sum = 0;
  for(i = 0; i < size; i++)
    {
      sum += a[i];
    }
}
int main()
{
  int a[] = {1,2,3,4,5};
  int size = sizeof(a)/sizeof(a[0]);
  int total = SumOfElements(a, size);
  printf("Sum of array elements = %d\n", total);
}