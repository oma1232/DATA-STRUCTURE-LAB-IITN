#include <stdio.h>
#include <stdlib.h>


struct node{

    int data;
    struct node *left,*right;
}*rootNode = NULL;

struct node *create(){
    int d;
    scanf("%d",&d);
    
    if(d == -1) return NULL;

    struct node *root = (struct node *)malloc(sizeof(struct node));

    if(rootNode == NULL){
        rootNode = root;
    }

        root->left = NULL;
        root->right = NULL;
        root->data = d;
    
        printf("Enter left child: ");
        root->left = create();
        printf("Enter right child: ");
        root->right = create();

        return root;
}

void preorder(struct node *root){

    if(root == NULL) return;
    else{

        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node* root){

    if(root ==  NULL) return;
    else{

        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void postorder(struct node* root){

    if(root == NULL) return;
    else{

        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

int main(){
    
    printf("Enter root node: ");
    create();
    preorder(rootNode);
    
    printf("\n");
    inorder(rootNode);
    printf("\n");
    postorder(rootNode);
    printf("\n");

    return 0;
}
