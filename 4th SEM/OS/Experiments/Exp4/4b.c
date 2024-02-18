#include <stdio.h>
#include <pthread.h>
#define MAX_SIZE 8
int array[MAX_SIZE];
int size = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void *addValue(void *arg)
{
  int num = *(int *)arg;
  pthread_mutex_lock(&mutex);
  if (size < MAX_SIZE)
  {
    array[size++] = num;
    printf("New Value %d is added to the array. Hence the New array is: ", num);
    for (int i = 0; i < size; i++)
    {
      printf("%d ", array[i]);
    }
    printf("\n");
  }
  else
  {
    printf("Cannot add %d. Array is full.\n", num);
  }
  pthread_mutex_unlock(&mutex);
  return NULL;
}
void *deleteValue(void *arg)
{
  pthread_mutex_lock(&mutex);
  if (size >= 2)
  {
    int lastElement1 = array[size - 1];
    int lastElement2 = array[size - 2];
    size -= 2;
    printf("Deleted %d and %d from the array. New array is: ", lastElement1,
           lastElement2);
    for (int i = 0; i < size; i++)
    {
      printf("%d ", array[i]);
    }
    printf("\n");
  }
  else
  {
    printf("As there are only 2 elements left in array. Therefore cannot perform delete operation.\n");
  }
  pthread_mutex_unlock(&mutex);
  return NULL;
}
int main()
{
  pthread_t addThread, deleteThread;
  int numbers[MAX_SIZE];
  printf("Enter up to %d integers: \n", MAX_SIZE);
  int number, index = 0;
  while (index < MAX_SIZE && scanf("%d", &number) == 1 && number != -1)
  {
    numbers[index++] = number;
  }
  for (int i = 0; i < index; i++)
  {
    pthread_create(&addThread, NULL, addValue, &numbers[i]);
    pthread_join(addThread, NULL);
    pthread_create(&deleteThread, NULL, deleteValue, NULL);
    pthread_join(deleteThread, NULL);
  }
  pthread_mutex_destroy(&mutex);
  return 0;
}
