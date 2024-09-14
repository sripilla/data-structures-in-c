/* To check whether a given String is Palindrome or not, using Recursion */
#include <stdio.h>
#include <string.h>

// Recursive function to check if a string is a palindrome
int isPalindrome(char *str, int start, int end) {
    // Base case: if there's only one or no characters left
    if (start >= end) {
        return 1; // The string is a palindrome
    }

    // Check if the characters at start and end match
    if (str[start] != str[end]) {
        return 0; // The string is not a palindrome
    }

    // Recursive call to check the next pair of characters
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    char str[100];

    // Input the string from the user
    printf("Enter a string: ");
    scanf("%s", str);

    // Get the length of the string
    int length = strlen(str);

    // Call the recursive function to check if the string is a palindrome
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
Enter a string: madam
The string is a palindrome.

Enter a string: hello
The string is not a palindrome.
*/

