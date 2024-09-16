#include<stdio.h>
#include<string.h>

int main()
{
  char ch[20];
  ch[0] = 'J';
  ch[1] = 'O';
  ch[2] = 'H';
  ch[3] = 'N';
  ch[4] = '\0';

  int len = strlen(ch);
  printf("Length of string is %d\n", len);
  printf("%s\n", ch);
}

/* SAMPLE OUTPUT 

Length of string is 4

*/