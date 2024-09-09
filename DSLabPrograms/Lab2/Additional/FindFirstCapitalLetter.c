/*To find the first capital letter in a string using Recursion. */

#include <stdio.h>

// Function prototype
char findFirstCapitalLetter(const char *str, int index);

// Main function
int main() {
    // Sample input string
    const char *inputString = "helloWorldExample";

    // Call the recursive function to find the first capital letter
    char result = findFirstCapitalLetter(inputString, 0);

    // Check if a capital letter was found and print the result
    if (result != '\0') {
        printf("The first capital letter is: %c\n", result);
    } else {
        printf("No capital letter found in the string.\n");
    }

    return 0;
}

// Recursive function to find the first capital letter in the string
char findFirstCapitalLetter(const char *str, int index) {
    // Base case: if the end of the string is reached
    if (str[index] == '\0') {
        return '\0'; // No capital letter found
    }

    // Check if the current character is a capital letter
    if (str[index] >= 'A' && str[index] <= 'Z') {
        return str[index]; // Return the first capital letter found
    }

    // Recursive call to check the next character in the string
    return findFirstCapitalLetter(str, index + 1);
}

/* SAMPLE OUTPUT
The first capital letter is: W
*/

/* EXPLANATION
1. Function findFirstCapitalLetter:

This function takes a string and an index as arguments.
It checks if the current character (pointed to by index) is a capital letter.
If it is, the function returns this character.
If it is not, the function recursively calls itself with the next index.
If the end of the string is reached without finding a capital letter, the function returns '\0' (indicating no capital letter was found).

2. main Function:

Defines a sample input string.
Calls the findFirstCapitalLetter function starting from index 0.
Checks the result and prints the first capital letter if found, otherwise indicates that no capital letter was found.*/