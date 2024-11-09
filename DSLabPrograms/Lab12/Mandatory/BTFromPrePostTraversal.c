/* Write a program to construct a BT for given pre-order and the post- order traversal
sequences.*/
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node of the Binary Tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with a given value
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to find the index of a value in an array (used for post-order)
int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

// Function to construct the Binary Tree from given pre-order and post-order sequences
struct Node* constructTree(int pre[], int post[], int* preIndex, int postStart, int postEnd, int size) {
    // Base case: if the indices are out of bounds
    if (*preIndex >= size || postStart > postEnd) {
        return NULL;
    }

    // Create the root node using the current pre-order element
    struct Node* root = createNode(pre[*preIndex]);
    (*preIndex)++; // Increment the pre-order index

    // If this node has no children (i.e., it's a leaf node), return the node
    if (postStart == postEnd) {
        return root;
    }

    // Find the index of the left child in post-order traversal
    int leftChild = pre[*preIndex];
    int postIndex = search(post, postStart, postEnd, leftChild);

    // If the left child exists, recursively construct the left subtree
    if (postIndex != -1) {
        root->left = constructTree(pre, post, preIndex, postStart, postIndex, size);
        root->right = constructTree(pre, post, preIndex, postIndex + 1, postEnd - 1, size);
    }

    return root;
}

// Function to perform in-order traversal of the Binary Tree
void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);  // Traverse left subtree
    printf("%d ", root->data);      // Print current node
    inorderTraversal(root->right); // Traverse right subtree
}

// Main function to drive the program
int main() {
    // Sample pre-order and post-order sequences (you can change these values)
    int pre[] = {1, 2, 4, 5, 3, 6};
    int post[] = {4, 5, 2, 6, 3, 1};
    int size = sizeof(pre) / sizeof(pre[0]);

    int preIndex = 0; // Initialize the pre-order index to 0

    // Construct the Binary Tree using the given pre-order and post-order traversals
    struct Node* root = constructTree(pre, post, &preIndex, 0, size - 1, size);

    // Display the in-order traversal of the constructed Binary Tree
    printf("In-order Traversal of the Constructed Binary Tree: ");
    inorderTraversal(root);  // Display in-order traversal
    printf("\n");

    return 0;
}


/* SAMPLE OUTPUT
In-order Traversal of the Constructed Binary Tree: 4 2 5 1 6 3

*/