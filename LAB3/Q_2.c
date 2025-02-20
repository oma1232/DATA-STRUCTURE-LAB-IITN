#include <stdio.h>
#include <limits.h>
#include <string.h>

//Insertion Sort Algorithm...
void Insertion_Sort(int *Array, int n){
    int temp;
    for(int i=0; i<n; i+=2){
            temp = Array[i];
            int j = i-2;
            while(j>=0 && temp < Array[j]){
                Array[j+2] = Array[j];
                j-=2;
            }
            Array[j+2] = temp;
        }
    for(int i=0; i<n; i++) printf("%d ", Array[i]);
}

//Selection_Sort...
void Selection_Sort(int *Array, int n){
    int min_index;
    for(int i=1; i<n; i+=2){
            int temp = Array[i];
            min_index = i;
            for(int j=i+2; j<n; j+=2){
                if(Array[min_index] > Array[j]){
                    min_index = j;
                }
            }
            if(min_index != i){
                Array[i] = Array[min_index];
                Array[min_index] = temp; 
            }
        }
}

//Now we need to perform quick sort also count no. of pivots.
int count=0;
int partition(int arr[], int start, int end){
    int pivot = arr[start];
    int i = start;
    int j = end;
    
    //when start > end we will stop and swap with pivot..
    while(i < j){
        while(arr[i] <= pivot && i <= end-1) i++;
        while(arr[j] > pivot && j >= start+1) j--;
        
        //if start is less than end we will swap to make partition of smaller and large numbers.
        if(i < j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    //Now swap the pivot with the element at index j. returning the index of pivot useful for recursion in quick sort.
    int temporary = arr[start];
    arr[start] = arr[j];
    arr[j] = temporary;
    count++;
    return j;
}

void quick_sort(int array[], int start, int end){
    if(start < end){
        int pIndex = partition(array, start, end);  //get the index of pivot and perform quick sort recursively to sort the array...
        quick_sort(array, start, pIndex-1);
        quick_sort(array, pIndex+1, end);
    }
}


//Performing merge sort...-----------------------------
//merge sort is divide and conquer algorithm. (time complexity is O(n log n))...
void merge(int arr[], int start, int mid, int end) {
    int i, j, k;
    int n1 = mid - start + 1;
    int n2 = end - mid;

    // Create temporary arrays..
    int temp[n1], temp2[n2];

    // Copy data to temporary arrays
    for (i = 0; i < n1; i++)
        temp[i] = arr[start + i];
    for (j = 0; j < n2; j++)
        temp2[j] = arr[mid + 1 + j];

    // Merge the temporary arrays
    i = 0; // Initial index of first sub-array
    j = 0; // Initial index of second sub-array
    k = start; // Initial index of merged sub-array
    while (i < n1 && j < n2) {
        if (temp[i] <= temp2[j]) {
            arr[k] = temp[i];
            i++;
        } else {
            arr[k] = temp2[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of temp[] if any
    while (i < n1) {
        arr[k] = temp[i];
        i++;
        k++;
    }

    // Copy remaining elements of temp2[] if any
    while (j < n2) {
        arr[k] = temp2[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;

        // Sort first and second halves..
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        // Merge the sorted halves...
        merge(arr, start, mid, end);
    }
}

//--------------------------------------------
int main(){
    int n;
    printf("Enter Array Size:");
    scanf("%d", &n);

    int array[n];
 
    printf("Enter elements:\n");
    for(int i=0; i<n; i++) scanf("%d", &array[i]);
    
    //Sorting Array...--------------------------
    Selection_Sort(array, n);
    Insertion_Sort(array, n);
    
    printf("\n");
    printf("Sorted using Quick Sort:\n");
    quick_sort(array, 0, n-1);
    
    for(int i=0; i<n; i++) printf("%d ", array[i]);
    printf("\nPivot count:%d\n", count);

    //Merge Sort... ------------------------------
    int arr2[n];
    printf("Enter Array to sort using Merge Sort:\n");
    
    for(int i=0; i<n; i++) scanf("%d", &arr2[i]);

    mergeSort(arr2, 0, n-1);
    for(int i=0; i<n; i++) printf("%d ", arr2[i]);

    // -------------------------------------------
    // //for string sorting...

    printf("\nSorting String using Merge Sort:");
    char str[] = "NAGPUR";
    int t = strlen(str);
    printf("\n");
    
    int ascii_[t];
    for (int i = 0;i<t; i++) {
        ascii_[i] = (int)str[i];
    }
    mergeSort(ascii_,0, t-1);
    
    for(int i=0;i<t;i++) printf("%c",ascii_[i]);
    return 0;
}
