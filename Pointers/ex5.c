#include<stdio.h>
int main()
{
  int a = 1025; 
  int *p; 
  p = &a;

  printf("Size of integer is %d bytes\n", sizeof(int));
  printf("Address = %d, value = %d\n", p, *p);
  printf("Address = %d, value = %d\n", p+1, *(p+1));

  char *p0;
  p0 = (char *) p; // type casting
  printf("Size of char is %d bytes\n", sizeof(char));
  printf("Address = %d, value = %d\n", p0, *p0);
  printf("Address = %d, value = %d\n", p0+1, *(p0+1));

  // 1025 = 00000000 00000000 00000100 00000001
  //                              4       1
}

/*  SAMPLE OUTPUT
Size of integer is 4 bytes
Address = -1801525876, value = 1025
Address = -1801525872, value = -1801525616
Size of char is 1 bytes
Address = -1801525876, value = 1
Address = -1801525875, value = 4

*/