#include <stdio.h>
#include <stdlib.h>

struct node {

    int data;
    struct node *next;
} *first = NULL;  //head node.
 
void create(int A[],int n){

    struct node *last, *t;
    first = (struct node*) malloc (sizeof(struct node));

    first->next = NULL;
    first->data = A[0];
    last = first;     //point a pointer to head then store the address of new node t inside first.
    
    for(int i=1;i<n;i++){

        t = (struct node*) malloc (sizeof(struct node));
        t->data = A[i];
        t->next = NULL;  //make next to null
        last->next = t;   //now store address in its previous node
        last = t;    //point previous node to current node
    }
}

void Display(struct node *p){

    while(p!=NULL){
        printf("%d ",p->data);
        p = p->next;
    }
}

// for finding length of linked list.
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
    p = first;   //make 2 pointers and a temp for deleting the node
    q = first->next;
    
    if(first == NULL) return;   //case only if linked list is not created.
    while(q!=NULL){
        if(p->data != q->data){   //if we didn't found any value duplicate then keep moving.
            p = q;
            q = q->next;
        }

        else{    //delete that q node.
            p->next = q->next; 
            t = q;
            p = q;
            q = q->next;
            free(t);

        }
    }
}
 
void reverse_linked_list(struct node *p){
    struct node *q = NULL, *r = NULL;  //we move 3 pointers p,q,r to reverse the linked list.

    if(p==NULL) return;
      //move pointers consecutively.
    while(p!=NULL){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;    //now point first(head) to q.
}   

      
int main(){
    
    int n;
    printf("Enter size of linked list: ");
    scanf("%d" ,&n);

    int A[n];

    printf("Enter the elements of linked list:\n");
    for(int i=0;i<n;i++) scanf("%d",&A[i]);

    //creating linked list.
    create(A,n);
    Display(first);
    //find length of linked list
    printf("\nLength of Linked list is: %d",len(first));
    
    //deleting duplicates from linked list..
    delete_duplicates();

    printf("\nLinked List after deleting duplicates: ");
    Display(first);

    printf("\nReversing the linked list: ");
    reverse_linked_list(first);
    Display(first);

    return 0;
}
