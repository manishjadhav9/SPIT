/*#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child process: PID = %d\n", getpid());
    } else if (pid > 0) {
        // Parent process
        wait(NULL);
        printf("Parent process: Child process terminated.\n");
    } else {
        // Fork failed
        printf("Fork failed.\n");
        return 1;
    }

    return 0;
}
// C program to demonstrate working of wait()
#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
	if (fork()== 0)
		printf("HC: hello from child\n");
	else
	{
		printf("HP: hello from parent\n");
		wait(NULL);
		printf("CT: child has terminated\n");
	}

	printf("Bye\n");
	return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t childPid;

    // Create a child process
    childPid = fork();

    if (childPid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (childPid == 0) {
        // Child process
        printf("Child process (PID: %d) is running.\n", getpid());
        sleep(3);  // Simulate some work in the child process
        printf("Child process (PID: %d) is exiting.\n", getpid());
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        printf("Parent process (PID: %d) is waiting for the child to exit.\n", getpid());

        int status;
        pid_t terminatedChildPid = wait(&status);

        if (terminatedChildPid == -1) {
            perror("wait");
            exit(EXIT_FAILURE);
        }

        if (WIFEXITED(status)) {
            printf("Child process (PID: %d) exited with status %d.\n", terminatedChildPid, WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Child process (PID: %d) terminated by signal %d.\n", terminatedChildPid, WTERMSIG(status));
        }

        printf("Parent process (PID: %d) is done.\n", getpid());
    }

    return 0;
}


