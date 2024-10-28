/*Illustrate the use of linked list to represent polynomials using structure. Specify the
following C functions
i. Create N polynomials and take input for each of them.
ii. Identify the degree of polynomial and display that within the function. Polynomial is
obtained as an argument. The highest power in a polynomial equation is considered
as the degree of the polynomial. */

#include <stdio.h>
#include <stdlib.h>

// Structure representing a term in the polynomial
struct Term {
    int coefficient; // Coefficient of the term
    int exponent;    // Exponent of the term
    struct Term* next; // Pointer to the next term
};

// Structure representing a polynomial
struct Polynomial {
    struct Term* head; // Pointer to the first term of the polynomial
};

// Function to create a new term
struct Term* createTerm(int coeff, int exp) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    if (newTerm == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newTerm->coefficient = coeff;
    newTerm->exponent = exp;
    newTerm->next = NULL;
    return newTerm;
}

// Function to add a term to the polynomial
void addTerm(struct Polynomial* poly, int coeff, int exp) {
    struct Term* newTerm = createTerm(coeff, exp);
    if (poly->head == NULL) {
        poly->head = newTerm; // If the polynomial is empty, set new term as head
    } else {
        struct Term* current = poly->head;
        while (current->next != NULL) {
            current = current->next; // Traverse to the end of the list
        }
        current->next = newTerm; // Link the new term at the end
    }
}

// Function to display the polynomial
void displayPolynomial(struct Polynomial* poly) {
    if (poly->head == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }
    struct Term* current = poly->head;
    while (current != NULL) {
        printf("%dx^%d", current->coefficient, current->exponent);
        if (current->next != NULL) {
            printf(" + ");
        }
        current = current->next; // Move to the next term
    }
    printf("\n");
}

// Function to calculate and display the degree of the polynomial
void calculateAndDisplayDegree(struct Polynomial* poly) {
    if (poly->head == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }
    int degree = 0; // Initialize degree
    struct Term* current = poly->head;
    while (current != NULL) {
        if (current->exponent > degree) {
            degree = current->exponent; // Update degree if current exponent is higher
        }
        current = current->next;
    }
    printf("Degree of the polynomial is: %d\n", degree);
}

int main() {
    int N; // Number of polynomials
    printf("Enter the number of polynomials (N): ");
    scanf("%d", &N);

    // Create an array of polynomials
    struct Polynomial* polynomials = (struct Polynomial*)malloc(N * sizeof(struct Polynomial));
    if (polynomials == NULL) {
        printf("Memory allocation failed for polynomials array.\n");
        exit(1);
    }

    // Initialize each polynomial
    for (int i = 0; i < N; i++) {
        polynomials[i].head = NULL; // Start with an empty polynomial
        int numTerms;
        printf("Enter the number of terms for Polynomial %d: ", i + 1);
        scanf("%d", &numTerms);

        for (int j = 0; j < numTerms; j++) {
            int coeff, exp;
            printf("Enter coefficient and exponent for term %d of Polynomial %d: ", j + 1, i + 1);
            scanf("%d%d", &coeff, &exp);
            addTerm(&polynomials[i], coeff, exp); // Add term to polynomial
        }

        // Display the polynomial and calculate its degree
        printf("Polynomial %d: ", i + 1);
        displayPolynomial(&polynomials[i]);
        calculateAndDisplayDegree(&polynomials[i]);
        printf("\n");
    }

    free(polynomials); // Free the allocated memory for the array of polynomials
    return 0;
}


/* SAMPLE OUTPUT 
Enter the number of polynomials (N): 2
Enter the number of terms for Polynomial 1: 3
Enter coefficient and exponent for term 1 of Polynomial 1: 3 4
Enter coefficient and exponent for term 2 of Polynomial 1: 5 2
Enter coefficient and exponent for term 3 of Polynomial 1: 2 0
Polynomial 1: 3x^4 + 5x^2 + 2x^0
Degree of the polynomial is: 4

Enter the number of terms for Polynomial 2: 2
Enter coefficient and exponent for term 1 of Polynomial 2: 4 3
Enter coefficient and exponent for term 2 of Polynomial 2: 1 1
Polynomial 2: 4x^3 + 1x^1
Degree of the polynomial is: 3
*/
