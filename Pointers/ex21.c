#include <stdio.h>
#include <string.h>

void print(char *c)
{
    c[2] = 'A';  // Modify the third character
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

    print(c);  // This will print "HeAlo" since the third character is modified

    // If you uncomment the following line:
    // c[0] = 'A';  // Modifies the first character to 'A'
    // printf("%s\n", c);  // This will print "AeAlo"

    return 0;
}
