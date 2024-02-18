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
void main()
{
  srand(time(NULL));
  FILE *fileptr;
  FILE *fileptr1;
  int n = 100000;
  fileptr = fopen("inp.txt", "w");
  int arr[n];
  for (int j = 0; j < n; j++)
  {
    arr[j] = rand() % 100000 + 1;
    fprintf(fileptr, "%d\n", arr[j]);
  }
  fclose(fileptr);

  fileptr1 = fopen("time.csv", "w");
  printf("Block Size\tInsertion Sort\tSelection sort\n");
  
  fileptr = fopen("inp.txt", "r");
  for (int p = 99; p < n; p = p + 100)
  {
    int array[p + 1];
    int array1[p + 1];
    for (int j = 0; j < p; j++)
    {
      array[j] = arr[j];
      fscanf(fileptr, "%1d", &array1[j]);
    }
    clock_t begin = clock();
    insertSort(array, p + 1);
    clock_t mid = clock();
    selectSort(array1, p + 1);
    clock_t end = clock();
    double time_spent = (double)(mid - begin);
    double time_spent1 = (double)(end - mid);
    printf("%d\t%lf\t%lf\n", p + 1, time_spent, time_spent1);
    fprintf(fileptr1, "%d,%lf,%lf\n", p + 1, time_spent, time_spent1);
  }
  printf("\n");
}