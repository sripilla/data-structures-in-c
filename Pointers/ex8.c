#include<stdio.h>
/*  int a is local variable to Increment function
Increment(int a) is called function */
/* CALL BY VALUE */
void Increment(int a)  // Formal Arguments
{
  a = a + 1;
  printf("Address of variable a in increment = %d\n", &a);
  printf("value of variable a in increment = %d\n", a);
}
int main()
{
  int a;
  a = 10;
  Increment(a); // Actual Arguments
  printf("Address of variable a in main = %d\n", &a);
  printf("a = %d\n", a);
}

/*  SAMPLE 

Address of variable a in increment = 1167314252
Address of variable a in increment = 1167314284
a = 10
*/