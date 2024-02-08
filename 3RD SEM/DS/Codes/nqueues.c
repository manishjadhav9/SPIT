/*
 * File: nqueues.c
 * Author: Manish Jadhav
 * Email: manishsj289@gmail.com
 * Created: September 16, 2023
 * Description: This program implements an n-series queues data structure
 */

/*
 N-Series and chill

You're tasked with creating a data structure, which we'll call the "NQueues,"
to manage the binge-watching habits of enthusiastic Netflix users.
The goal is to represent N queues of series in a single data
structure, allowing users to enjoy their favorite shows seamlessly.

This N Series Queues data structure should support the following operations:
1. add_episode(int episode_id, int queueNumber):
   This operation adds an episode with a specific ID to a queue, identified by its queueNumber.
   The queueNumber can range from 0 to N-1, accommodating different tastes.

2. WatchNextEpisode(int queueNumber):
   When it's time to continue the series, this operation allows the user to watch
   the next episode from the queue specified by queueNumber (ranging from 0 to N-1).

Users will specify the number of queues they want to manage, and they'll also determine
the initial series they'd like to add to each queue.

It's essential to maintain the following principles when designing this N Series Queues data structure for Netflix users:
-> New series are always added to the end of the queue, ensuring users can easily access the latest episodes.
-> When it's time to watch the next episode, it will be removed from the front of the queue,
   ensuring a seamless watching experience.
-> Throughout the process of adding and removing series, it's crucial to continuously check for both overflows
   (too many series in a queue) and underflows (attempting to watch when the queue is empty).
-> Additionally, remember that our data structure provides open access at both ends of the queue:
   one end is open for series additions, while the other end remains accessible for episode-watching operations.

Your task is to craft a data structure that will allow Netflix enthusiasts to enjoy their series without interruption.
Please complete all the template functions to make your data structure come alive. Keep the binge-watching spirit alive!
*/

#include "queue.c"
#include <stdio.h>
#include <stdlib.h>

struct NQueues
{
    int *front;
    int *rear;
    unsigned total_queues;
    unsigned size_per_queue;
    struct Queue *array[100];
};

struct NQueues *createNQueues(int n, int capacity_per_queue)
{
    struct NQueues *nqueues = (struct NQueues *)malloc(sizeof(struct NQueues));
    nqueues->total_queues = n;
    nqueues->size_per_queue = capacity_per_queue;
    for (int i = 0; i < n; i++)
    {
        nqueues->array[i] = initialize_queue(capacity_per_queue);
    }
    return nqueues;
}

void add_episode(struct NQueues *nqueues, int episode_id, int queue_number)
{
    enqueue(nqueues->array[queue_number], episode_id);
}

char watch_next_episode(struct NQueues *nqueues, int queue_number)
{
    char ep = dequeue(nqueues->array[queue_number]);
    return ep;
}

void display_queue(struct NQueues *nqueues, int queue_number)
{
    display(nqueues->array[queue_number]);
}

void display_all(struct NQueues *nqueues)
{
    for (int i = 0; i < nqueues->total_queues; i++)
    {
        printf("> Queue No: %d", i + 1);
        display(nqueues->array[i]);
    }
}

int main()
{
    struct NQueues *nqueues = createNQueues(3, 5);
    add_episode(nqueues, 77, 0);  
    add_episode(nqueues, 65, 0);  
    add_episode(nqueues, 78, 0);  
    add_episode(nqueues, 73, 1); 
    add_episode(nqueues, 83, 1); 
    add_episode(nqueues, 72, 1); 
    add_episode(nqueues, 80, 2); 
    add_episode(nqueues, 85, 2); 
    add_episode(nqueues, 82, 2); 

    display_all(nqueues);

    char next_episode = watch_next_episode(nqueues, 0);
    printf("Watched episode: %d : %c\n", next_episode, next_episode);

    printf("Queue after watching episode:\n");
    display_queue(nqueues, 0);

    next_episode = watch_next_episode(nqueues, 0);
    next_episode = watch_next_episode(nqueues, 0); 

    // Underflow check
    next_episode = watch_next_episode(nqueues, 0);

    // Empty Queue Display
    printf("\nQueue after watching episode:");
    display_queue(nqueues, 0);

    // Free Space
    free(nqueues->array);
    free(nqueues);

   return 0;
}