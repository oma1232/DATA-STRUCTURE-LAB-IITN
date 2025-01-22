//to calculate the moving average of a array
#include <stdio.h>

void moving_average(int arr[], int n, int k, double result[]) {
    double window_sum = 0;
    for (int i = 0; i < k; i++) {
        window_sum += arr[i];
    }
    result[0] = window_sum / k;

    for (int i = k; i < n; i++) {
        window_sum += arr[i] - arr[i - k];
        result[i - k + 1] = window_sum / k;
    }
}

void print_array(double arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    double moving_avg[n - k + 1];
    moving_average(arr, n, k, moving_avg);
    print_array(moving_avg, n - k + 1);
    return 0;
}



//no. of swaps
#include <stdio.h>

void main() {
    int arr[10], i, j, n, temp, swap_count = 0;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap_count++;
            }
        }
    }
    
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Number of swaps: %d\n", swap_count);
}




// removing duplicates from an array
#include <stdio.h>

void main() {
    int arr[10], n, i, j, k;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                for (k = j; k < n - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                n--;
                j--;
            }
        }
    }

    printf("Array after removing duplicates: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}






//sorting of an array
#include<stdio.h>
#include<conio.h>
int main()
{
    int a[10],n,i,j,temp;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    printf("Enter %d elements:",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
            }
            }
            printf("Sorted array is:");
            for(i=0;i<n;i++)
            {
                printf("%d ",a[i]);
            }
}






//kth largest  no. without sorting
#include <stdio.h>

int main() {
    int a[100], n, k, i, j, count, temp;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the value of k: ");
    scanf("%d", &k);

    
    for (i = 0; i < k; i++) {
        int maxindex = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] > a[maxindex]) {
                maxindex = j;
            }
        }
        
        
        if (maxindex != i) {
            temp = a[i];
            a[i] = a[maxindex];
            a[maxindex] = temp;
        }
    }

    printf("The %d-th largest element is: %d\n", k, a[k - 1]);

    return 0;
}




//sorting array using insertion sort
#include <stdio.h>

void main() {
    int arr[10], i, j, n, temp, insertion_count = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
            insertion_count++;
        }
        arr[j + 1] = temp;
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Number of insertions: %d\n", insertion_count);
}




//frequency of an array
#include <stdio.h>

void findFrequency(int arr[], int n) {
    int i, j, count;
    for (i = 0; i < n; i++) {
        count = 1;
        if (arr[i] == -1)
            continue;
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                arr[j] = -1;
            }
        }
        printf("%d occurs %d times\n", arr[i], count);
    }
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    findFrequency(arr, n);
    return 0;
}

