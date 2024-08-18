#include<stdio.h>
/* pointers and arrays */

int main()
{
  int a[] = {2,4,5,8,1};

  printf("%d\n", a); // *p = a
  printf("%d\n", &a[0]);
  printf("%d\n", a[0]);
  printf("%d\n", *a); 
}

/* SAMPLE OUTPUT
415857088
415857088
2
2
*/