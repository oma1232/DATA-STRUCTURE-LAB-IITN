//Merging Two Circular Linked Lists.

#include <stdio.h>
#include <stdlib.h>

struct cll{
    
    int data;
    struct cll *prev,*next;
} *first = NULL, *second = NULL, *third = NULL;

//creating linked lists.
void create(int n){

    if(first == NULL){
        first = (struct cll *)malloc (sizeof(struct cll));
        first->prev = first;
        first->next = first;
        scanf("%d",&first->data);

    }

    struct cll *last = first, *t;
    
    for(int i=1;i<n;i++){

        t = (struct cll *)malloc(sizeof(struct cll));
        scanf("%d",&t->data);
        t->next = first;
        t->prev = last;
        
        last->next = t;
        last = t;
        first->prev = last;
    }
}

void create_2(int m){

    if(second == NULL){
        second = (struct cll *)malloc (sizeof(struct cll));
        second->prev = second;
        second->next = second;
        scanf("%d",&second->data);

    }

    struct cll *last = second, *t;
    
    for(int i=1;i<m;i++){
        t = (struct cll *) malloc(sizeof(struct cll));
        scanf("%d",&t->data);
        t->next = second;
        t->prev = last;
        
        last->next = t;
        last = t;
        second->prev = last;
    }
}

//display function to display list.
void Display(struct cll *p){

    struct cll *q = p;
    printf("%d ",q->data);
    q = q->next;

    while(q!=p){
        printf("%d ",q->data);
        q = q->next;
    }
}

//merging linked lists (work for sorted only).
void merge(struct cll *p, struct cll *q){

    if(first == NULL && second == NULL) return; //suppose if no linked list exist.

    //what if only 1 linked list is there then just point third to the respective head and end the function.
    if(first == NULL){
        third = first;
        return;  
    }
    else if(second == NULL){
        third = second;
        return;
    }
    
    //No firstly break the circular linked lists and convert them in doubly thrn merge them.
    p = first, q = second;

    p->prev->next = NULL;
    p->prev = NULL;

    q->prev->next = NULL;
    q->prev = NULL;
    
     
    //storing the node information for linking next node.
     struct cll *temp;                
     
     //now get the smallest value between first and second node and store in third node (first node of merged linked list).
     if(first->data < second->data){
            third = first; 
            temp = third;
            p = p->next;   //move to next because we have done the comparison between them.
     }
     else{
        third = second;
        temp = third;
        q = q->next;    //if first is not smaller then store the second and move to next node.
     }
     
    //run loop if value is smaller link it and then move to the next node.
    while(p!= NULL && q != NULL){

        if(p->data < q->data){
            temp->next = p;
            p->prev = temp;
            temp = p;
            p = p->next;
        
        }
        else{

            temp->next = q;
            q->prev = temp;
            temp = q;
            q = q->next;
    
        }
    }

    //if linked list are not fully traversed then add remaining elements as lists are sorted,we are adding them till the last element of list.
    while(p != NULL){
        temp->next = p;
        p->prev = temp;
        temp = p;
        p = p->next;
    }

    while(q != NULL){
        temp->next = q;
        q->prev = temp;
        temp = q;
        q = q->next;
      
    }

    // now link the last remaining element with head of merged linked list to make it circular.
    temp->next = third;
    third->prev = temp;
}

int main(){

    int n;
    printf("Enter size of 1st List: ");
    scanf("%d",&n);
    
    printf("Enter elements: ");
    create(n);
    
    int m;
    printf("\nEnter size of 2nd List:");
    scanf("%d",&m);

    printf("Enter elements: ");
    create_2(m);

    printf("\n1st List: ");
    Display(first);

    printf("\n2nd List: ");
    Display(second);

    
    merge(first,second);
    printf("\nLinked List after Merging: ");
    Display(third);

    return 0;
}
