/*Consider the following structure definition in C.
struct Student
{
char name[50];
int rollNumber;
float marks;
}; 

Write a C function 
1. createAndPrintStudents that dynamically allocates memory for an array of Studentstructures, 
2. initializes the array with student data, and prints the details of each student in the format given below. Name: name, Roll Number: rollNumber, Marks: marks */

#include <stdio.h>
#include <stdlib.h>

// Define the Student structure
struct Student {
    char name[50];
    int rollNumber;
    float marks;
};

// Function to create and print student details
void createAndPrintStudents(int n) {
    // Dynamically allocate memory for 'n' students
    struct Student* students = (struct Student*)malloc(n * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Input student data
    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", students[i].name);  // Use " %[^\n]" to allow spaces in the name
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNumber);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }

    // Print student details
    printf("\nStudent Details:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Roll Number: %d, Marks: %.2f\n", students[i].name, students[i].rollNumber, students[i].marks);
    }

    // Free the allocated memory
    free(students);
}

int main() {
    int numStudents;

    // Input the number of students
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Call the function to create and print student details
    createAndPrintStudents(numStudents);

    return 0;
}

/* SAMPLE OUTPUT
Enter the number of students: 2
Enter details for student 1:
Name: Alice
Roll Number: 101
Marks: 85.5
Enter details for student 2:
Name: Bob
Roll Number: 102
Marks: 92.0

Student Details:
Name: Alice, Roll Number: 101, Marks: 85.50
Name: Bob, Roll Number: 102, Marks: 92.00
*/