#include <stdio.h>
#include <stdlib.h>

/* pointers in function returns */
int* add(int* a, int* b) { // called function - returns pointer to integer
    // Allocate memory for the result
    int* result = (int*)malloc(sizeof(int));
    *result = (*a) + (*b);
    return result;
}

int main() {
    int a = 2, b = 4; 
    int* ptr = add(&a, &b);

    if (ptr != NULL) { // Check if memory allocation was successful
        printf("Sum is: %d\n", *ptr);
        free(ptr); // Free the allocated memory
    }

    return 0;
}
