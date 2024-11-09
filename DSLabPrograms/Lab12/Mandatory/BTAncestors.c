/* Given a Binary Tree and a key, write a function that prints all the ancestors of the
key in the given binary tree.*/
#include <stdio.h>
#include <stdlib.h>

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

// Function to find and print all ancestors of a given key in the binary tree
// It returns true if the key is found, otherwise false.
int printAncestors(struct Node* root, int key) {
    // Base case: if the tree is empty, return false
    if (root == NULL) {
        return 0;
    }

    // If the current node is the key, return true
    if (root->data == key) {
        return 1;
    }

    // If the key is found in the left or right subtree, print the current node
    if (printAncestors(root->left, key) || printAncestors(root->right, key)) {
        printf("%d ", root->data);
        return 1; // Return true to indicate that the key is found
    }

    // If the key is not found in either subtree, return false
    return 0;
}

// Function to perform a pre-order traversal of the binary tree
void preorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data); // Print current node
    preorderTraversal(root->left); // Traverse the left subtree
    preorderTraversal(root->right); // Traverse the right subtree
}

// Main function to demonstrate the ancestors function
int main() {
    // Constructing a binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    int key;

    // Menu-driven program to demonstrate the functionality
    while (1) {
        printf("\nMenu:\n");
        printf("1. Print Ancestors of a given key\n");
        printf("2. Display the tree using Pre-order traversal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &key);

        if (key == 1) {
            printf("Enter the key to find its ancestors: ");
            scanf("%d", &key);

            // Call the function to print ancestors
            printf("Ancestors of node %d: ", key);
            if (!printAncestors(root, key)) {
                printf("No ancestors found or key not present in the tree.");
            }
            printf("\n");
        } 
        else if (key == 2) {
            // Call the function to perform pre-order traversal
            printf("Pre-order Traversal of the Tree: ");
            preorderTraversal(root);
            printf("\n");
        } 
        else if (key == 3) {
            // Exit the program
            printf("Exiting the program.\n");
            break;
        } 
        else {
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

/* SAMPLE OUTPUT 
Menu:
1. Print Ancestors of a given key
2. Display the tree using Pre-order traversal
3. Exit
Enter your choice: 1
Enter the key to find its ancestors: 4
Ancestors of node 4: 2 1 

Menu:
1. Print Ancestors of a given key
2. Display the tree using Pre-order traversal
3. Exit
Enter your choice: 2
Pre-order Traversal of the Tree: 1 2 4 5 3 6 7 

Menu:
1. Print Ancestors of a given key
2. Display the tree using Pre-order traversal
3. Exit
Enter your choice: 1
Enter the key to find its ancestors: 7
Ancestors of node 7: 3 1
*/