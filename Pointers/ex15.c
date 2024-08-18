#include<stdio.h>
int main()
{
  char ch[4];
  ch[0] = 'J';
  ch[1] = 'O';
  ch[2] = 'H';
  ch[3] = 'N';
  //ch[4] = '\0'; // String has to be terminates by null character
  printf("%s\n", ch);
}

/* SAMPLE OUTPUT
 JOHN`@  with comments
 JOHN      without comments
*/