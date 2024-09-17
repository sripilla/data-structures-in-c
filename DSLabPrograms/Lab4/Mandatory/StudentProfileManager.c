/*Create a structure STUDENT consisting of variables of structures:

i. DOB {day, month (use pointer ), year},
ii. STU_INFO {reg_no, name(use pointer), address},
iii. COLLEGE {college_name (use pointer), university_name}

where structure types from i to iii are declared outside the STUDENT independently.
Show how to read and display member variables of DOB type if pointer variable is created for DOB inside STUDENT and STUDENT variable is also a pointer variable. The
program should read and display the values of all members of STUDENT structure. */

#include <stdio.h>
#include <stdlib.h>

// Structure for DOB
struct DOB {
    int day;
    int *month;
    int year;
};

// Structure for STU_INFO
struct STU_INFO {
    int reg_no;
    char *name;
    char address[100];
};

// Structure for COLLEGE
struct COLLEGE {
    char *college_name;
    char university_name[100];
};

// Structure for STUDENT containing pointers to the structures
struct STUDENT {
    struct DOB *dob;  // Pointer to DOB structure
    struct STU_INFO stu_info;
    struct COLLEGE college;
};

int main() {
    // Creating a STUDENT variable pointer
    struct STUDENT *student = (struct STUDENT *)malloc(sizeof(struct STUDENT));

    // Allocating memory for DOB month pointer inside STUDENT
    student->dob = (struct DOB *)malloc(sizeof(struct DOB));
    student->dob->month = (int *)malloc(sizeof(int));

    // Reading values for STUDENT structure
    printf("Enter day of birth: ");
    scanf("%d", &student->dob->day);
    printf("Enter month of birth: ");
    scanf("%d", student->dob->month);
    printf("Enter year of birth: ");
    scanf("%d", &student->dob->year);

    printf("Enter registration number: ");
    scanf("%d", &student->stu_info.reg_no);
    getchar(); // Consume newline character

    student->stu_info.name = (char *)malloc(50 * sizeof(char));
    printf("Enter student name: ");
    fgets(student->stu_info.name, 50, stdin);

    printf("Enter student address: ");
    fgets(student->stu_info.address, 100, stdin);

    student->college.college_name = (char *)malloc(100 * sizeof(char));
    printf("Enter college name: ");
    fgets(student->college.college_name, 100, stdin);

    printf("Enter university name: ");
    fgets(student->college.university_name, 100, stdin);

    // Displaying values for STUDENT structure
    printf("\nStudent Details:\n");
    printf("Date of Birth: %d/%d/%d\n", student->dob->day, *(student->dob->month), student->dob->year);
    printf("Registration Number: %d\n", student->stu_info.reg_no);
    printf("Name: %s", student->stu_info.name);
    printf("Address: %s", student->stu_info.address);
    printf("College Name: %s", student->college.college_name);
    printf("University Name: %s", student->college.university_name);

    // Freeing allocated memory
    free(student->dob->month);
    free(student->dob);
    free(student->stu_info.name);
    free(student->college.college_name);
    free(student);

    return 0;
}


/* SAMPLE OUTPUT
Enter day of birth: 15
Enter month of birth: 8
Enter year of birth: 2000
Enter registration number: 12345
Enter student name: John Doe
Enter student address: 123 Elm St
Enter college name: ABC College
Enter university name: XYZ University

Student Details:
Date of Birth: 15/8/2000
Registration Number: 12345
Name: John Doe
Address: 123 Elm St
College Name: ABC College
University Name: XYZ University

*/