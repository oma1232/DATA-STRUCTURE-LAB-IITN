#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Find index of value in inorder array
int findIndex(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++)
        if (arr[i] == value)
            return i;
    return -1;
}

// Build tree using preorder and inorder
struct Node* buildTree(int inorder[], int preorder[], int start, int end, int* preIndex) {
    if (start > end) return NULL;

    int curr = preorder[*preIndex];
    (*preIndex)++;
    struct Node* root = newNode(curr);

    if (start == end) return root;

    int mid = findIndex(inorder, start, end, curr);

    root->left = buildTree(inorder, preorder, start, mid - 1, preIndex);
    root->right = buildTree(inorder, preorder, mid + 1, end, preIndex);

    return root;
}

// Print inorder traversal..
void postorder(struct Node* root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);

}

int main() {
    int inorder[] = {4, 2, 5, 1, 3};
    int preorder[] = {1, 2, 4, 5, 3};
    int n = sizeof(inorder)/sizeof(int);
    int preIndex = 0;

    struct Node* root = buildTree(inorder, preorder, 0, n - 1, &preIndex);

    printf("Given Preorder: ");
    for(int i=0;i<n;i++) printf("%d ",preorder[i]);
    printf("\n");

    printf("Given Inorder: ");
    for(int i=0;i<n;i++) printf("%d ",inorder[i]);

    printf("\n");
    printf("Post order traversal of constructed tree: ");

    postorder(root);
    printf("\n");

    return 0;
}
