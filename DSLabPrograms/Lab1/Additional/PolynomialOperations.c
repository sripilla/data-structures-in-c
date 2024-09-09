/*Addition of polynomials with two terms: To perform different operations on polynomial with two terms x, y using 2-D array representations. Operations like addition and multiplication have to be implemented [ref: J.P Trembly]. If the 2D array representation is sparse then optimize the memory usage by using suitable alternative representation. */

#include <stdio.h>
#include <stdlib.h>

// Function to initialize the polynomial
void initializePolynomial(int poly[][2], int size) {
    for (int i = 0; i < size; i++) {
        poly[i][0] = 0; // coefficient
        poly[i][1] = 0; // exponent
    }
}

// Function to print a polynomial
void printPolynomial(int poly[][2], int size) {
    for (int i = 0; i < size; i++) {
        if (poly[i][0] != 0) { // print only non-zero coefficients
            if (i != 0 && poly[i][0] > 0) {
                printf(" + ");
            }
            printf("%dx^%d", poly[i][0], poly[i][1]);
        }
    }
    printf("\n");
}

// Function to add two polynomials
void addPolynomials(int poly1[][2], int size1, int poly2[][2], int size2, int result[][2], int *resultSize) {
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (poly1[i][1] == poly2[j][1]) {
            result[k][0] = poly1[i][0] + poly2[j][0];
            result[k][1] = poly1[i][1];
            i++;
            j++;
            k++;
        } else if (poly1[i][1] > poly2[j][1]) {
            result[k][0] = poly1[i][0];
            result[k][1] = poly1[i][1];
            i++;
            k++;
        } else {
            result[k][0] = poly2[j][0];
            result[k][1] = poly2[j][1];
            j++;
            k++;
        }
    }
    while (i < size1) {
        result[k][0] = poly1[i][0];
        result[k][1] = poly1[i][1];
        i++;
        k++;
    }
    while (j < size2) {
        result[k][0] = poly2[j][0];
        result[k][1] = poly2[j][1];
        j++;
        k++;
    }
    *resultSize = k;
}

// Function to multiply two polynomials
void multiplyPolynomials(int poly1[][2], int size1, int poly2[][2], int size2, int result[][2], int *resultSize) {
    int temp[100][2] = {0}; // temporary storage for intermediate results
    int tempSize = 0;

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            int coeff = poly1[i][0] * poly2[j][0];
            int exp = poly1[i][1] + poly2[j][1];

            int found = 0;
            for (int k = 0; k < tempSize; k++) {
                if (temp[k][1] == exp) {
                    temp[k][0] += coeff;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                temp[tempSize][0] = coeff;
                temp[tempSize][1] = exp;
                tempSize++;
            }
        }
    }

    // Copy results to the result polynomial
    for (int i = 0; i < tempSize; i++) {
        result[i][0] = temp[i][0];
        result[i][1] = temp[i][1];
    }
    *resultSize = tempSize;
}

int main() {
    int poly1[10][2] = { {3, 2}, {5, 0} }; // Represents 3x^2 + 5
    int poly2[10][2] = { {2, 1}, {1, 0} }; // Represents 2x^1 + 1

    int resultAdd[20][2], resultMult[20][2];
    int resultSizeAdd, resultSizeMult;

    printf("Polynomial 1: ");
    printPolynomial(poly1, 2);

    printf("Polynomial 2: ");
    printPolynomial(poly2, 2);

    // Add polynomials
    addPolynomials(poly1, 2, poly2, 2, resultAdd, &resultSizeAdd);
    printf("Sum of Polynomials: ");
    printPolynomial(resultAdd, resultSizeAdd);

    // Multiply polynomials
    multiplyPolynomials(poly1, 2, poly2, 2, resultMult, &resultSizeMult);
    printf("Product of Polynomials: ");
    printPolynomial(resultMult, resultSizeMult);

    return 0;
}

/* SAMPLE OUTPUT 
Polynomial 1: 3x^2 + 5
Polynomial 2: 2x^1 + 1
Sum of Polynomials: 3x^2 + 2x^1 + 6
Product of Polynomials: 6x^3 + 11x^2 + 5x^1

NOTE: Explanation of the Output:
The program displays the addition and multiplication results of the two polynomials.
The addition combines like terms, while multiplication involves calculating the product of each term from both polynomials and combining like terms.*/

/* EXPLANATION 
1. Include Headers:

#include <stdio.h>: For input/output functions.
#include <stdlib.h>: For dynamic memory allocation (not used in this specific example but useful for larger applications).

2. Function Definitions:

initializePolynomial(): Initializes the polynomial array with zeros.
printPolynomial(): Prints the polynomial in a readable format.
addPolynomials(): Adds two polynomials and stores the result.
multiplyPolynomials(): Multiplies two polynomials and stores the result.

3. main() Function:

Defines two example polynomials.
Calls functions to add and multiply the polynomials.
Displays the results.
*/

