/*Write a program to check whether given string is a palindrome using a deque. */

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>

    #define MAX 100 // Maximum length of the string

    // Define the structure for the Deque
    struct Deque {
        char items[MAX]; // Array to store characters
        int front, rear; // Front and rear indices
    };

    // Function to initialize the deque
    void initDeque(struct Deque *dq) {
        dq->front = -1;
        dq->rear = -1;
    }

    // Check if deque is full
    int isFull(struct Deque *dq) {
        return ((dq->front == 0 && dq->rear == MAX - 1) || (dq->front == dq->rear + 1));
    }

    // Check if deque is empty
    int isEmpty(struct Deque *dq) {
        return (dq->front == -1);
    }

    // Insert a character at the rear
    void insertRear(struct Deque *dq, char ch) {
        if (isFull(dq)) {
            printf("Deque is full. Cannot insert more characters.\n");
            return;
        }

        // If deque is empty
        if (dq->front == -1) {
            dq->front = 0;
            dq->rear = 0;
        }
        // If rear is at the last position, wrap around
        else if (dq->rear == MAX - 1) {
            dq->rear = 0;
        }
        // Otherwise, increment rear
        else {
            dq->rear++;
        }
        dq->items[dq->rear] = ch;
    }

    // Delete a character from the front
    char deleteFront(struct Deque *dq) {
        if (isEmpty(dq)) {
            printf("Deque is empty. Cannot delete any more characters.\n");
            return '\0';
        }

        char ch = dq->items[dq->front];

        // If the deque has only one element
        if (dq->front == dq->rear) {
            dq->front = -1;
            dq->rear = -1;
        }
        // If front is at the last position, wrap around
        else if (dq->front == MAX - 1) {
            dq->front = 0;
        }
        // Otherwise, increment front
        else {
            dq->front++;
        }

        return ch;
    }

    // Delete a character from the rear
    char deleteRear(struct Deque *dq) {
        if (isEmpty(dq)) {
            printf("Deque is empty. Cannot delete any more characters.\n");
            return '\0';
        }

        char ch = dq->items[dq->rear];

        // If the deque has only one element
        if (dq->front == dq->rear) {
            dq->front = -1;
            dq->rear = -1;
        }
        // If rear is at the first position, wrap around to the last position
        else if (dq->rear == 0) {
            dq->rear = MAX - 1;
        }
        // Otherwise, decrement rear
        else {
            dq->rear--;
        }

        return ch;
    }

    // Function to check if a given string is a palindrome using a deque
    int isPalindrome(char str[]) {
        struct Deque dq;
        initDeque(&dq);

        int len = strlen(str);

        // Insert each character into the deque
        for (int i = 0; i < len; i++) {
            // Only consider alphanumeric characters and convert to lowercase
            if (isalnum(str[i])) {
                insertRear(&dq, tolower(str[i]));
            }
        }

        // Compare characters from front and rear
        while (dq.front != dq.rear && dq.front != -1) {
            if (deleteFront(&dq) != deleteRear(&dq)) {
                return 0; // Not a palindrome
            }
        }

        return 1; // Palindrome
    }

    // Main function to test the palindrome check
    int main() {
        char str[MAX];

        printf("Enter a string: ");
        fgets(str, MAX, stdin);
        str[strcspn(str, "\n")] = '\0'; // Remove trailing newline character

        if (isPalindrome(str)) {
            printf("\"%s\" is a palindrome.\n", str);
        } else {
            printf("\"%s\" is not a palindrome.\n", str);
        }

        return 0;
    }

/* SAMPLE OUTPUT

Enter a string: Madam, in Eden, I'm Adam
"Madam, in Eden, I'm Adam" is a palindrome.


Enter a string: Hello
"Hello" is not a palindrome.

*/