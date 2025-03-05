#include <stdio.h>
#include <stdlib.h>

struct node {

    int data;
    struct node *next;
} *first = NULL;  
 
void create(int A[],int n){

    struct node *last, *t;
    first = (struct node*) malloc (sizeof(struct node));

    first->next = NULL;
    first->data = A[0];
    last = first;     
    
    for(int i=1;i<n;i++){

        t = (struct node*) malloc (sizeof(struct node));
        t->data = A[i];
        t->next = NULL; 
        last->next = t;  
        last = t;   
    }
}

void Display(struct node *p){

    while(p!=NULL){
        printf("%d ",p->data);
        p = p->next;
    }
}

//  finding length of linked list.
int len(struct node *p){
    int c=0;
    while(p!=NULL){
        c++;
        p = p->next;
    }

    return c;
}

void delete_duplicates(){

    struct node *p,*q, *t;
    p = first;   
    q = first->next;
    
    if(first == NULL) return;   
    while(q!=NULL){
        if(p->data != q->data){  
            p = q;
            q = q->next;
        }

        else{    
            p->next = q->next; 
            t = q;
            p = q;
            q = q->next;
            free(t);

        }
    }
}
 
void reverse_linked_list(struct node *p){
    struct node *q = NULL, *r = NULL;  

    if(p==NULL) return;
      
    while(p!=NULL){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;   
}   

      
int main(){
    
    int n;
    printf("Enter size of linked list: ");
    scanf("%d" ,&n);

    int A[n];

    printf("Enter the elements of linked list:\n");
    for(int i=0;i<n;i++) scanf("%d",&A[i]);

   
    create(A,n);
    Display(first);
    
    printf("\nLength of Linked list is: %d",len(first));
    
    
    delete_duplicates();

    printf("\nLinked List after deleting duplicates: ");
    Display(first);

    printf("\nReversing the linked list: ");
    reverse_linked_list(first);
    Display(first);

    return 0;
}
