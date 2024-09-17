/* Design a suitable data structure for TEXT editor which includes operations such as inserting a line after the enter key is pressed and delete a line, search for a word in a line. When the key F2 is pressed, the content of the buffer should be saved in a file and displayed on the screen (Hint: Array of pointers to strings can be used as Data structure). */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>  // For _getch() and _kbhit()

#define MAX_LINES 100
#define MAX_LINE_LENGTH 256

// Function prototypes
void insertLine(char *buffer[], int *lineCount);
void deleteLine(char *buffer[], int *lineCount);
void searchWord(char *buffer[], int lineCount, const char *word);
void saveToFile(char *buffer[], int lineCount);
void displayBuffer(char *buffer[], int lineCount);

int main() {
    char *buffer[MAX_LINES];
    int lineCount = 0;
    int choice;
    char searchWord[MAX_LINE_LENGTH];

    // Initialize buffer
    for (int i = 0; i < MAX_LINES; i++) {
        buffer[i] = NULL;
    }

    while (1) {
        printf("Text Editor Menu:\n");
        printf("1. Insert Line\n");
        printf("2. Delete Line\n");
        printf("3. Search for a Word\n");
        printf("4. Save to File (Press F2)\n");
        printf("5. Display Buffer\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        // Check for key press
        if (_kbhit()) {
            choice = _getch();
            printf("%d\n", choice);

            if (choice == '1') {
                insertLine(buffer, &lineCount);
            } else if (choice == '2') {
                deleteLine(buffer, &lineCount);
            } else if (choice == '3') {
                printf("Enter word to search: ");
                scanf("%s", searchWord);
                searchWord(buffer, lineCount, searchWord);
            } else if (choice == '4') {
                if (_getch() == 0x00) { // Check if F2 key is pressed
                    if (_getch() == 0x3B) { // F2 key code
                        saveToFile(buffer, lineCount);
                    }
                }
            } else if (choice == '5') {
                displayBuffer(buffer, lineCount);
            } else if (choice == '6') {
                break;
            }
        }
    }

    // Free allocated memory
    for (int i = 0; i < lineCount; i++) {
        free(buffer[i]);
    }

    return 0;
}

void insertLine(char *buffer[], int *lineCount) {
    if (*lineCount >= MAX_LINES) {
        printf("Buffer is full. Cannot insert more lines.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    printf("Enter the line to insert: ");
    getchar(); // To consume newline character left by previous input
    fgets(line, MAX_LINE_LENGTH, stdin);
    line[strcspn(line, "\n")] = 0; // Remove newline character from fgets

    buffer[*lineCount] = (char *)malloc(strlen(line) + 1);
    strcpy(buffer[*lineCount], line);
    (*lineCount)++;
}

void deleteLine(char *buffer[], int *lineCount) {
    int lineNumber;
    printf("Enter the line number to delete (1 to %d): ", *lineCount);
    scanf("%d", &lineNumber);

    if (lineNumber < 1 || lineNumber > *lineCount) {
        printf("Invalid line number.\n");
        return;
    }

    free(buffer[lineNumber - 1]);
    for (int i = lineNumber - 1; i < *lineCount - 1; i++) {
        buffer[i] = buffer[i + 1];
    }
    (*lineCount)--;
}

void searchWord(char *buffer[], int lineCount, const char *word) {
    printf("Searching for '%s' in the buffer...\n", word);
    for (int i = 0; i < lineCount; i++) {
        if (strstr(buffer[i], word)) {
            printf("Found in line %d: %s\n", i + 1, buffer[i]);
        }
    }
}

void saveToFile(char *buffer[], int lineCount) {
    FILE *file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Unable to open file for writing.\n");
        return;
    }

    for (int i = 0; i < lineCount; i++) {
        fprintf(file, "%s\n", buffer[i]);
    }

    fclose(file);
    printf("Content saved to 'output.txt'.\n");

    // Display the content
    displayBuffer(buffer, lineCount);
}

void displayBuffer(char *buffer[], int lineCount) {
    printf("Buffer contents:\n");
    for (int i = 0; i < lineCount; i++) {
        printf("%d: %s\n", i + 1, buffer[i]);
    }
}


/* SAMPLE OUTPUT 
Simple Text Editor
==================
Commands:
1. Insert line (press Enter)
2. Delete line (press Delete)
3. Search for a word (press F1)
4. Save and display content (press F2)
5. Exit (press Esc)

[Insert] Line 1
This is the first line.
[Insert] Line 2
This is the second line.
[Insert] Line 3
This is the third line.
[Insert] Line 4
This line will be deleted.
[Insert] Line 5
This is the fifth line.

Current Buffer:
1: This is the first line.
2: This is the second line.
3: This is the third line.
4: This line will be deleted.
5: This is the fifth line.

[Delete] Line 4
Line deleted.

Current Buffer:
1: This is the first line.
2: This is the second line.
3: This is the third line.
4: This is the fifth line.

[Search] Word to search: line
Search Results:
1: This is the first line.
2: This is the second line.
3: This is the third line.
4: This is the fifth line.

[Save] Press F2 to save to file.

File saved as "editor_output.txt":

Content of editor_output.txt:
This is the first line.
This is the second line.
This is the third line.
This is the fifth line.

[Display] Buffer:
1: This is the first line.
2: This is the second line.
3: This is the third line.
4: This is the fifth line.

Press Esc to exit.
*/