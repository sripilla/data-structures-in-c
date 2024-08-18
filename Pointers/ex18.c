#include<stdio.h>
/* Arrays and pointers are different types that are used in similar manner */
int main()
{
  char c1[6] = "Hello";
  char *c2;
  c2 = c1;

  printf("%c\n", c2[1]);
  printf("%c\n", *(c2+1));
  printf("%c\n", *(c1+1));
  c2[0] = 'A';
  printf("%s\n", c1);
  c2++;
  printf("%s\n", c2);
  
}

/* SAMPLE OUTPUT
e
e
e
Aello
ello

NOTE: c2[i] = *(c2+i)
      c1[i] = *(c1+i)
*/