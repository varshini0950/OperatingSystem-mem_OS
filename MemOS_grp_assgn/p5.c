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
        pid_t child_pid, wpid;
        int status;
        child_pid = wait(&status);  // Wait for child process to finish
        printf("Parent process waiting for child PID %d to finish.\n", child_pid);
        printf("Child process exited with status code %d\n", status);
    }

    return 0;
}
