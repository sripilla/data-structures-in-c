#include<stdio.h>
#include<string.h>

int main()
{
  char ch[20] = "JOHN"; // char ch[] = "JOHN"
  // NULL termination of strings is implicit
  
  int size = sizeof(ch);
  int len = strlen(ch);
  printf("Size of string is %d bytes\n", size);
  printf("Length of string is %d\n", len);
}

/* SAMPLE OUTPUT 
Size of string is 20 bytes
Length of string is 4

in case of commented code
Size of string is 5 bytes
Length of string is 4
*/