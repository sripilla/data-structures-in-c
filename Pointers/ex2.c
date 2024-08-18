#include<stdio.h>
int main()
{
  int a, *p;
  a = 10; 
  p = &a;

  printf("Address of p is %d\n", p);
  printf("Value of p is %d\n", *p);

  int b = 20;
  *p = b; // will the address in change to point b?

  printf("Address of p is %d\n", p);
  printf("Value of p is %d\n", *p);
}

/* SAMPLE OUTPUT
Address of p is -229901664
Value of p is 10
Address of p is -229901664
Value of p is 20
*/