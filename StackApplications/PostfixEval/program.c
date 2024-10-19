#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
char infix[MAX], postfix[MAX];
int top = -1;

// Function prototypes
void push(int);
int pop();
int isEmpty();
int isFull();
void inToPost();
int space(char);
void printPostfix();
int precedence(char);
int power(int, int);
int post_eval();

int main()
{
    int result;
    printf("Enter the infix expression: ");
    fgets(infix, MAX, stdin); // Use fgets to avoid buffer overflow
    // Remove trailing newline if it exists
    infix[strcspn(infix, "\n")] = '\0'; 

    inToPost();
    result = post_eval();
    printPostfix();
    printf("Result obtained after postfix evaluation is: %d\n", result);
    return 0;
}

// Convert infix expression to postfix expression
void inToPost()
{
    int i, j = 0;
    char next;
    char symbol;

    for(i = 0; i < strlen(infix); i++) {
        symbol = infix[i];
        if(!space(symbol)) {
            switch(symbol) {
                case '(':
                    push(symbol);
                    break;
                case ')':
                    while(!isEmpty() && (next = pop()) != '(') {
                        postfix[j++] = next;
                    }
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                    while(!isEmpty() && precedence(stack[top]) >= precedence(symbol)) {
                        postfix[j++] = pop();
                    }
                    push(symbol);
                    break;
                default:
                    if(isdigit(symbol)) {
                        postfix[j++] = symbol;
                    }
                    break;
            }
        }
    }
    while(!isEmpty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

// Check if the character is a space or tab
int space(char c)
{
    return (c == ' ' || c == '\t');
}

// Determine the precedence of operators
int precedence(char symbol)
{
    switch(symbol) {
        case '^':
            return 3;
        case '/':
        case '*':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

// Print the postfix expression
void printPostfix()
{
    int i = 0;
    printf("The equivalent postfix expression is: ");
    while(postfix[i]) {
        printf("%c", postfix[i++]);
    }
    printf("\n");
}

// Push value onto the stack
void push(int val)
{
    if(top == MAX - 1) {
        printf("Stack Overflow.\n");
        exit(1);
    }
    top++;
    stack[top] = val;
}

// Pop value from the stack
int pop()
{
    if(top == -1) {
        printf("Stack Underflow.\n");
        exit(1);
    }
    return stack[top--];
}

// Check if the stack is empty
int isEmpty()
{
    return top == -1;
}

// Calculate power of a number
int power(int a, int b)
{
    int result = 1;
    for(int i = 0; i < b; i++) {
        result *= a;
    }
    return result;
}

// Evaluate the postfix expression
int post_eval()
{
    int i;
    int a, b;

    for(i = 0; i < strlen(postfix); i++) {
        if(isdigit(postfix[i])) {
            push(postfix[i] - '0'); // Convert char digit to int
        } else {
            a = pop();
            b = pop();
            switch(postfix[i]) {
                case '+':
                    push(b + a);
                    break;
                case '-':
                    push(b - a);
                    break;
                case '*':
                    push(b * a);
                    break;
                case '/':
                    push(b / a);
                    break;
                case '^':
                    push(power(b, a));
                    break;
            }
        }
    }
    return pop();
}
