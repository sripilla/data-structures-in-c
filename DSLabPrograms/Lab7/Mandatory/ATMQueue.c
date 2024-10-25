/* Vignesh and his wife Lata are facing a cash crisis. They go to the nearby ATM to get
some cash. There are 3 ATMs inside the same room. People are standing in queue
outside, and go inside the room in groups of 3 to the ATMs, fetch their money and
come out. Lata has an irrational fear in getting money from ATM that her ATM pin
will somehow be stolen and her money will be lost. So she will always like to go into
room with Vignesh. Vignesh is standing at position K in line, immediately followed
by lata (at position K+1). Can you tell whether Vignesh and Lata both will be able to
get money in such a way that Lata does not feel insecure? Using queue, find whether
they can get money for the given set of N and K. Input: the first line contains an
integer T denoting the number of test cases. T test cases follow. The only line of each
test case contains two spaces separated integers N and K , Where N denotes number
of people in the queue. And K denotes the position of Vignesh . Constraints
1<=T<=100 3<=N<=100 1<=K<=N-1, N is divisible by 3.
Sample Input
2
3 1
6 3
Output
Yes
No*/

#include <stdio.h>

int canGetMoney(int N, int K) {
    // Calculate the group number for Vignesh and Lata
    int groupPosition = (K - 1) / 3; // K is 1-based, so K-1 for 0-based index
    // Check if Lata can enter with Vignesh in the same group
    return (K % 3 == 0 || K % 3 == 1); // K must be in position 1 or 2 of its group
}

int main() {
    int T; // Number of test cases
    printf("Enter the number of test cases: ");
    scanf("%d", &T);

    while (T--) {
        int N, K; // Number of people and position of Vignesh
        printf("Enter N (number of people) and K (position of Vignesh): ");
        scanf("%d %d", &N, &K);

        // Check if both Vignesh and Lata can get money together
        if (canGetMoney(N, K)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}

/* SAMPLE OUTPUT

INPUT
2
3 1
6 3


OUTPUT

Yes
No

*/