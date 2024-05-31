//Merge Sort Implememtation

#include <stdio.h>
#define MAX 10

void merge(int arr[], int lb, int mid, int ub)
{
    int temp[MAX];      //create an extra array of original size
    int i = lb, j = mid + 1, k = 0;
    while(i <= mid && j<=ub)     // until one list is finished
    {
        if(arr[i] <= arr[j])     //if ith elements of first sublist is smaller than jth element of the second sublist then copy from the first sublist
        {
            temp[k] =arr[i];
            i++;
        }

        else{
            temp[k] = arr[j];
            j++;
        }

        k++;
    }

    while (i <= mid)        //copy all remaining elements from the first sublist if any
    {
        temp[k] = arr[i];
        i++;
        k++;
    }  

    while (j <= ub)        //copy all remaining elements from the second sublist if any
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    //now copy back the sorted list from temp to original array
    for(i = lb, k = 0; i <= ub; i++, k++)
        arr[i] = temp[k];
}

void mergeSort(int arr[], int lb, int ub)
{
    int mid = (lb + ub)/2;
    if(lb < ub)     //if there are more than one elements in the list
    {

        //divide the list into two sublist
        mergeSort(arr, lb, mid);          //first sublist
        mergeSort(arr, mid+1, ub);      //second sublist
        //then merge the sublist to construct single sorted list
        merge(arr, lb, mid, ub);  
    }
}

void main()
{
    int arr[MAX]={22, 18, 9, 4, 6, 3, 11, 5, 2, 8};
    int i;
    printf("Before Sorting: \n");
    for(i=0; i<MAX; i++)
    {
        printf("%d\t", arr[i]);
    }

    mergeSort(arr, 0, MAX-1);

    printf("\nAfter Sorting: \n");
    for(i=0; i<MAX; i++)
    {
        printf("%d\t", arr[i]);
    }
}