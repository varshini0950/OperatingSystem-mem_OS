#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        close(STDOUT_FILENO);  // Close standard output
        printf("This message will not be printed to the console.\n");  // Attempt to print
    } else {
        // Parent process
        printf("Parent process waiting for child to finish.\n");
        waitpid(pid, NULL, 0);
    }

    return 0;
}
