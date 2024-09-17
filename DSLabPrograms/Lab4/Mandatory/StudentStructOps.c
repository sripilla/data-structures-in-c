/*Write a C program to implement the following functions. Use pointers and
dynamic memory management functions.
i. To read one Student object where Student is a structure with name, roll
number and CGPA as the data members
ii. To display one Student object
iii. To sort an array of Student structures according to the roll number. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a student
struct Student {
    char name[50];
    int rollNumber;
    float CGPA;
};

// Function to read a Student object
struct Student* readStudent() {
    struct Student* student = (struct Student*)malloc(sizeof(struct Student));
    printf("Enter student name: ");
    scanf("%s", student->name);
    printf("Enter roll number: ");
    scanf("%d", &student->rollNumber);
    printf("Enter CGPA: ");
    scanf("%f", &student->CGPA);
    return student;
}

// Function to display a Student object
void displayStudent(struct Student* student) {
    printf("Name: %s, Roll Number: %d, CGPA: %.2f\n", student->name, student->rollNumber, student->CGPA);
}

// Function to sort an array of Student structures by roll number
void sortStudents(struct Student* students, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (students[j].rollNumber > students[j+1].rollNumber) {
                // Swap the students
                struct Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student* students = (struct Student*)malloc(n * sizeof(struct Student));

    // Reading student details
    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i+1);
        struct Student* student = readStudent();
        students[i] = *student;
        free(student);
    }

    // Displaying student details
    printf("\nStudent details before sorting:\n");
    for (int i = 0; i < n; i++) {
        displayStudent(&students[i]);
    }

    // Sorting students by roll number
    sortStudents(students, n);

    // Displaying sorted student details
    printf("\nStudent details after sorting by roll number:\n");
    for (int i = 0; i < n; i++) {
        displayStudent(&students[i]);
    }

    free(students);
    return 0;
}


/*  SAMPLE OUTPUT
Enter the number of students: 3
Enter details for student 1:
Enter student name: Alice
Enter roll number: 102
Enter CGPA: 8.5
Enter details for student 2:
Enter student name: Bob
Enter roll number: 101
Enter CGPA: 7.8
Enter details for student 3:
Enter student name: Charlie
Enter roll number: 103
Enter CGPA: 9.0

Student details before sorting:
Name: Alice, Roll Number: 102, CGPA: 8.50
Name: Bob, Roll Number: 101, CGPA: 7.80
Name: Charlie, Roll Number: 103, CGPA: 9.00

Student details after sorting by roll number:
Name: Bob, Roll Number: 101, CGPA: 7.80
Name: Alice, Roll Number: 102, CGPA: 8.50
Name: Charlie, Roll Number: 103, CGPA: 9.00
*/