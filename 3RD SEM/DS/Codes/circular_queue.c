/*
 * File: circular_queue.c
 * Author: Manish Jadhav
 * Email: manishsj289@gmail.com
 * Created: September 16, 2023
 * Description: This program implements a Queue ADT with a circular array
 */
#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int front;
    int rear;
    int size;
    char *array;
};

// 1 -> Initialize
struct Queue *initialize_queue(struct Queue *queue, int size)
{
    queue->size = size;
    queue->front = queue->rear = 0;
    queue->array = (char *)malloc(size * sizeof(char));
}

// 2 -> isEmpty
int isEmpty(struct Queue *queue)
{
    if (queue->rear == queue->front)
    {
        return 1;
    }
    return 0;
}

// 3 -> isFull
int isFull(struct Queue *queue)
{
    if ((queue->rear + 1) % queue->size == queue->front)
    {
        return 1;
    }
    return 0;
}

// 4 -> enqueue
void enqueue(struct Queue *queue, char item)
{
    if (isFull(queue))
    {
        printf("Queue Overflow\n");
    }
    else
    {
        queue->rear = (queue->rear + 1) % queue->size;
        queue->array[queue->rear] = item;
        printf("Enqueued element: %c\n", item);
    }
}

// 5 -> dequeue
char dequeue(struct Queue *queue)
{
    char val = '\0';
    if (isEmpty(queue))
    {
        printf("Empty queue\n");
    }
    else
    {
        queue->front = (queue->front + 1) % queue->size;
        val = queue->array[queue->front];
    }
    return val;
}

// 6 -> front
char front(struct Queue* queue){
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return '\0';
    }
      printf("The front is : %c\n", queue->array[(queue->front + 1) % queue->size]);
}

// 7 -> rear
char rear(struct Queue* queue){
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return '\0';
    }
    printf("The rear is : %c\n", queue->array[queue->rear]);
}

void display(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = queue->front;
    do
    {
        i = (i + 1) % queue->size;
        printf("%c ", queue->array[i]);
    } while (i != queue->rear);

    printf("\n");
}

int main()
{
    struct Queue q;
    initialize_queue(&q, 5);
    enqueue(&q, '8');
    enqueue(&q, '9');
    enqueue(&q, '1');
    enqueue(&q, '3');


    display(&q);
    front(&q);
    rear(&q);
    printf("Dequeued element: %c\n", dequeue(&q));
    printf("Dequeued element: %c\n", dequeue(&q));


    front(&q);
    rear(&q);
    display(&q);

    return 0;
}
