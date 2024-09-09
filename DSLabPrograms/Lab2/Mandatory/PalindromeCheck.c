/* To check whether a given String is Palindrome or not, using Recursion */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function prototype
bool isPalindrome(char str[], int start, int end);

// Main function
int main() {
    char str[100];

    // Input the string from the user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove the newline character if present
    str[strcspn(str, "\n")] = '\0';

    // Get the length of the string
    int length = strlen(str);

    // Check if the string is a palindrome
    if (isPalindrome(str, 0, length - 1)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}

// Recursive function to check if a string is a palindrome
bool isPalindrome(char str[], int start, int end) {
    // Base case: If the string has only one character or no characters
    if (start >= end) {
        return true;
    }

    // Check if the characters at the start and end are the same
    if (str[start] != str[end]) {
        return false;
    }

    // Move towards the middle of the string
    return isPalindrome(str, start + 1, end - 1);
}

/* SAMPLE OUTPUT 
INPUT:
Enter a string: madam

OUTPUT:
The string is a palindrome.
*/

/* EXPLANATION
Function isPalindrome:

1. Parameters:
      str[] - The string to check.
      start - The starting index of the substring to check.
      end - The ending index of the substring to check.
2. Base Case:
      If start is greater than or equal to end, the substring is either empty or has one character, which is always a palindrome.
3. Check Characters:
      Compare the characters at start and end. If they are different, the string is not a palindrome.
4. Recursive Call:
      Move inward by incrementing start and decrementing end and check the substring between these indices.

Main Function:

1. Input:
      Read a string from the user.
2. Process:
      Remove the newline character from the input.
      Call isPalindrome with the full length of the string.
3. Output:
      Print whether the string is a palindrome based on the result of the isPalindrome function.

*/