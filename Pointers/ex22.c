#include <stdio.h>
#include <string.h>

void print(const char *c)
{
    //c[2] = 'A';  // Modify the third character
    while(*c != '\0')
    {
        printf("%c", *c);
        c++;
    }
    printf("\n");
}

int main()
{
    char c[] = "Hello"; 
    printf("%s\n", c);  // Correct way to print a string in C
    return 0;
}

/* SAMPLE OUTPUT  = Hello

we can read but cant write in case of using constant pointer

const char *c: This declares c as a pointer to a constant character. It means that you cannot modify the content of the string that c points to. Attempting to do so (like c[2] = 'A';) will result in a compilation error because it violates the const qualifier.

*/