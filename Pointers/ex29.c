#include <stdio.h>
#include <stdlib.h>
/* Call by reference */
int add(int *a, int *b) {
  printf("Address of a in add:%d\n", &a);
  printf("Address of a of add (address in a of main) = %d\n", a);
  printf("value at address stored in a of add = %d\n", *a);
  printf("value at address stored in b of add = %d\n", *b);
  int c = (*a) + (*b);
  return c;
}

int main(){
  int a = 2, b = 4; 
  printf("Address of a in main:%d\n", &a);
  printf("Address of b in main:%d\n", &b);

  int c = add(&a, &b);

  printf("Sum is: %d\n", c);

}