#include <stdio.h>
#include <pthread.h>
#define MAX_SIZE 50
int arr[MAX_SIZE], size, index;
void *calculateAvg()
{
  float sum = 0;
  float average;
  printf("What will be the size of an array? ");
  scanf("%d", &size);
  printf("Please enter %d elements:\n", size);
  for (index = 0; index < size; index++)
  {
    scanf("%d", &arr[index]);
  }
  for (index = 0; index < size; index++)
  {
    sum = sum + arr[index];
  }
  average = sum / size;
  printf("The average of given elements in an array is: %.2f\n", average);
  return NULL;
}
void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}
void *calculateMid()
{
  for (index = 0; index < size - 1; index++)
  {
    int min = index;
    for (int j = index + 1; j < size; j++)
    {
      if (arr[j] < arr[min])
        min = j;
    }
    swap(&arr[min], &arr[index]);
  }
  float median;
  if (size % 2 == 0)
  {
    median = (arr[(size - 1) / 2] + arr[(size - 1) / 2 + 1]) / 2.0;
  }
  else
  {
    median = arr[size / 2];
  }
  printf("The median of given elements in an array is: %.2f\n", median);
  return NULL;
}
void *calculateMaxi()
{
  int maxVal = arr[0];
  for (int i = 1; i < size; i++)
  {
    if (maxVal < arr[i])
    {
      maxVal = arr[i];
    }
  }
  printf("The maximum of given elements in an array is:: %d\n", maxVal);
  return NULL;
}
int main()
{
  pthread_t thread1, thread2, thread3;
  pthread_create(&thread1, NULL, calculateAvg, NULL);
  pthread_join(thread1, NULL);
  pthread_create(&thread2, NULL, calculateMid, NULL);
  pthread_join(thread2, NULL);
  pthread_create(&thread3, NULL, calculateMaxi, NULL);
  pthread_join(thread3, NULL);
  return 0;
}