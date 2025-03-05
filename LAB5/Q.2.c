#include <stdio.h>
#include <stdlib.h>

struct node {

    int data;
    struct node *next;
} *first = NULL, *second = NULL;  //head node.
 
void create(struct node **p,int n){ //double pointer to modify head of linked list..

    struct node *last, *t;
    *p = (struct node*) malloc (sizeof(struct node));

    (*p)->next = NULL;
    scanf("%d",&(*p)->data);
    last = *p;     //point a pointer to head then store the address of new node t inside first.
    
    for(int i=1;i<n;i++){

        t = (struct node*) malloc (sizeof(struct node));
        scanf("%d",&t->data);
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

struct node *merge_linked_lists(struct node *p, struct node *q){
    
    struct node *third,*last; //create a pointer and point it to the lowest element between first two nodes
                              //last pointer to store address of next smallest node.
    if(p->data < q->data){      
        third = last = p;        //start by pointing third and last to the lower element
        p = p->next;               //move first to next node.
        last->next = NULL;         //make it's previous node's address empty.
    }
    else{

        third = last = q;      //if second lists node is smaller then point to second list node.
        q = q->next;           //Move second pointer to next.
        last->next = NULL;     //make last node's next address empty.
    }
    

    //now run loop until both lists are empty.
    while( p!= NULL && q!= NULL){
       if(p->data < q->data){  //f we get smaller element in first list then point last next to that node's address
        last->next = p;     
        last = p;          //point last to that node
        p = p->next;       //move the first to next
        last->next = NULL;   //make last node's next address empty.
       }
       else{  

        //similar coniditon if second lists element is smaller.
        last->next = q; 
        last = q;
        q = q->next;
        last->next = NULL;
       }
    }
    
     //add the remaining elements of both the lists
    if(p!=NULL) last->next = p;
    else last->next = q;
    
    //return the pointer to display third linked list.
    return third;
}

void freq(struct node *p){

    int max = -3670432;   //negetive value stored to find maximum value of linked list.
    while(p!=NULL){
         if(p->data > max){
            max = p->data;
            p = p->next;
         }
         else{
            p = p->next;
         }
    }

    int *hash = (int *) calloc(max+1,sizeof(int)); //create a hash table
    
    p = first;  //put all the values in hash table 
    while(p!=NULL){
        hash[p->data]++;
        p = p->next;
    }
                //now run a loop and check whenever value > 0 print its freq and corresponding element.
    for(int i=0;i<=max;i++){
        if(hash[i]>0){
            printf("freq of %d is: %d\n",i,hash[i]);
        }
}
         //free the memory we used for creating hash table.
    free(hash);
}


int main(){
   
    int n;
    printf("Enter size of linked list: ");
    scanf("%d" ,&n);

    printf("Enter the elements of linked list:\n");
    //creating linked list.
    create(&first,n);
    Display(first);
    
    printf("\n");
    freq(first);
    
    int m;
    printf("\nEnter second Linked List Size: ");
    scanf("%d",&m);

    printf("Enter elements of Second Linked List: ");

    create(&second,m);

    printf("Merging of Linked Lists:\n");
    Display(merge_linked_lists(first,second));


    return 0;
}
