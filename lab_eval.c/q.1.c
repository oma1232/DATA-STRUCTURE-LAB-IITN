#include <stdio.h>
#include <stdlib.h>
//add two numbers

struct node {

    int data;
    struct node *next;
} *first = NULL,*second = NULL, *third = NULL;
 
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

//addition of two numbers when length of lists is same and addition is less than 10.
//in general case we reverse the lists and then add and store its carry in a carry variable than pass it to next sum
//sum is stored as sum%10 and carry as sum/10.
//then at last reverse the final list.

void add_numbers(struct node *p,struct node *q){
    
    struct node * last, *t;
    if(p == NULL){
        third = q;
        return;
    }

    if(q== NULL){
        third = q;
        return;
    }

    while(p && q){

        if(third == NULL){
           third = (struct node *) malloc(sizeof(struct node));
           third->data = p->data + q->data;
           last = third;
           last->next = NULL;
        }
        else{
         t = (struct node *) malloc(sizeof(struct node));
         t->data = p->data + q->data;
         t->next = NULL;
         last->next = t;
         last = t;
        }

        p = p->next;
        q = q->next;
    }
}

int main(){

    int n;
    scanf("%d",&n);

    create(&first,n);

    int m;
    scanf("%d",&m);

    create(&second,m);
    
    printf("After Addition:\n");
    add_numbers(first,second);
    Display(third);

    return 0;
}
