/*Bishu went to fight for Coding club. There were N soldiers with various powers. There will be Q rounds to fight and in each round Bishu’s power will be varied. With power M, Bishu can kill all the soldiers whose power is less than or equal to M(<=M). After each round, all the soldiers who are dead in previous round will reborn. Such that in each round there will be N soldiers to fight. As Bishu is weak in mathematics, help him to count the number of soldiers that he can kill in each round and total sum of their powers. Explanation: In first round bishu power is 3 so there are 3 soldiers whose power is <=3 and the sum of their power is 1+2+3=6 therefore ans = 3 6 same for the next round. 
Sample Input 
7
123456 7 3
3
10
2
Sample Output 
36 7 28 23
 */
#include <stdio.h>
#include <stdlib.h>

// Function to perform binary search to find the count of soldiers with power <= M
int binarySearch(int arr[], int size, int M) {
    int left = 0, right = size - 1, mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (arr[mid] <= M) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return right + 1; // Number of elements <= M
}

int main() {
    int N, Q;

    // Read the number of soldiers
    scanf("%d", &N);
    int powers[N];

    // Read the powers of soldiers
    for (int i = 0; i < N; i++) {
        scanf("%d", &powers[i]);
    }

    // Sort the array of powers
    qsort(powers, N, sizeof(int), (int (*)(const void *, const void *)) strcmp);

    // Calculate prefix sums
    int prefixSum[N];
    prefixSum[0] = powers[0];
    for (int i = 1; i < N; i++) {
        prefixSum[i] = prefixSum[i - 1] + powers[i];
    }

    // Read the number of queries
    scanf("%d", &Q);

    // Process each query
    for (int i = 0; i < Q; i++) {
        int M;
        scanf("%d", &M);

        // Find the count of soldiers with power <= M
        int count = binarySearch(powers, N, M);

        // Calculate the sum of powers of soldiers with power <= M
        int sum = (count > 0) ? prefixSum[count - 1] : 0;

        // Print the results for this query
        printf("%d %d\n", count, sum);
    }

    return 0;
}

/* SAMPLE INPUT AND OUTPUT
INPUT
7
1 2 3 4 5 6 7
3
10
2

OUTPUT
3 6
7 28
2 3
*/

/* EXPLANATION 
1. Sorting:

The qsort function is used to sort the soldier powers in ascending order, which is crucial for efficient binary searching and prefix sum calculation.

2. Prefix Sum Calculation:

prefixSum[i] holds the sum of all soldier powers from index 0 to i. This allows quick computation of the sum of powers up to any given index.

3. Binary Search:

binarySearch function finds the number of soldiers with power less than or equal to 
𝑀
M. It returns the number of such soldiers by locating the rightmost index where the soldier's power is less than or equal to 
𝑀
M.

4. Query Processing:

For each query, the number of soldiers and their total power are calculated and printed. */