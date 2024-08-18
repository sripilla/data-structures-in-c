#include<stdio.h>
int main(){
  int a = 10; 
  int *p; 
  p = &a;

  // pointer arithmetic

  printf("Address of p is %d\n", p);
  printf("Size of integer is %d bytes\n", sizeof(int));
  printf("Address of p+1 is %d\n", p+1);

  printf("value of p is %d\n", *p);
  printf("value of p is %d\n", *(p+1));
  printf("value of p is %d\n", *p+1);
}


/* SAMPLE OUTPUT:

Address of p is -60601580
Size of integer is 4 bytes
Address of p+1 is -60601576
Address of p is 10
Address of p is -60601580
Address of p is 11
*/