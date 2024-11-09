/*1. Implement Binary Tree (BT) using iterative function and display the elements of the
BT using recursive in-order, pre-order, post-order traversal methods. */

#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the Binary Tree
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

// Function to insert a node iteratively in the Binary Tree
void insert(struct Node** root, int data) {
    struct Node* newNode = createNode(data);
    if (*root == NULL) {
        *root = newNode;  // If tree is empty, the new node becomes the root
        return;
    }

    struct Node* temp = *root;
    struct Node* parent = NULL;

    // Iteratively find the appropriate place to insert the new node
    while (temp != NULL) {
        parent = temp;
        if (data < temp->data)
            temp = temp->left;  // Go to left subtree
        else
            temp = temp->right; // Go to right subtree
    }

    // Insert the new node at the correct position
    if (data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
}

// In-order Traversal: Left, Root, Right
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);  // Visit the root
        inorderTraversal(root->right);
    }
}

// Pre-order Traversal: Root, Left, Right
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);  // Visit the root
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Post-order Traversal: Left, Right, Root
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);  // Visit the root
    }
}

int main() {
    struct Node* root = NULL;  // Start with an empty tree

    // Inserting nodes into the Binary Tree iteratively
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);

    // Displaying the tree elements using different traversals
    printf("In-order Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Pre-order Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}

/*SAMPLE OUTPUT
In-order Traversal: 20 30 40 50 60 70 80 
Pre-order Traversal: 50 30 20 40 70 60 80 
Post-order Traversal: 20 40 30 60 80 70 50 
*/