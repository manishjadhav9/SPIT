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
        sleep(5);
        wait(NULL);
        printf("Parent process: Child process terminated.\n");
    } else {
        // Fork failed
        printf("Fork failed.\n");
        return 1;
    }

    return 0;
}*/

// A C program to demonstrate Zombie Process. 
// Child becomes Zombie as parent is sleeping 
// when child process exits. 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{ 
	// Fork returns process id 
	// in parent process 
	pid_t child_pid = fork(); 

	// Parent process 
	if (child_pid > 0) 
		sleep(50); 

	// Child process 
	else		
		exit(0); 

	return 0; 
} 


