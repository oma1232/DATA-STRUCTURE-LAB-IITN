// Circular Linked List --> Creation/ Insertion/ Deletion.
//Create Circular Linked List(CLL) using Singly Linked List(SLL).
#include <stdio.h>
#include <stdlib.h>

struct cll{

    int data;
    struct cll *prev, *next;

} *first = NULL;

//for implementing the circular linked list using singly linked list.
struct sll{

    int data;
    struct sll* next;
} *second = NULL;


void create(int n){
     
    first = (struct cll *) malloc(sizeof(struct cll));
    
    //create first node and point its prev and next to itself , as it is a circular linked list.
    first->prev = first;
    scanf("%d",&first->data);
    first->next = first;
    
    struct cll *last;
    last = first;
     
    //now run loop and wheneveer we create node we will point next pointer to first node ,making it circular.
    for(int i=1;i<n;i++){
    
     struct cll *new = (struct cll *) malloc(sizeof(struct cll));

     scanf("%d",&new->data);
    
     new->next = first;
     new->prev = last;
     
     last->next = new;
     last = new;

     first->prev = last;
     last->next = first;

    }
}

//displaying the circular linked list.
void Display(struct cll *p){
    
    struct cll *q = p;
    
    //print current node's value and then move pointer to next node and run loop.
    //till we reach the same node again keep printing..
    printf("%d ",q->data);
    q = p->next;
     
    while(q != p){
        printf("%d ",q->data);
        q = q->next;
    }
}

//calculating the length of linked list useful for deletion and insertion of nodes.
int len(struct cll *p){
    
    int count=0;

    if(p == NULL) return 0;

    struct cll *q = p;

    do{
        count++;
        q = q->next;
    }while(q!=p);

    return count;
}

//inserting node's in linked list.
void insert(int index,int x,int n){
    
    if(index <0 || index > n) return; //check for bounds.

    struct cll *node = (struct cll *)malloc(sizeof(struct cll));
    node->data = x;
            
    //insertion at beginning.
    if(index == 0){
        if(first == NULL){
            first = node;
            first->prev = first;
            first->next = first;
        }
        else{
     node->prev = first->prev;
     node->next = first;

     first->prev->next = node;
     first->prev = node;
     first = node;     
    }
}                  //insertion at end,
    else if(index == n-1){
       node->next = first;
       node->prev = first->prev;
       first->prev->next = node;
       first->prev = node;
    }
    else{           //insertion at specific index.    
        struct cll *t = first;
        for(int i=0;i<index;i++){
            t = t->next;
        }
        
        node->next = t;
        node->prev = t->prev;
        t->prev->next = node;
        t->prev = node;
    }
}

//Deleting node in Circular Linked List.
void delete_node(int index,int n){

    if(first == NULL) return; //in case linked list is empty.
    
    if(index <0 || index >= n) return ;
     struct cll *del;

    if(index == 0){
        del = first;

        first->prev->next = del->next;
        del->next->prev = first->prev;
        first = first->next;

        free(del);
    }
    else if(index == n-1){
        // Delete the last node
        del = first->prev;
        if(first->next == first) {  // What if there is only one node in list?
            first = NULL;
        } 
        else {
            del->prev->next = first;
            first->prev = del->prev;
        }
        free(del);
    }
    else{
                //for deleting node from specific index.
        del = first;
        for(int i=0;i<index;i++){
            del = del->next; 
        }
        del->next->prev = del->prev;
        del->prev->next = del->next;

        free(del);
    }
}

// Implementing CLL Using SLL..
    void cll_using_sll(int n){
         
        //if head of singly linked list is NULL then create it first.
        // create two pointers 1 to store previous node address and second for new node creation.
        struct sll *temp, *new_node;
        if(second == NULL){
            second = (struct sll*) malloc(sizeof(struct sll));
            scanf("%d",&second->data);
            second->next = second;

            //point temp to head.
            temp = second;
        }   
            //now insert the other nodes in sll and make cll.
            for(int i=1;i<n;i++){
                new_node = (struct sll *) malloc(sizeof(struct sll));
                new_node->next = NULL;
                scanf("%d",&new_node->data);
                
                temp->next = new_node;
                temp = new_node;
                temp->next = second;
            }

        }

    void Display_cll_using_sll(struct sll* p){

        struct sll *q = p->next;
        // we are moving pointer from next node until we reach the current node.
        //missing the current node's value in loop,, print it before running loop,,

        printf("%d ",p->data);

        while(q !=p ){
            printf("%d ",q->data);
            q = q->next;
        }
    }

int main(){
    
    int n;
    printf("Enter Size of Circular Linked List: ");
    scanf("%d",&n);
    
    printf("Enter elements: ");
    create(n);
    
    n = len(first);

    printf("\nCircular Linked List: ");
    Display(first);
     
    // ----------Insert and Delete operations on linked list-------------
    int index;
    printf("\nIndex value for insertion of node: ");
    scanf("%d",&index);
    
    int insert_value;
    printf("Value: ");
    scanf("%d",&insert_value);

    printf("\nAfter inserting:\n");
    insert(index,insert_value,n);
    Display(first);
    
    int delete;
    printf("\nIndex for deleting the node: ");
    scanf("%d",&delete);

    printf("\n\nAfter Deleting node: ");
    delete_node(delete ,n);
    Display(first);
    

    //----------Now Using Singly Linked List------------
    int m;
    printf("\n\nImplementing Circular Linked List Using Singly Linked List:");
    printf("\n Enter Size: ");
    scanf("%d",&m);
    
    printf("Enter elements:\n");
    cll_using_sll(m);

    printf("\n");
    Display_cll_using_sll(second);
    return 0;
}
