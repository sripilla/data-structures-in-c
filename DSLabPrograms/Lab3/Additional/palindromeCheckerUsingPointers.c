/* Write a function Palindrome to check whether a given string is a palindrome using pointers to array.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if the given string is a palindrome
int isPalindrome(char *str) {
    char *start = str;               // Pointer to the start of the string
    char *end = str + strlen(str) - 1;  // Pointer to the end of the string

    while (start < end) {
        // Ignore non-alphabetic characters and case sensitivity
        while (start < end && !isalnum(*start)) {
            start++;  // Move start pointer forward if not alphanumeric
        }
        while (start < end && !isalnum(*end)) {
            end--;  // Move end pointer backward if not alphanumeric
        }

        if (tolower(*start) != tolower(*end)) {
            return 0;  // Return false if characters don't match
        }

        start++;  // Move pointers toward the center
        end--;
    }

    return 1;  // Return true if the string is a palindrome
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);  // Read input string

    // Remove the newline character if it's present
    str[strcspn(str, "\n")] = '\0';

    if (isPalindrome(str)) {
        printf("\"%s\" is a palindrome.\n", str);
    } else {
        printf("\"%s\" is not a palindrome.\n", str);
    }

    return 0;
}

/* SAMPLE OUTPUT 
Enter a string: madam
"madam" is a palindrome.

*/