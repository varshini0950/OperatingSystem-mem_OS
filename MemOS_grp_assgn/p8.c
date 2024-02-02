#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pipe_fd[2];
    pid_t child1, child2;

    // Create a pipe
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork the first child
    if ((child1 = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child1 == 0) {
        // First child process
        // Close read end of the pipe
        close(pipe_fd[0]);

        // Redirect standard output to the write end of the pipe
        dup2(pipe_fd[1], STDOUT_FILENO);

        // Close the write end of the pipe
        close(pipe_fd[1]);

        // Execute the command
        execlp("echo", "echo", "Hello from Child 1", NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    // Fork the second child
    if ((child2 = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child2 == 0) {
        // Second child process
        // Close write end of the pipe
        close(pipe_fd[1]);

        // Redirect standard input to the read end of the pipe
        dup2(pipe_fd[0], STDIN_FILENO);

        // Close the read end of the pipe
        close(pipe_fd[0]);

        // Execute the command
        execlp("cat", "cat", NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    // Parent process
    // Close both ends of the pipe
    close(pipe_fd[0]);
    close(pipe_fd[1]);

    // Wait for both child processes to finish
    waitpid(child1, NULL, 0);
    waitpid(child2, NULL, 0);

    return 0;
}

