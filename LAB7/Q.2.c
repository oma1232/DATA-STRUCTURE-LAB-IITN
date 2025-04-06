#include <stdio.h>
#include <stdlib.h>

struct dll{

    int data;
    struct dll *next, *prev;
}*top = NULL;

void stack(int n){
    
    if(n == 0) return;
    
    struct dll *t = (struct dll  *)malloc(sizeof(struct dll));
     
    if(top == NULL){
        scanf("%d",&t->data);
        t->next = top;
        t->prev = NULL;
        top = t;
    }

        for(int i = 1;i<n;i++){
            t = (struct dll  *)malloc(sizeof(struct dll));
            scanf("%d",&t->data);

            t->prev = NULL;
            t->next = NULL;

            t->prev = top;
            top->next = t;
            top = t;
        }
}

void Display(struct dll *t){
    
    if(top == NULL){
        printf("Stack is empty!");
        return;
    }

    while(t!=NULL){
        printf("%d ",t->data);
        t = t->prev;
    }

}

void push(int x){
    struct dll *new = (struct dll *)malloc(sizeof(struct dll));
    
    new->data = x;
    new->prev = NULL;
    new->next = NULL;

    new->prev = top;
    top->next = new;
    top = new;
    
}

void pop_back(){

    if(top == NULL) return;
    
    struct dll *p;
    p = top;

    top = top->prev;
    top->next = NULL;
    free(p);

}

int main(){

    int n;
    printf("Enter size of stack: ");
    scanf("%d",&n);

    printf("Enter the elements: ");
    stack(n);

    printf("Stack: ");
    Display(top);
    printf("\n");
    
    int x;
    printf("Enter element to push: ");
    scanf("%d",&x);

    push(x);

    printf("Stack after pushing element: ");
    Display(top);

    pop_back();
    printf("\nStack after pop: ");
    Display(top);

    return 0;
}
