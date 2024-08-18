#include<stdio.h>
int main()
{
  int a, *p;
  a = 10;
  p = &a;

  printf("a = %d\n", a);

  *p = 12; 
  printf("a = %d\n", a);
}

/* SAMPLE OUTPUT
a = 10
a = 12
*/