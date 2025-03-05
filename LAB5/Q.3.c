#include <stdio.h>
#include <stdlib.h>

struct node {

    int data;
    struct node *next;
};
 
void create(struct node **p,int n){ //we use double pointer to modify the head which we pass in main func.

    struct node *last, *t;
    *p = (struct node*) malloc (sizeof(struct node));

    (*p)->next = NULL;
    scanf("%d",&(*p)->data);
    last = *p;     //point a pointer to head then store the address of new node t inside first.
    
    for(int i=1;i<n;i++){

        t = (struct node*) malloc (sizeof(struct node));
       scanf("%d",&t->data);
        t->next = NULL;  //make next to null
        last->next = t;   //now store address in its previous node.
        last = t;    //point previous node to current node
    }
}

void Display(struct node *p){

    while(p!=NULL){
        printf("%d ",p->data);
        p = p->next;
    }
}

void odd_elements(struct node *p, struct node **q) {
    struct node *last = NULL;
    
    while (p != NULL) {
        if (p->data % 2 != 0) { // Odd element
            struct node *t = (struct node*) malloc(sizeof(struct node));
            t->data = p->data;
            t->next = NULL;

            if (*q == NULL) { // If second list is empty
                *q = t;
                last = *q;
            } else {
                last->next = t; // Add to the end of the second list
            }

            last = t; // Update last node to the new node
        }
        p = p->next; // Move to the next node
    }
}

//Similarly for even numbers...
void even_elements(struct node *p, struct node **q) {
    struct node *last = NULL;
    
    while (p != NULL) {
        if (p->data % 2 == 0) { 
            struct node *t = (struct node*) malloc(sizeof(struct node));
            t->data = p->data;
            t->next = NULL;

            if (*q == NULL) {
                *q = t;
                last = *q;
            } else {
                last->next = t; 
            }

            last = t; 
        }
        p = p->next; 
    }
}

int main(){
    struct node *first=NULL,*second=NULL,*third = NULL;

    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    
    create(&first,n);
 
    printf("\n");
    printf("Odd Elements:\n");
    odd_elements(first,&second);
    Display(second);
    
    printf("\n");
    printf("Even Elements:\n");
    even_elements(first,&third);
    Display(third);


    return 0;
}
