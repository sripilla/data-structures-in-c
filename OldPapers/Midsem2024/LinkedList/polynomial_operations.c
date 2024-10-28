/* Design the C functions to perform the following operations on a polynomial, where
the polynomial is of the form:
P(x)=an.xn + an-1.xn-1 + …..+ a1.x + a0
1. Insert a new term (coefficient and exponent) into the polynomial
2. Add two polynomials and return the resulting polynomial. */

/* coeff: Coefficient of the term.
   exp: Exponent of the term.
   next: Pointer to the next term in the polynomial. */

// NODE STRUCTURE 

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;  // Coefficient
    int exp;    // Exponent
    struct Node* next;
};

// Function to Insert a New Term into the Polynomial:
// Function to create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term into the polynomial
void insertTerm(struct Node** poly, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    struct Node* current = *poly;
    struct Node* prev = NULL;

    // Insert in descending order of exponents
    while (current != NULL && current->exp > exp) {
        prev = current;
        current = current->next;
    }

    // If a term with the same exponent exists, add the coefficients
    if (current != NULL && current->exp == exp) {
        current->coeff += coeff;
        free(newNode);  // New node is not needed
        return;
    }

    // Insert new node at the correct position
    if (prev == NULL) {
        newNode->next = *poly;
        *poly = newNode;
    } else {
        prev->next = newNode;
        newNode->next = current;
    }
}

//Function to Add Two Polynomials:
// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp > poly2->exp) {
            insertTerm(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            insertTerm(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            // Exponents are the same, so add coefficients
            insertTerm(&result, poly1->coeff + poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Insert remaining terms from poly1, if any
    while (poly1 != NULL) {
        insertTerm(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }

    // Insert remaining terms from poly2, if any
    while (poly2 != NULL) {
        insertTerm(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }

    return result;
}

// Utility Functions
// Function to print a polynomial
void printPolynomial(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        if (poly->next != NULL) {
            printf(" + ");
        }
        poly = poly->next;
    }
    printf("\n");
}
// Main Usage

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    // Create first polynomial: 3x^3 + 2x^2 + 1
    insertTerm(&poly1, 3, 3);
    insertTerm(&poly1, 2, 2);
    insertTerm(&poly1, 1, 0);

    // Create second polynomial: 5x^2 + 4x + 2
    insertTerm(&poly2, 5, 2);
    insertTerm(&poly2, 4, 1);
    insertTerm(&poly2, 2, 0);

    // Add polynomials
    struct Node* result = addPolynomials(poly1, poly2);

    // Print result
    printf("Polynomial 1: ");
    printPolynomial(poly1);
    printf("Polynomial 2: ");
    printPolynomial(poly2);
    printf("Sum: ");
    printPolynomial(result);

    return 0;
}

/*SAMPLE OUTPUT
Polynomial 1: 3x^3 + 2x^2 + 1
Polynomial 2: 5x^2 + 4x + 2
Sum: 3x^3 + 7x^2 + 4x + 3
*/