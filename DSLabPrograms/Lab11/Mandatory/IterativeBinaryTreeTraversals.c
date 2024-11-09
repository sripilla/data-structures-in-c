/* Display the elements of Binary Tree created using iterative preorder, post-order
(Use single stack), in-order and level-order traversals.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Function to insert a node in the Binary Tree iteratively
void insert(struct Node** root, int data) {
    struct Node* newNode = createNode(data);
    if (*root == NULL) {
        *root = newNode;  // If the tree is empty, set the new node as the root
        return;
    }

    struct Node* temp = *root;
    struct Node* parent = NULL;

    // Iteratively find the correct position to insert the new node
    while (temp != NULL) {
        parent = temp;
        if (data < temp->data)
            temp = temp->left;  // Move to the left child
        else
            temp = temp->right; // Move to the right child
    }

    // Insert the new node at the correct position
    if (data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
}

// In-order Traversal (Recursive): Left, Root, Right
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Iterative Pre-order Traversal: Root, Left, Right (using a single stack)
void iterativePreOrder(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* stack[100];  // Stack for storing nodes
    int top = -1;

    // Push root node to the stack
    stack[++top] = root;

    // Loop until the stack is empty
    while (top >= 0) {
        struct Node* currentNode = stack[top--];
        printf("%d ", currentNode->data);

        // Push right child first, so left child is processed first
        if (currentNode->right != NULL)
            stack[++top] = currentNode->right;
        if (currentNode->left != NULL)
            stack[++top] = currentNode->left;
    }
}

// Iterative Post-order Traversal: Left, Right, Root (using a single stack)
void iterativePostOrder(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* stack[100];  // Stack for storing nodes
    int top = -1;
    struct Node* lastVisited = NULL;
    struct Node* currentNode = root;

    // Loop until the stack is empty or the current node is not NULL
    while (top >= 0 || currentNode != NULL) {
        // Traverse the left subtree
        if (currentNode != NULL) {
            stack[++top] = currentNode;
            currentNode = currentNode->left;
        } else {
            // Peek the node from the stack
            struct Node* peekNode = stack[top];
            // If the right subtree is not visited or NULL
            if (peekNode->right != NULL && lastVisited != peekNode->right) {
                currentNode = peekNode->right;  // Move to the right child
            } else {
                // Visit the node
                printf("%d ", peekNode->data);
                lastVisited = stack[top--];  // Pop the node from the stack
            }
        }
    }
}

// Level-order Traversal (using a queue)
void levelOrderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* queue[100];  // Queue for storing nodes
    int front = 0, rear = 0;

    // Enqueue the root node
    queue[rear++] = root;

    // Process the queue until it's empty
    while (front < rear) {
        struct Node* currentNode = queue[front++];  // Dequeue a node
        printf("%d ", currentNode->data);

        // Enqueue left and right children if they exist
        if (currentNode->left != NULL)
            queue[rear++] = currentNode->left;
        if (currentNode->right != NULL)
            queue[rear++] = currentNode->right;
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

    printf("Iterative Pre-order Traversal: ");
    iterativePreOrder(root);
    printf("\n");

    printf("Iterative Post-order Traversal: ");
    iterativePostOrder(root);
    printf("\n");

    printf("Level-order Traversal: ");
    levelOrderTraversal(root);
    printf("\n");

    return 0;
}

/*SAMPLE OUTPUT
In-order Traversal: 20 30 40 50 60 70 80 
Iterative Pre-order Traversal: 50 30 20 40 70 60 80 
Iterative Post-order Traversal: 20 40 30 60 80 70 50 
Level-order Traversal: 50 30 70 20 40 60 80 
*/