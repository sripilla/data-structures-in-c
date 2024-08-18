void print(char *c)
{

  while(*c = '\0')
    {
      printf("%c", *c);
      c++;

    }
  printf("\n");
}

int main()
{
  char *c = "Hello"; 
  printf("%s\n", c);
  //c[0] = 'A'
}
/* SAMPLE OUTPUT = Hello

char *c = 'hello'
string gets stored as compile time constant
it may get stores in text segment of memory and cannot be modified

char c[] = "Hello";
char c[20] = "Hello";

string get stored in the space of memory allocated to it ie array space
it gets stored as stack frame in stack segment of memory
*/