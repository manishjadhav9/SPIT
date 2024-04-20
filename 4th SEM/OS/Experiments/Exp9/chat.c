#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024
#define KEY 1234

// Define predefined responses for the chat bot
char *responses[] = {
    "Hello, how can I help you today?",
    "I'm sorry, I cannot provide you with real-time stocks price of
TATA MOTORS.",
    "HP Victus is currently the best laptop for now.",
    "Currently Royal Enfeild Continental GT650 Twin is the best bike."
};

int main() {
    int shmid;
    char *shmaddr;
    char *user_input = NULL;
    size_t len = 0;
    ssize_t read;

    // Create a shared memory segment
    shmid = shmget(KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach to the shared memory segment
    shmaddr = (char *) shmat(shmid, NULL, 0);
    if (shmaddr == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    printf("Chat Bot initialized. Type 'exit' to quit.\n");

    // Chat loop
    while (1) {
        // Read user input
        printf("You: ");
        read = getline(&user_input, &len, stdin);
        if (read == -1) {
            perror("getline");
            exit(1);
        }

        // Write bot's response to shared memory
        if (strncmp(user_input, "exit", 4) == 0) {
            break;
        } else if (strncmp(user_input, "Hi", 2) == 0) {
            strncpy(shmaddr, responses[0], SHM_SIZE);
        } else if (strncmp(user_input, "What is the current stocks
price of TATA MOTORS?", 37) == 0) {
            strncpy(shmaddr, responses[1], SHM_SIZE);
        } else if (strncmp(user_input, "Which is the best laptop?", 20) == 0) {
            strncpy(shmaddr, responses[2], SHM_SIZE);
        } else if (strncmp(user_input, "Which is the best bike?", 18) == 0) {
            strncpy(shmaddr, responses[3], SHM_SIZE);
        }
        else {
            strncpy(shmaddr, "I'm sorry, I don't understand that.", SHM_SIZE);
        }

        // Wait for a moment
        sleep(1);

        // Read bot's response from shared memory
        printf("Bot: %s\n", shmaddr);
    }

    // Detach from the shared memory segment
    if (shmdt(shmaddr) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Clean up the shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    free(user_input);

    return 0;
}