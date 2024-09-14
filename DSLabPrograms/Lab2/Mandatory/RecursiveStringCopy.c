/* To copy one string to another using Recursion. */

#include <stdio.h>

// Function to copy one string to another using recursion
void copyString(char *source, char *destination) {
    // Base case: if the end of the source string is reached
    if (*source == '\0') {
        *destination = '\0'; // Append null character to destination
    } else {
        *destination = *source; // Copy current character
        // Recursive call for the next character
        copyString(source + 1, destination + 1);
    }
}

int main() {
    char stng1[20], stng2[20]; // Declaring two strings
    printf("\n\n Recursion : Copy One string to another :\n");
    printf("---------------------------------------------\n");    

    // Input the first string from the user
    printf(" Input the string to copy : ");
    scanf("%s", stng1);

    // Call the function to copy the string
    copyString(stng1, stng2);

    // Output the results
    printf("\n The string successfully copied.\n\n");
    printf(" The first string is : %s\n", stng1);
    printf(" The copied string is : %s\n\n", stng2);

    return 0;
}


/* SAMPLE OUTPUT
Enter the source string: Hello, World!
Copied string: Hello, World!
*/


