/* To copy one string to another using Recursion. */

#include <stdio.h>

// Function prototype for recursive string copy
void recursiveCopy(char *source, char *destination);

int main() {
    char source[100], destination[100];

    // Prompt user for input
    printf("Enter the source string: ");
    fgets(source, sizeof(source), stdin);

    // Remove trailing newline character if present
    for(int i = 0; source[i] != '\0'; i++) {
        if (source[i] == '\n') {
            source[i] = '\0';
            break;
        }
    }

    // Call the recursive function to copy the string
    recursiveCopy(source, destination);

    // Print the copied string
    printf("Copied string: %s\n", destination);

    return 0;
}

// Recursive function to copy a string from source to destination
void recursiveCopy(char *source, char *destination) {
    // Base case: If the source string is empty, end the recursion
    if (*source == '\0') {
        *destination = '\0'; // Null-terminate the destination string
        return;
    }

    // Copy the current character from source to destination
    *destination = *source;

    // Recursive call to copy the next character
    recursiveCopy(source + 1, destination + 1);
}


/* SAMPLE OUTPUT
Enter the source string: Hello, World!
Copied string: Hello, World!
*/

/*EXPLANATION
1. Function Prototype:

void recursiveCopy(char *source, char *destination);
This function is declared at the beginning and defined later. It copies characters from source to destination using recursion.

2. Main Function:

    Input Handling:
The program prompts the user to enter a source string. It uses fgets to read the input, which is safer than scanf as it prevents buffer overflow.
The program then removes any trailing newline character that fgets may leave.
    Function Call:
The recursiveCopy function is called with source and destination as arguments.
    Output:
After the copy operation, the program prints the copied string.

3. Recursive Function (recursiveCopy):

Base Case:
When the end of the source string is reached (*source == '\0'), the function terminates by setting the null-terminator in the destination string.
Recursive Case:
The function copies the current character from source to destination.
It then calls itself with the next characters in both source and destination.*/
