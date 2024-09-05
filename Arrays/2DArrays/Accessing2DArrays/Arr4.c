/* Write a program to read a 2D array "marks" which stores the marks of 5 students in 3 subjects. Write a program to display the highest marks in each subject. */

#include <stdio.h>

int main() {
    int marks[5][3], i, j, max_marks;

    // Input marks for 5 students in 3 subjects
    for(i = 0; i < 5; i++) {
        printf("\nEnter the marks obtained by student %d:\n", i + 1);
        for(j = 0; j < 3; j++) {
            printf("Marks in subject %d: ", j + 1);
            scanf("%d", &marks[i][j]);  // Input marks for each subject
        }
    }

    // Find and display the highest marks in each subject
    for(j = 0; j < 3; j++) {
        max_marks = -999;  // Initialize max_marks to a very low value
        for(i = 0; i < 5; i++) {
            if(marks[i][j] > max_marks) {
                max_marks = marks[i][j];  // Update max_marks if current marks are higher
            }
        }
        printf("\nHighest marks in subject %d = %d", j + 1, max_marks);
    }

    return 0;  // End of the program
}

/* SAMPLE OUTPUT
Enter the marks obtained by student 1:
Marks in subject 1: 78
Marks in subject 2: 82
Marks in subject 3: 90

Enter the marks obtained by student 2:
Marks in subject 1: 85
Marks in subject 2: 77
Marks in subject 3: 88

Enter the marks obtained by student 3:
Marks in subject 1: 92
Marks in subject 2: 80
Marks in subject 3: 85

Enter the marks obtained by student 4:
Marks in subject 1: 81
Marks in subject 2: 91
Marks in subject 3: 87

Enter the marks obtained by student 5:
Marks in subject 1: 89
Marks in subject 2: 88
Marks in subject 3: 84

Highest marks in subject 1 = 92
Highest marks in subject 2 = 91
Highest marks in subject 3 = 90

*/