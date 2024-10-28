/* During a traffic jam on a Highway, certain vehicles are given priority over other to give
way. The possible types of vehicles on road and their associated priority are given below.

Vehicle Type  :  Emergency, Fire, School, President, Others
Priority: 10, 9, 8, 7, 6

When a vehicle arrives, vehicle priority (an integer) is read and inserted into the traffic
queue in the order of arrival. When the traffic is to be cleared, a vehicle with highest priority is allowed to move first and the vehicles following it in the queue move forward by one position. Write a program to simulate the above situation using suitable data structure. */

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char vehicleType[20]; // Type of vehicle
    int priority;         // Priority of the vehicle
} Vehicle;

// Function prototypes
void insertVehicle(Vehicle queue[], int* size, char* vehicleType);
Vehicle deleteMaxPriority(Vehicle queue[], int* size);
void displayQueue(Vehicle queue[], int size);
int getPriority(char* vehicleType);

int main() {
    Vehicle queue[MAX_SIZE];
    int size = 0;

    // Simulate vehicle arrivals
    insertVehicle(queue, &size, "Emergency");
    insertVehicle(queue, &size, "Fire");
    insertVehicle(queue, &size, "School");
    insertVehicle(queue, &size, "President");
    insertVehicle(queue, &size, "Others");

    printf("Traffic queue before clearing:\n");
    displayQueue(queue, size);

    // Clear traffic based on priority
    while (size > 0) {
        Vehicle highestPriorityVehicle = deleteMaxPriority(queue, &size);
        printf("Cleared vehicle: %s (Priority: %d)\n", highestPriorityVehicle.vehicleType, highestPriorityVehicle.priority);
    }

    return 0;
}

// Function to insert a vehicle into the queue based on its type
void insertVehicle(Vehicle queue[], int* size, char* vehicleType) {
    queue[*size].priority = getPriority(vehicleType);
    strcpy(queue[*size].vehicleType, vehicleType);
    (*size)++;
}

// Function to delete the vehicle with the highest priority from the queue
Vehicle deleteMaxPriority(Vehicle queue[], int* size) {
    if (*size == 0) {
        printf("Queue is empty.\n");
        return (Vehicle){"", -1}; // Return an invalid vehicle if queue is empty
    }

    int maxIndex = 0;
    for (int i = 1; i < *size; i++) {
        if (queue[i].priority > queue[maxIndex].priority) {
            maxIndex = i; // Update maxIndex if a higher priority is found
        }
    }

    Vehicle maxVehicle = queue[maxIndex]; // Store the vehicle with the highest priority

    // Move the last vehicle to the position of the removed vehicle
    queue[maxIndex] = queue[*size - 1];
    (*size)--; // Decrease the size of the queue

    return maxVehicle; // Return the removed vehicle
}

// Function to display the current queue
void displayQueue(Vehicle queue[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Vehicle: %s (Priority: %d)\n", queue[i].vehicleType, queue[i].priority);
    }
}

// Function to return the priority based on vehicle type
int getPriority(char* vehicleType) {
    if (strcmp(vehicleType, "Emergency") == 0) return 10;
    if (strcmp(vehicleType, "Fire") == 0) return 9;
    if (strcmp(vehicleType, "School") == 0) return 8;
    if (strcmp(vehicleType, "President") == 0) return 7;
    return 6; // Others
}


/* SAMPLE OUTPUT 
Traffic queue before clearing:
Vehicle: Emergency (Priority: 10)
Vehicle: Fire (Priority: 9)
Vehicle: School (Priority: 8)
Vehicle: President (Priority: 7)
Vehicle: Others (Priority: 6)
Cleared vehicle: Emergency (Priority: 10)
Cleared vehicle: Fire (Priority: 9)
Cleared vehicle: School (Priority: 8)
Cleared vehicle: President (Priority: 7)
Cleared vehicle: Others (Priority: 6)
*/