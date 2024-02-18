#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        sleep(5);
        printf("Orphan Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
    } else if (pid > 0) {
        // Parent process
        printf("Parent process: PID = %d\n", getpid());
    } else {
        // Fork failed
        printf("Fork failed.\n");
        return 1;
    }

    return 0;
}
