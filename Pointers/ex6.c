#include<stdio.h>
int main()
{
  int a = 1025; 
  int *p;
  p = &a;

  printf("Size of integer is %d bytes\n", sizeof(int));
  printf("Address = %d, value = %d\n", p, *p);

  /* Void pointer is a genric pointer which can be assigned
    to any type.
    VOID pointer cannot be de-referenced*/
  
  void *p0; /* void pointer type is not mapped to any data type, so we cannot de-reference this type*/
  
  p0 = p; /* we dont need a explicit type casting here like po = (void *)p */
  
   //printf("Address = %d, value = %d\n", p0, *p0);
  
  printf("Address = %d", p0);
}

/* SAMPLE OUTPUT
Size of integer is 4 bytes
Address = -684738596, value = 1025
Address = -684738596
*/