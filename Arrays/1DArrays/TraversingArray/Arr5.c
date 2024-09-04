/* Write a program to enter n number of digits. Form a number using these digits. */
#include <stdio.h>
#include <math.h>

int main() {
    // Variable to store the final number
    // Array to store the digits (up to 10 digits)
    // Variables: numofdigits for number of digits, i for looping
    
    int number = 0;                 
    int digit[10];                  
    int numofdigits, i;             

    // Prompt the user to enter the number of digits
    printf("Enter the number of digits: ");
    scanf("%d", &numofdigits);      // Read the number of digits

    // Loop to read each digit
    for(i = 0; i < numofdigits; i++) {
        // Prompt for the i-th digit (1-based index for clarity)
        printf("Enter digit at position %d: ", i + 1);  
        scanf("%d", &digit[i]);      // Store the digit in the array
    }

    // Loop to form the number using the digits
    for(i = 0; i < numofdigits; i++) {
        number = number * 10 + digit[i];  // Shift number by one place and add the current digit
    }

    // Display the formed number
    printf("The number formed is %d\n", number);

    return 0;  // Return 0 to indicate successful execution
}

/* ***************** SAMPLE OUTPUT ******************
    Enter the number of digits: 4
    Enter digit at position 1: 3
    Enter digit at position 2: 1
    Enter digit at position 3: 4
    Enter digit at position 4: 2
    The number formed is 3142

*/