/* write a program to interchange the smallest and largest number in an array */

#include <stdio.h>

// Function prototypes
void read_array(int my_array[], int n);
void display_array(int my_array[], int n);
void interchange(int arr[], int n);
int find_biggest_pos(int my_array[], int n);
int find_smallest_pos(int my_array[], int n);

int main() {
    int arr[10], n;

    // Read the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Read the array elements
    read_array(arr, n);

    // Interchange the largest and smallest elements
    interchange(arr, n);

    // Display the new array after interchange
    printf("\nThe new array is: ");
    display_array(arr, n);

    return 0; // Return 0 to indicate successful execution
}

// Function to read array elements from the user
void read_array(int my_array[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &my_array[i]);
    }
}

// Function to display the array elements
void display_array(int my_array[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, my_array[i]);
    }
}

// Function to interchange the largest and smallest elements in the array
void interchange(int arr[], int n) {
    int big_pos, small_pos, temp;

    // Find positions of the largest and smallest elements
    big_pos = find_biggest_pos(arr, n);
    small_pos = find_smallest_pos(arr, n);

    // Swap the largest and smallest elements
    temp = arr[big_pos];
    arr[big_pos] = arr[small_pos];
    arr[small_pos] = temp;
}

// Function to find the position of the largest element in the array
int find_biggest_pos(int my_array[], int n) {
    int i, large = my_array[0], pos = 0;
    for (i = 1; i < n; i++) {
        if (my_array[i] > large) {
            large = my_array[i];
            pos = i;
        }
    }
    return pos;
}

// Function to find the position of the smallest element in the array
int find_smallest_pos(int my_array[], int n) {
    int i, small = my_array[0], pos = 0;
    for (i = 1; i < n; i++) {
        if (my_array[i] < small) {
            small = my_array[i];
            pos = i;
        }
    }
    return pos;
}


/* SAMPLE OUTPUT
Enter the size of the array: 5
arr[0] = 10
arr[1] = 3
arr[2] = 8
arr[3] = 15
arr[4] = 2

The new array is:
arr[0] = 10
arr[1] = 15
arr[2] = 8
arr[3] = 3
arr[4] = 2

*/