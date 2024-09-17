/*Samuel wants to store the data of his employees, which includes the following fields:
(i) Name of the employee 
(ii) Date of birth which is a collection of {day, month, year}
(iii) Address which is a collection of {house number, zip code and state}. 

Write a 'C'program to read and display the data of N employees using pointers to array of structures.*/

#include <stdio.h>
#include <stdlib.h>

// Define structures for Employee, DateOfBirth, and Address
struct DateOfBirth {
    int day;
    int month;
    int year;
};

struct Address {
    int houseNumber;
    int zipCode;
    char state[30];
};

struct Employee {
    char name[50];
    struct DateOfBirth dob;
    struct Address address;
};

int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    // Allocate memory for n employees
    struct Employee *employees = (struct Employee *)malloc(n * sizeof(struct Employee));

    // Read data for each employee
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);

        printf("Enter name: ");
        scanf(" %[^\n]", employees[i].name);  // Read string with spaces

        printf("Enter date of birth (day month year): ");
        scanf("%d %d %d", &employees[i].dob.day, &employees[i].dob.month, &employees[i].dob.year);

        printf("Enter house number: ");
        scanf("%d", &employees[i].address.houseNumber);

        printf("Enter zip code: ");
        scanf("%d", &employees[i].address.zipCode);

        printf("Enter state: ");
        scanf(" %[^\n]", employees[i].address.state);  // Read string with spaces
    }

    // Display data for each employee
    printf("\nEmployee Details:\n");
    for (int i = 0; i < n; i++) {
        printf("\nEmployee %d:\n", i + 1);
        printf("Name: %s\n", employees[i].name);
        printf("Date of Birth: %02d-%02d-%d\n", employees[i].dob.day, employees[i].dob.month, employees[i].dob.year);
        printf("Address: House Number: %d, Zip Code: %d, State: %s\n", employees[i].address.houseNumber, employees[i].address.zipCode, employees[i].address.state);
    }

    // Free allocated memory
    free(employees);

    return 0;
}


/* SAMPLE OUTPUT 
Enter the number of employees: 2

Enter details for employee 1:
Enter name: John Doe
Enter date of birth (day month year): 15 6 1985
Enter house number: 123
Enter zip code: 98765
Enter state: California

Enter details for employee 2:
Enter name: Jane Smith
Enter date of birth (day month year): 22 11 1990
Enter house number: 456
Enter zip code: 12345
Enter state: New York

Employee Details:

Employee 1:
Name: John Doe
Date of Birth: 15-06-1985
Address: House Number: 123, Zip Code: 98765, State: California

Employee 2:
Name: Jane Smith
Date of Birth: 22-11-1990
Address: House Number: 456, Zip Code: 12345, State: New York
*/