/* Create an expression tree for the given postfix expression and evaluate it.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Structure for a tree node
struct Node {
    char data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to evaluate the expression tree
int evaluateTree(struct Node* root) {
    // If the node is a leaf (operand), return its integer value
    if (root == NULL)
        return 0;

    if (!isOperator(root->data))
        return root->data - '0'; // Convert character to integer

    // Otherwise, evaluate the left and right subtrees and apply the operator
    int leftValue = evaluateTree(root->left);
    int rightValue = evaluateTree(root->right);

    // Apply the operator to the left and right subtree results
    switch (root->data) {
        case '+': return leftValue + rightValue;
        case '-': return leftValue - rightValue;
        case '*': return leftValue * rightValue;
        case '/': return leftValue / rightValue;
    }
    return 0;
}

// Function to create an expression tree from postfix expression
struct Node* constructTree(char postfix[]) {
    struct Node* stack[100];  // Stack to store nodes
    int top = -1;

    // Process each character in the postfix expression
    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        // If the character is an operand, create a node and push it to the stack
        if (!isOperator(c)) {
            stack[++top] = createNode(c);
        }
        else {
            // If the character is an operator, pop two nodes from the stack
            struct Node* right = stack[top--];
            struct Node* left = stack[top--];

            // Create a new node for the operator and set the two nodes as its children
            struct Node* newNode = createNode(c);
            newNode->left = left;
            newNode->right = right;

            // Push the new node back to the stack
            stack[++top] = newNode;
        }
    }

    // The remaining node in the stack is the root of the expression tree
    return stack[top];
}

// Function to print the tree (in-order traversal) for visualization
void inorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    printf("%c ", root->data);
    inorderTraversal(root->right);
}

int main() {
    char postfix[] = "23*45*+";

    // Construct the expression tree from the postfix expression
    struct Node* root = constructTree(postfix);

    // Print the expression tree using in-order traversal
    printf("In-order Traversal of Expression Tree: ");
    inorderTraversal(root);
    printf("\n");

    // Evaluate the expression tree
    int result = evaluateTree(root);
    printf("Result of the expression evaluation: %d\n", result);

    return 0;
}

/*In-order Traversal of Expression Tree: 2 * 3 + 4 * 5 
Result of the expression evaluation: 26
 */