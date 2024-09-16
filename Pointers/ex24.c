#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n); 

    int *a = (int *)calloc(n, sizeof(int));
     if (a == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        a[i] = i + 1; 
        printf("%d ", a[i]);
    }
    free(a);
    return 0;
}

/*
Enter the number of elements in the array: 5
1 2 3 4 5 
*/