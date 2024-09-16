#include<stdio.h>
/* Arrays are always passes to function by reference */
void print(char *c)
{
  int i = 0;
  while(c[i] != '\0')
    {
      printf("%c", c[i]);
      i++;

    }
  printf("\n");
}

int main()
{
  char c[] = "Hello";
  printf("%s\n", c);
}

/* SAMPLE OUTPUT
 Hello


 change the while loop to while(*c != '\0')
 while(*c != '\0')
   {
     printf("%c", *c);
     c++;

   }

   the output will be same
*/