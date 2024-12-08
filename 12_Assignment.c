#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the AVL tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

// Function to get the height of a node
int height(struct Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to calculate the balance factor of a node
int getBalanceFactor(struct Node* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1; // New node is initially added at height 1
    return newNode;
}

// Right rotate function
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));

    return x;
}

// Left rotate function
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));

    return y;
}

// Function to insert a node into the AVL tree
struct Node* insertNode(struct Node* node, int data) {
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insertNode(node->left, data);
    else if (data > node->data)
        node->right = insertNode(node->right, data);
    else // Duplicate data is not allowed in AVL tree
        return node;

    // Update height of the current node
    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));

    // Get the balance factor to check whether the node is unbalanced
    int balance = getBalanceFactor(node);

    // If the node is unbalanced, perform rotations

    // Left-Left Case
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Right-Right Case
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Left-Right Case
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right-Left Case
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Inorder traversal function
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Main function
int main() {
    struct Node* root = NULL;
    int choice, data;

    printf("AVL Tree Program\n");
    do {
        printf("\nMenu:\n");
        printf("1. Insert Node\n");
        printf("2. Inorder Traversal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
