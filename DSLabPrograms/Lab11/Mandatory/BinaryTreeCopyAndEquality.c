/* Implement recursive functions to do the following:
a) To create a copy of a BT.
b) Testing for equality of two BTs.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for a node in the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to recursively create a copy of a binary tree
struct Node* copyTree(struct Node* root) {
    // Base case: If the tree is empty, return NULL
    if (root == NULL) {
        return NULL;
    }

    // Create a new node with the same data as the root of the current tree
    struct Node* newNode = createNode(root->data);

    // Recursively copy the left and right subtrees
    newNode->left = copyTree(root->left);
    newNode->right = copyTree(root->right);

    return newNode;
}

// Function to recursively check if two binary trees are equal
bool areTreesEqual(struct Node* root1, struct Node* root2) {
    // If both trees are empty, they are equal
    if (root1 == NULL && root2 == NULL) {
        return true;
    }

    // If one of the trees is empty and the other is not, they are not equal
    if (root1 == NULL || root2 == NULL) {
        return false;
    }

    // Check if the data of the roots is the same and recursively check the left and right subtrees
    return (root1->data == root2->data) &&
           areTreesEqual(root1->left, root2->left) &&
           areTreesEqual(root1->right, root2->right);
}

// Function to perform an in-order traversal and display the tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    // Create a sample binary tree
    struct Node* root1 = createNode(10);
    root1->left = createNode(20);
    root1->right = createNode(30);
    root1->left->left = createNode(40);
    root1->left->right = createNode(50);

    // Create a copy of the tree
    struct Node* root2 = copyTree(root1);

    // Check if the original tree and the copied tree are equal
    if (areTreesEqual(root1, root2)) {
        printf("The two binary trees are equal.\n");
    } else {
        printf("The two binary trees are not equal.\n");
    }

    // Display both trees using in-order traversal
    printf("In-order traversal of the original tree: ");
    inorderTraversal(root1);
    printf("\n");

    printf("In-order traversal of the copied tree: ");
    inorderTraversal(root2);
    printf("\n");

    return 0;
}

/* SAMPLE OUTPUT
The two binary trees are equal.
In-order traversal of the original tree: 40 20 50 10 30 
In-order traversal of the copied tree: 40 20 50 10 30 
*/