/* Write a menu driven program to do the following using iterative functions:
i. To create a BST for a given set of integer numbers
ii. To delete a given element from BST .
Note: Replace the element to be deleted with the largest element in the LST (Left
Sub Tree) ) when the node to be deleted has both LST (Left Sub Tree) and RST
(Right Sub Tree).
iii. To display the elements using in-order traversal.*/

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the Binary Search Tree
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

// Function to insert a node in a Binary Search Tree (BST) iteratively
struct Node* insertNode(struct Node* root, int data) {
    struct Node* newNode = createNode(data);

    // If the tree is empty, the new node becomes the root
    if (root == NULL) {
        return newNode;
    }

    struct Node* current = root;
    struct Node* parent = NULL;

    // Find the appropriate parent for the new node
    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            current = current->left;  // Move to the left subtree
        } else {
            current = current->right; // Move to the right subtree
        }
    }

    // Insert the new node
    if (data < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    return root;
}

// Function to find the node with the maximum value in a BST
struct Node* findMax(struct Node* root) {
    struct Node* current = root;

    // Keep going to the right to find the largest value
    while (current != NULL && current->right != NULL) {
        current = current->right;
    }

    return current;
}

// Function to delete a node from the BST iteratively
struct Node* deleteNode(struct Node* root, int data) {
    struct Node* parent = NULL;
    struct Node* current = root;

    // Search for the node to delete
    while (current != NULL && current->data != data) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    // If the node was not found
    if (current == NULL) {
        printf("Node with value %d not found.\n", data);
        return root;
    }

    // Case 1: Node has no children (leaf node)
    if (current->left == NULL && current->right == NULL) {
        if (current == root) {
            root = NULL; // If the node is the root
        } else if (parent->left == current) {
            parent->left = NULL; // If the node is the left child of the parent
        } else {
            parent->right = NULL; // If the node is the right child of the parent
        }
        free(current);
    }
    // Case 2: Node has one child
    else if (current->left == NULL || current->right == NULL) {
        struct Node* child = (current->left != NULL) ? current->left : current->right;

        if (current == root) {
            root = child; // If the node is the root
        } else if (parent->left == current) {
            parent->left = child; // If the node is the left child of the parent
        } else {
            parent->right = child; // If the node is the right child of the parent
        }
        free(current);
    }
    // Case 3: Node has two children
    else {
        // Find the maximum value in the left subtree (in-order predecessor)
        struct Node* maxNode = findMax(current->left);

        // Replace the current node's data with the maximum node's data
        current->data = maxNode->data;

        // Delete the maximum node from the left subtree
        root = deleteNode(root, maxNode->data);
    }

    return root;
}

// Function to perform in-order traversal of the BST iteratively
void inorderTraversal(struct Node* root) {
    struct Node* current = root;
    struct Node* stack[100]; // Stack to simulate recursion
    int top = -1;

    // Iterative in-order traversal using stack
    while (current != NULL || top >= 0) {
        while (current != NULL) {
            stack[++top] = current; // Push the current node to the stack
            current = current->left; // Move to the left child
        }

        // Pop the node from the stack and print it
        current = stack[top--];
        printf("%d ", current->data);

        // Move to the right child
        current = current->right;
    }
}

// Main function with menu-driven interface
int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        // Display the menu options
        printf("\nMenu:\n");
        printf("1. Insert a node in the BST\n");
        printf("2. Delete a node from the BST\n");
        printf("3. Display the BST using In-order traversal\n");
        printf("4. Exit\n");

        // Get the user's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                printf("Node with value %d inserted.\n", value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;

            case 3:
                printf("In-order traversal of BST: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 4:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

/*SAMPLE OUTPUT
Menu:
1. Insert a node in the BST
2. Delete a node from the BST
3. Display the BST using In-order traversal
4. Exit
Enter your choice: 1
Enter value to insert: 50
Node with value 50 inserted.

Menu:
1. Insert a node in the BST
2. Delete a node from the BST
3. Display the BST using In-order traversal
4. Exit
Enter your choice: 1
Enter value to insert: 30
Node with value 30 inserted.

Menu:
1. Insert a node in the BST
2. Delete a node from the BST
3. Display the BST using In-order traversal
4. Exit
Enter your choice: 1
Enter value to insert: 70
Node with value 70 inserted.

Menu:
1. Insert a node in the BST
2. Delete a node from the BST
3. Display the BST using In-order traversal
4. Exit
Enter your choice: 3
In-order traversal of BST: 30 50 70 

Menu:
1. Insert a node in the BST
2. Delete a node from the BST
3. Display the BST using In-order traversal
4. Exit
Enter your choice: 2
Enter value to delete: 30

Menu:
1. Insert a node in the BST
2. Delete a node from the BST
3. Display the BST using In-order traversal
4. Exit
Enter your choice: 3
In-order traversal of BST: 50 70
*/