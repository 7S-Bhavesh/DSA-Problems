#include <stdio.h>
void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d   ", arr[i]);
    }
    printf("\n");
}
void BubbleSort(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void insertionSort(int *arr, int n)
{
    int key;
    int j;
    for (int i = 1; i <= n - 1; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (arr[j] > pivot)
        {
            j--;
        }
        while (arr[i] < pivot)
        {
            i++;
        }
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}
void quickSort(int arr[], int low, int high)
{
    int partitionIndex;
    if (low < high)
    {
        partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}
void mergeSort(int arr[], int low, int high, int mid)
{
    int i = low;
    int k = low;
    int j = mid + 1;
    int b[100];

    while (i <= mid && j <= high)
    {
        if (arr[i] > arr[j])
        {
            b[k] = arr[j];
            k++;
            j++;
        }
        else
        {
            b[k] = arr[i];
            k++;
            i++;
        }
    }
    while (i <= mid)
    {
        b[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        b[k] = arr[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = b[i];
    }
}

void merge(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {

        mid = (low + high) / 2;
        merge(arr, low, mid);
        merge(arr, mid + 1, high);
        mergeSort(arr, low, high, mid);
    }
}
int main()
{
    int arr[] = {12, 54, 21, 24, 322, 12};
    int n = 6;
    printArray(arr, n);
    printf("After sorting\n");

    // insertionSort(arr,n);
    // selectionSort(arr,n);
    // quickSort(arr,0,n-1);
    merge(arr, 0, n - 1);
    printArray(arr, n);
}