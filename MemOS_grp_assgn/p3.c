#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        printf("hello\n");
    } else {
        // Parent process
        // Introduce a brief delay to give the child process a chance to run first
        usleep(10000);  // Adjust the delay as needed
        printf("goodbye\n");
        wait(NULL);
    }

    return 0;
}
