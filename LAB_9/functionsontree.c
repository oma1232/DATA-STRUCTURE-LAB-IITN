#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left,*right;
}*rootNode = NULL;

//creation of binary tree
struct node *create(){

    int data;
    scanf("%d",&data);

    if(data == -1) return NULL;

    struct node *root = (struct node *)malloc(sizeof(struct node));

    if(rootNode == NULL){
        rootNode = root;
    }

        root->left = NULL;
        root->right = NULL;
        root->data = data;
    
        printf("Enter left child of %d: ",data);
        root->left = create();
        printf("Enter right child %d: ",data);
        root->right = create();

        return root;
}

//count the number of total nodes.
int countNodes(struct node* root) {
    
    if (root == NULL) return 0;

    return 1 + (countNodes(root->left) + countNodes(root->right));
}

// count the number of leaf nodes only.
int count_Leaf_Nodes(struct node* root) {
    if (root == NULL) return 0;

    if (root->left == NULL && root->right == NULL)  return 1;

    return count_Leaf_Nodes(root->left) + count_Leaf_Nodes(root->right);
}

//find the height of the tree.
int height_of_the_tree(struct node* root) {
    if (root == NULL)
        return 0;
    int leftHeight = height_of_the_tree(root->left);
    int rightHeight = height_of_the_tree(root->right);
    
    if(leftHeight > rightHeight){
        return 1 + leftHeight;
    }
    else{
        return 1 + rightHeight;
    }

}


int main(){

    printf("Enter the root node: ");
    create();

    printf("\n");
    int count = countNodes(rootNode);
    printf("Number of nodes in tree are: %d\n",count);
 
    int leafnode = count_Leaf_Nodes(rootNode);
    int height = height_of_the_tree(rootNode);

    printf("Number of Leaf Nodes: %d\n",leafnode);
    printf("Height of the tree: %d\n",height);

    return 0;
}
