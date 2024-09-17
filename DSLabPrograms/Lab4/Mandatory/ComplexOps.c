/*Implement Complex numbers using structures. Write functions to add, multiply,
subtract two complex numbers. */

#include <stdio.h>

// Define a structure for complex numbers
struct Complex {
    float real;
    float imag;
};

// Function to add two complex numbers
struct Complex add(struct Complex c1, struct Complex c2) {
    struct Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

// Function to subtract two complex numbers
struct Complex subtract(struct Complex c1, struct Complex c2) {
    struct Complex result;
    result.real = c1.real - c2.real;
    result.imag = c1.imag - c2.imag;
    return result;
}

// Function to multiply two complex numbers
struct Complex multiply(struct Complex c1, struct Complex c2) {
    struct Complex result;
    result.real = c1.real * c2.real - c1.imag * c2.imag;
    result.imag = c1.real * c2.imag + c1.imag * c2.real;
    return result;
}

int main() {
    struct Complex num1, num2, sum, difference, product;

    // Input complex numbers
    printf("Enter the real and imaginary parts of the first complex number: ");
    scanf("%f %f", &num1.real, &num1.imag);

    printf("Enter the real and imaginary parts of the second complex number: ");
    scanf("%f %f", &num2.real, &num2.imag);

    // Perform operations
    sum = add(num1, num2);
    difference = subtract(num1, num2);
    product = multiply(num1, num2);

    // Output results
    printf("Sum: %.2f + %.2fi\n", sum.real, sum.imag);
    printf("Difference: %.2f + %.2fi\n", difference.real, difference.imag);
    printf("Product: %.2f + %.2fi\n", product.real, product.imag);

    return 0;
}

/* 
Sample output

Enter the real and imaginary parts of the first complex number: 3 2
Enter the real and imaginary parts of the second complex number: 1 7
Sum: 4.00 + 9.00i
Difference: 2.00 - 5.00i
Product: -11.00 + 23.00i
*/