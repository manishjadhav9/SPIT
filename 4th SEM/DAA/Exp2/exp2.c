#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = (low - 1);

    for (int j = low; j <= high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{


     srand(time(NULL));
    int n = 100;
    int arr[n];

    for (int j = 0; j < n; j++)
    {
        arr[j] = rand() % 100000 + 1;
    }

    printf("Unsorted array:\n");
    for (int j = 0; j < n; j++)
    {
        printf("%d ", arr[j]);
    }
    printf("\n");

    clock_t start_merge = clock();
    mergeSort(arr, 0, n - 1);
    clock_t end_merge = clock();
    double time_merge = ((double)(end_merge - start_merge)) / CLOCKS_PER_SEC;

    printf("Sorted array using merge sort:\n");
    for (int j = 0; j < n; j++)
    {
        printf("%d ", arr[j]);
    }
    printf("\nTime takenzz for merge sort: %lf seconds\n", time_merge);

    clock_t start_quick = clock();
    quickSort(arr, 0, n - 1);
    clock_t end_quick = clock();
    double time_quick = ((double)(end_quick - start_quick)) / CLOCKS_PER_SEC;

    printf("Sorted array using quick sort:\n");
    for (int j = 0; j < n; j++)
    {
        printf("%d ", arr[j]);
    }
    printf("\nTime taken for quick sort: %lf seconds\n", time_quick);

    return 0;
}




