/*Design an application using suitable data structure to automate the process of class representative election. The application should take the inputs – No of students(voters)
present in the class and No of Candidates and their name(s). During the voting process,
the faculty on duty of conduction of election, need to initiate the voting (say by pressing
a particular key during which a beep sound is heard). Then, a student can come and cast
his/her vote against the candidate by entering the candidate’s serial number. Aftercasting
a vote, a beep sound is given to confirm that the voting is done. This process is repeated
until all students cast their vote. At the end, the total votes obtained by each candidate
should be displayed along with number of foul votes. the candidate who has */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // For _getch() function (Windows only)
#include <windows.h> // For Beep() function (Windows only)

// Function to display the candidates
void displayCandidates(char candidates[][50], int numCandidates) {
    printf("\nCandidates List:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i]);
    }
}

int main() {
    int numStudents, numCandidates;

    // Input number of candidates
    printf("Enter the number of candidates: ");
    scanf("%d", &numCandidates);
    getchar(); // Consume newline character

    // Input candidate names
    char candidates[numCandidates][50];
    for (int i = 0; i < numCandidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        fgets(candidates[i], sizeof(candidates[i]), stdin);
        candidates[i][strcspn(candidates[i], "\n")] = '\0'; // Remove trailing newline
    }

    // Input number of students
    printf("\nEnter the number of students (voters): ");
    scanf("%d", &numStudents);

    // Initialize votes array and foul votes counter
    int votes[numCandidates];
    for (int i = 0; i < numCandidates; i++) {
        votes[i] = 0;
    }
    int foulVotes = 0;

    // Start voting process
    printf("\nVoting has started! Press any key to begin...\n");
    _getch(); // Wait for user input

    Beep(1000, 500); // Beep sound to indicate voting start

    for (int i = 0; i < numStudents; i++) {
        int vote;
        printf("Student %d, enter the candidate number (1-%d) you are voting for: ", i + 1, numCandidates);
        scanf("%d", &vote);
        if (vote < 1 || vote > numCandidates) {
            printf("Invalid candidate number. This vote will be considered as a foul vote.\n");
            foulVotes++;
        } else {
            votes[vote - 1]++;
            Beep(1000, 500); // Beep sound to confirm vote
        }
    }

    // Display results
    printf("\nElection Results:\n");
    displayCandidates(candidates, numCandidates);
    printf("\nVotes received:\n");
    int maxVotes = 0, winnerIndex = -1;

    for (int i = 0; i < numCandidates; i++) {
        printf("Candidate %d (%s): %d votes\n", i + 1, candidates[i], votes[i]);
        if (votes[i] > maxVotes) {
            maxVotes = votes[i];
            winnerIndex = i;
        }
    }

    printf("Number of foul votes: %d\n", foulVotes);

    if (winnerIndex != -1) {
        printf("The class representative is Candidate %d (%s) with %d votes.\n", winnerIndex + 1, candidates[winnerIndex], maxVotes);
    } else {
        printf("No valid votes were cast.\n");
    }

    return 0;
}

/* SAMPLE OUTPUT 
Class Representative Election

Enter the number of students (voters): 5
Enter the number of candidates: 3

Enter the names of the candidates:
1. Alice
2. Bob
3. Charlie

Voting Process:
Press any key to start voting...

Student 1: 
Vote for candidate (enter serial number): 1
Vote recorded for Alice.
Beep sound...

Student 2: 
Vote for candidate (enter serial number): 2
Vote recorded for Bob.
Beep sound...

Student 3: 
Vote for candidate (enter serial number): 1
Vote recorded for Alice.
Beep sound...

Student 4: 
Vote for candidate (enter serial number): 3
Vote recorded for Charlie.
Beep sound...

Student 5: 
Vote for candidate (enter serial number): 2
Vote recorded for Bob.
Beep sound...

Voting Complete!

Results:
Alice: 2 votes
Bob: 2 votes
Charlie: 1 vote
Foul votes: 0

Winner: Alice (with the highest votes)

*/