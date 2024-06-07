#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertSort(int *arr, int n)
{
    for (int j = 1; j < n; j++)
    {
        int key = arr[j];
        int i = j - 1;
        while (i > -1 && key < arr[i])
        {
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
    }
}

void selectSort(int *a, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        int p = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[p] > a[j])
            {
                p = j;
            }
        }
        if (p != i)
        {
            temp = a[i];
            a[i] = a[p];
            a[p] = temp;
        }
    }
}

int main()
{
    srand(time(NULL));
    int n = 2500;
    int arr[n];
    for (int j = 0; j < n; j++)
    {
        arr[j] = rand() % 1000 + 1;
    }

    printf("Generated Numbers:\n");
    for (int j = 0; j < n; j++)
    {
        printf("%d ", arr[j]);
    }
    printf("\n\n");

    int array[n];
    int array1[n];
    for (int j = 0; j < n; j++)
    {
        array[j] = arr[j];
        array1[j] = arr[j];
    }

    clock_t begin = clock();
    insertSort(array, n);
    clock_t mid = clock();
    selectSort(array1, n);
    clock_t end = clock();
    double time_spent = (double)(mid - begin) / CLOCKS_PER_SEC;
    double time_spent1 = (double)(end - mid) / CLOCKS_PER_SEC;

    printf("Insertion Sort:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\nTime taken: %lf seconds\n", time_spent);

    printf("\nSelection Sort:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d", array1[i]);
    }
    printf("\nTime taken: %lf seconds\n", time_spent1);

    return 0;
}



