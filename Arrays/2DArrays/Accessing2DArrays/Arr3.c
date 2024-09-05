/*
In a small company there are five salesmen. Each salesmam is supposed to sell three products. Write a program using 2D array to print
(i) the total sales by each salesman and
(ii) total sales of each item 
*/

#include <stdio.h>

int main() {
    // Declare a 2D array to store sales data for 5 salesmen and 3 items
    int sales[5][3], i, j, total_sales;

    // Prompt the user to enter sales data for each salesman
    printf("ENTER THE DATA\n");
    printf("*************\n");

    for(i = 0; i < 5; i++) {
        printf("\nEnter the sales of 3 items sold by salesman %d:\n", i+1);
        for(j = 0; j < 3; j++) {
            printf("Item %d: ", j+1);
            scanf("%d", &sales[i][j]);  // Input sales for each item
        }
    }

    // Calculate and print total sales by each salesman
    printf("\nTotal sales by each salesman:\n");
    for(i = 0; i < 5; i++) {
        total_sales = 0;  // Reset total sales for each salesman
        for(j = 0; j < 3; j++) {
            total_sales += sales[i][j];  // Sum up sales of all items for the salesman
        }
        printf("Salesman %d: %d\n", i+1, total_sales);
    }

    // Calculate and print total sales of each item
    printf("\nTotal sales of each item:\n");
    for(j = 0; j < 3; j++) {
        total_sales = 0;  // Reset total sales for each item
        for(i = 0; i < 5; i++) {
            total_sales += sales[i][j];  // Sum up sales of the item across all salesmen
        }
        printf("Item %d: %d\n", j+1, total_sales);
    }

    return 0;  // End of the program
}

/* SAMPLE OUTPUT
ENTER THE DATA
*************

Enter the sales of 3 items sold by salesman 1:
Item 1: 100
Item 2: 200
Item 3: 150

Enter the sales of 3 items sold by salesman 2:
Item 1: 120
Item 2: 210
Item 3: 140

Enter the sales of 3 items sold by salesman 3:
Item 1: 130
Item 2: 220
Item 3: 160

Enter the sales of 3 items sold by salesman 4:
Item 1: 140
Item 2: 230
Item 3: 170

Enter the sales of 3 items sold by salesman 5:
Item 1: 150
Item 2: 240
Item 3: 180

Total sales by each salesman:
Salesman 1: 450
Salesman 2: 470
Salesman 3: 510
Salesman 4: 540
Salesman 5: 570

Total sales of each item:
Item 1: 640
Item 2: 1100
Item 3: 800

*/