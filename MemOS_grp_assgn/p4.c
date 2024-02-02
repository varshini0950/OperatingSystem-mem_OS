#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    printf("hello (pid:%d)\n", (int)getpid());
    int rc = fork();
    if (rc < 0) {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("child (pid:%d)\n", (int)getpid());
        // Using execl()
        execl("/bin/ls", "ls", "-l", NULL);
        // Using execle()
        // char *envp[] = {"PATH=/bin", NULL};
        // execle("/bin/ls", "ls", "-l", NULL, envp);
        // Using execlp()
        // execlp("ls", "ls", "-l", NULL);
        // Using execv()
        // char *args[] = {"ls", "-l", NULL};
        // execv("/bin/ls", args);
        // Using execvp()
        // char *args[] = {"ls", "-l", NULL};
        // execvp("ls", args);
        // Using execvpe()
        // char *args[] = {"ls", "-l", NULL};
        // char *envp[] = {"PATH=/bin", NULL};
        // execvpe("ls", args, envp);
    } else {
        // parent goes down this path (main)
        printf("parent of %d (pid:%d)\n", rc, (int)getpid());
    }
    return 0;
}

