
#include<iostream>
#include <stdio.h>

using namespace std;

//Creating Structure...
struct Array{
    
    //Dynamic Array 
    int *A;
    int size;
}arr;

//Function to display array.
void Display(struct Array arr,int n){
    
    for(int i=0;i<arr.size;i++) cout<<arr.A[i]<<" ";
    cout<<endl;
}

//Function to Delete element from Array...
void Delete(struct Array *arr,int index,int n){
    
     for(int i=index;i<n;i++){
        //Traverse from that index to the end of array and copy the element to the previous one.
        arr->A[i] = arr->A[i+1];
     }
     //Decrease the size of array by 1 (but the element will still exist in memory)
     arr->size--;
}

//Now Let's insert an element in array...
void insert(struct Array *arr,int index,int n,int x){
    
    //Run a loop from end to that index and copy the element to the next one.
    for(int i=n;i>index;i--)arr->A[i] = arr->A[i-1];  //I have used i=n (means i+1)
    arr->size++;  //Increase the size as we are inserting an element
    arr->A[index] =  x;   //Now put that element in the array at that index.
}

//Reversing array simply taking i and j running i from beginning and j from last till j>i and swaping elements.
void Reverse(struct Array *arr,int n){

    for(int i=0,j=n-1;i<n && j>i;i++,j--){
        int temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}

//Shifting array by 1 place to the right. Put the last element at first as it is shifted..
void Shift(struct Array *arr,int n){
    int x = arr->A[n-1];
    for(int i=n-1;i>0;i--){
        arr->A[i]= arr->A[i-1];
    }
    arr->A[0] = x;
}

//Sorting Array simply using Bubble Sort...
void sort(struct Array *arr,int n){
    int temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr->A[j] > arr->A[j+1]){
                temp = arr->A[j];
                arr->A[j] = arr->A[j+1];
                arr->A[j+1] = temp;
            }
        }
    }
}


//CHeck for even index and apply bubble sort on them...
void evenSort(struct Array *arr,int n){

    for(int i=0;i<n;i++){
        for(int j=n-2;j>0;j=j-2){
          if(arr->A[j] < arr->A[j-2]){
                int temp;
                temp = arr->A[j];
                arr->A[j] = arr->A[j-2];
                arr->A[j-2]=temp;
            }
        }
    }
}

//Similarly for odd index and apply bubble sort on them...
void oddSort(struct Array *arr,int n){

    for(int i=0;i<n;i++){
        for(int j=n-1;j>1;j=j-2){
          if(arr->A[j] < arr->A[j-2]){
                int temp;
                temp = arr->A[j];
                arr->A[j] = arr->A[j-2];
                arr->A[j-2]=temp;
            }
        }
    }
}

//Let's sort the array by even elements...
void even_Sort_by_Element(struct Array *arr,int n){

       //First traverse the array       
       for(int i=0;i<n;i++){
            int index,temp=0;   //creating variables to store index and value

            //Check if element is even and store it in temp and min variable
            if(arr->A[i]%2==0){  
                
                temp = arr->A[i];
                int min = arr->A[i];
                
                //now we will traverse from next array to find the minimum value element which is even
                for(int j=i+1;j<n;j++){
                    if(min > arr->A[j] && arr->A[j]%2==0){
                        min = arr->A[j];
                        index = j; //Store the index of that element which is minimum
                    }
                    
                    //Now swap the element with minimum element, we will swap only if the element found has minimum value...
                    if(temp > min){
                    arr->A[i] = min;
                    arr->A[index] = temp;
                }
                }
            }
        }
    }

//Same method for sorting only odd element...
void odd_Sort_by_Element(struct Array *arr,int n){

       for(int i=0;i<n;i++){
            int index,temp=0;  

            if(arr->A[i]%2!=0){  
                
                temp = arr->A[i];
                int min = arr->A[i];
                
                for(int j=i+1;j<n;j++){
                    if(min > arr->A[j] && arr->A[j]%2!=0){
                        min = arr->A[j];
                        index = j; 
                    }
                    
                    if(temp > min){
                    arr->A[i] = min;
                    arr->A[index] = temp;
                }
                }
            }
        }
    }

//In main function create a dynamic array..
int main(){
    
    cout<< "Enter the size of the array: ";
    cin>>arr.size;

    arr.A = new int[arr.size];
    
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<arr.size;i++) cin>>arr.A[i];

    Display(arr,arr.size);


//     Remove the comment to perform spercific task.


//     int index;
//     cout<<"Enter the index to delete: ";
//     cin>>index;


//     Delete(&arr,index,arr.size);
//     Display(arr,arr.size);


//    cout<<"Enter the index to insert: ";
//    cin>>index;


//    int x;
//    cout<<"Enter element to insert:";
//    cin>>x;


//    insert(&arr,index,arr.size,x);
//    Display(arr,arr.size);


//    cout<<"Reversing array: \n";
//    Reverse(&arr,arr.size);
//    Display(arr,arr.size);


//    cout<<"Shifting Array: \n";
//    Shift(&arr,arr.size);
//    Display(arr,arr.size);


//    cout<<"Sorting Array: \n";
//    sort(&arr,arr.size);
//    Display(arr,arr.size);


//    cout<<"EvenSort:\n";
//    evenSort(&arr,arr.size);
//    Display(arr,arr.size);


//    cout<<"OddSort:\n";
//    oddSort(&arr,arr.size);
//    Display(arr,arr.size);


//    cout<<"Even Sort by Element Value:\n";
//     even_Sort_by_Element(&arr,arr.size);
//     Display(arr,arr.size);


//    cout<<"Odd Sort by Element Value:\n";
//     odd_Sort_by_Element(&arr,arr.size);
//     Display(arr,arr.size);
    

//Delete the array after performing the task.
    delete [] arr.A;  

    return 0;
}
