#include <stdio.h>
#include <unistd.h>

int main() {
    int x = 100;
    printf("Before fork, x in parent process: %d\n", x);

    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        x = x + 1;
        printf("After fork, x in child process: %d\n", x);
    } else {
        // Parent process
        x = x - 1;
        printf("After fork, x in parent process: %d\n", x);
    }

    return 0;
}
