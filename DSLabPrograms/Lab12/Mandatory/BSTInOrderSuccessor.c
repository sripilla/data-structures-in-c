/*Given a BST, write a function to find the in - order successor of a node. */

#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the Binary Search Tree
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

// Function to insert a node in the BST iteratively
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

// Function to find the node with the minimum value in the BST
struct Node* findMin(struct Node* root) {
    struct Node* current = root;

    // Keep going to the left to find the smallest value
    while (current != NULL && current->left != NULL) {
        current = current->left;
    }

    return current;
}

// Function to find the in-order successor of a given node
struct Node* findInOrderSuccessor(struct Node* root, struct Node* node) {
    // If the node has a right subtree, the successor is the minimum value node in the right subtree
    if (node->right != NULL) {
        return findMin(node->right);
    }

    // If the node doesn't have a right subtree, start from the root and search for the successor
    struct Node* successor = NULL;
    struct Node* current = root;

    // Traverse the tree to find the successor
    while (current != NULL) {
        if (node->data < current->data) {
            successor = current;  // This node could be a potential successor
            current = current->left;  // Move to the left subtree
        } else if (node->data > current->data) {
            current = current->right;  // Move to the right subtree
        } else {
            break;  // Node found, stop searching
        }
    }

    return successor;
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

// Main function to demonstrate the in-order successor functionality
int main() {
    struct Node* root = NULL;
    struct Node* node = NULL;
    int choice, value;

    // Menu-driven program to build and manipulate the BST
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a node in the BST\n");
        printf("2. Find the In-order Successor of a given node\n");
        printf("3. Display the BST using In-order traversal\n");
        printf("4. Exit\n");
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
                printf("Enter value to find its In-order Successor: ");
                scanf("%d", &value);

                // Search for the node with the given value
                node = root;
                while (node != NULL && node->data != value) {
                    if (value < node->data) {
                        node = node->left;
                    } else {
                        node = node->right;
                    }
                }

                // If the node is found, find its in-order successor
                if (node != NULL) {
                    struct Node* successor = findInOrderSuccessor(root, node);
                    if (successor != NULL) {
                        printf("The in-order successor of node with value %d is %d\n", value, successor->data);
                    } else {
                        printf("The node with value %d has no in-order successor.\n", value);
                    }
                } else {
                    printf("Node with value %d not found.\n", value);
                }
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

/* SAMPLE OUTPUT
Menu:
1. Insert a node in the BST
2. Find the In-order Successor of a given node
3. Display the BST using In-order traversal
4. Exit
Enter your choice: 1
Enter value to insert: 50
Node with value 50 inserted.

Menu:
1. Insert a node in the BST
2. Find the In-order Successor of a given node
3. Display the BST using In-order traversal
4. Exit
Enter your choice: 1
Enter value to insert: 30
Node with value 30 inserted.

Menu:
1. Insert a node in the BST
2. Find the In-order Successor of a given node
3. Display the BST using In-order traversal
4. Exit
Enter your choice: 1
Enter value to insert: 70
Node with value 70 inserted.

Menu:
1. Insert a node in the BST
2. Find the In-order Successor of a given node
3. Display the BST using In-order traversal
4. Exit
Enter your choice: 2
Enter value to find its In-order Successor: 30
The in-order successor of node with value 30 is 50

Menu:
1. Insert a node in the BST
2. Find the In-order Successor of a given node
3. Display the BST using In-order traversal
4. Exit
Enter your choice: 3
In-order traversal of BST: 30 50 70
*/