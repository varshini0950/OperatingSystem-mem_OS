#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child process working...\n");
        sleep(5);  // Simulate some work
        printf("Child process finished.\n");
    } else {
        // Parent process
        pid_t child_pid, status;
        child_pid = waitpid(pid, &status, 0);  // Wait for specific child (pid)
        printf("Parent process waiting for child PID %d to finish.\n", child_pid);
        printf("Child process exited with status code %d\n", status);
    }

    return 0;
}
