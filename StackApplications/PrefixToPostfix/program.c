#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;

void push(char *str);
char* pop();
int isEmpty();
void reverse(char *exp);
void prefixToPostfix(char *prefix);
void printPostfix();

int main() {
    char prefix[MAX];

    printf("Enter the prefix expression: ");
    fgets(prefix, MAX, stdin);

    // Remove newline character if present
    prefix[strcspn(prefix, "\n")] = '\0';

    prefixToPostfix(prefix);
    printPostfix();

    return 0;
}

void push(char *str) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    strcpy(stack[top], str);
}

char* pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

void reverse(char *exp) {
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[len - i - 1];
        exp[len - i - 1] = temp;
    }
}

void prefixToPostfix(char *prefix) {
    reverse(prefix);

    char temp[MAX];

    for (int i = 0; i < strlen(prefix); i++) {
        if (isalnum(prefix[i])) {
            temp[0] = prefix[i];
            temp[1] = '\0';
            push(temp);
        } else if (prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '*' || prefix[i] == '/' || prefix[i] == '^') {
            char operand1[MAX], operand2[MAX];

            strcpy(operand1, pop());
            strcpy(operand2, pop());

            sprintf(temp, "%s%s%c", operand1, operand2, prefix[i]);
            push(temp);
        }
    }
}

void printPostfix() {
    printf("The equivalent postfix expression is: %s\n", pop());
}
