/*To read a line of text and write it out backwards using Recursion  */
#include <stdio.h>
#include <string.h>

// Function prototype for the recursive function
void printReverse(const char *str, int length);

int main() {
    // Buffer to hold the input line of text
    char text[100];

    // Prompt user to enter a line of text
    printf("Enter a line of text: ");
    fgets(text, sizeof(text), stdin);

    // Remove newline character from the end if it exists
    size_t len = strlen(text);
    if (len > 0 && text[len - 1] == '\n') {
        text[len - 1] = '\0';
    }

    // Calculate the length of the text
    len = strlen(text);

    // Print the text in reverse
    printf("The text in reverse is: ");
    printReverse(text, len);

    return 0;
}

// Recursive function to print a string in reverse
void printReverse(const char *str, int length) {
    // Base case: if length is 0, stop recursion
    if (length == 0) {
        return;
    }

    // Recursive case: print last character and call function with reduced length
    printf("%c", str[length - 1]);

    // Recursive call with one less character
    printReverse(str, length - 1);
}

/* SAMPLE OUTPUT
INPUT:
Enter a line of text: Hello, World!

OUTPUT:
The text in reverse is: !dlroW ,olleH
*/

/* EXPLANATION
1. Reading Input:

      The fgets function reads a line of text from the user. It is used to handle input with spaces.
      The newline character (if present) at the end of the input is removed.

2. Calling Recursive Function:

      The printReverse function is called with the input string and its length.

3. Recursive Function Logic:

Base Case: The recursion stops when the length is 0. This means there are no more characters to print.

Recursive Case: The function prints the last character of the string and then recursively calls itself with a reduced length (excluding the last character).

4. Output:

The program prints the string in reverse order by recursively printing the characters from the end to the beginning.*/