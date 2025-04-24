#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node..
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node..
struct Node* createNode(int value) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;

}

// Insert a node into the BST..
struct Node* insert(struct Node* root, int value) {

    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;

}

// Search for a value in BST..
struct Node* search(struct Node* root, int key) {

    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);

}

// Find the node with the minimum value..
struct Node* findMin(struct Node* root) {

    while (root->left != NULL)
        root = root->left;
    return root;

}

// Delete a node from BST..
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with one or no child..
        if (root->left == NULL) {

            struct Node* temp = root->right;
            free(root);
            return temp;

        }
        else if (root->right == NULL) {

            struct Node* temp = root->left;
            free(root);
            return temp;

        }

        // Node with two children..
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);

    }
    return root;
}

// Inorder traversal (for verification)..
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Main to test..
int main() {
    struct Node* root = NULL;

    // Insert values..
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder Traversal Of BST: ");
    inorder(root);
    printf("\n");

    // Search for a value..
    int key;
    printf("\nEnter key value to find: ");
    scanf("%d",&key);

    if (search(root, key))
        printf("Found %d.\n", key);
    else
        printf("%d Not found.\n", key);

    // Delete a node..
    root = deleteNode(root, 70);
    root = deleteNode(root,50);
    root = deleteNode(root,30);

    printf("Inorder after deleting 70 50 30: ");
    inorder(root);

    printf("\n");
    return 0;
}
