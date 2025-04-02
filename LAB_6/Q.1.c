// Doubly Linked List --> creation/ forward and reverse traversing/ insertion and deletion of node.

#include <stdio.h>
#include <stdlib.h>

struct dll{

    int data;
    struct dll *prev, *next;
} *first = NULL ,*last =  NULL; //first >> head and last >> tail.


// create doubly linked list,,
void create(int n){

    first = (struct dll *) malloc(sizeof(struct dll));

    first->prev = NULL;

    scanf("%d",&first->data);
    
    first->next = NULL;
     
    struct dll *t;  // t >>  new node.
     
    last = first;
    
    for(int i=1;i<n;i++){

      t = (struct dll *) malloc(sizeof(struct dll));

      scanf("%d",&t->data);
      
      t->prev = NULL;
      t->next = NULL;

      t->prev = last;
      last->next = t;
      last = t;
    }

}

//finding length of Doubly Linked List..
int len(struct dll *p){

    int count=0;
    while(p!=NULL){
        count++;
        p = p->next;
    }

    return count;
}

//forward traverse using head pointer ->> *first..
void Display(struct dll *p){

    p = first;
    while(p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
}

// reverse traverse using tail pointer ->> *last... 
void Reverse_Display(struct dll *q){

    q = last;
    while(q !=NULL){
        printf("%d ",q->data);
        q = q->prev;
    }
}

//Insertion...
void insert(int index,int x,int n){
    
    struct dll *new = (struct dll *) malloc(sizeof(struct dll));
    
    if(index < 0 || index > n-1) return; //if inserting position is out of bounds.

    new->data = x;
    
    //if doubly linked list is empty. make first node
    if(first == NULL){
        new->prev = NULL;
        new->next = NULL;
        first = new;
    }
    else{
        
        // inserting at beginning.
        if(index == 0){
           
            new->prev = NULL;
            new->next = first;
            first->prev = new;
            first = new;
        }
        //at end.
        else if(index == n-1){

            last->next = new;
            new->prev = last;
            new->next = NULL;
            last = new;
        
        }
        else{
             
            struct dll *t = first; //Moving from first to the inserting position.
            
            for(int i=1;i<index-1;i++){
                   t = t->next;
            }
              new->next = t->next;      //Inserting node.
              t->next->prev = new;
              new->prev = t;
              t->next = new;

        }
    }
}

//Deletion..
void Delete(int index,int n){

    struct dll *del = first, *q = NULL;
    
    if(index < 0 || index >= n) return;
    
    //deleting first node..
    if(index == 0){
       del = first;
       first = first->next;
       first->prev = NULL;
       
       free(del);

    }
    else if(index == n-1){

        del = last;
        last = last->prev;
        last->next = NULL;

        free(del);
    }
    else{
        
        //Reach the specified position and delete the node.
        for(int i = 0;i<index;i++){
            q = del;
            del = del->next;
        }
        
        del->next->prev = q;
        q->next = del->next;

        free(del);
    }

}


int main(){
   
    int n;
    printf("Size of doubly linked list: ");
    scanf("%d",&n);

    printf("Enter the elements:\n");
    create(n);
    
    printf("\ndoubly linked list: ");
    Display(first);
    
    printf("\nReverse doubly linked list: ");
    Reverse_Display(last);
     

    //-------- Insertion of element in dll ---------
    int index;
    printf("\nEnter node index for inserting: ");
    scanf("%d",&index);

    int x;
    printf("\nEnter data: ");
    scanf("%d",&x);

    insert(index,x,len(first));
    printf("List after insertion: \n");
    Display(first);
    
    // ---------- Deletion of node in dll ----------
    int del_index;
    printf("\nEnter Index of Node You Want to Delete: ");
    scanf("%d",&del_index);

    Delete(del_index,len(first));

    printf("List After Deletion: ");
    Display(first);
    return 0;
}
