/* Given a structure BOOK as follows:
typedef struct {char* title;char *author_name}BOOK;
Demonstrate the following using code snippets
i. Store N BOOKS using concept of pointers and dynamic memory allocation utilizing
the above given structure BOOK
ii. Function to check if any two BOOKS are having same title and author. Pass entire
structure as an argument. Display the result – Books are same or not – within the
function.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the BOOK structure
typedef struct {
    char* title;
    char* author_name;
} BOOK;

// Function to create a new BOOK
BOOK createBook(const char* title, const char* author_name) {
    BOOK book;
    book.title = (char*)malloc(strlen(title) + 1);  // Allocate memory for title
    book.author_name = (char*)malloc(strlen(author_name) + 1);  // Allocate memory for author name
    strcpy(book.title, title);  // Copy title to the structure
    strcpy(book.author_name, author_name);  // Copy author name to the structure
    return book;
}

// Function to free the memory allocated for a BOOK
void freeBook(BOOK book) {
    free(book.title);
    free(book.author_name);
}

// Function to check if two BOOKS are the same
void checkSameBooks(BOOK book1, BOOK book2) {
    if (strcmp(book1.title, book2.title) == 0 && strcmp(book1.author_name, book2.author_name) == 0) {
        printf("Books are the same: '%s' by '%s'\n", book1.title, book1.author_name);
    } else {
        printf("Books are different: '%s' by '%s' and '%s' by '%s'\n", 
               book1.title, book1.author_name, book2.title, book2.author_name);
    }
}

int main() {
    int N;
    printf("Enter the number of books: ");
    scanf("%d", &N);
    getchar(); // To consume the newline character left by scanf

    // Allocate memory for N BOOKS
    BOOK* books = (BOOK*)malloc(N * sizeof(BOOK));

    // Input data for each book
    for (int i = 0; i < N; i++) {
        char title[100];
        char author[100];

        printf("Enter title of book %d: ", i + 1);
        fgets(title, sizeof(title), stdin);
        title[strcspn(title, "\n")] = 0;  // Remove newline character

        printf("Enter author name of book %d: ", i + 1);
        fgets(author, sizeof(author), stdin);
        author[strcspn(author, "\n")] = 0;  // Remove newline character

        // Create and store the book
        books[i] = createBook(title, author);
    }

    // Check if any two books are the same
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            checkSameBooks(books[i], books[j]);
        }
    }

    // Free the allocated memory
    for (int i = 0; i < N; i++) {
        freeBook(books[i]);
    }
    free(books);

    return 0;
}

/* SAMPLE OUTPUT
Enter the number of books: 3
Enter title of book 1: The Great Gatsby
Enter author name of book 1: F. Scott Fitzgerald
Enter title of book 2: To Kill a Mockingbird
Enter author name of book 2: Harper Lee
Enter title of book 3: The Great Gatsby
Enter author name of book 3: F. Scott Fitzgerald
Books are different: 'The Great Gatsby' by 'F. Scott Fitzgerald' and 'To Kill a Mockingbird' by 'Harper Lee'
Books are the same: 'The Great Gatsby' by 'F. Scott Fitzgerald'
Books are different: 'To Kill a Mockingbird' by 'Harper Lee' and 'The Great Gatsby' by 'F. Scott Fitzgerald'
*/
