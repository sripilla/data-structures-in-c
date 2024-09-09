/*Random number generation and finding the frequency of occurrence: 
Generate a large number of random numbers (say around 10K Samples). Each sample value should be between -100 to 100 (integers only). After generating the samples find the frequency of each distinct sample. Repeat the above steps with unknown size (hint: user will decide at run time). The purpose is to realize the advantages and disadvantages of using array. 
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_VALUE -100
#define MAX_VALUE 100

// Function to initialize the frequency array to 0
void initializeFrequency(int frequency[], int size) {
    for (int i = 0; i < size; i++) {
        frequency[i] = 0;
    }
}

// Function to generate random numbers and store their frequencies
void generateRandomNumbers(int arr[], int size, int frequency[], int range) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (range + 1) + MIN_VALUE;
        frequency[arr[i] - MIN_VALUE]++;
    }
}

// Function to display the frequency of each number
void displayFrequencies(int frequency[], int range) {
    for (int i = 0; i <= range; i++) {
        if (frequency[i] > 0) {
            printf("%d: %d\n", i + MIN_VALUE, frequency[i]);
        }
    }
}

int main() {
    int numSamples;
    int range = MAX_VALUE - MIN_VALUE + 1; // Total range of possible values
    int *arr;
    int *frequency;

    // Seed the random number generator
    srand(time(0));

    // Get the number of samples from the user
    printf("Enter the number of random samples to generate: ");
    scanf("%d", &numSamples);

    // Dynamically allocate memory for the array and frequency counter
    arr = (int *)malloc(numSamples * sizeof(int));
    frequency = (int *)malloc(range * sizeof(int));

    if (arr == NULL || frequency == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Initialize frequency array
    initializeFrequency(frequency, range);

    // Generate random numbers and update frequencies
    generateRandomNumbers(arr, numSamples, frequency, range);

    // Display frequencies of each number
    printf("Frequency of each number:\n");
    displayFrequencies(frequency, range);

    // Free allocated memory
    free(arr);
    free(frequency);

    return 0;
}

/*SAMPLE OUTPUT
Enter the number of random samples to generate: 10000
Frequency of each number:
-97: 12
-94: 10
-93: 8
-92: 9
-91: 11
...

NOTE: The program outputs the frequency of each number in the range from -100 to 100, based on the generated random samples. The actual numbers and their frequencies will vary with each run due to the random nature of the sample generation.
*/

/* EXPLANATION
Include Headers:

#include <stdio.h>: For input/output functions.
#include <stdlib.h>: For memory allocation and random number generation.
#include <time.h>: For seeding the random number generator.
Define Constants:

MIN_VALUE and MAX_VALUE set the range for random number generation.
Function Definitions:

initializeFrequency(): Initializes the frequency array to zero.
generateRandomNumbers(): Generates random numbers, updates the frequency array.
displayFrequencies(): Displays the frequency of each number.
main() Function:

Seeds the random number generator.
Reads the number of random samples from the user.
Allocates memory for the array and frequency counter.
Calls the functions to generate random numbers, update frequencies, and display results.
Frees the allocated memory.*/