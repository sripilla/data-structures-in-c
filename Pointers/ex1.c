#include<stdio.h>
int main()
{
  int a;
  int *p;
  p = &a;   // &a = address of a

  printf("%d\n", p);   // *p prints address of a
  
  /* *p - value at address pointed by p. Since a is not intialized to any value it prints some garbage value*/
  printf("%d\n", *p);  
  printf("%d\n", &a);  // &a points to address of a

  a = 10;
  printf("%d\n", *p);  // *p points value of a
}

/* SAMPLE OUTPUT
1958766244
32765
1958766244
10
*/