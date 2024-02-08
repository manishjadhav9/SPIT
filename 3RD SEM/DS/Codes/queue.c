/*
 * File: queue.c
 * Author: Siddhartha Chandra
 * Email: siddhartha_chandra@spit.ac.in
 * Created: September 1, 2023
 * Description: This program implements a Queue ADT with a circular array
 */

#include <stdio.h>
#include <stdlib.h>

// Build a Queue Abstract Data structure and perform operations on it
// Operations:
// 1. display
// 2. isFull
// 3. isEmpty
// 4. enqueue
// 5. dequeue
// 6. front
// 7. rear

struct Queue
{
	int front;
	int rear;
	unsigned size;
	char *array;
};

// 0 -> Initialize
struct Queue *initialize_queue(unsigned size)
{
	struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
	queue->front = 0;
	queue->rear = -1;
	queue->size = size;
	queue->array = (char *)malloc((size) * sizeof(char));
	return queue;
}

// 1 -> display
void display(struct Queue *queue)
{
	printf("\n> Queue Front\n");
	for (int i = 0; i <= queue->rear; i++)
	{
		printf("> %c\n", queue->array[i]);
	}
	printf("> Queue Rear\n\n");
}

// 2 -> isEmpty
int isEmpty(struct Queue *queue) { return queue->rear == -1; }

// 3 -> isFull
int isFull(struct Queue *queue) { return queue->rear == queue->size - 1; }

// 4 -> enqueue
void enqueue(struct Queue *queue, char item)
{
	if (isFull(queue))
	{
		printf("\n> Dequeue-ing to free space: %c\n", queue->array[queue->front]);
		for (int i = 1; i <= queue->rear; i++)
		{
			queue->array[i - 1] = queue->array[i];
		}
		queue->rear--;
	}
	queue->rear++;
	queue->array[queue->rear] = item;
	queue->array[queue->rear + 1] = '\0';
}

// 5 -> dequeue
char dequeue(struct Queue *queue)
{
	if (isEmpty(queue))
	{
		printf("\n> Queue already Empty! \n");
		return '\0';
	}
	char front = queue->array[queue->front];
	for (int i = 1; i < queue->size; i++)
	{
		queue->array[i - 1] = queue->array[i];
	}
	queue->rear--;
	return front;
}

// 6 -> front
char front(struct Queue *queue) { return queue->array[queue->front]; }

// 7 -> rear
char rear(struct Queue *queue) { return queue->array[queue->rear]; }

// void main()
// {
// 	struct Queue *q = initialize_queue(8);
// 	printf("> IsEmpty: %d\n", isEmpty(q)); // 1 for Empty Queue Array
// 	dequeue(q);							   // Checking for Dequeue in Empty Queue
// 	enqueue(q, 'a');					   // Enqueue-d 8 characters
// 	enqueue(q, 'b');
// 	enqueue(q, 'c');
// 	enqueue(q, 'd');
// 	enqueue(q, 'e');
// 	enqueue(q, 'f');
// 	enqueue(q, 'g');
// 	enqueue(q, 'h');
// 	display(q);						   // Checking Queue
// 	printf("> Front: %c\n", front(q)); // Checking Front and Rear
// 	printf("> Rear: %c\n", rear(q));
// 	printf("> isFull: %d\n", isFull(q));
// 	printf("> Enqueing i to test limitations");
// 	enqueue(q, 'i');							 // Enqueueing when Full
// 	display(q);									 // Checking Queue
// 	printf("> Dequeued Item: %c\n", dequeue(q)); // Checking Dequeue
// 	display(q);									 // Final Display
// }
