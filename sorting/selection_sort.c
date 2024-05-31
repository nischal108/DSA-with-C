#include <stdio.h>

// Function to perform selection sort
void selectionSort(int arr[], int n)
{
    int i, j, minIdx, temp;

    // Traverse through all array elements
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in the unsorted part of the array
        minIdx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }

        // Swap the found minimum element with the first element
        temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int n, i;

    // Input: Number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input: Elements of the array
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Perform selection sort
    selectionSort(arr, n);

    // Output: Sorted array
    printf("Sorted array in ascending order:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
