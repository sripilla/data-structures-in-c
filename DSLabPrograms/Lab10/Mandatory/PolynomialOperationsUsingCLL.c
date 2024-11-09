/* Given two polynomials, write a program to perform the following operations on
singly circular linked list with header node. Use menu driven approach to input two
polynomials, subtract, multiply and display the result. */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the circular singly linked list
struct Node {
    int coeff;   // Coefficient of the polynomial term
    int exp;     // Exponent of the polynomial term
    struct Node* next;  // Pointer to the next node (circular link)
};

// Function to create a new node with given coefficient and exponent
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  // Allocate memory for new node
    newNode->coeff = coeff;   // Set the coefficient of the term
    newNode->exp = exp;       // Set the exponent of the term
    newNode->next = newNode;  // Initially, the node points to itself (circular link)
    return newNode;
}

// Function to insert a new term into the circular singly linked list
void insertEnd(struct Node** head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);  // Create a new node with the given coefficient and exponent

    // If the list is empty (head is NULL), the new node becomes the first node
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;

        // Traverse the list until we reach the last node (circular link)
        while (temp->next != *head) {
            temp = temp->next;
        }

        // Insert the new node at the end of the list and update the circular link
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to display a polynomial stored in the circular linked list
void displayPolynomial(struct Node* head) {
    if (head == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        // Print the coefficient and exponent of each term
        printf("%d*x^%d", temp->coeff, temp->exp);
        temp = temp->next;  // Move to the next term

        // Print "+" between terms if not the last term
        if (temp != head) {
            printf(" + ");
        }
    } while (temp != head);  // Continue until we circle back to the head
    printf("\n");
}

// Function to subtract two polynomials
struct Node* subtractPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;  // Initialize the result polynomial
    struct Node *ptr1 = poly1, *ptr2 = poly2;  // Pointers to traverse both polynomials

    // Traverse both polynomials until we reach the end of both
    do {
        struct Node* temp = NULL;

        // Case 1: If the exponent of poly1 is greater than poly2, add the term from poly1
        if (ptr1->exp > ptr2->exp) {
            temp = createNode(ptr1->coeff, ptr1->exp);
            insertEnd(&result, temp->coeff, temp->exp);
            ptr1 = ptr1->next;  // Move to the next term in poly1
        }
        // Case 2: If the exponent of poly2 is greater than poly1, subtract the term from poly2
        else if (ptr1->exp < ptr2->exp) {
            temp = createNode(-ptr2->coeff, ptr2->exp);  // Negate the coefficient of poly2
            insertEnd(&result, temp->coeff, temp->exp);
            ptr2 = ptr2->next;  // Move to the next term in poly2
        }
        // Case 3: If both exponents are equal, subtract the coefficients
        else {
            int coeffDiff = ptr1->coeff - ptr2->coeff;
            if (coeffDiff != 0) {
                temp = createNode(coeffDiff, ptr1->exp);
                insertEnd(&result, temp->coeff, temp->exp);
            }
            ptr1 = ptr1->next;  // Move to the next term in poly1
            ptr2 = ptr2->next;  // Move to the next term in poly2
        }
    } while (ptr1 != poly1 && ptr2 != poly2);  // Loop until both polynomials are completely traversed

    // Add any remaining terms from poly1
    while (ptr1 != poly1) {
        struct Node* temp = createNode(ptr1->coeff, ptr1->exp);
        insertEnd(&result, temp->coeff, temp->exp);
        ptr1 = ptr1->next;
    }

    // Add any remaining terms from poly2 (with negated coefficients)
    while (ptr2 != poly2) {
        struct Node* temp = createNode(-ptr2->coeff, ptr2->exp);
        insertEnd(&result, temp->coeff, temp->exp);
        ptr2 = ptr2->next;
    }

    return result;  // Return the result of subtraction
}

// Function to multiply two polynomials
struct Node* multiplyPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;  // Initialize the result polynomial
    struct Node* ptr1 = poly1;

    // Traverse the first polynomial
    do {
        struct Node* ptr2 = poly2;

        // Traverse the second polynomial for each term in the first polynomial
        do {
            int coeffProduct = ptr1->coeff * ptr2->coeff;  // Multiply coefficients
            int expSum = ptr1->exp + ptr2->exp;  // Add exponents
            struct Node* temp = createNode(coeffProduct, expSum);
            insertEnd(&result, temp->coeff, temp->exp);  // Insert the product term into the result
            ptr2 = ptr2->next;  // Move to the next term in poly2
        } while (ptr2 != poly2);  // Continue for all terms in poly2

        ptr1 = ptr1->next;  // Move to the next term in poly1
    } while (ptr1 != poly1);  // Continue for all terms in poly1

    return result;  // Return the result of multiplication
}

// Main function to handle the menu-driven interface
int main() {
    struct Node* poly1 = NULL;  // First polynomial
    struct Node* poly2 = NULL;  // Second polynomial
    struct Node* result = NULL; // Result polynomial
    int choice, coeff, exp;
    int n1, n2;

    do {
        // Display menu options
        printf("\nMenu:\n");
        printf("1. Input first polynomial\n");
        printf("2. Input second polynomial\n");
        printf("3. Display first polynomial\n");
        printf("4. Display second polynomial\n");
        printf("5. Subtract polynomials\n");
        printf("6. Multiply polynomials\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);  // Read user's choice

        switch (choice) {
            case 1:
                // Input the first polynomial
                printf("Enter number of terms in the first polynomial: ");
                scanf("%d", &n1);
                for (int i = 0; i < n1; i++) {
                    printf("Enter coefficient and exponent for term %d: ", i + 1);
                    scanf("%d %d", &coeff, &exp);
                    insertEnd(&poly1, coeff, exp);  // Insert term into poly1
                }
                break;

            case 2:
                // Input the second polynomial
                printf("Enter number of terms in the second polynomial: ");
                scanf("%d", &n2);
                for (int i = 0; i < n2; i++) {
                    printf("Enter coefficient and exponent for term %d: ", i + 1);
                    scanf("%d %d", &coeff, &exp);
                    insertEnd(&poly2, coeff, exp);  // Insert term into poly2
                }
                break;

            case 3:
                // Display the first polynomial
                printf("First Polynomial: ");
                displayPolynomial(poly1);
                break;

            case 4:
                // Display the second polynomial
                printf("Second Polynomial: ");
                displayPolynomial(poly2);
                break;

            case 5:
                // Subtract the polynomials and display the result
                result = subtractPolynomials(poly1, poly2);
                printf("Result of Subtraction: ");
                displayPolynomial(result);
                break;

            case 6:
                // Multiply the polynomials and display the result
                result = multiplyPolynomials(poly1, poly2);
                printf("Result of Multiplication: ");
                displayPolynomial(result);
                break;

            case 7:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);  // Keep running until the user chooses to exit

    return 0;
}

/*Menu:
1. Input first polynomial
2. Input second polynomial
3. Display first polynomial
4. Display second polynomial
5. Subtract polynomials
6. Multiply polynomials
7. Exit
Enter your choice: 1

Enter number of terms in the first polynomial: 3
Enter coefficient and exponent for term 1: 3 2
Enter coefficient and exponent for term 2: 4 1
Enter coefficient and exponent for term 3: 5 0

Menu:
1. Input first polynomial
2. Input second polynomial
3. Display first polynomial
4. Display second polynomial
5. Subtract polynomials
6. Multiply polynomials
7. Exit
Enter your choice: 2

Enter number of terms in the second polynomial: 2
Enter coefficient and exponent for term 1: 2 2
Enter coefficient and exponent for term 2: 1 0

Menu:
1. Input first polynomial
2. Input second polynomial
3. Display first polynomial
4. Display second polynomial
5. Subtract polynomials
6. Multiply polynomials
7. Exit
Enter your choice: 3

First Polynomial: 3*x^2 + 4*x^1 + 5*x^0

Menu:
1. Input first polynomial
2. Input second polynomial
3. Display first polynomial
4. Display second polynomial
5. Subtract polynomials
6. Multiply polynomials
7. Exit
Enter your choice: 4

Second Polynomial: 2*x^2 + 1*x^0

Menu:
1. Input first polynomial
2. Input second polynomial
3. Display first polynomial
4. Display second polynomial
5. Subtract polynomials
6. Multiply polynomials
7. Exit
Enter your choice: 5

Result of Subtraction: 1*x^2 + 4*x^1 + 4*x^0

Menu:
1. Input first polynomial
2. Input second polynomial
3. Display first polynomial
4. Display second polynomial
5. Subtract polynomials
6. Multiply polynomials
7. Exit
Enter your choice: 6

Result of Multiplication: 6*x^4 + 13*x^3 + 9*x^2 + 4*x^1 + 5*x^0
 */
