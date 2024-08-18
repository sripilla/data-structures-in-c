#include<stdio.h>
/* CALL BY REFERENCE */
void Increment(int *p)  // Formal Arguments
{
  *p = *p + 1;
  printf("Address of variable a in increment = %d\n", p);
  printf("value of variable a in increment = %d\n", *p);
}
int main()
{
  int a;
  a = 10;
  Increment(&a); // Actual Arguments
  printf("Address of variable a in main = %d\n", &a);
  printf("a = %d\n", a);
}

/* SAMPLE OUTPUT
Address of variable a in main = 904252044
a = 11
*/