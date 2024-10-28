/* Write a C program to simulate a Car Parking System (CPS) with a maximum
capacity of N parking slots, 
where no more than N-1 cars can be parked at a time.
Each car is identified by its registration number and the owner's Aadhar ID.
Vehicles enter the parking lot in order of their arrival and leave in the same order.
If the parking lot is full when a new vehicle arrives, the system should notify that the
parking lot is full. 
When all vehicles have exited, the system should indicate that
the parking lot is empty. 
Cars can enter the parking lot if space becomes available
due to the departure of other vehicles.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100  // Maximum number of parking slots

// Define the structure for a car
struct Car {
    char registrationNumber[20];
    char aadharID[15];
};

// Define the Car Parking System (CPS)
struct ParkingLot {
    struct Car cars[MAX];
    int front;
    int rear;
    int capacity;
};

// Function to initialize the parking lot
void initializeParkingLot(struct ParkingLot *pl, int capacity) {
    pl->front = pl->rear = -1;  // Empty state
    pl->capacity = capacity;
}

// Check if the parking lot is full
int isFull(struct ParkingLot *pl) {
    return (pl->rear + 1) % pl->capacity == pl->front;
}

// Check if the parking lot is empty
int isEmpty(struct ParkingLot *pl) {
    return pl->front == -1;
}

// Function to park a car in the parking lot
void parkCar(struct ParkingLot *pl) {
    if (isFull(pl)) {
        printf("Parking lot is full. No space available!\n");
        return;
    }

    struct Car newCar;

    // Input car details
    printf("Enter car registration number: ");
    scanf("%s", newCar.registrationNumber);
    printf("Enter owner's Aadhar ID: ");
    scanf("%s", newCar.aadharID);

    // Insert car in the parking lot
    if (isEmpty(pl)) {
        pl->front = pl->rear = 0;
    } else {
        pl->rear = (pl->rear + 1) % pl->capacity;
    }
    pl->cars[pl->rear] = newCar;
    printf("Car with registration number %s parked.\n", newCar.registrationNumber);
}

// Function to remove a car from the parking lot
void removeCar(struct ParkingLot *pl) {
    if (isEmpty(pl)) {
        printf("Parking lot is empty. No cars to remove!\n");
        return;
    }

    printf("Car with registration number %s has exited.\n", pl->cars[pl->front].registrationNumber);

    // If only one car is present, set front and rear to -1 (empty state)
    if (pl->front == pl->rear) {
        pl->front = pl->rear = -1;
    } else {
        pl->front = (pl->front + 1) % pl->capacity;
    }
}

// Function to display the current status of the parking lot
void displayParkingLot(struct ParkingLot *pl) {
    if (isEmpty(pl)) {
        printf("Parking lot is empty.\n");
        return;
    }

    printf("Cars currently in the parking lot:\n");
    int i = pl->front;
    while (i != pl->rear) {
        printf("Car Registration: %s, Aadhar ID: %s\n", pl->cars[i].registrationNumber, pl->cars[i].aadharID);
        i = (i + 1) % pl->capacity;
    }
    // Print the last car
    printf("Car Registration: %s, Aadhar ID: %s\n", pl->cars[i].registrationNumber, pl->cars[i].aadharID);
}

// Main function to simulate the car parking system
int main() {
    struct ParkingLot parkingLot;
    int capacity, choice;

    // Input the maximum capacity of the parking lot
    printf("Enter the maximum number of parking slots: ");
    scanf("%d", &capacity);

    if (capacity <= 1) {
        printf("Invalid parking capacity. The parking lot should have at least 2 slots.\n");
        return 0;
    }

    // Initialize the parking lot with N-1 available slots (N is the capacity, N-1 cars can be parked)
    initializeParkingLot(&parkingLot, capacity);

    while (1) {
        printf("\n--- Car Parking System Menu ---\n");
        printf("1. Park a car\n");
        printf("2. Remove a car\n");
        printf("3. Display parking lot status\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                parkCar(&parkingLot);
                break;
            case 2:
                removeCar(&parkingLot);
                break;
            case 3:
                displayParkingLot(&parkingLot);
                break;
            case 4:
                printf("Exiting Car Parking System...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

/* SAMPLE OUTPUT
Enter the maximum number of parking slots: 5

--- Car Parking System Menu ---
1. Park a car
2. Remove a car
3. Display parking lot status
4. Exit
Enter your choice: 1
Enter car registration number: KA01AB1234
Enter owner's Aadhar ID: 123456789012
Car with registration number KA01AB1234 parked.

--- Car Parking System Menu ---
1. Park a car
2. Remove a car
3. Display parking lot status
4. Exit
Enter your choice: 1
Enter car registration number: KA01XY5678
Enter owner's Aadhar ID: 987654321098
Car with registration number KA01XY5678 parked.

--- Car Parking System Menu ---
1. Park a car
2. Remove a car
3. Display parking lot status
4. Exit
Enter your choice: 3
Cars currently in the parking lot:
Car Registration: KA01AB1234, Aadhar ID: 123456789012
Car Registration: KA01XY5678, Aadhar ID: 987654321098

--- Car Parking System Menu ---
1. Park a car
2. Remove a car
3. Display parking lot status
4. Exit
Enter your choice: 2
Car with registration number KA01AB1234 has exited.

--- Car Parking System Menu ---
1. Park a car
2. Remove a car
3. Display parking lot status
4. Exit
Enter your choice: 3
Cars currently in the parking lot:
Car Registration: KA01XY5678, Aadhar ID: 987654321098

--- Car Parking System Menu ---
1. Park a car
2. Remove a car
3. Display parking lot status
4. Exit
Enter your choice: 4
Exiting Car Parking System...
*/