#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    // Open a file
    int fd = open("output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    pid_t pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        printf("Child process: PID = %d\n", getpid());
        
        // Write to the file from the child process
        dprintf(fd, "Child process writing to the file\n");
    } else {
        // Parent process
        printf("Parent process: PID = %d\n", getpid());
        
        // Write to the file from the parent process
        dprintf(fd, "Parent process writing to the file\n");
    }

    // Close the file descriptor
    close(fd);

    return 0;
}
