#include <stdio.h>

// stack using arrays..,
int top = -1;

void stack_(int arr[],int n,int size_){
    
    if(n == 0) return;
    
    printf("Enter the elements: ");
    if(top == -1){
        scanf("%d",&arr[0]);
        top++;
    }

    if(top == size_-1){
        printf("Stack is Full!");
        return;
    }
    
    for(int i=1;i<n;i++){
      scanf("%d",&arr[i]);
      top++;

    }
 }

void Display(int arr[]){
    int t = top;

    if(t == -1){
        printf("Stack is Empty!\n");
        return;
    }

    while(t != -1){
        printf("%d ",arr[t]);
        t--;
    }
}

void push(int *arr,int x,int size_){

       if( top == size_-1) return;
       
       int i = 0;

       if(top == -1){
        arr[i] = x;
        top++;
       }
       else{
        arr[++top] = x;
       }
}

void pop(){

       if(top == -1){
        printf("Stack is Empty: ");
        return;
       }
       else{
        top--;
       }
}

int main(){
    
    int size;
    printf("Enter size: ");
    scanf("%d",&size);

    int n;
    printf("Enter no. of elements to push in stack: ");
    scanf("%d",&n);
    
    int arr[size];

    stack_(arr,n,size);
    printf("\nDisplaying Stack: ");
    Display(arr);
    
    int x;
    printf("\nEnter element to push: ");
    scanf("%d",&x);
    
    printf("Stack after push: ");
    push(arr,x,size);
    Display(arr);

    pop();
    printf("\nAfter pop: ");
    Display(arr);
    
    return 0;
}
