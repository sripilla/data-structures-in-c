#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n); 

    int *a = (int *)malloc(n*sizeof(int));

    for (int i = 0; i < n; i++) {
        a[i] = i + 1; 
        printf("%d ", a[i]);
    }

    int *b = (int *)realloc(a, 2 * n * sizeof(int));
    printf("\nprev block address = %d, new address = %d\n", a,b);

     for (int i = 0; i < 2 * n; i++) {
        printf("%d\n ", b[i]);
    }
}

/*
Enter the number of elements in the array: 2
1 2 
prev block address = 29166272, new address = 29166272
1
 2
 0
 0
 */